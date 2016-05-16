#include <stdio.h>  
#include <string.h>  
#include <algorithm>  
using namespace std;  

int main(){  

  int setSize;  
  int set[1005];  
  int subt;  
  int a, b, c, d;  

  while (scanf("%d", &setSize) != EOF && setSize){  

    int found = 0;  
    for(int i = 0; i < setSize; i ++)
      scanf("%d", &set[i]);  

    sort(set, set + setSize);  
    
    for(d = setSize - 1; d >= 0; d --){ 
      for(a = setSize - 1; a > 1; a --){  
	if(a != d)
	  subt = set[d] - set[a];
	for(b = 0, c = a - 1; b < c;){  
	  if(set[b] + set[c] == subt){  
	    found = 1;
	    break;
	  }  
	  else if(set[b] + set[c] < subt)  
	    b ++;  
	  else  
	    c --;  
	}  
	if(found)
	  break;
      }  
      if(found)
	break;
    }  
    if(found)
      printf("%d\n", set[d]);  
    else  
      printf("no solution\n");  
  }  
  return 0;  
}
