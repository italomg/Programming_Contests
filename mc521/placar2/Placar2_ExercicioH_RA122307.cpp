#include<iostream>
#include<map>
#include<string>
#include<cmath>
#include<iomanip>
#include<stdio.h>

using namespace std;

struct carro{
  
  int preco, km, mes;
  float conta;
  string state;

};

int main(){

  int precos[24], testes, preco, km;
  map<string, struct carro> carros;
  string plate, toparse, state;
  cin>>testes;

  while(testes--){

    for(int i = 0; i < 24; i++)
      cin>>precos[i];
    while(cin>>plate>>toparse>>state>>km){
      preco = precos[stoi(toparse.substr(6,2))];
      struct carro temp;
      temp.mes = stoi(toparse.substr(0,2));
      temp.state = state;
      if(state == "enter")
	temp.preco = preco;
      else
	temp.preco = 0;
      temp.km = km;
      temp.conta = -1.0;
      if(carros.find(plate) == carros.end())
	carros[plate] = temp;
      else{
	if((carros[plate].state != temp.state) && (temp.mes == carros[plate].mes)){
	  if(temp.preco == 0)
	    carros[plate].conta = ((0.01 * carros[plate].preco) * abs(temp.km - carros[plate].km)) + 3;
	  else
	    carros[plate].conta = ((0.01 * temp.preco) * abs(temp.km - carros[plate].km)) + 3;
	}
      }
    }
    for(map<string, struct carro>::iterator it = carros.begin(); it != carros.end(); it++)
      if(it->second.conta != -1)
	printf("%s $%.02f\n", it->first.c_str(), it->second.conta);
    if(testes)
      cout<<endl;
    carros.clear();
  }
  return 0;
}
