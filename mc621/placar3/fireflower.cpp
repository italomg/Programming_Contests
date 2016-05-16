#include <stdio.h>
#include <math.h>

int main(){

  int r1 = 0, x1 = 0, y1 = 0, r2 = 0, x2 = 0, y2 = 0;
  float eucl_dist = 0;
  
  while(scanf("%d %d %d %d %d %d", &r1, &x1, &y1, &r2, &x2, &y2) != EOF){
    eucl_dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    if(r1 - eucl_dist >= r2)
      printf("RICO\n");
    else
      printf("MORTO\n");
  }
  
  return 0;
}
