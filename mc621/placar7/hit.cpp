#include <cstdio>
#include <cmath>

using namespace std;


int main(){

  int wallN, p, l, r, goal1, loc1, goal2, loc2;
  double m1, m2;

  scanf("%d", &wallN);
  goal1 = 0;
  goal2 = 100000;
  for(int i = 0; i < wallN; i++){
    scanf("%d %d %d", &p, &l, &r);
    if(goal1 < l){
      goal1 = l;
      loc1 = p;
    }
    if(goal2 > r){
      goal2 = r;
      loc2 = p;
    }
  }
  scanf("%d %d %d", &p, &l, &r);
  m1 = (double)goal1/(double)loc1;
  m2 = (double)goal2/(double)loc2;
  
  if(m1 < m2)
    printf("Y\n");
  else
    printf("N\n");

  return 0;
}
