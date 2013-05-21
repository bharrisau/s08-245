usb = require 'usb'

# Find device
device = null
empty = new Buffer(0)

waitDevice = () ->
  console.log "Waiting"
  device = usb.findByIds 0x1d50, 0xAAAA
  return testDevice() if device
  setTimeout waitDevice, 500

testDevice = () ->
  device.open()
  console.log "Found device - disabling power"
  device.controlTransfer 0x40, 0x71, 0, 0, empty, test2

test2 = () ->
  setTimeout test3, 5000

test3 = () ->
  console.log "Enabling power"
  device.controlTransfer 0x40, 0x70, 0, 0, empty, test4

test4 = () ->
  setTimeout test5, 1000

test5 = () ->
  console.log "Bootloader mode"
  device.controlTransfer 0x40, 0x68, 0, 0, empty, null

waitDevice()