#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

bool compare(pair<double,double> i, pair<double,double> j){
  if(i.first < j.first) return true;
  if(i.first > j.first) return false;
  if(i.second > j.second) return true;
  return false;
}

int main(){

  double n, l, w, x, r, count, flag;
  double dx, start, fim;

  while(scanf("%lf %lf %lf", &n, &l, &w) == 3){
    vector<pair<double, double> > sprinklers;
    for(int i = 0; i < n; i++){
      scanf("%lf %lf", &x, &r);
      if((r*r) >= ((w*w)/4.0)){
	dx = sqrt((r*r) - ((w*w)/4.0));
	sprinklers.push_back(pair<double, double>(x-dx, x+dx));
      }
    }
    flag = 1;
    if(sprinklers.size() > 0){
      sort(sprinklers.begin(), sprinklers.end(), compare);
      count = fim = start = 0;
      for(int i = 0; i < sprinklers.size(); i++){
	if(sprinklers[i].first <= start){
	  if(fim < sprinklers[i].second){
	    fim = sprinklers[i].second;
	    flag = 0;
	  }
	}
	else if(!flag){
	  start = fim;
	  // if(start >= l)
	  //   break;
	  count++;
	  i--;
	  flag = 1;
	}
      }
    }
    if(!flag && fim >= l){
      count++;
      printf("%d\n", (int)count);
    }
    else
      printf("-1\n");
  }

  return 0;
}
