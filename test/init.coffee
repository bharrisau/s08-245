app = require '../js/app'
should = require 'should'

###
# Clock/oscillator MCG
# USB Endpoints
# GPIO directions
# GPIO pullups
# Interupts
# SOPT1
# SOPT2
# SPMSC1

MCG init

USB init
###

set = (reg, value) ->
  should.exist(app['__'+reg])
  app.setValue app['__'+reg], value, 'i8'

get = (reg, mask) ->
  should.exist(app['__'+reg])
  app.getValue(app['__'+reg], 'i8') & mask

bin = () ->
  ret = 0
  for i in arguments
    ret += (1<<i)
  ret
  
describe 'init', () ->
  describe 'system', () ->
    func = 'init_system'

    describe 'write once', () ->
      it 'sets SOPT1', () ->
        ###
        # 7:6 COP Watchdog 0 = disable
        # 5   Stop mode    0 = disable
        # 1   BKGD select  0 = PTB2
        # 0   RESET enable 0 = PTB1
        ###
        mask = bin 7, 6, 5, 1, 0
        val = 0
        reg = 'SOPT1'

        set reg, (0xFF ^ val)
        app.ccall 'init_system'
        get(reg, mask).should.equal val

      it 'sets SOPT2', () ->
        ###
        # 7   COP select   0 = internal 1kHz
        # 6   COP window   0 = normal
        # 2   SPI1 filter  0 = disable
        ###
        mask = bin 7, 6, 2
        val = 0
        reg = 'SOPT2'

        set reg, (0xFF ^ val)
        app.ccall 'init_system'
        get(reg, mask).should.equal val

      it 'sets SPMSC1', () ->
        ###
        # 5   LowV int     0 = disabled
        # 4   LowV reset   1 = enabled
        # 3   LowV in stop 0 = disabled
        # 2   LowV detect  1 = enabled
        ###
        mask = bin 5, 4, 3, 2
        val = bin 4, 2
        reg = 'SPMSC1'

        set reg, (0xFF ^ val)
        app.ccall 'init_system'
        get(reg, mask).should.equal val

      it 'sets SPMSC2', () ->
        ###
        # 0   PWR down    0 = stop3
        ###
        mask = bin 0
        val = 0
        reg = 'SPMSC2'

        set reg, (0xFF ^ val)
        app.ccall 'init_system'
        get(reg, mask).should.equal val

    describe 'port a', () ->
      it 'sets PTAD', () ->
        ###
        # For outputs, 0 = low, 1 = high
        # PTA0 Device Reset       = 0
        # PTA1 TCK                = 0
        # PTA3 TMS                = 0
        # PTA4 TDO (s08->device)  = 0
        # PTA5 Fet                = 1
        # PTA7 Tx (s08->device)   = 0
        ###
        mask = bin 0, 1, 3, 4, 5, 7
        val = bin 5
        reg = 'PTAD'

        set reg, (0xFF ^ val)
        app.ccall 'init_system'
        get(reg, mask).should.equal val

      it 'sets PTADD', () ->
        ###
        # 0 for input, 1 for output
        # PTA0 Device Reset       = 1
        # PTA1 TCK                = 1
        # PTA2 TDI (device->s08)  = 0
        # PTA3 TMS                = 1
        # PTA4 TDO (s08->device)  = 1
        # PTA5 Fet                = 1
        # PTA6 Rx (device->s08)   = 0
        # PTA7 Tx (s08->device)   = 1
        ###
        mask = 0xFF
        val = bin 0, 1, 3, 4, 5, 7
        reg = 'PTADD'

        set reg, (0xFF ^ val)
        app.ccall 'init_system'
        get(reg, mask).should.equal val

      it 'sets PTAPE', () ->
        ###
        # 0 = no pullup, 1 = pullup
        # PTA2 TDI (device->s08)  = 1
        # PTA6 Rx (device->s08)   = 1
        ###
        mask = bin 2, 6
        val = bin 2, 6
        reg = 'PTAPE'

        set reg, (0xFF ^ val)
        app.ccall 'init_system'
        get(reg, mask).should.equal val

      it 'sets PTASE', () ->
        ###
        # 0 = no slew control, 1 - slew control
        # PTA0 Device Reset       = 1
        # PTA1 TCK                = 1
        # PTA3 TMS                = 1
        # PTA4 TDO (s08->device)  = 1
        # PTA5 Fet                = 1
        # PTA7 Tx (s08->device)   = 1
        ###
        mask = bin 0, 1, 3, 4, 5, 7
        val = bin 0, 1, 3, 4, 5, 7
        reg = 'PTASE'

        set reg, (0xFF ^ val)
        app.ccall 'init_system'
        get(reg, mask).should.equal val

      it 'sets PTADS', () ->
        ###
        # 0 = low drive (all)
        ###
        mask = 0xFF
        val = 0
        reg = 'PTADS'

        set reg, (0xFF ^ val)
        app.ccall 'init_system'
        get(reg, mask).should.equal val

    describe 'port b', () ->
      it 'sets PTBD', () ->
        ###
        # For outputs, 0 = low, 1 = high
        # PTB0 Device Suspend     = 0
        # PTB3 Device Delay Init  = 0
        ###
        mask = bin 0, 3
        val = 0
        reg = 'PTBD'

        set reg, (0xFF ^ val)
        app.ccall 'init_system'
        get(reg, mask).should.equal val

      it 'sets PTBDD', () ->
        ###
        # 0 for input, 1 for output
        # PTB0 Device Suspend     = 1
        # PTB1 Device Ready       = 0
        # PTB2 Unconnected        = 0
        # PTB3 Device Delay Init  = 1
        # PTB4 XTAL               = 0
        # PTB5 XTAL               = 0
        ###
        mask = bin 0, 1, 2, 3, 4, 5
        val = bin 0, 3
        reg = 'PTBDD'

        set reg, (0xFF ^ val)
        app.ccall 'init_system'
        get(reg, mask).should.equal val

      it 'sets PTBPE', () ->
        ###
        # 0 = no pullup, 1 = pullup
        # PTB1 Device Ready       = 1
        # PTB2 Unconnected        = 1
        # PTB4 XTAL               = 0
        # PTB5 XTAL               = 0
        ###
        mask = bin 1, 2, 4, 5
        val = bin 1, 2
        reg = 'PTBPE'

        set reg, (0xFF ^ val)
        app.ccall 'init_system'
        get(reg, mask).should.equal val

      it 'sets PTBSE', () ->
        ###
        # 0 = no slew control, 1 - slew control
        # PTB0 Device Suspend     = 1
        # PTB3 Device Delay Init  = 1
        ###
        mask = bin 0, 3
        val = bin 0, 3
        reg = 'PTBSE'

        set reg, (0xFF ^ val)
        app.ccall 'init_system'
        get(reg, mask).should.equal val

      it 'sets PTBDS', () ->
        ###
        # 0 = low drive (all)
        ###
        mask = 0xFF
        val = 0
        reg = 'PTBDS'

        set reg, (0xFF ^ val)
        app.ccall 'init_system'
        get(reg, mask).should.equal val