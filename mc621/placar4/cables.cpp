#include <cstdio>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

int pai[1005];

int find(int i){
  if(pai[i] == i)
    return i;
  else
    return find(pai[i]);
}

void unio(int i, int j){
  int ri, rj;
  ri = find(i);
  rj = find(j);
  pai[ri] = rj;
}

int main(){

  int V, o, d;
  double dist, res;
  while(scanf("%d", &V) != EOF && V){
    res = dist = 0;
    multimap<double, pair<int, int> >  edgeList;
    vector<pair<int, int> > points;
    for(int i = 0; i < 1005; i++)
      pai[i] = i;

    for(int i = 0; i < V; i++){
      scanf("%d %d", &o, &d);
      points.push_back(pair<int, int>(o, d));
    }

    for(int i = 0; i < V; i++){
      for(int j = i+1; j < V; j++){
	dist = sqrt(pow(points[i].first - points[j].first, 2) + pow(points[i].second - points[j].second, 2));
	edgeList.insert(pair<double, pair<int, int> > (dist, pair<int, int>(i, j)));
      }
    }

    multimap<double, pair<int, int> >::iterator it;
    for(it = edgeList.begin(); it != edgeList.end(); it++)
      if(find(it->second.first) != find(it->second.second)){
	res += it->first;
	unio(it->second.first, it->second.second);
      }

    printf("%.2f\n", res);
    
  }

  return 0;
}
