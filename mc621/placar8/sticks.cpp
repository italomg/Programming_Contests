#include <cstdio>

int main(){

  int n, m;

  scanf("%d %d", &n, &m);

  if(n < m)
    m = n;

  if(!(m % 2))
    printf("Malvika\n");
  else
    printf("Akshat\n");

  return 0;
}
