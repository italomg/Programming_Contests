#include<iostream>
#include<stdio.h>

using namespace std;

struct armario{

  long long int dif, mov, sumd, summ;

};

int main(){
  
  long long int N,L,input, old, min;
  int flag;
  cin>>N>>L;

  struct armario mario[100000];

  while(N && L){
    cin>>old;
    flag = 1;
    for(long long int i = 0; i < L-1; i++){
      cin>>input;
  
      mario[i].dif = input-old;
      mario[i].mov = mario[i].dif-1;
      if(i>0){
	mario[i].sumd = mario[i-1].sumd + mario[i].dif;
	mario[i].summ = mario[i-1].summ + mario[i].mov;
      }
      else{
	mario[i].sumd = mario[i].dif;
	mario[i].summ = mario[i].mov;
      }
      if(mario[i].sumd+1 >= N && mario[i].summ == 0){
	min = 0;
	flag = 0;
	cin.ignore(100000,'\n');
	break;
      }	
      else if(mario[i].sumd+1 >= N && mario[i].summ == 1){
	min = 1;
	flag = 0;
	cin.ignore(100000,'\n');
	break;
      }
      old = input;
    }
    if(flag){
      min = mario[L-2].summ;
      for(long long int i = 0; i < L; i++){
	for(long long int j = L-1; j > i; j--){
	  if((mario[j].sumd - mario[i].sumd)+1 >= N){
	    if((mario[j].summ - mario[i].summ) < min)
	      min = mario[j].summ - mario[i].summ;
	  }
	  if(min <= 1){
	    break;
	  }
	}
      }
    }
  
    cout<<min<<endl;
    cin>>N>>L;
  }

  return 0;
}
