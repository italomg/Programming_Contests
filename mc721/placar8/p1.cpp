#include<bits/stdc++.h>

using namespace std;


int main(){

  int K, N;
  while(cin>>N>>K && (N != 0 || K != 0)){
    int dp[105][105] = {{0}};
    int cur = 1;

    for(int i = 1; i <= N; i++)
      dp[i][1] = 1;

    for(int i = 1; i <= K; i++)
      dp[0][i] = 1;


    for(int i = 1; i <= N; i++){
      for(int j = 2; j <= K; j++){
	dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000;
      }
    }

    cout<<dp[N][K]<<endl;
  }

  return 0;
}
