#include<cstdio>
#include<vector>
#include<cstring>
#include<list>

using namespace std;

vector<int> dist(50005);

int dfs(vector<int> &graph, int *cor, int node){

  int res = 1;
  if(cor[node] == 1)
    return 0;
  
  // if(cor[node] == 2){
  //   return dist[node];
  // }
 
  cor[node] = 1;
  res += dfs(graph, cor, graph[node]);
  if(dist[node] < res)
    dist[node] = res;
  cor[node] = 2;
  return res;
}

int main(){

  int V, O, D, test, mini, maxi;
  scanf("%d", &test);
  for(int k = 1; k <= test; k++){
    scanf("%d", &V);
      vector<int> graph(V);
      dist.assign(50005, 0);
      int cor[V];
      memset(cor, 0, V*sizeof(int));

      for(int i = 0; i < V; i++){
	scanf("%d %d", &O, &D);
	graph[O-1] = D-1;
      }

      for(int i = 0; i < V; i++){
	//memset(cor, 0, V*sizeof(int));
	if(!cor[i]){
	  dfs(graph, cor, i);
	}
      }
      maxi = -1;
      for(int i = 0; i < V; i++){
	if(dist[i] > maxi){
	  maxi = dist[i];
	  mini = i;
	}
      }
      printf("Case %d: %d", k, mini+1);
      //if(k < test)
      puts("");
      //scanf("%d %d", &V, &A);
  }

  return 0;
}
