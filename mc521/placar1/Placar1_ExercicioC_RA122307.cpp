#include<iostream>
#include<string>
#include<cstring>
#include<stdlib.h>
#include<stdio.h>
#include<list>

using namespace std;
 
int main ()
{

  char line[100000];
  while((scanf("%s", line)) != EOF ) { 
    int len = strlen (line);
    list <char> resp;
    list <char>::iterator it = resp.begin();
 
    for(int i = 0; i < len; i++){
      if (line[i] == '[') it = resp.begin();
      else if(line[i] == ']') it = resp.end();
      else resp.insert(it, line[i]);
    }
 
    for(it = resp.begin(); it != resp.end(); it++)
      printf("%c", *it);
 
    printf("\n");
  }
 
  return 0;
}
