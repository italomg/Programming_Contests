#include <cstdio>
#include <map>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

map<string, int>::iterator mit (map<string, int>::iterator it){
  return ++it;
}

int main(){

  int ca;
  map<string, int> loves;
  string input;
  char country[80] = {0};
  
  scanf("%d", &ca);

  for(int i = 0; i < ca; i++){
    scanf("%s%*[^\n]", country);
    input.assign(country);
    loves[input]++;
    memset(country, 0, 80);
  }

  map<string, int>::iterator it;

  for(it = loves.begin(); it != loves.end(); it++){
    cout<<it->first<<" "<<it->second<<endl;
    //if(mit(it) != loves.end())
    //cout<<endl;
  }
  
  
  return 0;
}
