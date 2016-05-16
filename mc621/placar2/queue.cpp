#include <cstdio>
#include <list>

using namespace std;

int main(){

  long long int n, input, happy = 0, sum = 0;
  list<long long int> queue;

  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &input);
    queue.push_back(input);
  }

  queue.sort();

  list<long long int>::iterator it;
  for(it = queue.begin(); it != queue.end(); it++){
    if(sum <= *it)
      happy++;
    sum += *it;
  }

  printf("%lld", happy);
  
  return 0;
}
