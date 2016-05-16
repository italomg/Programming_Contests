#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int pai[1000005], rank[1000005];

struct VAP{
  int origem, destino, peso;
};

void make_set(int node){
  pai[node] = node;
  rank[node] = 0;
}

int find_set(int node){
  if(node != pai[node])
    pai[node] = find_set(pai[node]);
  return pai[node];
}

void link(int node1, int node2){
  if(rank[node1] > rank[node2])
    pai[node2] = node1;
  else{
    pai[node1] = node2;
    if(rank[node1] == rank[node2])
      rank[node2] += 1;
  }
}

void union_set(int node1, int node2){
  link(find_set(node1), find_set(node2));
}

bool compare(struct VAP vap1, struct VAP vap2){
  return vap1.peso < vap2.peso;
}

int main(){
  
  int V, A, O, D, P, mini;
  int sum = 0, maxi;


  scanf("%d %d", &V, &A);
  while(V != 0 || A != 0){
  vector<vector<pair<int, int> > > graph(V);
  vector<VAP> vap(A);
  int Az = A;
  memset(pai, 0, V*sizeof(int));
  memset(rank, 0, V*sizeof(int));
  for(int i = 0; i < A; i++){
    scanf("%d %d %d", &O, &D, &P);
    vap[i].origem = O;
    vap[i].destino = D;
    vap[i].peso = P;
    graph[O].push_back(pair<int, int>(D, P));
    graph[D].push_back(pair<int, int>(O, P));
  }
  
  for(int i = 0; i < V; i++)
    make_set(i);
  
  sort(vap.begin(), vap.end(), compare);
  maxi = 0;
  for(int i = 0; i < A; i++){
    if(find_set(vap[i].origem) != find_set(vap[i].destino)){
      //sum += vap[i].peso;
      union_set(vap[i].origem, vap[i].destino);
      Az--;
      maxi = max(maxi, vap[i].peso);
    }
  }
  int cur = pai[0], impossible = 0;
  if(V > 1){
    for(int i = 1; i < V; i++){
      if(cur !=  pai[i]){
	impossible = 1;
	break;
      }
    }
  }
  if(impossible)
    printf("IMPOSSIBLE\n");
  else
    printf("%d\n", maxi);
  scanf("%d %d", &V, &A);
  }
  return 0;
}
