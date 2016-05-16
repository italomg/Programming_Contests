#include <cstdio>
#include <vector>
#include <algorithm>

#define INF 0x3f3f3f3f

using namespace std;

int main(){

  int n, m, mindir;

  scanf("%d %d", &n, &m);

  vector<int> option(m);
  
  for(int i = 0; i < m; i++)
    scanf("%d", &option[i]);
  
  sort(option.begin(), option.end());

  mindir = INF;
  for(int i = 0, j = n-1; j < m; i++, j++)
    mindir = min(mindir, option[j] - option[i]);
  
  printf("%d\n", mindir);

  return 0;
}
