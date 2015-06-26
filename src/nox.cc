#include <node.h>
#include <stdio.h>
using namespace v8;


/**
 * return default screen sizes. Might be replaced by a less dumb function in the future.
 */
void getSize(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);
  Local<Object> size = Object::New(isolate);
  size->Set(String::NewFromUtf8(isolate,"width"),Number::New(isolate,1280));
  size->Set(String::NewFromUtf8(isolate,"height"),Number::New(isolate,1024));
  args.GetReturnValue().Set(size);
}

//Mandatory Init function
void init(Handle<Object> exports) {
  NODE_SET_METHOD(exports, "getSize",getSize);
}

NODE_MODULE(xscreen, init)
