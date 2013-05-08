app = require '../js/app'

main = app.cwrap 'main'

describe 'main', () ->
  it 'should set PTAD to 0xC', () ->
    app.setValue app.__PTAD, 0, "i8"
    main()
    app.getValue(app.__PTAD, "i8").should.equal(0xC)