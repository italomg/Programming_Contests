#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){

  int n, m, boy, girl, pairs;
  int i, j;
  vector<int> boys, girls;
  
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &boy);
    boys.push_back(boy);
  }

  scanf("%d", &m);
  for(i = 0; i < m; i++){
    scanf("%d", &girl);
    girls.push_back(girl);
  }

  sort(boys.begin(), boys.end());
  sort(girls.begin(), girls.end());

  pairs = j = i = 0;
  while(i < n && j < m){
    if(abs(boys[i] - girls[j]) <= 1){
      pairs++;
      i++;
      j++;
    }
    else if(boys[i] > girls[j])
      j++;
    else if(boys[i] < girls[j])
      i++;
    else{
      i++;
      j++;
    }
  }
  printf("%d\n", pairs);
  
  return 0;
}
