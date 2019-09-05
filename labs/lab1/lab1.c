#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
  int k=0;
  int start = 1;
  int end = 90;
  for(int i = start; i<=end; i++) {
    if ((i+5)%10 !=0)
    {
      k++;
      printf("\n%i",i);
    }
  }
  printf("\n\n%i\n",k);
}