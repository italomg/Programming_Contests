#include<iostream>

using namespace std;

int main(){

  long long int N, last, mid, peaks, cur, first, second;
  int dir;
  cin>>N;

  while(N){
    cin>>last;
    cin>>mid;
    first = last;
    second = mid;
    peaks = 0;
    dir = 0;
    for(long long int i = 0; i < N; i++){
      if(i == N-2)
	cur = first;
      else if(i == N-1)
	cur = second;
      else
	cin>>cur;
      
      if(last > mid && mid < cur){
	//if(dir == 1)
	  peaks++;
	  //dir = -1;
      }
      else if(last < mid && mid > cur){
	peaks++;
	//dir = 1;
      }
      last = mid;
      mid = cur;
    }

    cout<<peaks<<endl;
    cin>>N;
  }
  
  return 0;

}
