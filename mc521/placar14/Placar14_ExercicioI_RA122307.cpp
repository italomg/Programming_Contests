#include <cstdio>
#include <vector>
#include <queue>

using namespace std;


vector<int> match, vis;

int Aug(int l, vector<vector<int> > &AdjList){
  if (vis[l])
    return 0;

  vis[l] = 1;

  for (int j = 0; j < (int)AdjList[l].size(); j++){
    int r = AdjList[l][j];
    if(match[r] == -1 || Aug(match[r], AdjList)){
      match[r] = l;
      match[l] = r;
      return 1;
    }
  }

  return 0;
}

int main(){

  int MCBM = 0, R = 0, C = 0, N = 0, x = 0, y = 0, aug = 0, cur = 0, m;

  scanf("%d %d %d", &R, &C, &N);
  while(R != 0 || C != 0 || N != 0){
    MCBM = 0;
    vector<vector<int> > AdjList(R+C);
    vector<bool> U(R+C), Z(R+C), K(R+C);
    for(int i = 0; i < N;  i++){
      scanf("%d %d", &x, &y);
      AdjList[x-1].push_back((y-1)+R);
    }

    match.assign(R+C, -1);
    for (int l = 0; l < R; l++){
      vis.assign(R, 0);
      aug = Aug(l, AdjList);
      MCBM += aug;
    }

    queue<int> Q;
    vector<int>::iterator it;
    vis.assign(R+C, 0);

    for(int i = 0; i < R; i++){
      if(match[i] == -1){
	Z[i] = true;
	Q.push(i);
	vis[i] = 1;
      }
    }

    while(!Q.empty()){
      cur = Q.front();
      Q.pop();
      //vis[cur] = 1;
      for(it = AdjList[cur].begin(); it != AdjList[cur].end(); it++){
	if(match[*it] != cur && !vis[*it]){
	  vis[*it] = 1;
	  Z[*it] = true;
	  m = match[*it];
	  if(m != -1 && !vis[m]){
	    vis[m] = 1;
	    Z[m] = true;
	    Q.push(m);
	  }
	}
      }
    }

  

    int flag = 1;
    printf("%d ", MCBM);
    for(int i = 0; i < R+C; i++){
      if((i < R && !Z[i]) || (i >= R && Z[i])){
	if(!flag)
	  printf(" ");
	if(i < R)
	  printf("r%d", i+1);
	else
	  printf("c%d", i+1-R);
      }
      flag = 0;
    }
    puts("");
    scanf("%d %d %d", &R, &C, &N);
  }
  return 0;
}
