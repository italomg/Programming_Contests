#include <cstdio>
#include <cstring>

using namespace std;

char T[100005], P[1005];
int b[1005], n, m, found;

void kmpPreproccess(){
  int i = 0, j = -1;
  b[0] = -1;
  while(i < m){
    while(j >= 0 && P[i] != P[j]) 
      j = b[j];
    i++; 
    j++;
    b[i] = j;
  }
}

void kmpSearch(){
  int i = 0, j = 0;
  while(i < n){
    while(j >= 0 && T[i] != P[j])
      j = b[j];
    i++;
    j++;
    if(j == m){
      found = 1;
      return;
    }
  }
}

int main(){

  int t, Qs;

  scanf("%d", &t);
  while(t--){
    memset(T, 0, 100005*sizeof(char));
    scanf("%s", T);
    scanf("%d", &Qs);
    for(int i = 0; i < Qs; i++){
      memset(b, 0, 1005*sizeof(int));
      memset(P, 0, 1005*sizeof(char));
      scanf("%s", P);
      n = strlen(T);
      m = strlen(P);
      kmpPreproccess();
      found = 0;
      kmpSearch();
      if(found)
	printf("y");
      else
	printf("n");
      if(T)
	puts("");
    }
  }

  return 0;
}
