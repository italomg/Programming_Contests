#include <stdio.h>
#include <math.h>

int main(){

  unsigned long int n, raiz;
  int swit;
  
  while(scanf("%ld", &n) != EOF && n != 0){
    raiz = (unsigned long int)sqrt(n);
    if(n == raiz*raiz)
      printf("yes\n");
    else
      printf("no\n");
  }
  
  return 0;
}
