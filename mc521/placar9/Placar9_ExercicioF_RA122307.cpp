#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
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
  
  int tests;
  long int sum, sum1, corr, tot;
  int V, A, O, D, P;

  scanf("%d", &tests);
  while(tests--){
    scanf("%d %d", &V, &A);
    vector<vector<pair<int, int> > > graph(V);
    vector<VAP> vap(A);
    memset(pai, 0, V*sizeof(int));
    memset(rank, 0, V*sizeof(int));
    for(int i = 0; i < A; i++){
      scanf("%d %d %d", &O, &D, &P);
      vap[i].origem = O-1;
      vap[i].destino = D-1;
      vap[i].peso = P;
      graph[O-1].push_back(pair<int, int>(D-1, P));
      graph[D-1].push_back(pair<int, int>(O-1, P));
    }

    for(int i = 0; i < V; i++)
       make_set(i);

    sort(vap.begin(), vap.end(), compare);
    vector<int> done;
    corr = sum = 0;
    for(int i = 0; i < A; i++){
      if(find_set(vap[i].origem) != find_set(vap[i].destino)){
    	sum += vap[i].peso;
    	done.push_back(i);
    	union_set(vap[i].origem, vap[i].destino);
      }
    }
   
    multiset<int> possi;
    possi.insert(sum);
    vector<int>::iterator it;
    for(it = done.begin(); it != done.end(); it++){
      memset(pai, 0, V*sizeof(int));
      memset(rank, 0, V*sizeof(int));
      for(int i = 0; i < V; i++)
	make_set(i);
      //sum1 = 400000;
      corr = sum = 0;
      for(int i = 0; i < A; i++){
	if((find_set(vap[i].origem) != find_set(vap[i].destino)) && (i != *it)){
	  sum += vap[i].peso;
	  corr++;
	  union_set(vap[i].origem, vap[i].destino);
	}
      }
      if(corr == V-1)
	possi.insert(sum);
    }

    printf("%d %d\n", *possi.begin(), *(++possi.begin()));
    //if(tests)
    //scanf("%d %d", &V, &A);
    
  }
  return 0;
}
