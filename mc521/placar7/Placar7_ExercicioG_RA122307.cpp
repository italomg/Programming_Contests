#include<cstdio>
#include<map>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int main(){

  int books, price, money;

  while(scanf("%d", &books) != EOF){
    vector<int> prices(books);
    map<int, pair<int, int> > possibilities;
    for(int i = 0; i < books; i++){
      scanf("%d", &price);
      prices[i] = price;
    }
    scanf("%d", &money);
    for(int j = 0; j < books; j++){
      for(int i = j+1; i < books; i++){
	if(prices[i] + prices[j] == money)
	  possibilities[abs(prices[i] - prices[j])] = pair<int,int>(prices[j], prices[i]);
      }
    }
    sort(prices.begin(), prices.end());
    map<int, pair<int,int> >::iterator it = possibilities.begin();
    printf("Peter should buy books whose prices are %d and %d.\n\n", it->second.first, it->second.second);
  }

  return 0;
}
