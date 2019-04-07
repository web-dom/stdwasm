# stdwasm

A smaller standard library for web assembly apps written in C

* [x] NULL, TRUE, FALSE, SUCCESS, FAILURE
* [x] export attribute for easily exposing a function on web assembly
* [x] assert() with compatability for [west](https://github.com/web-dom/west) testing framework
* [ ] malloc, free, realloc
* [ ] json_parse, json_stringify
* [ ] vector, hashmap, linked list
* [x] immutable string helpers
* [ ] webdom.h for accessing DOM,canvas,webgl via [web-dom](https://github.com/web-dom/web-dom/)

# Why create a new standard library?

`stdwasm` is a subset of `stdlib` that's more targeted for web assembly and it's minimal capabilities. The C standard library, while great at memory management and file based system calls, contains many ideas meant for a variety of architectures and system capabilities that may not reflect web assembly itself, the web, or other places web assembly might run (wasmer, embedded, etc.). Current trends for web assembly in C require bindings (like emscripten) that makes web assembly modules locked to an API of imports it may not even use. Building an app that uses `stdwasm` and needs environment capabilities (like DOM access or file access) would have you use 3rd party libary that directly reflects the environment your web assembly runs in (such as [web-dom](https://github.com/web-dom/web-dom/) for DOM access) hopefully creating less magic about what's going on. This project aims to enable an ecosystem of libraries that run highly optimized web assembly code, work well together, and are portable the many places web assembly runs. 

To give specific examples of what `stdwasm` will not include:
* `fprintf`, `fopen` that work on files
* `printf` and logging functions

`stdwasm` will however include:
* `malloc`, `memcpy` and other memory management functions
* common defines like `NULL`

# Testing
```C
#include "stdwasm.h"
export int test_addition(){
  assert(4 == 2*2,"2*2 should be 4");
  assert(1 == 1*1,"1*1 should be 1");
  return SUCCESS;
}
```

# Compiling this project

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
