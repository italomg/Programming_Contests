#include <bits/stdc++.h>

using namespace std;

int main(){

  int N;
  cin>>N;

  //  int Ans[105][25020] = {{0}};

  while(N--){

    int m = 0, val = 0, original_m = 0;
    cin>>m;

    vector<int> vals;
    int sum = 0, original_sum = 0;
    vals.push_back(0);
    original_m = m;

    while(m--){
      cin>>val;
      vals.push_back(val);
      sum += val;
    }

    m = original_m;
    int **Ans = (int **) malloc((m+5) * sizeof(int*));
    for(int i = 0; i < m+5; i++){
      Ans[i] = (int *) malloc((sum+5) * sizeof(int));
      memset((int *)Ans[i], 0, (sum+5) * sizeof(int));
    }

    sort(vals.begin(), vals.end());
    original_sum = sum;
    sum = sum / 2;

    for(int i = 1; i <= m; i++){
      for(int j = 1; j <= sum; j++){
	if(j >= vals[i])
	  Ans[i][j] = max(vals[i] + Ans[i-1][j-vals[i]], Ans[i-1][j]);
	else
	  Ans[i][j] = Ans[i-1][j];
      }
    }

    printf("%d\n", original_sum - 2*Ans[m][sum]);
  }

  return 0;
}
