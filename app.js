//Test file for this module

var screen = require("./index.js");

var start = process.hrtime();
console.log(screen.size());
var diff = process.hrtime(start);
console.log("elapsed time : ");
console.log("- %s seconds",diff[0]+diff[1]*1e-9);
console.log("or : %s milliseconds",diff[0]*1e-3 + diff[1]*1e-6);
console.log("or : %s microseconds",diff[0]*1e-6 + diff[1]*1e-3);
console.log("or : %s nanoseconds",diff[0]*1e-9 + diff[1]);
