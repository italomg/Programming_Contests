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
  
  int V, A, O, D, P, mini, K, M, flag = 1;
  long int sum = 0, inic;


  while(scanf("%d", &V) != EOF){
    if(!flag)
      puts("");
    A = V-1;
    vector<vector<pair<int, int> > > agm(V);
    vector<VAP> vap;

    inic = 0;
    for(int i = 0; i < A; i++){
      scanf("%d %d %d", &O, &D, &P);
      inic += P;
    }
    scanf("%d", &K);
    for(int i = 0; i < K; i++){
      scanf("%d %d %d", &O, &D, &P);
      struct VAP temp;
      temp.origem = O;
      temp.destino = D;
      temp.peso = P;
      vap.push_back(temp);
      agm[O-1].push_back(pair<int, int>(D-1, P));
      agm[D-1].push_back(pair<int, int>(O-1, P));
    }
    scanf("%d", &M);
    for(int i = 0; i < M; i++){
      scanf("%d %d %d", &O, &D, &P);
      struct VAP temp;
      temp.origem = O;
      temp.destino = D;
      temp.peso = P;
      vap.push_back(temp);
      agm[O-1].push_back(pair<int, int>(D-1, P));
      agm[D-1].push_back(pair<int, int>(O-1, P));
    }


    for(int i = 0; i < (V+K); i++)
      make_set(i);

    sort(vap.begin(), vap.end(), compare);
    sum = 0;
    for(int i = 0; i < vap.size(); i++){
      if(find_set(vap[i].origem) != find_set(vap[i].destino)){
	sum += vap[i].peso;
	union_set(vap[i].origem, vap[i].destino);
      }
    }
    flag = 0;
    printf("%d\n%d\n", inic, sum);
  }
  return 0;
}
