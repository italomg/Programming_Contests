#include <cstdio>
#include <vector>
#include <map>
#include <cstring>

#define NORTE 0
#define SUL 2
#define LESTE 1
#define OESTE 3

using namespace std;

int main(){

  int T, caso = 0; 
  scanf("%d", &T);

  while(T--){

    char commands[150] = {0}, cur;
    int posx, posy, state = NORTE, visitado[70][70] = {{0}}, repeated = 0;
    scanf("%d %d", &posx, &posy);
    scanf("%s", commands);

    visitado[posx][posy]++;
    for(int i = 0; i < strlen(commands); i++){
      cur = commands[i];
      switch(cur){
      case 'F':
	if(state == NORTE)
	  posy++;
	if(state == SUL)
	  posy--;
	if(state == LESTE)
	  posx++;
	if(state == OESTE)
	  posx--;
	if(visitado[posx][posy] == 1)
	  repeated++;
	visitado[posx][posy]++;
	break;
      case 'R':
	state = (state + 1) % 4;
	break;
      case 'L':
	state = (state + 3) % 4;
	break;
      default:
	break;
      }
    }
    printf("Case #%d: %d %d %d\n", ++caso, posx, posy, repeated);
  }

  return 0;
}
