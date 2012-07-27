#include <stdio.h>
#include <malloc.h>

int main() {
  const unsigned long BUF_SIZE = 1024L*1024*1024*2;
  void * p = calloc(BUF_SIZE/8, 8);
  //memset(p, 0, BUF_SIZE);
  printf("Successfully allocated %lu bytes", BUF_SIZE);
  free(p);
  return 0;
}
