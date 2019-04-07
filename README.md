# stdwasm

A barebones common library for web assembly apps written in C

* [x] NULL, TRUE, FALSE, SUCCESS, FAILURE
* [x] export attribute for easily exposing a function on web assembly
* [x] assert() with compatability for [west](https://github.com/web-dom/west) testing framework
* [ ] malloc, free, realloc
* [ ] json_parse, json_stringify
* [ ] vector, hashmap, linked list
* [x] immutable string helpers
* [ ] webdom.h for accessing DOM,canvas,webgl via [web-dom](https://github.com/web-dom/web-dom/)

# Why create a new standard library?

The C standard libray contains historical code meant for a variety of architectures and system capabilities that make no sense for the web. For instance, assuming a `println` is an archiac abstraction that may not be reflective of the actual environment. `stdwasm` aims to create a standard library optimized for web assembly memory and assume no system capabilities. If you want system capabilities, bring your own that actually reflect the system your web assembly runs in (such as [web-dom](https://github.com/web-dom/web-dom/) for DOM access). The hope to create an ecosystem of `stdwasm` libraries that make highly optimized web assembly that work well together.

# Testing
```C
#include "stdwasm.h"
export int test_addition(){
  assert(4 == 2*2,"2*2 should be 4");
  assert(1 == 1*1,"1*1 should be 1");
  return SUCCESS;
}
```

# Compiling examples in this project

You'll need several LLVM tools before you can compile:

Add to your sources appropriate sources

`sudo vim /etc/apt/sources.list`

choose the right sources from http://apt.llvm.org/

```
sudo apt-get update
sudo apt-get install llvm-8
sudo apt-get install wasm-ld-8
sudo apt-get install lld-8
sudo apt-get install clang-8
sudo apt-get install clang-format
```

Now you should be ready to build

`make`

Then you can serve the example with

`make serve`
