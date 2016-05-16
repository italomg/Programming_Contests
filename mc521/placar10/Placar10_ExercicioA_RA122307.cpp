#include<string>
#include<cstdio>
#include<cstring>

using namespace std;


int main(){

  int len, tests, flag, i;
  char input[90];

  scanf("%d", &tests);

  while(tests--){
    memset(input, 0, 90*sizeof(char));
    scanf("%s", input);
    len = strlen(input);
    
    for(i = 1; i <= len; i++){
      flag = 0;
      if(len % i == 0){
	for(int j = 0; j < len-i; j++){
	  if(input[j] != input[j+i]){
	    flag = 1;
	    break;
	  }
	}
	if(!flag)
	  break;
      }
    }
    printf("%d\n", i);
    if(tests)
      puts("");
  }

  return 0;
}
