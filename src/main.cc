#define BUILDING_NODE_EXTENSION
#include <node.h>
#include <v8.h>
#include <stdio.h>
#include <X11/Xlib.h>
using namespace v8;

//Send the size of display :0
Handle<Value> size(const Arguments& args) {
  HandleScope scope;
  Display *dpy;
  Screen *screen;
  int x,y;
  dpy = XOpenDisplay(":0");

  Local<Object> size = Object::New();
  //Get Screen object
  screen= XScreenOfDisplay(dpy,0);

  size->Set(String::NewSymbol("width"),Integer::New(screen->width));
  size->Set(String::NewSymbol("height"),Integer::New(screen->height));
  return scope.Close(size);
}

//Mandatory Init function
void init(Handle<Object> exports) {
  exports->Set(String::NewSymbol("size"),
      FunctionTemplate::New(size)->GetFunction());
}

NODE_MODULE(xscreen, init)
