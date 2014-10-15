#define BUILDING_NODE_EXTENSION
#include <node.h>
#include <v8.h>
#include <stdio.h>
using namespace v8;


/**
 * return default screen sizes. Might be replaced by a less dumb function in the future.
 */
Handle<Value> getSize(const Arguments& args) {
  HandleScope scope;
  Local<Object> size = Object::New();
  size->Set(String::NewSymbol("width"),Integer::New(1280));
  size->Set(String::NewSymbol("height"),Integer::New(1024));
  return scope.Close(size);
}

//Mandatory Init function
void init(Handle<Object> exports) {
  exports->Set(String::NewSymbol("getSize"),
      FunctionTemplate::New(getSize)->GetFunction());
}

NODE_MODULE(xscreen, init)
