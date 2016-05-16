#include<cstdio>
#include<cstring>
#include<vector>
#include<string>

using namespace std;

int row,col;
vector<string> visit;


int dfs(int i, int j){

  int res = 0;

  if(i < 0 || j < 0 || i >= row || j >= col || visit[i][j] == '1')
    return res;
  visit[i][j] = '1';
  res = 1;
  res += dfs(i+1, j);
  res += dfs(i-1, j);
  res += dfs(i, j+1);
  res += dfs(i, j-1);
  return res;
}


int main(){

  int tests, resp, si, sj;
  scanf("%d", &tests);

  while(tests--){
    string temps;
    char temp[120];
    col = row = 0;
    resp = 0;
    visit.clear();
    scanf("%d %d ", &si, &sj);
    fgets(temp,120,stdin);
    if(temp[strlen(temp)-1] == '\n')
      temp[strlen(temp)-1] = 0;
    col = strlen(temp);
    while(*temp != '\n' && !feof(stdin)){
      row++;
      if(temp[strlen(temp)-1] == '\n')
	temp[strlen(temp)-1] = 0;
      temps.assign(temp);
      visit.push_back(temp);
      fgets(temp,120,stdin);
    }
    si--;
    sj--;
    resp = dfs(si, sj);
    printf("%d\n", resp);
    if(tests)
      puts("");
  }
  
  return 0;
}
