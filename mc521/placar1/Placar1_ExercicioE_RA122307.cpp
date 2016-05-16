#include<iostream>
#include <unordered_map>

using namespace std;

int main(){

  unordered_map<long long int, long long int> votos;

  long long int total, candidato, max, eleito;

  cin>>total;
  max = 0;
  for(long long int i = 0; i < total; i++){
    cin>>candidato;
    if(votos.find(candidato) != votos.end()){
      votos[candidato]++;
      if(votos[candidato] > max){
	max = votos[candidato];
	eleito = candidato;
      }
    }
    else{
      votos[candidato] = 1;
      if(votos[candidato] > max){
	max = votos[candidato];
	eleito = candidato;
      }
    }
  }
  cout<<eleito<<endl;
  return 0;
}
