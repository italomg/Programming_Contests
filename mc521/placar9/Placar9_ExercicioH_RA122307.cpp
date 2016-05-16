#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
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
  
  int tests;
  long int sum, corr;
  int V, A, O, D, T;
  float P;

  scanf("%d", &tests);
  while(tests--){
    scanf("%d", &T);
    vector<pair<int, int> > points;
    vector<VAP> vap;
    vector<float> news;
    // memset(pai, 0, V*sizeof(int));
    // memset(rank, 0, V*sizeof(int));

    while(scanf("%d", &O) == 1 && O != -1){
      scanf("%d", &D);
      points.push_back(pair<int, int>(O, D));
    }
    V = points.size();
    vector<vector<pair<int, int> > > graph(V);
    // scanf("%d", &A);
    // for(int i = 0; i < A; i++){
    //   scanf("%d %d", &O, &D);
    //   P = 0;
    //   struct VAP temp;
    //   temp.origem = O-1;
    //   temp.destino = D-1;
    //   temp.peso = P;
    //   vap.push_back(temp);
    //   graph[O-1].push_back(pair<int, int>(D-1, P));
    //   graph[D-1].push_back(pair<int, int>(O-1, P));
    // }

    for(int i = 0; i < V; i++){
      for(int j = i+1; j < V; j++){
	P = sqrt(pow(points[i].first - points[j].first, 2.0) + pow(points[i].second - points[j].second, 2.0));
	struct VAP temp;
	temp.origem = i;
	temp.destino = j;
	temp.peso = P;
	vap.push_back(temp);
	graph[i].push_back(pair<int, int>(j, P));
	graph[j].push_back(pair<int, int>(i, P));
      }
    }

    for(int i = 0; i < V; i++)
       make_set(i);

    sort(vap.begin(), vap.end(), compare);

    corr = sum = 0;
    for(int i = 0; i < vap.size(); i++){
      if(find_set(vap[i].origem) != find_set(vap[i].destino)){
    	//sum += vap[i].peso;
	//corr++;
	//if(vap[i].peso)
	news.push_back(vap[i].peso);
    	union_set(vap[i].origem, vap[i].destino);
      }
    }
   
    vector<float>::reverse_iterator it = news.rbegin();
    for(int i = 1; i < T && it != news.rend(); i++)
      it++;

    if(it == news.rend())
      printf("0\n");
    else
      printf("%0.0lf\n", ceil(*it));
    // if(tests)
    //   puts("");
  }
	   
  return 0;
}
