#include <bits/stdc++.h>

using namespace std;


void dfs(vector<vector<int> >& graph, vector<int>& visited, int i){

  visited[i] = 1;

  vector<int>::iterator it;

  for(it = graph[i].begin(); it != graph[i].end(); it++){
    if(!visited[*it]){
      dfs(graph, visited, *it);
    }
  }
}

int main(){

  int V, E;
  while(cin>>V>>E){

    int s, d;
    vector<vector<int> > graph(V);
    vector<int> visited(V), out(V), in(V);
    for(int i = 0; i < E; i++){
      cin>>s>>d;
      graph[s].push_back(d);
      graph[d].push_back(s);
      out[s]++;
      in[d]++;
    }

    for(int i = 0; i < V; i++){
      if(out[i] + in[i] > 0){
	dfs(graph, visited, i);
	break;
      }
    }

    int connected = 1;    
    for(int i = 0; i < V; i++){
      if(!visited[i] && (out[i]+in[i] > 0)){
	connected = 0;
	break;
      }
    }
    
    bool has_odd = false;

    for(int i = 0; i < V; i++){
      if(((out[i] + in[i]) % 2 == 1)){
	has_odd = true;
	break;
      }
    }

    //cout<<has_odd<<connected<<E<<endl;
    if(!has_odd && connected && E > 0)
      cout<<"Possible"<<endl;
    else
      cout<<"Not Possible"<<endl;

  }  

  return 0;
}
