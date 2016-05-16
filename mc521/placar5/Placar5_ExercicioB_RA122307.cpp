#include<cstdio>
#include<queue>
#include<vector>
#include<cstdlib>
#include<list>
#include<algorithm>

using namespace std;

int main(){


  int cases, time, lento1, lento2, indo, rapido1, rapido2, tempoTotal, people, state;

  scanf("%d", &cases);
  while(cases--){
    list<int> A, B;
    vector<int> log;
    scanf("%d", &people);
    while(people--){
      scanf("%d", &time);
      A.push_back(time);
    }
    A.sort();;
    indo = 1;
    tempoTotal = 0;
    state = 0;
    if(A.size() == 1){
      tempoTotal = A.front();
      log.push_back(A.front());
      A.pop_front();
    }
    while(!A.empty()){
      if(indo == 1){

	lento1 = A.back();
	A.pop_back();
	lento2 = A.back();
	A.push_back(lento1);

	rapido1 = A.front();
	A.pop_front();
	rapido2= A.front();
	A.push_front(rapido1);

	if(state == 1){
	  log.push_back(rapido1);
	  log.push_back(lento1);
	  B.push_back(lento1);
	  B.push_front(rapido1);
	  tempoTotal += max(rapido1, lento1);
	  A.pop_front();
	  A.pop_back();
	  B.sort();
	  state = 0;
	}
	else if(state == 2){
	  log.push_back(lento2);
	  log.push_back(lento1);
	  tempoTotal += max(lento1, lento2);
	  A.pop_back();
	  A.pop_back();
	  B.push_back(lento1);
	  B.push_back(lento2);
	  B.sort();
	  state = 0;
	}
	else if(2 * rapido2 > rapido1 + lento2 && !state){
	  log.push_back(rapido1);
	  log.push_back(lento1);
	  B.push_back(lento1);
	  B.push_front(rapido1);
	  tempoTotal += max(rapido1, lento1);
	  A.pop_front();
	  A.pop_back();
	  B.sort();
	  state = 1;
	}
	else if(!state){
	  log.push_back(rapido1);	  
	  log.push_back(rapido2);
	  B.push_front(rapido1);
	  B.push_front(rapido2);
	  tempoTotal += max(rapido2, rapido1);
	  A.pop_front();
	  A.pop_front();
	  B.sort();
	  state = 2;
	}
	indo = 0;
      }
      else{
	log.push_back(B.front());
	tempoTotal += B.front();
	A.push_front(B.front());
	B.pop_front();
	A.sort();
	indo = 1;
      }
    }
    printf("%d\n", tempoTotal);
    for(unsigned int i = 0; i < log.size(); i = i+3){
      if(i+2 < log.size())
	printf("%d %d\n%d\n", log[i], log[i+1], log[i+2]);
      else if(log[i+1] > 0)
	printf("%d %d\n", log[i], log[i+1]);
      else
	printf("%d\n", log[i]);
    }
    if(cases)
      printf("\n");
    //printf("%d %d", log[i-3], log[i-2]);
  }
  

  return 0;
}
