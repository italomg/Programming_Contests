#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
  
  int caso;
  scanf("%d", &caso);

  char direction;
  getchar();
  while(caso--){
    int coords[4] = {0}, pos[2] = {0};
    direction = getchar();
    while(direction != '\n'){
      switch (direction){
	case 'R':
	  pos[0]++;
	  break;
	case 'L':
	  pos[0]--;
	  break;
	case 'U':
	  pos[1]++;
	  break;
	case 'D':
	  pos[1]--;
	  break;
	case '?':
	  coords[0]++;
	  coords[1]--;
	  coords[2]++;
	  coords[3]--;
	  break;
	default:
	  break;
	}
      direction = getchar();
    }
    printf("%d %d %d %d\n", pos[0]+coords[1], pos[1]+coords[3], pos[0]+coords[0], pos[1]+coords[2]);
  }

  return 0;
}
