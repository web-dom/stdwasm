# stdwasm

A barebones common library for web assembly apps written in C

* [x] NULL, TRUE, FALSE, SUCCESS, FAILURE
* [x] export attribute for easily exposing a function on web assembly
* [x] assert() with compatability for [west](https://github.com/web-dom/west) testing framework
* [ ] malloc, free, realloc
* [ ] json_parse, json_stringify
* [ ] vector, string, hashmap
* [ ] webdom.h for accessing DOM,canvas,webgl via [web-dom](https://github.com/web-dom/web-dom/)


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
