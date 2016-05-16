#include <cstdio>

int main(){

  int ca = 1, balance, events, input;

  while(scanf("%d", &events) != EOF && events){
    balance = 0;
    for(int i = 0; i < events; i++){
      scanf("%d", &input);
      input ? balance++ : balance--;
    }
    printf("Case %d: %d\n", ca, balance);
    ca++;
  }
  
  return 0;
}
