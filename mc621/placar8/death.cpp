#include <cstdio>
#include <vector>

#define MAX 1000000005


using namespace std;

int main(){

  long long int T, OKN = 10000005;
  vector<bool> isprime(MAX, true);
  vector<long long int> onlyPrime;

  scanf("%lld", &T);

  isprime[0] = false;
  for(long long int p = 2; p < OKN; p++){
    for(long long int c = p+p; c < OKN; c += p){
      isprime[c] = false;
    }
    if(isprime[p])
      onlyPrime.push_back(p);
  }

  long long int res, input;
  for(long long int i = 0; i < T; i++){
    scanf("%lld", &input);
    res = 0;
    while(input > 0){
      if(input > OKN && !(input & 2)){
	for(long long int p = onlyPrime[onlyPrime.size()-1]; p <= input; p++){
	  for(long long int c = p+p; c <= input; c += p){
	    isprime[c] = false;
	  }
	  if(isprime[p])
	    onlyPrime.push_back(p);
	}
      }
      if(isprime[input]){
	input--;
      }
      else{
	for(long long int p = 0; p < onlyPrime.size(); p++)
	  if(!(input % onlyPrime[p]))
	    input = input / onlyPrime[p];
      } 
      res++;
    }
    printf("%d\n", res);
  }

  return 0;
}
