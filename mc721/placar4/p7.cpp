#include<bits/stdc++.h>

using namespace std;

bool is_palindrome(const string& str, int start, int end){

  for(int i = start; i < end; i++)
    if(str[i] != str[end-i+(start-1)])
      return false;
  return true;
}

int main(){

  int n;
  cin>>n;
  while(n--){

    string input;
    int type = 0;
    cin>>input;
    for(int i = 0; i <= input.size(); i++){
      
      if(is_palindrome(input, 0, i) && is_palindrome(input, i, input.size())){
	if(i == 0 || i == input.size())
	  type = 1;
	else
	  type = 2;
      }
      if(type == 2){
	break;
      }
    }

    if(type == 1)
      cout<<"palindrome"<<endl;
    else if(type == 2)
      cout<<"alindrome"<<endl;
    else
      cout<<"simple"<<endl;

  }
  return 0;
}
