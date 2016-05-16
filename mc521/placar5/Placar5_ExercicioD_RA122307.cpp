#include<cstdio>
#include<cstring>
#include<map>
#include<set>
#include<vector>

using namespace std;

int main(){

  char input;
  char query[105] = {0};
  int Q, inic, fim, k, maxi;
  //multimap<char, int> stateToPos;
  vector<set<int> > candidates (70);
  k= 0;
  input = getchar();
  while(input != '\n'){
    candidates[input%'A'].insert(k);
    k++;
    input = getchar();
  }
  //scanf("%s", candidates);
  
  scanf("%d", &Q);
  
  while(Q--){
    //multimap<char, int> each (stateToPos);
    //priority_queue<int> indices;
    scanf("%s", query);
    
    inic = -1;
    fim = -1;
    //indices.push(-1);
    maxi = -1;
    set<int>::iterator cur;
    for(unsigned int i = 0; i < strlen(query); i++){
      if(!candidates[(query[i] % 'A')].empty()){
	cur = candidates[(query[i] % 'A')].lower_bound(maxi+1);
	if(cur != candidates[(query[i] % 'A')].end()){
	  if(inic == -1)
	    inic = *cur;
	  if(i == strlen(query)-1)
	    fim = *cur;
	  maxi = *cur;
	}
	else
	  break;
      }
      else
	break;
    }
    
    if(fim == -1)
      printf("Not matched");
    else
      printf("Matched %d %d", inic, fim);
    puts("");
  }

  return 0;
}
