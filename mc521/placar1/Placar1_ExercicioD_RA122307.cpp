#include<iostream>
#include<stdio.h>
#include<cmath>

using namespace std;

int main(){

  int qntdCarro, flag = 1;
  long int carNmb[1005] = {0};
  long long int posCmpt[1005] = {0};
  int occPos[1005] = {0};
  long long int carPos[1005] = {0};

  cin>>qntdCarro;
  while(qntdCarro){
    flag = 1;
    for(int i = 0; i < qntdCarro; i++){
      cin>>carNmb[i];
      cin>>posCmpt[i];
    }
    for(int i = 0; i < qntdCarro; i++){
      if(((i+1)+posCmpt[i] > qntdCarro) || (i+1)+posCmpt[i] <= 0){
	cout<<-1<<endl;
	flag = 0;
	break;
      }
      else if(!occPos[(i+1)+posCmpt[i]]){
	occPos[(i+1)+posCmpt[i]] = 1;
	carPos[(i+1)+posCmpt[i]] = carNmb[i];
      }
      else{
	cout<<-1<<endl;
	flag = 0;
	break;
      }
    }
    if(flag){
      for(int i = 0; i < qntdCarro; i++)
	if(i == qntdCarro-1)
	  printf("%lld", carPos[i+1]);
	else
	  printf("%lld ", carPos[i+1]);
      printf("\n");
    }

    for(int i = 0; i < qntdCarro+1; i++){
      carNmb[i] = 0;
      carPos[i] = 0;
      occPos[i] = 0;
      posCmpt[i] = 0;
    }
    cin>>qntdCarro;
  }

  return 0;
}
