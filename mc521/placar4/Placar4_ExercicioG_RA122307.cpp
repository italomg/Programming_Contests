#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int mini, n;

void backTrack(int base[8][8]){
  
  int escolhido[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  mini = 10000000;
  do {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += base[i][escolhido[i]];
    }
    mini = min(sum, mini);
  } while (next_permutation(escolhido, escolhido + n));

}


int main(){

  int cases;
  cin>>cases;

  while(cases--){

    cin>>n;

    int base[8][8] = {{0}};

    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
	cin>>base[i][j];


    backTrack(base);

    cout<<mini<<endl;
  }


  return 0;
}
