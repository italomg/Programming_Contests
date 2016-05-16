#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdlib>

using namespace std;

int current;
void dfs(vector<vector<int> > &graph, int *cor,int *low,int *num,int *art,int *pai, int node, vector<vector<int> > &newGraph){

  vector<int>::iterator it;
  low[node] = num[node] = current++;
  cor[node] = 1;
  int children = 0;
  for(it = graph[node].begin(); it != graph[node].end(); it++){
    if(!cor[*it]){
      pai[*it] = node;
      dfs(graph, cor, low, num, art, pai, *it, newGraph);



      if(num[node] < low[*it]){
	art[node] = 1;
	newGraph[node][*it] = 1;
	newGraph[*it][node] = 1;
      }
      else if(!newGraph[*it][node])
	newGraph[node][*it] = 1;
    
	    
      low[node] = min(low[node], low[*it]);
      children++;
    }
    else if(pai[node] != *it){
      if(!newGraph[*it][node])
	newGraph[node][*it] = 1;
      low[node] = min(low[node], num[*it]);
    }
  }
  if(node == 0)
    art[0] = children > 1;
}

int main(){

  int V, A, O, D, no, tem;
  scanf("%d %d", &V, &A);
  no = 0;
  while(V != 0 || A != 0){
    vector<vector<int> > graph(V), newGraph(V, vector<int>(V));
    int cor[V], low[V], num[V], art[V], pai[V], grau[V];
    memset(cor, 0, V*sizeof(int));
    memset(low, 0, V*sizeof(int));
    memset(num, 0, V*sizeof(int));
    memset(art, 0, V*sizeof(int));
    memset(pai, 0, V*sizeof(int));
    memset(grau, 0, V*sizeof(int));

    for(int i = 0; i < A; i++){
      scanf("%d %d", &O, &D);
      graph[O-1].push_back(D-1);
      graph[D-1].push_back(O-1);
      grau[O-1]++;
      grau[D-1]++;
    }

    current = 0;
    for(int i = 0; i < V; i++){
      if(!cor[i]){
	pai[i] = i;
	dfs(graph, cor, low, num, art, pai, i, newGraph);
      }
    }

	
    no++;
    printf("%d\n\n", no);
    for(int i = 0; i < V; i++){
      for(int j = 0; j < V; j++)
	if(newGraph[i][j])
	  printf("%d %d\n", i+1, j+1);
	  
    }
    printf("#\n");
	

    scanf("%d %d", &V, &A);
  }

  return 0;
}

