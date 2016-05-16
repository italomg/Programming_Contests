#include <iostream>
#include <strings>

using namespace std;

int main(){

  string A, B;
  while(cin>>A>>B){
    int smaller = min(A.size(), B.size()), maxSize, i, j;
    maxSize = i = j = 0;
    while(i < smaller){
      if(A[i] == B[i])
	i++
    }
  }

  return 0;
}
