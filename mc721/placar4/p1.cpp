#include <bits/stdc++.h>

using namespace std;

int main(){

  vector<int> corresp;
  for(int i = 0; i < 26; i++){
    if(i <= 2)
      corresp.push_back(2);
    else if(i <= 5)
      corresp.push_back(3);
    else if(i <= 8)
      corresp.push_back(4);
    else if(i <= 11)
      corresp.push_back(5);
    else if(i <= 14)
      corresp.push_back(6);
    else if(i <= 18)
      corresp.push_back(7);
    else if(i <= 21)
      corresp.push_back(8);
    else if(i <= 25)
      corresp.push_back(9);
  }
  
  string input;

  while(cin>>input){
    for(int i = 0; i < input.size(); i++){
      if(input[i] < 'A')
	cout<<input[i];
      else
	cout<<corresp[input[i] - 'A'];
    }
    cout<<endl;
  }

  return 0;
}
