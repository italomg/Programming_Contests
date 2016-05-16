#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stdio.h>

using namespace std;

int main() {
  
  int S, C, saux, sumMass, set, ix;
  double IMBALANCE, AM;
  
  set = 1;
  while(cin>>C>>S){
    vector<int> animals, chambers;
    sumMass = 0;
    for(int i = 0; i < S; i++){
      cin>>saux;
      animals.push_back(saux);
      sumMass += saux;
    }
    AM = ((double)sumMass)/C;
    if(S != 2*C){
      for(int i = S; i < 2*C; i++){
	animals.push_back(0);
      }
    }

    IMBALANCE = 0;
    sort(animals.begin(), animals.end());
    vector<int>::iterator it = animals.begin();
    vector<int>::iterator bit = animals.end();
    bit--;
    for(; it < bit; it++, bit--){
      chambers.push_back(*it);
      chambers.push_back(*bit);
      IMBALANCE += fabs((*it+*bit) - AM);
    }
    cout<<"Set #"<<set<<endl;
    ix = 0;
    for(int i = 0; i < chambers.size(); i = i + 2){
      cout<<" "<<ix<<":";
      if(chambers[i] != 0)
	cout<<" "<<chambers[i];
      if(chambers[i+1] != 0)
	cout<<" "<<chambers[i+1]<<endl;
      else
	cout<<endl;
      ix++;
    }

    printf("IMBALANCE = %.05lf\n\n", IMBALANCE);
    set++;
  }

}
