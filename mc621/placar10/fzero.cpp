#include <cstdio>

int main(){

  long long unsigned low, max;

  while(scanf("%llu %llu", &low, &max) != EOF && (low || max)){
    long long unsigned ldiv, mdiv, lval, mval, lzero, mzero, res, diff;

    lval = low/5;
    mval = max/5;

    res = (mval - lval) + 1;

    printf("%llu\n", res);
  }

  return 0;
}
