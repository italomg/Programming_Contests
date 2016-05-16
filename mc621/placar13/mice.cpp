#include <cstdio>

int main(){

  int w, b, total;
  double princes = 0.0, lastprob = 0.0, dragon = 0.0;
  scanf("%d %d", &w, &b);

  total = w + b;

  while(w != 0){

    lastprob = (double)w / total;
    princes += lastprob;
    
    if(b > 0){
      b--;
      total--;
    }
    else
      break;

    dragon = (1 - lastprob) * ((double)b/total);
    princes +=  ;
    
    
  }

  return 0;
}
