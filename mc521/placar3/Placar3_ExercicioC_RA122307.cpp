#include<iostream>
#include<utility>
#include<vector>

using namespace std;

int main(){

  int V, A, tests, flag, input;

  cin>>tests;

  while(tests--){

    cin>>V>>A;
    flag = 0;
    int arestas[60] = {0};
    int vertices[10] = {0};
    pair<int, int> arestasCoord[60];
    for(int j = 0; j < V; j++){

      for(int i = 0; i < A; i++){
	cin>>input;
	if(input){
	  arestas[i]++;
	  vertices[j]++;
	  if(get<0>(arestasCoord[i]) == 0)
	    get<0>(arestasCoord[i]) = j+1;
	  else
	    get<1>(arestasCoord[i]) = j+1;
	}
      }
      // if(vertices[j] > V-1)
      // 	flag = 1;
    }

    for(int i = 0; i < A; i++)
      if(arestas[i] != 2)
	flag = 1;

    if(!flag){
      for(int i = 0; i < A; i++)
	for(int j = i+1; j < A; j++)
	  if((get<1>(arestasCoord[i]) ==  get<1>(arestasCoord[j])) && (get<0>(arestasCoord[i]) ==  get<0>(arestasCoord[j]))){
	    flag = 1;
	    break;
	  }
    }
    
    // if(tests){
      if(!flag)
	cout<<"Yes"<<endl;
      else
	cout<<"No"<<endl;
    // }
    // else{
    //   if(!flag)
    // 	cout<<"Yes";
    //   else
    // 	cout<<"No";
    // }
  }

  return 0;
}
