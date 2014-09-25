describe("get screen size",function(){
  var screen;
  before(function(){
    screen = require("../index.js");
  })
  it("on default screen",function(){
    var res = screen.getSize();
    expect(res).to.be.not.null;
    expect(res).to.have.property("width");
    expect(res).to.have.property("height");
  })
})
