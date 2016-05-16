#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>

#define INF 999

using namespace std;

int main(){

  int adjMatrix[100][100], T, s, t, roads, build, cases, total1, total2, longest;

  scanf("%d", &T);
  cases = 1;
  
  while(T--){
    scanf("%d", &build);
    scanf("%d", &roads);
    
    for(int i = 0; i < 100; i++){
      for(int j = 0; j < 100; j++)
	adjMatrix[i][j] = INF;
      adjMatrix[i][i] = 0;
    }
    
    for(int i = 0; i < roads; i++){
      scanf("%d %d", &s, &t);
      adjMatrix[s][t] = 1;
      adjMatrix[t][s] = 1;
    }

    for(int i = 0; i < build; i++)
      for(int j = 0; j < build; j++)
	for(int k = 0; k < build; k++)
	  adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);

    scanf("%d %d", &s, &t);
    longest = total2 = total1 = 0;
    
    for(int i = 0; i < build; i++){
      total1 = max(total1, adjMatrix[s][i] + adjMatrix[i][t]);
    }

    printf("Case %d: %d", cases, total1);
    cases++;
    if(T)
      puts("");

  }

  return 0;
}
