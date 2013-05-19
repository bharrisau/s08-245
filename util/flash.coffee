usb = require 'usb'
lazy = require 'lazy'
fs = require 'fs'

data = []

ll = new lazy(fs.createReadStream('./S08JS16.s19'))
  .on 'end', () ->
    work()
  .lines
  .map (line) ->
    line = line.toString()
    length = parseInt(line.slice(2,4), 16)
    switch line.slice(0, 2)
      when "S1"
        length -= 3
        return {
          length: length
          address: parseInt(line.slice(4,8), 16)
          data: new Buffer(line.slice(8,8+length*2), 'hex')
        }
      when "S2"
        length -= 4
        return {
          length: length
          address: parseInt(line.slice(4,10), 16)
          data: new Buffer(line.slice(10,10+length*2), 'hex')
        }
      when "S3"
        length -= 5
        return {
          length: length
          address: parseInt(line.slice(4,12), 16)
          data: new Buffer(line.slice(12,12+length*2), 'hex')
        }
    return null
  .filter (line) ->
    line
  .forEach (line) ->
    data.push line

code = []
index = 0

close = (msg) ->
  console.log msg
  process.exit(1)

getResult     = (cb) -> device.controlTransfer 0xC0, 0x6F, 0, 0, 1, cb
program       = (start, length, data, cb) -> device.controlTransfer 0x40, 0x61, start, start+length-1, data, waitCB(cb, 5)
massErase     = (cb) -> device.controlTransfer 0x40, 0x63, 0, 0, null, waitCB(cb, 150)
partialErase  = (cb) -> device.controlTransfer 0x40, 0x64, 0, 0, null, waitCB(cb, 700)
reset         = (cb) -> device.controlTransfer 0x40, 0x68, 0, 0, null, cb
crcCheck      = (cb) -> device.controlTransfer 0x40, 0x69, 0, 0, null, waitCB(cb, 10)

waitCB = (cb, timeout) ->
  checkResult = (err, data) ->
    cb(err) if err
    cb(new Error("Command failed")) if data[0] != 0x01
    cb(err, data)

  (err, data) ->
    cb(err, data) if err
    setTimeout getResult, timeout, checkResult

work = () ->
  # Find device
  device = usb.findByIds 0x15A2, 0x0038
  close("Unable to find device") if !device
  #all this in try catch
  device.open()

  console.log "Erasing the device"
  massErase startProgram

startProgram = (err) ->
  close("Unable to erase flash") if err
  #set index for array
  programLoop(null)

programLoop = (err) ->
  close("Failed during programming") if err

  if index >= code.length
    console.log "Programming complete             "
    console.log "Calculating checksum"
    return crcCheck(endProgram)

  line = code[index]
  index++
  process.stdout.write("Writing " + index + "/" + code.length + "\r")
  program line.start, line.end, line.data, programLoop

endProgram = (err) ->
  close("CRC check failed") if err
  "Checksum correct"
  "Resetting device"
  reset (err) ->
    close("Reset failed") if err
    console.log "Successful"
    process.exit(0)



