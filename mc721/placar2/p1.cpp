#include<bits/stdc++.h>

using namespace std;

int dfs(vector<vector<int> > &graph, int node, vector<int> &visited){
  
  visited[node] = 1;

  vector<int>::iterator it;
  for(it = graph[node].begin(); it != graph[node].end(); it++){
    int res = 0;
    if(visited[*it] == 0){
      res = dfs(graph, *it, visited);
    }
    else if(visited[*it] == 1)
      return 1;
    
    if(res)
      return 1;
  }
  visited[node] = 2;
  return 0;
}

int main(){

  int T, Docs, Depends, A, B;

  cin>>T;

  while(T--){
    cin>>Docs>>Depends;

    vector<vector<int> > graph(Docs);
    vector<int> visited(Docs);
    for(int i = 0; i < Depends; i++){
      cin>>A>>B;
      graph[A-1].push_back(B-1);
    }

    int tem_loop = 0;
    for(int i = 0; i < Docs; i++){
      if(!visited[i])
	tem_loop = dfs(graph, i, visited);
      if(tem_loop)
	break;
    }

    if(tem_loop)
      cout<<"SIM"<<endl;
    else
      cout<<"NAO"<<endl;
    
    
  }

  return 0;
}
