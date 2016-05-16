#include <cstdio>

int main(){

  long long int n, m;

  scanf("%lld %lld", &n, &m);

  long long int basemin, sobremin, mini, maxi, aux, num;

  aux = basemin = sobremin = mini = maxi = 0;
  
  num = (n - (m - 1)) - 1;

  maxi = ((1 + num) * num)/2;
  
  basemin = n/m;
  sobremin = n % m;
  
  num = basemin - 1;
  mini = ((1 + num) * num)/2;

  mini = mini * m;
  mini = mini + (basemin * sobremin);

  printf("%lld %lld\n", mini, maxi);

  return 0;
}
