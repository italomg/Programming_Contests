#include<stdio.h>
#include<string.h>

int main(){

  char subseq[1000005] = {0}, seq[1000005] = {0};
  int cur, i;
  while(scanf("%s %s", subseq, seq) != EOF){
    if(strlen(subseq) <= strlen(seq)){
      cur = 0;
      for(i = 0; i < strlen(seq); i++){
	if(cur < strlen(subseq)){
	  if(seq[i] == subseq[cur])
	    cur++;
	}
	else
	  break;
      }
    }
    if(cur == strlen(subseq))
      printf("Yes\n");
    else
      printf("No\n");
    memset(seq, 0, strlen(seq)*sizeof(char));
    memset(subseq, 0, strlen(subseq)*sizeof(char));
  }

  return 0;
}
