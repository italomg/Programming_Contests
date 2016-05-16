#include <cstdio>
#include <algorithm>

int main(){


  int a, b;

  while(scanf("%d %d", &a, &b) != EOF){
    printf("%d\n", std::max(a,b));
  }

  return 0;
}
