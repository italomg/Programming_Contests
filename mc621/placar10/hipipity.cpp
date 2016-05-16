#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int main(){

  int cases;
  scanf("%d", &cases);

  while(cases--){
    int n, k;
    scanf("%d %d", &n, &k);
    
    unsigned input, board[n][n];
    long unsigned val_matriz[n][n];

    memset(board, 0, n*n*sizeof(unsigned));
    memset(val_matriz, 0, n*n*sizeof(long unsigned));
    queue<pair<int, int> > to_visit;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
	scanf("%u", &board[i][j]);
    
    to_visit.push(pair<int, int>(0, 0));
    val_matriz[0][0] = board[0][0];
    pair<int, int> cur;
    long unsigned maxi = 0;
    while(!to_visit.empty()){
      cur = to_visit.front();
      to_visit.pop();

      maxi = max(maxi, val_matriz[cur.first][cur.second]);
      
      for(int i = cur.first+1; i <= cur.first+k && i < n; i++)
	if((board[cur.first][cur.second] < board[i][cur.second]) && val_matriz[i][cur.second] < (val_matriz[cur.first][cur.second] + board[i][cur.second])){
	  val_matriz[i][cur.second] = val_matriz[cur.first][cur.second] + board[i][cur.second];
	  to_visit.push(pair<int, int>(i, cur.second));
	}
      
      for(int i = cur.second+1; i <= cur.second+k && i < n; i++)
	if((board[cur.first][cur.second] < board[cur.first][i]) && (val_matriz[cur.first][i] < val_matriz[cur.first][cur.second] + board[cur.first][i])){
	  val_matriz[cur.first][i] = val_matriz[cur.first][cur.second] + board[cur.first][i];
	  to_visit.push(pair<int, int>(cur.first, i));
	}      

      for(int i = cur.first-1; i >= cur.first-k && i >= 0; i--)
	if((board[cur.first][cur.second] < board[i][cur.second]) && (val_matriz[i][cur.second] < val_matriz[cur.first][cur.second] + board[i][cur.second])){
	  val_matriz[i][cur.second] = val_matriz[cur.first][cur.second] + board[i][cur.second];
	  to_visit.push(pair<int, int>(i, cur.second));
	}
      
      for(int i = cur.second-1; i >= cur.second-k && i >= 0; i--)
	if((board[cur.first][cur.second] < board[cur.first][i]) && (val_matriz[cur.first][i] < val_matriz[cur.first][cur.second] + board[cur.first][i])){
	  val_matriz[cur.first][i] = val_matriz[cur.first][cur.second] + board[cur.first][i];
	  to_visit.push(pair<int, int>(cur.first, i));
	}
      
    }
    printf("%lu\n", maxi);
    if(cases)
      puts("");
  }

  return 0;
}
