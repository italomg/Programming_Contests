#include<iostream>
#include<queue>
#include<list>
#include<map>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

long long int pai[1000000];

long long int achaPai(long long int p){
  if(pai[p] == p)
    return p;
  else
    return pai[p] = achaPai(pai[p]);
}

int main(){

  long long int netSize, origem, destino, correct = 0, wrong = 0, u, flag, testes, first;
  map<long long int, list<long long int> > graph;
  deque<long long int> queue;
  long long int dist[100000];
  char cmd;
  long long int p, q;
  scanf("%lld", &testes);
  first = 1;
  while(testes--){
    scanf("%lld", &netSize); 
    getchar();
    correct = 0;
    wrong = 0;
    for(long long int i = 0; i < 1000000; i++)
      pai[i] = i;
    //graph.clear();
    //cmd = "";
    while((cmd = getchar()) && isalpha(cmd)){
      scanf("%lld %lld", &origem, &destino);
      getchar();


      int p = achaPai(origem);
      int q = achaPai(destino);
 
      if(cmd == 'c'){
	pai[p] = q;
      } 
      else{
	if (p == q) correct++;
	else wrong++;
      }

      // if(cmd == 'c'){
      // 	graph[origem].push_back(destino);
      // 	graph[destino].push_back(origem);
      // }
      // else{
      // 	for(long long int i = 0; i < netSize; i++){
      // 	  dist[i] = netSize;
      // 	  cor[i] = 0;
      // 	  if(!queue.empty())
      // 	    queue.pop_front();
      // 	}
      // 	dist[origem-1] = 0;
      // 	cor[origem-1] = 1;
	

      // 	flag = 0;
      // 	queue.push_back(origem);
      // 	while(!queue.empty()){

      // 	  u = queue.front();
      // 	  queue.pop_front();
      // 	  for(list<long long int>::iterator it = graph[u].begin(); it != graph[u].end(); it++){
      // 	    if(cor[(*it)-1] == 0){
      // 	      cor[(*it)-1] = 1;
      // 	      dist[(*it)-1] = dist[u-1] + 1;
      // 	      if(*it == destino){
      // 		flag = 1;
      // 		correct++;
      // 		break;
      // 	      }
      // 	      queue.push_back(*it);
      // 	    }
      // 	  }
      // 	  cor[u-1] = 2;
      // 	}
      // 	if(!flag)
      // 	  wrong++;
      // }
    }
    if(testes)
      cout<<correct<<","<<wrong<<endl<<endl;
    else      
      cout<<correct<<","<<wrong<<endl;
  }

  return 0;
}
