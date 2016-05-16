#include <stdio.h>
#include <vector>

using namespace std;

void swap(vector<int> &ar, int i1, int i2){
  int aux = ar[i1];
  ar[i1] = ar[i2];
  ar[i2] = aux;
}

int main(){

  int size, input, totswaps, mini, curj;
  scanf("%d", &size);
  vector<int> array;
  vector<pair<int, int> > moves;
      
  for(int i = 0; i < size; i++){
    scanf("%d", &input);
    array.push_back(input);
  }

  totswaps = 0;
  for(int i = 0; i < size; i ++){
    mini = array[i];
    curj = i;
    for(int j = i+1; j < size; j++){
      if(mini > array[j]){
	mini = array[j];
	curj = j;
      }
    }
    if(array[i] != mini){
      swap(array, i, curj);
      totswaps++;
      moves.push_back(pair<int, int>(i, curj));
    }
  }

  printf("%d\n", totswaps);
  for(int i = 0; i < moves.size(); i++)
    printf("%d %d\n", moves[i].first, moves[i].second);
  
  return 0;
}
