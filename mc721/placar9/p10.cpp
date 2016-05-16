#include <bits/stdc++.h>

using namespace std;

int main(){

  int T;
  cin>>T;

  while(T--){

    int cur, res = 0x3f3f3f3f;
    cin>>cur;

    for(int i = 1; i <= sqrt(cur); i++){
      for(int j = 1; j <= sqrt(cur); j++){
	for(int k = 1; k <= cur; k++){
	  if(i*j*k == cur)
	    res = min(res, (2 * i * j) + (2 * i * k) + (2 * j * k));
	}
      }
    }

    cout<<res<<endl;

  }

  return 0;
}
