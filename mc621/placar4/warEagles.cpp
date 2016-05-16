#include <cstdio>
#include <cstring>

int size;

void dfs(int field[25][25], int visitado[25][25], int i, int j){
  //DFS

  visitado[i][j] = 1;
  
  if(i-1 >= 0 && field[i-1][j] && !visitado[i-1][j])
    dfs(field, visitado, i-1, j);
  
  if(i-1 >= 0 && j-1 >= 0 && field[i-1][j-1] && !visitado[i-1][j-1])
    dfs(field, visitado, i-1, j-1);
  
  if(i-1 >= 0 && j+1 < size && field[i-1][j+1] && !visitado[i-1][j+1])
    dfs(field, visitado, i-1, j+1);
  
  if(j-1 >= 0 && field[i][j-1] && !visitado[i][j-1])
    dfs(field, visitado, i, j-1);
  
  if(j+1 < size && field[i][j+1] && !visitado[i][j+1])
    dfs(field, visitado, i, j+1);
  
  if(i+1 < size && field[i+1][j] && !visitado[i+1][j])
    dfs(field, visitado, i+1, j);
  
  if(i+1 < size && j-1 >= 0 && field[i+1][j-1] && !visitado[i+1][j-1])
    dfs(field, visitado, i+1, j-1);
  
  if(i+1 < size && j+1 < size && field[i+1][j+1] && !visitado[i+1][j+1])
    dfs(field, visitado, i+1, j+1);
    
}

int main(){

  int field[25][25], visitado[25][25], eagles, img = 1;
  char line[27];

  while(scanf("%d", &size) != EOF){
    memset(field, 0, 25*25*sizeof(int));
    memset(visitado, 0, 25*25*sizeof(int));
    memset(line, 0, 27*sizeof(char));
    eagles = 0;
    
    for(int i = 0; i < size; i++){
      scanf("%s", line);
      for(int j = 0; j < size; j++){
	if(line[j] == '1')
	  field[i][j] = 1;
      }
    }

    for(int i = 0; i < size; i++)
      for(int j = 0; j < size; j++){
	if(field[i][j] && !visitado[i][j]){
	  dfs(field, visitado, i, j);
	  eagles++;
	}	
      }

    printf("Image number %d contains %d war eagles.\n", img, eagles);
    img++;

  }

  return 0;
}
