#include<iostream>
#include<map>
#include<deque>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

struct menor
{  
  bool operator()(const int& l, const int& r)  
  {  
      return l > r;  
  }  
}; 
struct maior
{  
  bool operator()(const int& l, const int& r)  
  {  
      return l < r;  
  }  
};

int main(){

  long long int K;

  cin>>K;

  while(K--){


    long long int nA, nu, Aelem, uelem, count;
    cin>>nA>>nu;

    queue<long long int> A, u;    
    for(long long int i = 0; i < nA; i++){
      cin>>Aelem;
      A.push(Aelem);
    }
    for(long long int i = 0; i < nu; i++){
      cin>>uelem;
      u.push(uelem);
    }

    count = 0;
    priority_queue<long long int, vector<long long int>, maior > maxHeap;
    priority_queue<long long int, vector<long long int>, menor > minHeap;

    while(!A.empty()){

      if( !minHeap.empty() && A.front() > maxHeap.top()){
	minHeap.push(A.front());
      }
      else
	maxHeap.push(A.front());

      A.pop();

      while(!u.empty() && maxHeap.size() + minHeap.size() == u.front()){

	while(maxHeap.size() != count){

	  if(maxHeap.size() < count){
	    maxHeap.push(minHeap.top());
	    minHeap.pop();
	  }
	  else if (maxHeap.size() > count){
	    minHeap.push(maxHeap.top());
	    maxHeap.pop();
	  }
	}
	cout<<minHeap.top()<<endl;
	count++;
	u.pop();
      }
    }
    if(K)
      cout<<endl;
  }
 
  return 0;
}
