#include <cstdio>

int main(){

  int n;
  while(scanf("%d", &n) != EOF){
    int sum = 0, input[n];
    for(int i = 0; i < n; i++){
      scanf("%d", &input[i]);
      sum += input[i];
    }
    if(sum % n)
      printf("-1\n");
    else{
      int cur, avg, ans;
      avg = sum/n;
      cur = n-1;
      ans = 1;
      for(int i = 0; i < n; i++){
	if(input[i] < avg){
	  ans += avg-input[i];
	  input[i] = avg;
	  if(input[cur] > avg)
	    input[cur] -= avg-input[i];
	  else
	    cur--;
	}
      }
      printf("%d\n", ans);
    }
  }

  return 0;
}
