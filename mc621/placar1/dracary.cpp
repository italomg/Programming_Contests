#include<cstdio>

using namespace std;

int main(){

  int ld, cd, lv, cv;
  long long int r1 = 0, r2 = 0, r3 = 0, r4 = 0, r5 = 0, r6 = 0, res = 0;

  scanf("%d %d %d %d", &ld, &cd, &lv, &cv);

  r1 = (long long)ld * (long long)cd;
  r2 = (long long)ld * (long long)lv;
  r3 = (long long)ld * (long long)cv;
  r4 = (long long)cd * (long long)lv;
  r5 = (long long)cd * (long long)cv;
  r6 = (long long)lv * (long long)cv;

  if(ld == cd && res < r1)
    res = r1;
  if(ld == lv && res < r2)
    res = r2;
  if(ld == cv && res < r3)
    res = r3;
  if(cd == lv && res < r4)
    res = r4;
  if(cd == cv && res < r5)
    res = r5;
  if(lv == cv && res < r6)
    res = r6;
  

  // for(int i = 0; i < 4; i++)
  //   for(int j = i+1; j < 4; j++)
  //     if(c[i] == c[j] && big < c[i]*c[j])
  // 	big = c[i]*c[j];
      

  printf("%lld", res);

  return 0;
}
