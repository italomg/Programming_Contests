#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>

using namespace std;

int soma(vector<int> bag){

  int som = 0;
  for(int i = 0; i < bag.size(); i ++)
    som += bag[i];
  
  return som;
}

int main(){

  int nbags, bag;

  cin>>nbags;
  while(nbags){
    vector<vector<int> > bags(100005);
    for(int i = 0; i < nbags; i++){
      cin>>bag;
      bags[i].push_back(bag);
    }
    
    //sort(bags.begin, bags.end());

    int j = 0, sum1, sum2, pos = nbags;
    for(int i = 0; i < nbags, j < nbags;){
      sum1 = soma(bags[i]);
      sum2 = soma(bags[j]);
      if(sum1 <= sum2){
	for(int k = 0; k < bags[i].size(); k++)
	  bags[j].push_back(bags[i][k]);
	bags[i].front() = -1;
	pos--;
	j++;
	i++;
      }
      else if(sum2 < sum1)
	i++;
      else
	j++;
	
    }

    printf("%d\n", pos);

    for(int i = 0; i < nbags; i++){
      if(bags[i].front() != -1){
	for(int j = bags[i].size()-1; j >= 0 ; j--){
	  if(j)
	    printf("%d", bags[i][j]);
	  else
	    printf(" %d", bags[i][j]);
	}
	puts("");
      }
    }
    cin>>nbags;
    if(nbags)
      puts("");
  }

}
