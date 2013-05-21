app = require '../js/app'
should = require 'should'

set = (reg, value) ->
  should.exist(app['_'+reg])
  app.setValue app['_'+reg], value, 'i8'

get = (reg, mask) ->
  should.exist(app['_'+reg])
  app.getValue(app['_'+reg], 'i8') & mask

setO = (reg, offset, value) ->
  should.exist(app['_'+reg])
  app.setValue app['_'+reg]+offset, value, 'i8'

getO = (reg, offset, mask) ->
  should.exist(app['_'+reg])
  app.getValue(app['_'+reg]+offset, 'i8') & mask

#Check if first call since STOP3
#Check INTSTAT_RESUME
#Check INTSTAT_USBRSTF
#Check INTSTAT_SOFTOKF
#Check INTSTAT_STALLF
#Check INTSTAT_ERRORF
#Check INTSTAT_SLEEPF
#Check INTSTAT_TOKDNEF

describe 'usb', () ->
  it 'sends device descriptor', () ->
    #PID is SETUP 1101
    set 'USB_EP0_OUT', 0x34
    #Length is 8
    setO 'USB_EP0_OUT', 1, 8
    #hex  80 06 00 01 00 00 40 00
    #Into EP0_OUT_BUFF
    setO 'ep0_setup_packet', 0, 0x80
    setO 'ep0_setup_packet', 1, 0x06
    setO 'ep0_setup_packet', 2, 0x00
    setO 'ep0_setup_packet', 3, 0x01
    setO 'ep0_setup_packet', 4, 0x00
    setO 'ep0_setup_packet', 5, 0x00
    setO 'ep0_setup_packet', 6, 0x40
    setO 'ep0_setup_packet', 7, 0x00
    
    app.ccall 'usb_ep0_token'

    getO('USB_EP0_IN', 0, 0xFF).should.equal(0xC0)
    getO('USB_EP0_IN', 1, 0xFF).should.equal(0x08)

    addr = app.getValue(app['_EP0_IN_BUFF'], 'i32')
    app.getValue(addr, 'i8').should.equal(18)
    app.getValue(addr+1, 'i8').should.equal(1)
    app.getValue(addr+2, 'i8').should.equal(16)
    app.getValue(addr+3, 'i8').should.equal(1)
    app.getValue(addr+4, 'i8').should.equal(0)
    app.getValue(addr+5, 'i8').should.equal(0)
    app.getValue(addr+6, 'i8').should.equal(0)
    app.getValue(addr+7, 'i8').should.equal(8)

#Expect EP0_IN_BUFF to be
#18 1 16 1 0 0 0 8   (dec)
#check count is 8
#check own is set and data1
