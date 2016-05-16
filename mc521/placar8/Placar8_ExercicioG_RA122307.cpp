#include<cstdio>
#include<vector>
#include<cstring>
#include<list>

using namespace std;

list<int> resp;

int dfs(vector<vector<int> > &graph, int *cor, int node){

  int res = 0;
  if(cor[node])
    return 0;
  vector<int>::iterator it;
  cor[node] = 1;
  for(it = graph[node].begin(); it != graph[node].end(); it++){
    if(!cor[*it]){
      res = dfs(graph, cor, *it);
      if(res == -1)
	return res;
    }
    else if(cor[*it] == 1)
      return -1;
  }
  resp.push_front(node);
  cor[node] = 2;
  return 0;
}

int main(){

  int V, A, O, D, res;
  scanf("%d %d", &V, &A);
  while(V != 0 || A != 0){
    vector<vector<int> > graph(V);
    int cor[V];
    memset(cor, 0, V*sizeof(int));

    for(int i = 0; i < A; i++){
      scanf("%d %d", &O, &D);
      graph[O-1].push_back(D-1);
    }
    resp.clear();
    res = 0;
    for(int i = 0; i < V; i++){
      if(!cor[i]){
	//resp.push_back(i);
	res = dfs(graph, cor, i);
      }
      if(res == -1)
	break;
    }
    if(!res){
      for(list<int>::iterator it = resp.begin(); it != resp.end(); it++)
	printf("%d\n", (*it)+1);
    }
    else
      printf("IMPOSSIBLE\n");
    scanf("%d %d", &V, &A);
  }

  return 0;
}
