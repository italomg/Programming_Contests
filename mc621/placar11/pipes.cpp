#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

  int K, J;
  scanf("%d", &K);
  scanf("%d", &J);
  
  int V[1005] = {0}, P[1005] = {0};
  vector<vector<int> > val_matrix(1005, vector<int>(5005));

  for(int i = 0; i < K; i++)
    scanf("%d %d", &P[i], &V[i]);

  for(int i = 1; i <= K; i++){
    for(int j = 1; j <= J; j++){
      if(P[i-1] <= j)
	val_matrix[i][j] = max(val_matrix[i][j-P[i-1]] + V[i-1], max(val_matrix[i-1][j-P[i-1]] + V[i-1], val_matrix[i-1][j]));
      else
	val_matrix[i][j] = val_matrix[i-1][j];
    }
  }

  printf("%d\n", val_matrix[K][J]);

  return 0;
}
