#include<iostream>
#include<list>
#include<unordered_map>
#include<cstring>
#include<deque>

using namespace std;

int main(){

  long int teamnbm, team, cont, no = 0, cur;
  long long int id;
  string cmd;
  unordered_map<int, deque<long long int> > queue;//liga posicao do time a sua queue
  unordered_map<int, int> base;
  for(int i = 0; i < 1010; i++)
    base[i] = -1;
  
  while(cin>>teamnbm){
    cont = 0;
    cur = 0;
    no++;
    if(!teamnbm)
      break;
    cout<<"Scenario #"<<no<<endl;
    unordered_map<int, int> teams(base);//liga time a sua posicao
    unordered_map<long long int, int> teampart;//liga jogador ao seu time
    while(teamnbm--){
      cin>>team;
      while(team--){
	cin>>id;
	teampart[id] = teamnbm;
      }
    }
    while(cin>>cmd){
      if(cmd == "STOP"){
	cout<<endl;
	break;
      }
      else if(cmd == "ENQUEUE"){
	cin>>id;
	if(teams[teampart[id]] < 0){
	  teams[teampart[id]] = cont;
	  cont++;
	}
	queue[teams[teampart[id]]].push_back(id);
      }
      else if(cmd == "DEQUEUE"){
	if(queue[cur].size() > 0){
	  id = queue[cur].front();
	  cout<<id<<endl;
	  queue[cur].pop_front();
	}
	if(queue[cur].size() == 0){
	  queue[cur].clear();
	  teams[teampart[id]] = -1;
	  cur++;
	}
      }
    }
    for(unordered_map<int, deque<long long int> >::iterator it = queue.begin(); it != queue.end(); it++)
      it->second.clear();
  }
  

  return 0;
}
