#include <cstdio>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main(){

  int T, no = 1;

  scanf("%d", &T);
  
  while(T--){
    
    int E, R, bully, bullied;
    
    scanf("%d %d", &E, &R);
    vector<int> rank(E, 1), visitado(E), leaf(E, 1);
    vector<vector<int> > relations(E), pai(E);
    queue<int> Q;
    for(int i = 0; i < R; i++){
      scanf("%d %d", &bullied, &bully);
      relations[bully].push_back(bullied);
      pai[bullied].push_back(bully);
      rank[bullied] = 0;
      leaf[bully] = 0;
    }

    int cur;
    for(int i = 0; i < E; i++){
      if(rank[i] == 1){
	visitado.clear();
	Q.push(i);
	while(!Q.empty()){
	  cur = Q.front();
	  Q.pop();
	  vector<int>::iterator it;
	  for(it = relations[cur].begin(); it != relations[cur].end(); it++){
	    if(rank[*it] < rank[cur]+1)
	      rank[*it] = rank[cur]+1;
	    if(!visitado[*it]){
	      Q.push(*it);
	      visitado[cur] = 1;
	    }
	  }
	}
      }
    }

    for(int i = 0; i < E; i++){
      if(leaf[i]){
	visitado.clear();
	Q.push(i);
	while(!Q.empty()){
	  cur = Q.front();
	  Q.pop();
	  vector<int>::iterator it;
	  for(it = pai[cur].begin(); it != pai[cur].end(); it++){
	    if(rank[cur] < rank[*it]+1)
	      rank[cur] = rank[*it]+1;
	    if(!visitado[*it]){
	      Q.push(*it);
	      visitado[cur] = 1;
	    }
	  }
	}
      }
    }
    
    multimap<int,int> organizado;
    printf("Scenario #%d:\n", no);
    no++;
    for(int i = 0; i < E; i++)
      organizado.insert(pair<int,int>(rank[i], i));

    multimap<int,int>::iterator it1;
    for(it1 = organizado.begin(); it1 != organizado.end(); it1++)
      printf("%d %d\n", it1->first, it1->second); 
    
    if(T)
      puts("");
  }

  return 0;
}
