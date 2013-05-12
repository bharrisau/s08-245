app = require '../js/app'
should = require 'should'
sinon = require 'sinon'

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

  describe 'mcg', () ->
    before () ->
      app._init_wait_MCGSC
      #Mock out call to init_wait_MCGSC
    it 'moves from FEI to FBE', () ->
      #BDIV      7:6 = 00   divide by 1
      #RANGE       5 =  1   External 1M-16M
      #HGO         4 =  1   High gain
      #EREFS       2 =  1   Crystal
      #ERCLKEN     1 =  1   External
      MCGC2 = bin 5, 4, 2, 1

      #OSCINIT - bit 1 = 1
      init_wait_MCGSC bin(1), bin(1)

      #Block interrupts?

      #CLKS      7:6 = 10   Extref
      #RDIV      5:3 = 111  Divide by 128
      #IREFS       2 = 0    External clock
      MCGC1 = bin 7, 5, 4, 3

      #IREFST - bit 4 = 0
      #CLKST - bit 3:2 = 10
      init_wait_MCGSC bin(4,3,2), bin(3)

    it 'moves from FBE to PBE', () ->
      #BLPE mode because of high clock
      #LP          3 = 1    Disable FLL/PLL
      MCGC2 = MCGC2 | bin 3

      #16 Mhz clock - 48Mhz output  (16/8)*24 = 48
      #RDIV      5:3 = 011  Divide by 8
      MCGC1 = (MCGC1 & bin(7,6,2,1,0)) | bin(4,3)
      
      #PLLS       6 = 1     PLL
      #VDIV     3:0 = 0110  Mult by 24
      MCGC3 = bin 6, 2, 1

      #PLLST - bit 5 = 1
      init_wait_MCGSC bin(5), bin(5)

      #Leave BLPE mode
      #LP          3 = 0    Enable FLL/PLL
      MCGC2 = MCGC2 & bin(7, 6, 5, 4, 2, 1, 0)

      #LOCK - bit 6 = 1
      init_wait_MCGSC bin(6), bin(6)

    it 'moves from PBE to PEE', () ->
      #16 Mhz clock
      #CLKS     7:6 = 00    PLL
      MCGC1 = (MCGC1 & bin(5, 4, 3, 2, 1, 0))

      #CLKST - bit 3:2 = 11
      init_wait_MCGSC bin(3,2), bin(3,2)

  describe 'usb', () ->
    #USBCTL0_RESET = 1

    #Resetted?
    #wait USBCTL0_RESET = 0

    #Initialize the BD of endpoint 0
    #  (For BD OUT: set buffer address EPADR,
    #  set CNT = 8, DATA0, DTS=1, OWN = 1)
    # USB+0x02 = ADDR
    # Set other ednpoint addresses. 64 bytes?
    # USB+0x05 = ADDR
    # USB+0x04 = 0x08
    # USB+0x03 = 0x88

    #Enable EP0 (EPCTL0 = 0x0D)

    #Config USB module (pullup resistor, regulator, PHY)
    #USBCTL0_USBPU = 1
    #USBCTL0_USBVREN = 0
    #USBCTL0_USBPHYEN = 1

    #Enable USB module and USB interrupt
    #INTENB = 0xBF if want interrupts
    #ERRENB = 0xBF if error interrupts
    #CTL_USBEN = 1

    #Set USB state ATTACHED (of POWERED, DEFAULT, ADDR_PENDING,
      #ADDRESSED, CONFIGURED, SUSPEND)
    #Internal RAM value

