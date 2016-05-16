#include <bits/stdc++.h>

using namespace std;

int main(){

  int N, G;

  while(cin>>N>>G){

    priority_queue<int> games;
    int S, R, res = 0;

    for(int i = 0; i < N; i++){
      cin>>S>>R;
      if(S  - R <= 0)
	games.push(S - R);
      
      if(S - R > 0)
	res += 3;
    }
    
    int cur;
    while(!games.empty()){
      cur = games.top();
      if(abs(cur) + 1 <= G){
	G -= abs(cur) + 1;
	res += 3;
      }
      else if(abs(cur) == G){
	G -= abs(cur);
	res++;
      }
      games.pop();
    }

    cout<<res<<endl;
  }

  return 0;
}
