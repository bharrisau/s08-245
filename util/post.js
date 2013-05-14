module.exports = Module;
var sinon = require('sinon');
module.exports.stubInit_wait_MCGSC = function(func) {
  _init_wait_MCGSC = func;
}
module.exports.stubInit_wait_USBCTL0 = function(func) {
  _init_wait_USBCTL0 = func;
}