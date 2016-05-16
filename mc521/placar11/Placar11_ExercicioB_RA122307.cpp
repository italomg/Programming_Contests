#include<cstdio>
#include<map>
#include<string>
#include<cstring>
#include<set>
#include<iostream>
#include<vector>

using namespace std;


int main(){

  //char input[25150][20];
  char input[20];
  int cur = 0, flag;
  string temp;
  set<string> dict;


  memset(input, 0, 20*sizeof(char));
  fgets(input, 20, stdin);

  while(*input != '\n'){

    if(input[strlen(input)-1] = '\n')
      input[strlen(input)-1] = '\0';
    temp.assign(input);
    dict.insert(temp);

    memset(input, 0, 20*sizeof(char));
    fgets(input, 20, stdin);
  }

  string word1, word2;
  vector<string> resp;
  int i, inic = 1, existe;
  while(cin>>word1>>word2){

    flag = 1;
    if(!inic)
      cout<<endl;

    resp.clear();
    if(word1.size() == word2.size()){
      temp = word1;
      resp.push_back(temp);
      for(i = 0; i < word1.size(); i++){
	existe = 0;
	if(temp[i] != word2[i]){
	  temp[i] = word2[i];
	  if(dict.find(temp) != dict.end())
	    resp.push_back(temp);
	  else
	    break;
	}
      }
      if(i == word1.size()){
	flag = 0;
	for(int j = 0; j < resp.size(); j++)
	  cout<<resp[j]<<endl;
      }
    }
    if(flag){
      cout<<"No solution."<<endl;
    }
    inic = 0;
  }

  return 0;
}
