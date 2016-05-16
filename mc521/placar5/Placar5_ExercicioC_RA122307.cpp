#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main(){

  int sets, parlSize;

  scanf("%d", &sets);
  while(sets--){
    vector<int> sum;
    scanf("%d", &parlSize);

    for(int i = 2; i <= parlSize; i++){
      sum.push_back(i);
      parlSize -= i;
    }

    for(int i = sum.size()-1; i >= 0 && parlSize; i--){
      sum[i]++;
      parlSize--;
    }

    if(parlSize)
      sum.back()++;

    for(vector<int>::iterator it = sum.begin(); it != sum.end(); it++){
      if(it == sum.begin())
	printf("%d", *it);
      else
	printf(" %d", *it);
    }
    puts("");
    if(sets)
      puts("");
  }

  return 0;
}
