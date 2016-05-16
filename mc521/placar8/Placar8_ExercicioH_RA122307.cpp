#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;


int dfsC(vector<vector<int> > graph, int *cor, int curCor, int node){

  if(cor[node] >= 0)
    return 0;
  if(!graph[node].size()){
    cor[node] = 3;
    return 0;
  }
  int otherCor = 1-curCor, res;

  vector<int>::iterator it;
  for(it = graph[node].begin(); it != graph[node].end(); it++){
    if(cor[*it] == curCor || node == *it){
      return -1;
    }
  }
  cor[node] = curCor;
  res = 0;
  for(it = graph[node].begin(); it != graph[node].end(); it++){
    if(cor[*it] == -1)
      res = dfsC(graph, cor, otherCor, *it);
    if(res == -1)
      return -1;
  }
  return 0;
}

int main(){

  int test, ppl, enemies, enemy, res, cor1, cor2, maxi;

  scanf("%d", &test);

  while(test--){

    scanf("%d", &ppl);
    vector<vector<int> > graph(ppl);
    int cor[ppl], backup[ppl];

    memset(cor, -1, ppl*sizeof(int));
    for(int i = 0; i < ppl; i++){
      scanf("%d", &enemies);
      for(int j = 0; j < enemies; j++){
	scanf("%d", &enemy);
	if(enemy-1 < ppl){
	  graph[i].push_back(enemy-1);
	  graph[enemy-1].push_back(i);
	}
      }
    }
    res = 0;
    maxi = 0;
    memcpy(backup, cor, ppl*sizeof(int));
    for(int i = 0; i < ppl; i++){
      if(cor[i] == -1)
	res = dfsC(graph, cor, 0, i);
      if(res == -1){
	memcpy(cor, backup, ppl*sizeof(int));
	res = dfsC(graph, cor, 1, i);
      }
      // if(res == -1)
      // 	break;
      if(res == 0){
	cor1 = 0;
	cor2 = 0;
	for(int i = 0; i < ppl; i++){
	  if(cor[i] == 0 || cor[i] == 3){
	    cor1++;
	    if(!cor[i])
	      cor[i] = -2;
	  }
	  if(cor[i] == 1 || cor[i] == 3){
	    cor2++;
	    cor[i] = -2;
	  }
	}
	maxi += max(cor1, cor2);
      }
      if(res == -1)
	memcpy(cor, backup, ppl*sizeof(int));
      else if(res != 1)
	memcpy(backup, cor, ppl*sizeof(int));
      res = 1;
    }
    printf("%d\n", maxi);
    
  }
  return 0;

}
