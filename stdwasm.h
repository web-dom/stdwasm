#ifndef STDWASM_H
#define STDWASM_H
#define size_t unsigned long
#define export __attribute__((visibility("default")))
#define NULL 0
#define TRUE 1
#define FALSE 0
#define SUCCESS 0
#define FAILURE 1
#define assert(expr, message)                                                  \
  if (!(expr))                                                                 \
  return assert_failed(message, __FILE__, __LINE__)

void *malloc(size_t size);
size_t assert_failed(char *message, char *file, int line);

struct LinkedList {
  void *data;
  struct LinkedList *next;
};

struct LinkedList *cons(void *data, struct LinkedList *next);
size_t cons_len(struct LinkedList *list);
size_t strlen(const char *a);
char *concat(char *strFirst, char *strSecond);
char *itoa(int num);
#endif
