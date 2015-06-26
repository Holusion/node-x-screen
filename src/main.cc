#include <node.h>
#include <v8.h>
#include <stdio.h>
#include <X11/Xlib.h>
using namespace v8;


//Send the size of display :0
void getSize(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);
  Display *dpy;
  //Determine target display

  dpy = XOpenDisplay(":0");
  //Check display opening
  if(!dpy){
    args.GetReturnValue().Set(Undefined());
  }else{
    Local<Object> size = Object::New(isolate);
    size->Set(String::NewFromUtf8(isolate,"width"),Number::New(isolate,DisplayWidth(dpy,0)));
    size->Set(String::NewFromUtf8(isolate,"height"),Number::New(isolate,DisplayHeight(dpy,0)));
    XCloseDisplay(dpy);
    args.GetReturnValue().Set(size);
  }


}

//Mandatory Init function
void init(Handle<Object> exports) {
  NODE_SET_METHOD(exports, "getSize",getSize);
}

NODE_MODULE(xscreen, init)
