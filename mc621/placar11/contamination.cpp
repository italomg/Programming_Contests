#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int N, M;

void bfs(vector<string> &mapa, vector<vector<int> > &visitado, int i, int j){

  if(visitado[i][j] || mapa[i][j] == 'X')
    return;
  
  visitado[i][j] = 1;
  mapa[i][j] = 'T';

  if(i-1 >= 0 && !visitado[i-1][j])
    bfs(mapa, visitado, i-1, j);
  if(i+1 < N && !visitado[i+1][j])
    bfs(mapa, visitado, i+1, j);
  if(j-1 >= 0 && !visitado[i][j-1])
    bfs(mapa, visitado, i, j-1);
  if(j+1 < M && !visitado[i][j+1])
    bfs(mapa, visitado, i, j+1);

  return;
}

int main(){

  while(scanf("%d %d", &N, &M) != EOF && (N != 0 || M != 0)){

    vector<string> mapa(N);
    vector<vector<int> > visitado(N, vector<int>(M));

    for(int i = 0; i < N; i++){
      cin>>mapa[i];
    }
  
    for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
	if(!visitado[i][j] && mapa[i][j] == 'T')
	  bfs(mapa, visitado, i, j);
      }
    }

    for(int i = 0; i < N; i++)
      cout<<mapa[i]<<endl;
    cout<<endl;
  }

  return 0;
}
