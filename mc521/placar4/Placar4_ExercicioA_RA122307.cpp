#include<math.h>
#include<stdio.h>
#include<stdlib.h>


#define E 0.000000000001

using namespace std;

int main(){

  double res, maxres,Vt, Vo;
  long int maxi, i;
  scanf("%lf %lf", &Vt, &Vo);
  while(Vt || Vo){
    maxi = 0;
    maxres = 0;
    i = 1;
    while((Vt/i)>Vo){
      res = (0.3*sqrt((Vt/i)-Vo))*i;
      if(res == maxres)
	maxi = 0;
      else if(fabs(res-maxres) < E)
	maxi = 0;
      else if(res > maxres){
	maxres = res;
	maxi = i;
      }
      i++;
    }
    printf("%ld\n", maxi);
    scanf("%lf %lf", &Vt, &Vo);
  }

  return 0;
}
