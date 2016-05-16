#include<iostream>
#include<string>
#include<cstring>
#include<stdlib.h>
#include<cmath>
#include<vector>

using namespace std;

int main(){

  string line;
  char *cline, *tkline;
  int old, cur, diff, flag = 0, n;
  
  while(getline(cin, line)){
    cline = (char *) line.c_str();
    
    tkline = strtok(cline, " ");
    n = atoi(tkline);
    
    tkline = strtok(NULL, " ");
    old = atoi(tkline);
    flag = 0;
    vector<int> binary(n,0);

    for(int i = 0; i < n-1; i++){

      tkline = strtok(NULL, " ");
      cur = atoi(tkline);
      diff = abs(cur - old);
     
      if(diff == 0 || diff >= n || binary[diff] == 1){
	cout<<"Not jolly"<<endl;
	flag = 1;
	break;
      }
      binary[diff] = 1;
      old = cur;
    }

    if(!flag)
      cout<<"Jolly"<<endl;
  }

  return 0;

}
