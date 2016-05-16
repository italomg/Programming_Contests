#include <bits/stdc++.h>

using namespace std;

map<pair<int,int>, int> dp;

int bt(string &s, int start, int end){

  if(end - start < 1)
    return 0;

 if(dp.find(pair<int,int>(start, end)) != dp.end())
    return dp[pair<int,int>(start, end)];

 if(s[start] == s[end]){
  dp[pair<int,int>(start, end)] = bt(s, start+1, end-1);
  return dp[pair<int,int>(start, end)];
 }

  dp[pair<int,int>(start, end)] = 1 + min(bt(s,start+1, end),min(bt(s,start,end-1),bt(s,start+1,end-1)));

  return dp[pair<int,int>(start, end)];

}

int backtrack(string& s, int len_s, string& t, int len_t){

  int cost = 0; 

  if(dp.find(pair<int,int>(len_s, len_t)) != dp.end())
    return dp[pair<int,int>(len_s, len_t)];

  if(len_s == 0) 
    return len_t;
  if(len_t == 0)
    return len_s;

  if(s[len_s-1] == t[len_t-1])
    cost = 0;
  else
    cost = 1;

  dp[pair<int,int>(len_s, len_t)] = min(min(backtrack(s, len_s - 1, t, len_t) + cost, backtrack(s, len_s, t, len_t -1) + cost), backtrack(s, len_s - 1, t, len_t -1) + cost);

  return dp[pair<int,int>(len_s, len_t)];
}

int main(){

  int T, cases = 1;
  cin>>T;
  
  while(T--){

    string input;
    cin>>input;
    dp.clear();
    
    string s = input.substr(0, input.size()/2), t = input.substr((input.size()/2)+1, input.size()/2);
    //int res1 = backtrack(s, s.size(), t, t.size());
    int res1 = bt(input, 0, input.size()-1);

    cout<<"Case "<<cases++<<": "<<res1<<endl;
    
  }

  return 0;
}
