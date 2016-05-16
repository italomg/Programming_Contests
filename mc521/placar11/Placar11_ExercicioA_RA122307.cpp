#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<queue>
#include<map>
#include<unordered_map>
#include<list>

using namespace std;


list<string>::iterator itm(list<string>::iterator it){
  return ++it;
}

int main(){

  int C, flag, inic = 1;
  string O, D, cur;

  unordered_map<string, vector<string> > graph;
  unordered_map<string, string> pai;
  unordered_map<string, int> visited;
  while(cin>>C){

    if(!inic)
      cout<<endl;

    pai.clear();
    visited.clear();
    unordered_map<string, vector<string> >::iterator it;
    for(it = graph.begin(); it != graph.end(); it++)
      it->second.clear();
    graph.clear();
    
    for(int i = 0; i < C; i++){
      //scanf("%s %s", &O, &D);
      cin>>O>>D;
      graph[O].push_back(D);
      graph[D].push_back(O);
      pai[O] = string("N");
      pai[D] = string("N");
      visited[O] = 0;
      visited[D] = 0;
      
    }
    
    cin>>O>>D;
    pai[O] = string("N");
    pai[D] = string("N");
    //scanf("%s %s", &O, &D);

    queue<string> Q;
    list<string> caminho;
    Q.push(O);
    //bfs(graph, caminho, Q);
    //pai[O] = O;
    while(!Q.empty()){
	cur = Q.front();
	visited[cur] = 1;
	vector<string>::iterator it;
	for(it = graph[cur].begin(); it != graph[cur].end(); it++){
	  if(!visited[*it]){
	    pai[*it] = cur;
	    Q.push(*it);
	  }
	}
	Q.pop();
    }


    cur = D;
    if(pai[D] != string("N") && C != 0){
      
      while(cur != O){
	caminho.push_front(cur);
	cur = pai[cur];
      }
      caminho.push_front(O);


      list<string>::iterator it = caminho.begin();
      cout<<*it<<" ";
      it++;
      flag = 1;
      for(; it != caminho.end(); it++){
	if(flag){
	  cout<<*it<<endl;
	  flag = 0;
	}
	if(!flag && itm(it) != caminho.end()){
	  cout<<*it<<" ";
	  flag = 1;
	}
      }
    }
    else{
      cout<<"No route"<<endl;
    }    
    inic = 0;
  }

  return 0;
}
