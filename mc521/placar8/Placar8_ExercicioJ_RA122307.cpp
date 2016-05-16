#include<cstdio>
#include<set>
#include<string>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

int main(){

  int words;
  char word[900] = {0}, *each;
  string sword, base;
  scanf("%d", &words);
  getchar();
  map<string, vector<string> > graph;
  while(words--){
    word[899] = 0;
    fgets(word, 900, stdin);
    each = strtok(word, " ");
    if(each[strlen(each)-1] != '\n'){
      base.assign(each);
      graph[base] = vector<string>();
    }
    while(1){
      each = strtok(NULL, " ");
      if(each[strlen(each)-1] == '\n'){
	each[strlen(each)-1] = 0;
	sword.assign(each);
	graph[base].push_back(sword);
	break;
      }
      else{
	each[strlen(each)-1] = 0;
	sword.assign(each);
	graph[base].push_back(sword);
      }
    }

  }
  scanf("%d", &words);
 
  return 0;
}
