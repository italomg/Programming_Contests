#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


int main(){

  //vector<long long int> pos;
  unordered_map<long long int, vector<long long int> > numb;

  unsigned long long int n, m, input, i, ind;
  
  while(cin>>n>>m){
    for(i = 0; i < n; i++){
      cin>>input;
      numb[input].push_back(i);
    }
  
    for(i = 0; i < m; i++){
      cin>>ind>>input;
      if(ind > numb[input].size())
	cout<<0<<endl;
      else
	cout<<(numb[input][ind-1])+1<<endl;
    }
  }
  return 0;
}
