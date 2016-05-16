#include<cstdio>
#include<string>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;


void imprime(vector<string> names, int max, int count, string past, int start){
  
 
  if(count >= max)
    return;
  for(int i = start; i <= names.size()-(max-count); i++){
    string newpast(past);
    if(past.empty()){
 
      if(count == max-1)
	printf("%s\n", names[i].c_str());
      else
	newpast += names[i];
    }
    else if(count == max-1){
      printf("%s, %s\n", past.c_str(), names[i].c_str());
    }
    else{
      newpast += ", ";
      newpast += names[i];
    }
    imprime(names, max, count+1, newpast, i+1);
  }
}

int main(){

  int tests;
  scanf("%d", &tests);
  getchar();
  getchar();
  while(tests--){
    
    char i1, i2;
    i1 = getchar();
    if(i1 != '*'){
      i2 = getchar();
      if(i2 != '\n'){
	i2 = getchar();
	getchar();
      }
    }
    else
      getchar();
    
    string namest, past;
    char name[35], oldname[35];
    vector<string> names;
    
    fgets(name, 35, stdin);

    while(isalpha(*name)){
      if(name[strlen(name)-1] == '\n')
	name[strlen(name)-1] = 0;
      if(!strcmp(oldname,name))
	break;
      namest.assign(name);
      names.push_back(name);
      strcpy(oldname,name);
      fgets(name, 35, stdin);
    }

    if(i1 == '*')
      for(int i = 1; i <= names.size(); i++){
        printf("Size %d\n", i);
	imprime(names, i, 0, past, 0);
	puts("");
      }
    else if(i2 == '\n'){
      printf("Size %d\n", i1%'0');
      imprime(names, i1%'0', 0, past, 0);
    }
    else
      for(int i = i1%'0'; i <= i2%'0'; i++){
        printf("Size %d\n", i);
	imprime(names, i, 0 , past, 0);
	puts("");
      }
    if(tests)
      puts("");
  }

  return 0;
}
