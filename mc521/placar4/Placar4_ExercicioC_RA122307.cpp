#include<iostream>
#include<cmath>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<map>

using namespace std;

int N, songs, maxi;
int peso[100000];
vector<int> caminho;

void backTrack(vector<int>localCaminho, int item, int localMax){
  
  if(item > songs)
    return;

  backTrack(localCaminho, item+1, localMax);
  if(peso[item]+localMax <= N){
    localMax += peso[item];
    localCaminho.push_back(peso[item]);
    backTrack(localCaminho, item+1, localMax);
  }
  if(localMax > maxi){
    maxi = localMax;
    caminho = localCaminho;
  }
  return;
}

int main(){

  while(scanf("%d %d", &N, &songs) == 2){

    vector<int> localCaminho(0);

    for(int i = 1; i <= songs; i++)
      scanf("%d", &peso[i]);

    maxi = 0;
    backTrack(localCaminho, 1, 0);

    for(int i = 0; i < caminho.size(); i++)
      cout<<caminho[i]<<" ";
    cout<<"sum:"<<maxi<<endl;
  }
  
  return 0;
}
