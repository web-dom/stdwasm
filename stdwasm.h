#ifndef STDWASM_H
#define STDWASM_H

#define export __attribute__((visibility("default")))
#define NULL 0
#define TRUE 1
#define FALSE 0
#define SUCCESS 0
#define FAILURE 1
#define ASSERT(expr, message)                                                  \
  if (!(expr))                                                                 \
  return assert_failed(message, __FILE__, __LINE__)

void *malloc(unsigned long size);
int assert_failed(char *message, char *file, int line);

#endif
