#include <cstdio>
#include <cmath>

#define E 0.0000000001

int main(){

  double angle, side, dist, arc;
  char type[5] = {0};

  while(scanf("%lf %lf %s", &side, &angle, type) != EOF){

    if(*type == 'm')
      angle = angle/60.0;
    side = side + 6440.0;
    
    if(angle - 180.0 > 0)
      angle = 360.0 - angle;

    dist = sqrt(2*pow(side,2) * (1 - cos(angle * M_PI / 180.0)));
    arc = (angle/360.0) * (2*M_PI*side);

    printf("%0.6lf %0.6lf\n", arc, dist);
  }

  return 0;
}
