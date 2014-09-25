#define BUILDING_NODE_EXTENSION
#include <node.h>
#include <v8.h>
#include <stdio.h>
#include <X11/Xlib.h>
using namespace v8;

const char* ToCString(const v8::String::Utf8Value& value) {
  return *value ? *value : "<string conversion failed>";
}

//Send the size of display :0
Handle<Value> size(const Arguments& args) {
  HandleScope scope;
  Display *dpy;
  int x,y;
  const char *name;
  //Determine target display
  if (args.Length() < 2) {
    name = ":0";
  }else {
    String::Utf8Value name_utf8(args[1]->ToString());
    name =ToCString(name_utf8);
  }
  dpy = XOpenDisplay(name);
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
  exports->Set(String::NewSymbol("size"),
      FunctionTemplate::New(size)->GetFunction());
}

NODE_MODULE(xscreen, init)
