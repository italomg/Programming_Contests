#include<cstdio>
#include<cstring>

using namespace std;

void dfsI(char contour[30][80], int i, int j){
  if(i >= 0 || j >= 0 || i < 30 || j < 80 || contour[i][j] == '#')
    return;
  if(contour[i][j] == ' '){
    if(j > start[i] && j < )
    contour[i][j] = '#';
    return;
  }
  
}


int main(){

  char contour[30][80], input, lastchar, col, row;
  int tests, inside, wherepaint, start[30], end[30], top[80], bot[80];
  scanf("%d", &tests);

  while(tests--){
    input = getchar();
    wherepaint = -1;
    row = 0;
    while(input != '-'){
      inside = 0;
      col = 0;
      while(input != '\n'){
	if(input == '*')
	  wherepaint = inside;
	else{
	  if(input != ' '){
	    inside = 1;
	    start[row] = col;
	  }
	  contour[row][col] = input;
	}
	if(input != ' '){
	  lastchar = input;
	  end[row] = col;
	  if(top[col] > row)
	    row
	}
	col++;
	input = getchar();
      }
      if(lastchar == '*')
	wherepaint = 0;
      input = getchar();
      row++;
    }
    while(input != '\n')
      input = getchar();
    
    //dfs(contour);
  }

  return 0;
}
