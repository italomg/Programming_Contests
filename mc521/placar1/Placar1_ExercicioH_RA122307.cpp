#include<iostream>

using namespace std;

int main(){

  int cur, mypos, test, start, done, time;
  int queue[10000], qntd[10] = {0};

  cin>>test;

  while(test--){

    cin>>cur;
    cin>>mypos;
    start = 0;
    done = 1;
    time = 0;
      
    for(int i = 1; i < 10; i++)
      qntd[i] = 0;
    
    for(int i = 0; i < cur; i++){
      cin>>queue[i];
      qntd[queue[i]]++;
    }

    while(done){
      if(queue[start] == 9){
	time++;
	qntd[queue[start]]--;
	if(mypos == start)
	  done = 0;
	start++;
      }
      else{
	for(int i = queue[start]+1; i < 10; i++){
	  if(qntd[i] > 0){
	    queue[cur] = queue[start];
	    if(mypos == start)
	      mypos = cur;
	    cur++;
	    start++;
	    break;
	  }
	  else if(i == 9){
	    time++;
	    qntd[queue[start]]--;
	    if(mypos == start)
	      done = 0;
	    start++;
	    break;
	  }
	}
      }
    }
    cout<<time<<endl;
  }
  
  return 0;
}
