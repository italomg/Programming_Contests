#include<cstdio>
#include<vector>
#include<cmath>

#define E 0.000000001f

using namespace std;


double calcFunc(vector<int> cfs, double irr){

  double res = cfs[0];  
  for(unsigned int i = 1; i < cfs.size(); i++){
    res += ((double)cfs[i])/pow(1.0 + irr, i);
  }
  return res;
}

int main(){
  
  int input;
  scanf("%d", &input);
  while(input){
    vector<int> cfs(input+1);
    for(int i = 0; i <= input; i++)
      scanf("%d", &cfs[i]);
    

    double low = -0.99f, high = 10000.0f, irr = 0;

    while(low <=  high + E){
      double mid = (high+low)/2.0f;
      double cfsmid = calcFunc(cfs, mid);

      if(fabs(cfsmid) <= E){
	irr = mid;
	break;
      }
      if(cfsmid > E)
	low = mid;
      else
	high = mid;

    }

    printf("%1.2lf\n", irr);

    scanf("%d", &input);
  }
  
  return 0;
}
