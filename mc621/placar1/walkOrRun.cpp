#include <cstdio>
#include <list>

using namespace std;

int main(){

  int cases, S, C, R, input;
  double res;
  list<int> Vi;

  scanf("%d", &cases);
  while(cases--){
    res = 0;
    scanf("%d %d %d", &S, &C, &R);
    for(int i = 0; i < S; i++){
      scanf("%d", &input);
      Vi.push_back(input);
    }
    
    Vi.sort();
    for(int i = 0; i < S; i++){
      if(i < C)
	res += (double)1/(Vi.front()+R);
      else
      res += (double)1/Vi.front();
      Vi.pop_front();
    }
    printf("%.2lf", res);
    //if(cases)
      puts("");
  }

  return 0;
}
