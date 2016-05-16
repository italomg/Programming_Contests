#include <stdio.h>
#include <string.h>
#include <map>

using namespace std;

int main (){

  int N, maxi, numb, input;
  
  while(scanf("%d", &N) != EOF && N){
    maxi = numb = 0;
    map<int, int> ducks;
    for(int i = 0; i < N; i++){
      scanf("%d", &input);
      ducks[input]++;
    }
    printf("%d\n", ducks.begin()->first);
  }

  return 0;
}
