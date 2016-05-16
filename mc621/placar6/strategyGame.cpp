#include <cstdio>
#include <vector>

using namespace std;

int main(){

  int J, R, points, winner;

  while(scanf("%d %d", &J, &R) != EOF){
    vector<int> players(J);
    for(int i = 0; i < J*R; i++){
      scanf("%d", &points);
      players[i%J] += points;
    }

    points = winner = 0;
    for(int i = J-1; i >= 0; i--){
      if(players[i] > points){
	points = players[i];
	winner = i;
      }
    }

    printf("%d\n", winner+1);
  }

  return 0;
}
