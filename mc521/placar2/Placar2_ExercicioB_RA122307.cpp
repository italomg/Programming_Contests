#include<iostream>
#include<stdio.h>

using namespace std;

int main(){

  int K, N, R, C;
  
  cin>>N>>R>>C>>K;
  while(N != 0 && R != 0 && C != 0 && K != 0){
    int field[R+2][C+2][2], invadido[R+2][C+2];
    for(int i = 0; i < R+2; i++){
      for(int j = 0; j < C+2; j++){
	if(i == 0 || j == 0 || i == R+1 || j == C+1){
	  field[i][j][K%2] = 101;
	  field[i][j][(K+1)%2] = field[i][j][K%2];
	}
	else{
	  cin>>field[i][j][K%2];
	  field[i][j][(K+1)%2] = field[i][j][K%2];
	}
	invadido[i][j] = K;
      }
    }
    
    while(K--){

      for(int i = 0; i < R+2; i++)
	for(int j = 0; j < C+2; j++)
	  invadido[i][j] = 0;
      for(int i = 1; i < R+1; i++){
	for(int j = 1; j < C+1; j++){
	  if(field[i-1][j][K%2] == (field[i][j][K%2] + 1)%N){
	    field[i-1][j][(K+1)%2] = field[i][j][K%2];
	    invadido[i-1][j]=1;
	  }
	  
	  if(field[i][j-1][K%2] == (field[i][j][K%2] + 1)%N){
	    field[i][j-1][(K+1)%2] = field[i][j][K%2];
	    invadido[i][j-1]=1;
	  }
	  
	  if(field[i][j+1][K%2] == (field[i][j][K%2] + 1)%N){
	    field[i][j+1][(K+1)%2] = field[i][j][K%2];
	    invadido[i][j+1]=1;
	  }
	  if(field[i+1][j][K%2] == (field[i][j][K%2] + 1)%N){
	    field[i+1][j][(K+1)%2] = field[i][j][K%2];
	    invadido[i+1][j]=1;
	  }	  
	}
      }
      for(int i = 1; i < R+1; i++)
	for(int j = 1; j < C+1; j++)
	  if(!invadido[i][j]){
	    field[i][j][(K+1)%2] = field[i][j][K%2];
	    invadido[i][j]=1;
	  }
    }
    for(int i = 1; i < R+1; i++){
      for(int j = 1; j < C+1; j++)
	if(j == C)
	  printf("%d", field[i][j][1]);
      else
	printf("%d ", field[i][j][1]);
      printf("\n");
    }
    for(int i = 0; i < R+2; i++)
      for(int j = 0; j < C+2; j++){
	field[i][j][1] = 0;
    	field[i][j][0] = 0;
      }
    cin>>N>>R>>C>>K;
  }

  return 0;
}
