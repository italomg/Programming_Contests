#include <cstdio>

int resolve(int fatorial[9], int target, int index){

  int k = 0;
  while(target){
    if(target >= fatorial[index]){
      k += target / fatorial[index];
      target = target % fatorial[index];
    }
    else
      index--;
  }

  return k;
} 


int main(){


  int input, fatorial[9] = {0};

  fatorial[1] = 1;
  for(int i = 2; i < 9; i++)
    fatorial[i] = fatorial[i-1] * i;
  
  while(scanf("%ld", &input) != EOF)
    printf("%ld\n", resolve(fatorial, input, 8));
  

  return 0;
}
