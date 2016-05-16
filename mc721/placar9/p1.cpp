#include<bits/stdc++.h>

using namespace std;

int main(){

  bool flag = 1;
  string line;

  while(getline(cin, line)){
    for(int i = 0; i < line.size(); i++){
      if(line[i] == '"' && flag){
	flag = false;
	cout<<"``";
      }
      else if(line[i] == '"' && !flag){
	flag = true;
	cout<<"''";
      }
      else{
	cout<<line[i];
      }
    }
    cout<<endl;
  }

  return 0;
}
