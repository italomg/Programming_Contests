#include<cstdio>
#include<cmath>

#define E 0.000000001

using namespace std;
int p,q,r,s,t,u;
double equation(double x){
  return (p * exp(-x)) + (q * sin(x)) + (r * cos(x)) + (s * tan(x)) + (t * x *x) + u;
}

int main(){

  double start, final, media, mini, maxi;
  
  scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u);

  while(p != 0 || q != 0 || r != 0 || s != 0 || t != 0 || u != 0){

    start = 0;
    final = 1;
    if(equation(0) * equation(1) > 0){
      printf("No solution\n");
    }
    else{
      while(start + E < final){
	mini = equation(start);
	media = (start+final)/2;
	maxi = equation(media);
	if(mini * maxi <= 0)
	  final = media;
	else
	  start = media;
      }
      printf("%.4lf\n", media);
    }
   scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u);
  }

  return 0;
}
