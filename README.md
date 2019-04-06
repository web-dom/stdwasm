# stdwasm

A barebones common library for web assembly apps written in C

* [x] NULL, TRUE, FALSE, SUCCESS, FAILURE
* [x] export attribute for easily exposing a function on web assembly
* [x] assert() with compatability for [west](https://github.com/web-dom/west) testing framework
* [ ] malloc, free, realloc
* [ ] json_parse, json_stringify
* [ ] vector, string, hashmap


# Testing
```C
#include "stdwasm.h"
export int test_addition(){
  assert(4 == 2*2,"2*2 should be 4");
  assert(1 == 1*1,"1*1 should be 1");
  return SUCCESS;
}
```
