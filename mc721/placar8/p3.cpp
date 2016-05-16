#include<bits/stdc++.h>

using namespace std;

int main(){

  int Y, P;
  while(cin>>Y>>P){

    vector<int> popes(P);
    for(int i = 0; i < P; i++){
      cin>>popes[i];
    }

    int best_s = 0, best_e = 0, best_val = 1, s = 0, val = 1;
    for(int i = 0; i < P && s < P; i++){
      if((popes[i] - popes[s] < Y) && (i - s > best_val)){
	best_val = i - s;
	best_s = s;
	best_e = i;
      }
      else if(popes[i] - popes[s] >= Y){
	i--;
	s++;
      }
    }

    cout<<best_val+1<<" "<<popes[best_s]<<" "<<popes[best_e]<<endl;
  }

  return 0;
}
