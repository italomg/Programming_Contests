#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

  int T;
  while(scanf("%d", &T) != EOF){
    vector<pair<long int, long int> > lamps;
    long int x,y, total = 0;
    int bad;
    for(int i = 0; i < T; i++){
      scanf("%ld %ld", &x, &y);
      lamps.push_back(pair<long int, long int>(x,y));
    }

    sort(lamps.begin(), lamps.end());

    for(int i = 0; i < T; i++){
      for(int j = i+1; j < T; j++){
	bad = 0;
	for(int k = i+1; k < j; k++)
	  if((lamps[k].second > lamps[i].second && lamps[k].second < lamps[j].second) || (lamps[k].second < lamps[i].second && lamps[k].second > lamps[j].second)){
	    bad = 1;
	    break;
	  }
	if(!bad)
	  total++;
      }
    }
    printf("%d\n", total);
  }

  return 0;
}
