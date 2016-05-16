#include <cstdio>
#include <set>
#include <cmath>

using namespace std;

int main(){

  multiset<pair<double, int> > distancies;
  int n, o, d, p, pop;
  double dist, res;

  scanf("%d %d", &n, &pop);
  for(int i = 0; i < n; i++){
    scanf("%d %d %d", &o, &d, &p);
    dist = sqrt(pow(o,2) + pow(d,2));
    distancies.insert(pair<double, int>(dist, p));
  }

  res = 0;
  pop = 1000000 - pop;
  multiset<pair<double,int> >::iterator it = distancies.begin();
  while(pop > 0 && it != distancies.end()){
    res = it->first;
    pop -= it->second;
    it++;
  }
  if(pop > 0)
    printf("-1\n");
  else
    printf("%lf\n", res);

  return 0;
}
