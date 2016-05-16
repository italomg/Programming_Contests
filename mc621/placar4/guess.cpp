#include <cstdio>
#include <cstring>

#define INF 2000000000

int main(){

  char comp[3] = {0}, resp, m, e;
  long long int x, maxi = INF, mini = -INF;
  int impossible = 0, n;
  
  scanf("%d", &n);

  for(int i = 0; i < n; i++){
    scanf("%s %lld %c", comp, &x, &resp);
    
    if((!strcmp(comp, ">=") && resp == 'N') || (!strcmp(comp, "<") && resp == 'Y'))
      if(maxi > x-1)
	maxi = x-1;

    if((!strcmp(comp, "<=") && resp == 'N') || (!strcmp(comp, ">") && resp == 'Y'))
      if(mini < x+1)
	mini = x+1;
    
    if((!strcmp(comp, ">") && resp == 'N') || (!strcmp(comp, "<=") && resp == 'Y'))
      if(maxi > x)
	maxi = x;
    
    if((!strcmp(comp, "<") && resp == 'N') || (!strcmp(comp, ">=") && resp == 'Y'))
      if(mini < x)
	mini = x;

    if(mini > maxi){
      impossible = 1;
      break;
    }
  }
  if(impossible)
    printf("Impossible\n");
  else
    printf("%lld\n", (mini+maxi)/2);
  
  return 0;
}
