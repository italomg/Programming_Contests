#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main(){

  vector<int> op1, op2;
  string input;

  cin>>input;

  int Af = 0, Bf = 0;
  for(int i = 1; i < input.size(); i++){
    if(input[i-1] == 'A' && input[i] == 'B'){
      op1.push_back(i-1);
      //found.insert(pair<int, pair<int, int> >(1, pair<int, int>(i-1,i)));
    }
    else if(input[i-1] == 'B' && input[i] == 'A'){
      //found.insert(pair<int, pair<int, int> >(2, pair<int, int>(i-1,i)));
      op2.push_back(i-1);
    }
  }
  
  if(op2.size() && op1.size() && (abs(op1[0] - op2[op2.size()-1]) >= 2 || abs(op1[op1.size()-1] - op2[0]) >= 2))
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
  

  return 0;
}
