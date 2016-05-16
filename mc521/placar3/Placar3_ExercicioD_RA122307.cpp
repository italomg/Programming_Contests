#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main(){


  int sleptAreas, numbConnection, sum, flag, years, stop, wokenCont;
  char origem, destino;

  //gets(go);
  while(cin>>sleptAreas>>numbConnection){
    // scanf("%d", &sleptAreas);
    // sleptAreas = atoi(go);
    // scanf("%d", &numbConnection);
    //getchar();
    int awaken[26] = {0}, connection[26][26] = {{0}}, connections[26] = {0};
    for(int i = 0; i < 3; i++){
      cin>>origem;
      awaken[origem%'A'] = 1;
    }

    getchar();
    for(int i = 0; i < numbConnection; i++){
      cin>>origem>>destino;
      // origem = getchar();
      // destino = getchar();
      // getchar();
      connection[origem%'A'][destino%'A'] = 1;
      connection[destino%'A'][origem%'A'] = 1;
    }

    sum = 0;
    flag = 0;
    wokenCont = 0;
    stop = 0;
    for(int i = 0; i < 26; i++){
      for(int j = 0; j < 26; j++){
	if(awaken[j] && connection[i][j])
	  sum += connection[i][j];
      }
      connections[i] = sum;
      if(sum >= 3)
	flag = 1;
      if(awaken[i])
	wokenCont++;
      sum = 0;
    }
    if(wokenCont == sleptAreas){
      cout<<"WAKE UP IN, 0, YEARS"<<endl;
      stop = 1;
    }
    else if(!flag){
      cout<<"THIS BRAIN NEVER WAKES UP"<<endl;
      stop = 1;
    }
    years = 0;
    while(!stop){
      for(int i = 0; i < 26; i++){
	if(connections[i] >= 3 && !awaken[i])
	  awaken[i] = 1;
      }
      sum = 0;
      flag = 0;
      wokenCont = 0;
      for(int i = 0; i < 26; i++){
	if(connections[i] < 3){
	  for(int j = 0; j < 26; j++){
	    if(awaken[j] && connection[i][j])
	      sum += connection[i][j];
	  }
	  connections[i] = sum;
	  if(sum >= 3)
	    flag = 1;
	  sum = 0;
	}
	if(awaken[i])
	  wokenCont++;
      }
      years++;
      if(wokenCont == sleptAreas){
	cout<<"WAKE UP IN, "<<years<<", YEARS"<<endl;
	break;
      }
      else if(!flag){
	cout<<"THIS BRAIN NEVER WAKES UP"<<endl;
	break;
      }
      
    }
    //gets(go);
  }
  
  return 0;
}
