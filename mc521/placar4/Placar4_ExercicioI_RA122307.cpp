#include<iostream>
#include<vector>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<map>

using namespace std;

int val, none, qntd;
map<vector<int>, int> jafoi;

void backTrack(int poss[1000], int sum, int cur, vector<int> vals){
  if(cur < qntd){
    if(poss[cur] + sum < val){
      vals.push_back(poss[cur]);
      backTrack(poss, poss[cur]+sum, cur+1, vals);
      vals.pop_back();
      backTrack(poss, sum, cur+1, vals);
    }
    else if(poss[cur] + sum == val){
      vals.push_back(poss[cur]);
      if(jafoi.find(vals) == jafoi.end()){
	for(vector<int>::iterator it = vals.begin(); it != vals.end(); it++){
	  if(it+1 != vals.end())
	    printf("%d+", *it);
	  else
	    printf("%d\n", *it);
	}
      }

      backTrack(poss, poss[cur]+sum, cur+1, vals);
      jafoi[vals] = 1;
      none = 0;
      vals.pop_back();
      backTrack(poss, sum, cur+1, vals);
    }
    else{
      for(int i = cur+1; i < qntd; i++)
	backTrack(poss, sum, i, vals);
    }
  }
  return;
}

int main(){

  int poss[1000];
  while(scanf("%d", &val) != EOF){

    scanf("%d",&qntd);

    if(!qntd)
      break;

    for(int i = 0; i < 1000; i++)
      poss[i] = -1;

    jafoi.clear();
    vector<int> vals;
    none = 1;
   

    for(int i = 0; i < qntd; i++)
      scanf("%d", &poss[i]);

    printf("Sums of %d:\n", val);
    
    for(int i = 0; i < qntd; i++)
      backTrack(poss, 0, i, vals);
    if(none)
      printf("NONE\n");
    

  }
  

  return 0;
}
