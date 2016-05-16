#include<stdio.h>

int main(){


  long long int s, d;

  while(scanf("%lld %lld", &s, &d) != EOF){
    d = d*-1;
    if(4*s + d < 0 && 10*s+2*d > 0)
      printf("%lld\n", 10*s+2*d);
    else if(3*s + 2*d < 0 && 8*s+4*d > 0)
      printf("%lld\n", 8*s+4*d);
    else if(2*s + 3*d < 0 && 6*s+6*d > 0)
      printf("%lld\n", 6*s+6*d);
    else if(s + 4*d < 0 && 3*s+9*d > 0)
      printf("%lld\n", 3*s+9*d);
    else
      printf("Deficit\n");

  }
  return 0;
}
