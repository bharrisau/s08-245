app = require '../js/app'
should = require 'should'
sinon = require 'sinon'

set = (reg, value) ->
  should.exist(app['__'+reg])
  app.setValue app['__'+reg], value, 'i8'

get = (reg, mask) ->
  should.exist(app['__'+reg])
  app.getValue(app['__'+reg], 'i8') & mask

getOffset = (reg, offset) ->
  should.exist(app['_'+reg])
  a = app.getValue(app['_'+reg] + offset, 'i8')
  a += 256 if a < 0
  a

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
    it 'moves from FEI to FBE', () ->
      #Set MCGC2
      #BDIV      7:6 = 00   divide by 1
      #RANGE       5 =  1   External 1M-16M
      #HGO         4 =  1   High gain
      #EREFS       2 =  1   Crystal
      #ERCLKEN     1 =  1   External

      #Wait MCGSC
      #OSCINIT - bit 1 = 1
      firstWait = (a, b) ->
        get('MCGC2', 0xFF).should.equal bin(5, 4, 2, 1)
        a.should.equal bin(1)
        b.should.equal bin(1)

        app.stubInit_wait_MCGSC secondWait


      #Block interrupts?

      #Set MCGC1
      #CLKS      7:6 = 10   Extref
      #RDIV      5:3 = 111  Divide by 128
      #IREFS       2 = 0    External clock

      #Wait MCGSC
      #IREFST - bit 4 = 0
      #CLKST - bit 3:2 = 10
      secondWait = sinon.spy (a, b) ->
        get('MCGC1', 0xFF).should.equal bin(7, 5, 4, 3)
        a.should.equal bin(4,3,2)
        b.should.equal bin(3)

        #stub.restore()

      #stub = sinon.stub app.that, "_init_wait_MCGSC", firstWait
      app.stubInit_wait_MCGSC firstWait
      app.ccall 'init_fbe'
      secondWait.called.should.be.true

    it 'moves from FBE to PBE', () ->
      #Set MCGC2
      #BLPE mode because of high clock
      #LP          3 = 1    Disable FLL/PLL

      #Set MCGC1
      #16 Mhz clock - 48Mhz output  (16/8)*24 = 48
      #RDIV      5:3 = 011  Divide by 8
      
      #Set MCGC3
      #PLLS       6 = 1     PLL
      #VDIV     3:0 = 0110  Mult by 24

      #Wait MCGSC
      #PLLST - bit 5 = 1
      firstWait = (a, b) ->
        get('MCGC1', 0xFF).should.equal bin(7, 4, 3)
        get('MCGC2', 0xFF).should.equal bin(5, 4, 3, 2, 1)
        get('MCGC3', 0xFF).should.equal bin(6, 2, 1)
        a.should.equal bin(5)
        b.should.equal bin(5)

        app.stubInit_wait_MCGSC secondWait

      #Set MCGC2
      #Leave BLPE mode
      #LP          3 = 0    Enable FLL/PLL

      #Wait MCGSC
      #LOCK - bit 6 = 1
      secondWait = sinon.spy (a, b) ->
        get('MCGC2', 0xFF).should.equal bin(5, 4, 2, 1)
        a.should.equal bin(6)
        b.should.equal bin(6)

      app.stubInit_wait_MCGSC firstWait
      app.ccall 'init_pbe'
      secondWait.called.should.be.true

    it 'moves from PBE to PEE', () ->
      #16 Mhz clock
      #CLKS     7:6 = 00    PLL
      MCGC1 = (MCGC1 & bin(5, 4, 3, 2, 1, 0))

      #Wait MCGSC
      #CLKST - bit 3:2 = 11
      firstWait = sinon.spy (a, b) ->
        get('MCGC1', 0xFF).should.equal bin(4, 3)
        a.should.equal bin(3,2)
        b.should.equal bin(3,2)

      app.stubInit_wait_MCGSC firstWait
      app.ccall 'init_pee'
      firstWait.called.should.be.true

  describe 'usb', () ->
    it 'resets USB', () ->
      #USBCTL0_RESET = 1
      #bit 7

      #wait USBCTL0_RESET = 0
      firstWait = sinon.spy (a, b) ->
        a += 256 if a < 0
        get('USBCTL0', bin(7)).should.equal bin(7)
        a.should.equal bin(7)
        b.should.equal 0
        set 'USBCTL0', 0

      app.stubInit_wait_USBCTL0 firstWait
      app.ccall 'init_reset_usb'
      firstWait.called.should.be.true

    it 'sets EP0 OUT for enumeration', () ->
      # Initialize the BD of endpoint 0
      #  (For BD OUT: set buffer address EPADR,
      #  set CNT = 8, DATA0, DTS=1, OWN = 1)
      app.ccall 'init_ep0_out'

      getOffset('USB_EP0_OUT', 2).should.equal 0
      getOffset('USB_EP0_OUT', 1).should.equal 0x08
      getOffset('USB_EP0_OUT', 0).should.equal bin(7, 3)

      get('EPCTL0', 0xFF).should.equal bin(3, 2, 0)

    it 'configures the USB module', () ->
      #Config USB module (pullup resistor, regulator, PHY)
      #USBCTL0_USBPU = 1  bit 6
      #USBCTL0_USBVREN = 0  bit 2
      #USBCTL0_USBPHYEN = 1  bit 0
      app.ccall 'init_usbctl0'

      get('USBCTL0', 0xFF).should.equal bin(6, 0)

    it 'enables the USB module', () ->
      #Enable USB module and USB interrupt
      #INTENB = 0xBF if want interrupts
      #ERRENB = 0xBF if error interrupts
      #CTL_USBEN = 1

      #Set USB state ATTACHED (of POWERED, DEFAULT, ADDR_PENDING,
      #ADDRESSED, CONFIGURED, SUSPEND)
      app.ccall 'init_enable_usb'

      get('CTL', 0xFF).should.equal bin(0)
      getOffset('usb_state', 0).should.equal 1

