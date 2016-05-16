#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<string.h>

using namespace std;

int main(){
  
  int pessoa, arvore, casos, totalPeople, aux;
  char line[7], *input, *p, *a;

  cin>>casos;
  getchar();
  getchar();

  while(casos--){
    input = gets(line);
    totalPeople = atoi(strtok(line, " "));
    input = gets(line);
    map<int, set<int> > PtoA;
    map<set<int>, int> AtoP;
    
    while(input != NULL && strlen(input)){
      set<int> temp;
      p = strtok(line, " ");
      a = strtok(NULL, "\n ");
      pessoa = atoi(p);
      arvore = atoi(a);
      if(PtoA.find(pessoa) != PtoA.end())
	PtoA[pessoa].insert(arvore);
      else{
	temp.insert(arvore);
	PtoA[pessoa] = temp;
      }
      input = gets(line);
    }
    for(map<int, set<int> >::iterator it = PtoA.begin(); it != PtoA.end(); it++){
      AtoP[it->second] = 1;
    }
    aux = 0;
    if(PtoA.size()<totalPeople)
      aux = 1;
    if(casos)
      cout<<AtoP.size()+aux<<endl<<endl;
    else
      cout<<AtoP.size()+aux<<endl;
  }
  
  
  
  
  return 0;
}
