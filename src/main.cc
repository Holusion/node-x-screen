#define BUILDING_NODE_EXTENSION
#include <node.h>
#include <v8.h>
#include <stdio.h>
#include <X11/Xlib.h>
using namespace v8;


//Send the size of display :0
Handle<Value> getSize(const Arguments& args) {
  HandleScope scope;
  Display *dpy;
  //Determine target display

  dpy = XOpenDisplay(":0");
  //Check display opening
  if(!dpy){
    return scope.Close(Undefined());
  }else{
    Local<Object> size = Object::New();
    size->Set(String::NewSymbol("width"),Integer::New(DisplayWidth(dpy,0)));
    size->Set(String::NewSymbol("height"),Integer::New(DisplayHeight(dpy,0)));
    XCloseDisplay(dpy);
    return scope.Close(size);
  }


}

//Mandatory Init function
void init(Handle<Object> exports) {
  exports->Set(String::NewSymbol("getSize"),
      FunctionTemplate::New(getSize)->GetFunction());
}

NODE_MODULE(xscreen, init)
