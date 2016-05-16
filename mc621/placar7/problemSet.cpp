#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 10000000

long long int possible, l, r, n, x;

void backtrack(vector<long long int> ci, int index, vector<int> picked, long long int sum){
  
  long long int mini = INF, maxi = 1;

  for(int i = 0; i < n; i++){
    if(picked[i]){
      mini = min(ci[i], mini);
      maxi = max(ci[i], maxi);
    }
  }
  
  if(sum >= l && sum <= r && (maxi-mini >= x))
    possible++;

  for(int i = index; i < n; i++){
    if(!picked[i]){
      sum += ci[i];
      picked[i] = 1;
      backtrack(ci, i, picked, sum);
      sum -= ci[i];
      picked[i] = 0;
    }
  }

}

int main(){

  long long int c;
  vector<long long int> ci;
  scanf("%lld %lld %lld %lld", &n, &l, &r, &x);

  for(int i = 0; i < n; i++){
    scanf("%lld", &c);
    ci.push_back(c);
  }

  sort(ci.begin(), ci.end());
  
  possible = 0;
  vector<int> picked(n);
  backtrack(ci, 0, picked, 0);

  printf("%lld\n", possible);
  
  return 0;
}
