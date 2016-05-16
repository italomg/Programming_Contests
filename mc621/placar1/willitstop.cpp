#include <cstdio>

using namespace std;

int main(){


  long long int n;

  scanf("%lld", &n);
  while(n != 1){
    
    if(n % 2 == 0)
      n = n / 2;
    else{
      printf("NIE\n");
      return 0;
    }
  }
  printf("TAK\n");
  //   while(n > 1){

  //   if(n == 2){
  //     printf("TAK\n");
  //     break;
  //   }
  //   else if(n == 3){
  //     printf("NIE\n");
  //     break;
  //   }

  //   if(n % 2 == 0)
  //     n = n/2;
  //   else
  //     n = (3*n)+3;
    
  // }


  return 0;
}
