/* USER: 154349 (Italo.M) */
/* PROBLEM: 975 (10034 - Freckles) */
/* SUBMISSION: 15452477 */
/* SUBMISSION TIME: 2015-05-08 20:08:07 */
/* LANGUAGE: 3 */

#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

int pai[1000005], rank[1000005];

struct VAP{
  int origem, destino;
  float peso;
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
  
  int V, tests;
  int cur;
  
  scanf("%d", &tests);
  scanf("%d", &V);
  while(tests--){
    vector<vector<pair<int,float> > > graph(V);
    vector<pair<float,float> > points;
    vector<VAP> vap(V*(V-1));
    float O, D, sum, P;
    memset(pai, 0, V*sizeof(int));
    memset(rank, 0, V*sizeof(int));

    for(int i = 0; i < V; i++){
      scanf("%f %f", &O, &D);
      points.push_back(pair<float, float>(O,D));
    }

    for(int i = 0; i < vap.size(); i++)
      vap[i].peso = -1;


    cur = 0;
    for(int i = 0; i < V; i++){
      for(int j = 0; j < V; j++){
	if(i != j){
	  P = sqrt((pow(abs(points[i].first - points[j].first), 2.0) + pow(abs(points[i].second - points[j].second),2.0)));
	  graph[i].push_back(pair<int, float>(j, P));
	  //graph[j].push_back(pair<int, double>(i, P));
	  
	  vap[cur].origem = i;
	  vap[cur].destino = j;
	  vap[cur].peso = P;
	  cur++;
	}
      }
    }
  
    for(int i = 0; i < cur; i++)
      make_set(i);
  
    sort(vap.begin(), vap.end(), compare);
    sum = 0;
    
    for(int i = 0; i < vap.size(); i++){
      if(find_set(vap[i].origem) != find_set(vap[i].destino)){
	sum += vap[i].peso;
	union_set(vap[i].origem, vap[i].destino);
      }
    }
    printf("%0.2lf\n", sum);
    if(tests){
      puts("");
      scanf("%d", &V);
    }
  }
  return 0;
}
