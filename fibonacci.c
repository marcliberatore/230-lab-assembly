#include <stdlib.h>

int count(int seq[], int len);

int* fibonacci(int len)
{
  int* seq = (int*) malloc(len * sizeof(int));
  seq[0] = 0;
  seq[1] = 1;
  for (int i = 2; i < len; i++)
  {
    seq[i] = seq[i-1] + seq[i-2];
  }
  return seq;
}

int main(int argc, char const *argv[])
{
  int size = 10;
  int* sequence = fibonacci(10);
  int result = count(sequence, size);
  return 0;
}
