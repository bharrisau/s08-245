usb = require 'usb'

code = []
index = 0

# Find device
device = usb.findByIds 0x15A2, 0x0038

close = (msg) ->
  console.log msg
  process.exit(1)

close("Unable to find device") if !device

getResult     = (cb) -> device.controlTransfer 0xC0, 0x6F, 0, 0, 1, cb
program       = (start, end, data, cb) -> device.controlTransfer 0x40, 0x61, start, end, data, waitCB(cb, 5)
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

#Open the file
#Parse the file into array
#parseInt(,16) for addresses
#new Buffer for data

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



