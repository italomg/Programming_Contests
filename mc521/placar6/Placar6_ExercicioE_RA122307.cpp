#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int money5[11] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};

int main(){

  int intVal;
  double val;
  long long possibilities[6000] = {0};
  possibilities[0] = 1;
  for(int j = 0; j < 11; j++){
    for(int i = money5[j]; i <= 6000; i++){
      possibilities[i] += possibilities[i-money5[j]];
    }
  }
  scanf("%lf", &val);
  while(val){
    intVal = val*20;
    printf("%6.2lf%17lld\n", val, possibilities[intVal]);
    scanf("%lf", &val);
  }
  
  return 0;
}
