#include<cstdio>

using namespace std;

int main(){

  int cases, no = 0, degrais;
  
  scanf("%d", &cases);

  while(cases--){
    scanf("%d", &degrais);
    int n[100000] = {0}, diff = 0, maxi = -1, res;
    n[0] = 0;
    for(int i = 1; i <= degrais; i++){
      scanf("%d", &n[i]); 
    }
    
    for(int i = 1; i <= degrais; i++){
      diff = n[i] - n[i-1];
      if(diff > maxi)
	maxi = diff;
    }

    res = maxi;

    for(int i = 1; i <= degrais; i++){
      diff = n[i] - n[i-1];
      if(maxi == diff)
	maxi--;
      else if(diff > maxi){
	res++;
	break;
      }
    }
    no++;
    printf("Case %d: %d", no, res);
    //if(cases)
    puts("");
    
  }

  return 0;
}
