#include <bits/stdc++.h>

using namespace std;

void dijkstra(int dist[100005], vector<vector<int> > graph, priority_queue<pair<int,int>, vector<pair<int, int> >, greater<pair<int, int> > >& Q){

  while(!Q.empty()){
    int cur = Q.top().second;
    Q.pop();

    vector<int>::iterator it;
    for(it = graph[cur].begin(); it != graph[cur].end(); it++){
      int cur_dist = dist[cur] + 1;
      if(cur_dist < dist[*it]){
	dist[*it] = cur_dist;
	Q.push({cur_dist, *it});
      }
    }
  }

}

int main(){

  int T;
  cin>>T;

  while(T--){
    int camarades;
    cin>>camarades;

    vector<vector<int> > graph(camarades);
    int high = 0;
    int dist[100005] = {0};

    int neigbr_nmbr, cur_camarade;
    priority_queue<pair<int,int>, vector<pair<int, int> >, greater<pair<int, int> > > Q;

    for(int i = 0; i < camarades; i++){
      cin>>cur_camarade;
      cin>>neigbr_nmbr;
      int neigbr;
      Q.push({0x3f3f3f3f, cur_camarade});
      for(int j = 0; j < neigbr_nmbr; j++){
	cin>>neigbr;
	graph[cur_camarade].push_back(neigbr);
	graph[neigbr].push_back(cur_camarade);
      }
    }

    int s, e;
    cin>>s>>e;

    for(int i = 0; i < camarades; i++){
      dist[i] = 0x3f3f3f3f;
    }

    dist[s] = 0;
    Q.push({0, s});

    dijkstra(dist, graph, Q);

    cout<<s<<" "<<e<<" "<<dist[e]-1<<endl;
    if(T)
      puts("");
    
  }

  return 0;
}
