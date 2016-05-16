#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

int main(){

  int tests, v, e, orig, dest, no, moved;
  cin>>tests;
  no = 0;
  while(tests--){
    cin>>v>>e;
    int graph[105][105] = {{0}};
    int conn[105] = {0};
    vector<int> ans;
    for(int i = 0; i < e; i++){
      cin>>orig>>dest;
      graph[orig][dest] = 1;
      graph[dest][orig] = 1;
      conn[orig]++;
      conn[dest]++;
    }
    int agora = e, pos, Max, Max1;
    moved = 0;
    while(agora >= e/2){
      pos = -1, Max = 0;
      for(int i = 1; i <= v; i++){
	if(conn[i] > Max){
	  Max = conn[i];
	  pos = i;	
	}
      }
      if(pos == -1)
	break;
      Max1 = 0;
      for(int i = 0; i < ans.size(); i++)
      	if(graph[pos][ans[i]])
      	  Max1++;

      if(Max >= Max1){
	agora -= Max;
	conn[pos] = 0;
	ans.push_back(pos);
	moved++;
      }
      
      for(int i = 1; i <= v; i++){
	if(graph[pos][i])
	  conn[i]--;
      }
    }
    no++;
    if(pos == -1)
      printf("Impossible\n");
    else{
      printf("Case #%d: %d\n", no, moved);
      for(int i = 0; i < moved; i++)
	if(i)
	  printf(" %d", ans[i]);
	else
	  printf("%d", ans[i]);
    }
    puts("");
    
  }

  return 0;
}
