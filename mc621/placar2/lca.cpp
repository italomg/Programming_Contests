#include <cstdio>
#include <vector>

using namespace std;

int main(){

  int tests, cases = 1, N, o, d, Q, childs, son, res;

  scanf("%d", &tests);
  while(tests--){
    scanf("%d", &N);
    vector<int> pai(N+1);
    res = 0;
    for(int i = 1; i <= N; i++){
      scanf("%d", &childs);
      for(int j = 0; j < childs; j++){
	scanf("%d", &son);
	pai[son] = i;
      }
    }

    scanf("%d", &Q);
    printf("Case %d:\n", cases);
    for(int i = 0; i < Q; i++){
      scanf("%d %d", &o, &d);
      if(d == o)
	res = o;
      else
	while(1){
	  if(pai[o] == d || pai[d] == o || pai[d] == pai[o]){
	    res = max(pai[o], pai[d]);
	    break;
	  }
	  else if(pai[o] > pai[d])
	    o = pai[o];
	  else if(pai[o] < pai[d])
	    d = pai[d];
	}
      printf("%d\n", res);
    }
    
    cases++;
    
  }

  return 0;
}
