#include <cstdio>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

int main(){

  int V, o, d;
  double dist, res;
  while(scanf("%d", &V) != EOF && V){
    res = dist = 0;
    multimap<double, pair<int, int> >  edgeList;
    vector<pair<int, int> > points;
    vector<int> visitado(V);

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
      if(!visitado[it->second.first] || !visitado[it->second.second]){
	res += it->first;
	visitado[it->second.first] = 1;
	visitado[it->second.second] = 1;
      }

    printf("%.2f\n", res);
    
  }

  return 0;
}
