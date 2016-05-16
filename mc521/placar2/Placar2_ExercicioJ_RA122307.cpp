#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>


using namespace std;


int main() {

  int tests, cmd, nmb;

  while(cin>>tests){
    queue<int> que;
    stack<int> sta;
    priority_queue<int> pqu;
    bool ehStack = true, ehQueue = true, ehPQue = true;

    for(int i = 0; i < tests; i++){
      cin>>cmd>>nmb;

      switch(cmd){
      case 1:
	if(ehStack)
	  sta.push(nmb);
	if(ehQueue)
	  que.push(nmb);
	if(ehPQue)
	  pqu.push(nmb);
	break;
      case 2:
	if(ehStack){
	  if(sta.empty() || sta.top() != nmb)
	    ehStack = false;
	  else
	    sta.pop();
	}
	if(ehQueue){
	  if(que.empty() || que.front() != nmb)
	    ehQueue = false;
	  else
	    que.pop();
	}
	if(ehPQue){
	  if(pqu.empty() || pqu.top() != nmb)
	    ehPQue = false;
	  else
	    pqu.pop();
	}
	break;
      default:
	break;	
      }
    }

    if(ehStack && !ehQueue && !ehPQue)
      cout<<"stack"<<endl;

    else if(!ehStack && ehQueue && !ehPQue)
      cout<<"queue"<<endl;

    else if(!ehStack && !ehQueue && ehPQue)
      cout<<"priority queue"<<endl;

    else if(!ehStack && !ehQueue && !ehPQue)
      cout<<"impossible"<<endl;

    else
      cout<<"not sure"<<endl;
  }

  return 0;
}
