#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int W, H;
int graph1[110][110], graph2[110][110];

int dfs1(int i, int j){

  int res = 0;
  if(i < 0 || j < 0 || i >= H || j >= W || graph1[i][j] == 0)
    return res;
  graph1[i][j] = 0;
  res = 1;
  res += dfs1(i+1, j);
  res += dfs1(i-1, j);
  res += dfs1(i, j+1);
  res += dfs1(i, j-1);
  return res;
}

int dfs2(int i, int j){

  int res = 0;
  if(i < 0 || j < 0 || i >= H || j >= W || graph2[i][j] == 0)
    return res;
  graph2[i][j] = 0;
  res = 1;
  res += dfs2(i+1, j);
  res += dfs2(i-1, j);
  res += dfs2(i, j+1);
  res += dfs2(i, j-1);
  return res;
}

int main(){
  
  int tests, n, x, y;

  scanf("%d", &tests);
  while(tests--){

    scanf("%d %d %d", &W, &H, &n);
    memset(graph1, 0, 110*110*sizeof(int));
    memset(graph2, 0, 110*110*sizeof(int));
    for(int i = 0; i < n; i++){
      scanf("%d %d", &y, &x);
      graph1[x][y] = 1;
    }
    for(int i = 0; i < n; i++){
      scanf("%d %d", &y, &x);
      graph2[x][y] = 1;
    }

    for(int i = 0; i < H; i++){
      for(int j = 0; j < W; j++)
	printf("%d ", graph1[i][j]);
      puts("");
    }
    puts("");
    for(int i = 0; i < H; i++){
      for(int j = 0; j < W; j++)
	printf("%d ", graph2[i][j]);
      puts("");
    }

    vector<int> count1, count2;
    for(int i = 0; i < H; i++){
      for(int j = 0; j < W; j++){
	if(graph1[i][j] == 1){
	  count1.push_back(dfs1(i,j));
	}
      }
    }
    for(int i = 0; i < H; i++){
      for(int j = 0; j < W; j++){
	if(graph2[i][j] == 1){
	  count2.push_back(dfs2(i,j));
	}
      }
    }
    sort(count1.begin(), count1.end());
    sort(count2.begin(), count2.end());

    if(count1 == count2)
      printf("YES\n");
    else
      printf("NO\n");   
  }

  return 0;
}
