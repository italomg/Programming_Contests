#include<iostream>

using namespace std;

int main(){

  int tests, days, parties, lost;
  int hartal[100];

  cin>>tests;

  while(tests--){

    cin>>days>>parties;
    lost = 0;
    for(int i = 0; i < parties; i++)
      cin>>hartal[i];

    for(int j = 1; j <= days; j++){
      
      for(int i = 0; i < parties; i++){
	if(j % 7 == 6 || j % 7 == 0)
	  break;
	if(j % hartal[i] == 0){
	  lost++;
	  break;
	}
      }
    }
    cout<<lost<<endl;
  }

  return 0;
}
