#include <cstdio>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int xo, yo;

vector<pair<int, int> >::iterator mit(vector<pair<int, int> >::iterator it){
  return ++it;
}

bool epg(int x, int y, float m, float b, int flag){
  float y1;
  
  if(m == 0 && flag)
    return x == b;
  
  y1 = m*x + b;

  if(abs(y1 - y) > 0.0001)
    return false;

  return true;
}

int main(){
  
  int n, x, y, shots, flag;
  float m, b;
  vector<pair<int,int> >troppers;
  set<pair<int,int> > aux;
  
  scanf("%d", &n);
  shots = 0;
  scanf("%d %d", &xo, &yo);
  
  for(int i = 0; i < n; i++){
    scanf("%d %d", &x, &y);
    troppers.push_back(pair<int,int>(x,y));
  }

  vector<pair<int,int> >::iterator it, it1;
  for(it = troppers.begin(); it != troppers.end(); it = troppers.begin()){
    flag = 0;
    if(xo - it->first == 0){
      m = 0;
      b = xo;
      flag = 1;
    }
    else{
      m = (float)(yo - it->second) / (float)(xo - it->first);
      b = (float)(yo) - (float)(m*xo);
    }
    
    for(it1 = mit(it); it1 != troppers.end(); it1++){
      if(epg(it1->first, it1->second, m, b, flag)){
	troppers.erase(it1);
	it1--;
      }
    }
    troppers.erase(it);
    shots++;
  }

  printf("%d\n", shots);
  
  return 0;
}
