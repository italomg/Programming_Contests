#include<iostream>
#include<deque>
#include<string>
#include<algorithm>
#include<map>
#include<list>

using namespace std;

int main(){

  long long int ferry, test, cap, cross, cars, arrivetime, count;
  long long int time, mini;
  string side;
  deque<map<long long int,long long int> >right, left;//as pilhas da esquerda e direita, com hash map que liga a hora de chegada a sua  posicao de chegada
  map<long long int, long long int> ord;//hash ligando o tempo de chegada "id" ao seu tempo de chegada ao outro lado
  cin>>test;

  while(test--){
    cin>>cap>>cross>>cars;
    time = 0;//tempo total decorrido
    ferry = 0; //LEFT eh 0 e RIGHT eh 1
    count = 1;//ordem de chegada
    map<long long int, long long int> entry;

    //Loop para popular o deque e o hash
    for(long long int i = 0; i < cars; i++){
      cin>>arrivetime>>side;
      if(side == "left"){
	entry[arrivetime] = count;
	left.push_back(entry);
	count++;
      }
      else{
	entry[arrivetime] = count;
	right.push_back(entry);
	count++;
      }
      entry.clear();
    }

    //aqui comeca de verdade
    count = 1;
    while(count <= cars){
      //verifica direita ou esquerda
	if(!ferry){
	  if(left.size()>0 && left.front().begin()->first <= time){
	    mini = min(cap, (long long int)left.size());
	    //Faz um loop para ver que vai no barco, e utiliza o campo que tem a order como indice do hash
	    for(long long int j = 0; j < mini; j++){
	      if(left.front().begin()->first <= time){
		ord[left.front().begin()->second] = time+cross;
		left.pop_front();
		count++;
	      }
	    }
	    time += cross;
	    ferry = (ferry+1)%2;
	  }
	  //verifica como esta o outro lado e se deve ir ou nao para la
	  else{
	    if(right.size() > 0){
	      if(right.front().begin()->first <= time){
		ferry = (ferry+1)%2;
		time += cross;
	      }
	      else if(left.size() == 0 || right.front().begin()->first < left.front().begin()->first){
		time = right.front().begin()->first + cross;
		ferry = (ferry+1)%2;
	      }
	      else
		time = left.front().begin()->first;
	    }
	    else if(left.size() > 0)
	      time = left.front().begin()->first;
	  }
	}
	//O procedimento eh basicamente o mesmo para o lado direito, se vc entendeu alguma coisa ate agora
	//daqui pra frente vai ser DE BOA ;)
	if(ferry){
	  if(right.size()>0 && right.front().begin()->first <= time){
	    mini = min(cap, (long long int)right.size());
	    for(long long int j = 0; j < mini; j++){
	      if(right.front().begin()->first <= time){
		ord[right.front().begin()->second] = time+cross;
		right.pop_front();
		count++;
	      }
	    }
	    time += cross;
	    ferry = (ferry+1)%2;
	  }
	  else{
	    if(left.size() > 0){
	      if(left.front().begin()->first <= time){
		ferry = (ferry+1)%2;
		time += cross;
	      }
	      else if(right.size() == 0 || left.front().begin()->first < right.front().begin()->first){
		time = left.front().begin()->first + cross;
		ferry = (ferry+1)%2;
	      }
	      else
		time = right.front().begin()->first;
	    }
	    else if(right.size() > 0)
	      time = right.front().begin()->first;
	  }
	  
	}
    }
    for(map<long long int, long long int>::iterator it = ord.begin(); it != ord.end(); it++)
      cout<<it->second<<endl;
    if(test != 0)
      cout<<endl;
    ord.clear();
  }
  return 0;
}
