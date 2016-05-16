#include<iostream>
#include<vector>
#include<cmath>
#include<queue>

using namespace std;

int main(){
  
  int casos, members, parente;
  long long int sum;
  cin>>casos;
  while(casos--){
    vector<int> input;
    priority_queue<int, vector<int>, greater<int> > sumset;
    cin>>members;

    while(members--){
      cin>>parente;
      input.push_back(parente);
    }
    for(vector<int>::iterator  it = input.begin(); it != input.end(); it++){
      sum = 0;
      for(vector<int>::iterator  it1 = input.begin(); it1 != input.end(); it1++){
	sum += abs((*it)-(*it1));
      }
      sumset.push(sum);
    }
    //if(casos)
    cout<<sumset.top()<<endl;
    // else
    //   cout<<sumset.top();
  }

  return 0;
}
