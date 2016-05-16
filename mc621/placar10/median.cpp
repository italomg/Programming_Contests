#include <cstdio>
#include <vector>

using namespace std;

int main(){


  int cases;
  scanf("%d", &cases);

  while(cases--){
    int datasetn, n, input, sum, old_sum;

    sum = old_sum = 0;
    scanf("%d %d", &datasetn, &n);
    printf("%d %d\n", datasetn, (n/2)+1);
    vector<int> options;

    for(int i = 0; i < n; i++){
      scanf("%d", &input);
      vector<int>::iterator it;
      int inseriu = 0;
      for(it = options.begin(); it != options.end(); it++)
	if(*it > input){
	  options.insert(it, input);
	  inseriu = 1;
	  break;
	}
      if(!inseriu)
	options.push_back(input);

      if(!(i % 2)){
	int median = 0;
	if(options.size() % 2)
	  median = options[(options.size()/2)];
	else
	  median = (options[(options.size()/2) + 1] + options[(options.size()/2)])/2;
	printf("%d", median);
	if((i+2) % 20 == 0)
	  puts("");
	else if(i != n-1 && i != n-2)
	  printf(" ");
      }
    }
    puts("");
  }

  return 0;
}
