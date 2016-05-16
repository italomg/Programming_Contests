#include <cstdio>
#include <map>

#define INF 0x3f3f3f3f

using namespace std;

struct comp{
  bool operator()(const pair<int, int> &i, const pair<int,int> &j) const{
    int mini, minj;
    mini = min(i.first, i.second);
    minj = min(j.first, j.second);
    if(mini > minj)
      return true;
    else
      return false;
  }
};

int main(){

  int N, A, B, K, DA, DB, diff1, diff2, diff3, diff4;
  long long int res, op1, op2;
  multimap<pair<int,int>, int, comp> allVal;
  while(scanf("%d %d %d", &N, &A, &B) != EOF && (N || A || B)){
    allVal.clear();
    res = 0;
    for(int i = 0; i < N; i++){
      scanf("%d %d %d", &K, &DA, &DB);
      allVal.insert(pair<pair<int,int>, int>(pair<int, int>(DA, DB), K));
    }

    multimap<pair<int,int>, int, comp>::iterator it;
    for(it = allVal.begin(); it != allVal.end(); it++){
      diff1 = diff2 = 0;
      op1 = op2 = INF;
      DA = it->first.first;
      DB = it->first.second;
      K = it->second;
      if(A > K){
	op1 = DA*K;
	diff1 = K;
      }
      else{
	op1 = DA*A + DB*(K-A);
      }
      if(B > K){
	op2 = DB*K;
	diff2 = K;
      }
      else{
	op2 = DB*B + DA*(K-B);
      }

      if(op1 < op2){
	if(diff1)
	  A -= diff1;
	else{
	  B = (K-A);
	  A = 0;
	}
	res += op1;
      }
      else{
	if(diff3)
	  B -= diff3;
	else{
	  A = (K-B);
	  B = 0;
	}
	res += op2;
      }
    }
    printf("%d\n", res);
  }

  return 0;
}
