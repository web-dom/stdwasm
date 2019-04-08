#include "../../stdwasm.h"

export int test_memory(){
  size_t a = (size_t)malloc(3);
  size_t b = (size_t)malloc(3);
  assert(a!=b,"consecutive malloc should be different");
  char * src = "12";
  char * dest = "abc";
  memcpy(dest,src,2);
  assert('1'==dest[0],"memcpy first character should be 1");
  assert('2'==dest[1],"memcpy first character should be 2");
  assert('c'==dest[2],"memcpy first character should be c");
  return SUCCESS;
}

export int test_str(){
  assert(TRUE==streq("a","a"),"a and a should be equal");
  assert(FALSE==streq("a","b"),"a and b should not be equal");
  assert(FALSE==streq("aa","b"),"aa and b should not be equal");
  assert(TRUE==streq("",""),"empty strings should be equal");
  assert(0==strlen(""),"empty string should be length 0");
  assert(3==strlen("abc"),"abc should be length 3");
  assert(TRUE==streq("ab",strconcat("a","b")),"concat a and b should be length 2");
  return SUCCESS;
}

export int test_cons(){
  struct LinkedList *a = cons("a",NULL);
  struct LinkedList *b = cons("b",NULL);
  assert(1==cons_len(a),"cons length should be 1");
  assert(0==cons_len(NULL),"cons length should be 0");
  assert(NULL==a->next,"const next should be null");
  assert(2==cons_len(cons("a",cons("b",NULL))),"cons length should be 2");
  return SUCCESS;
}
