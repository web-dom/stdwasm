#include "stdwasm.h"

// you would use this variable to write your own malloc/free
extern size_t __heap_base;
size_t current_heap = 0;

void *malloc(size_t size) {
  if(current_heap == 0){
    current_heap = __heap_base;
  }
  size_t target = current_heap;
  current_heap += size;
  return (void *)target;
}

size_t assert_failed(char *message, char *file, int line) {
  return (size_t)message;
}

size_t cons_len(struct LinkedList *list) {
  int len;
  for (len = 0; list != NULL; len++) {
    list = list->next;
  }
  return len;
}

struct LinkedList *cons(void *data, struct LinkedList *next) {
  struct LinkedList *list = malloc(sizeof(struct LinkedList));
  list->data = data;
  list->next = next;
  return list;
}

char *itoa(int num) {
  char *str = malloc(10);
  int i, rem, len = 0, n;
  for (n = num; n != 0; n /= 10) {
    len++;
  }
  for (i = 0; i < len; i++) {
    rem = num % 10;
    num = num / 10;
    str[len - (i + 1)] = rem + '0';
  }
  str[len] = '\0';
  return str;
}

void *memcpy(void *str1, const void *str2, size_t n) {
  size_t i;
  for (i = 0; i < n; i++) {
    ((char *)str1)[i] = ((char *)str2)[i];
  }
  return str1;
}

size_t strlen(const char *a) {
  int len;
  for (len = 0; a[len] != '\0'; len++) {
  }
  return len;
}

char *strconcat(char *strFirst, char *strSecond) {
  size_t firstLen = strlen(strFirst);
  size_t secondLen = strlen(strSecond);
  size_t len = firstLen + secondLen;
  char *newStr = malloc(len + 1);
  memcpy(newStr, strFirst, firstLen);
  memcpy((char *)((size_t)newStr + strFirst), strSecond, secondLen);
  newStr[len - 1] = '\0';
  return newStr;
}
