#include <cstdio>
#include <algorithm>

using namespace std;

int main(){

  int caso;
  scanf("%d", &caso);

  for(int c = 1; c <= caso; c++){
    int qnt_notas, notas, maior, seq, ended, res;

    scanf("%d", &qnt_notas);
    res = ended = maior = seq = 0;
    for(int i = 0; i < qnt_notas; i++){
      scanf("%d", &notas);
      if(notas > maior){
	maior = notas;
	seq = 1;
	ended = 0;
	res= 1;
      }
      else if(notas == maior && !ended)
	seq++;
      else if(notas == maior && ended){
	seq = 1;
	ended = 0;
      }
      else
	ended = 1;
      res = max(res, seq);
    }
    printf("Caso #%d: %d", c, res);
    if(caso)
      puts("");
  }

  return 0;
}
