#include<iostream>

using namespace std;

struct assoc{

  int d1, d2;

};

int main(){

  struct assoc associ[5], senha[6];
  int resp[6];
  int tests, no = 0;
  char dig;
  cin>>tests;
  while(tests){

    for(int i = 0; i < 5; i++){
      associ[i].d1 = -1;
      associ[i].d2 = -1;
      senha[i].d1 = -1;
      senha[i].d2 = -1;
    }
    senha[5].d1 = -1;
    senha[5].d2 = -1;

    for(int i = 0; i < tests; i++){
      for(int j = 0; j < 5; j++){
	cin>>associ[j].d1;
	cin>>associ[j].d2;
      }
      for(int j = 0; j < 6; j++){
	cin>>dig;
	if((senha[j].d1 == associ[dig%'A'].d1 || senha[j].d1 == associ[dig%'A'].d2) && (senha[j].d2 != associ[dig%'A'].d2 && senha[j].d2 != associ[dig%'A'].d1))
	  resp[j] = senha[j].d1;
	if((senha[j].d2 == associ[dig%'A'].d1 || senha[j].d2 == associ[dig%'A'].d2) && (senha[j].d1 != associ[dig%'A'].d2 && senha[j].d1 != associ[dig%'A'].d1))
	  resp[j] = senha[j].d2;
	else{
	  senha[j].d1 = associ[dig%'A'].d1;
	  senha[j].d2 = associ[dig%'A'].d2;
	}
      }
    }

    no++;
    cout<<"Teste "<<no<<endl;
    for(int i = 0; i < 6; i++){
      cout<<resp[i]<<" ";
    }
    cout<<endl<<endl;
    
    cin>>tests;
  }

}
