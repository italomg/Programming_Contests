#include<cstdio>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

bool comparaPos(pair<int,int> i, pair<int,int> j){
  return i.second < j.second;
}

int main(){

  int N, M, input, res, sizes, count;
  scanf("%d %d", &M, &N);
  while(M != 0 || N != 0){
    vector<int> teams(M);
    vector<pair<int, int> >tables(N);
    vector<vector<int> > resp(M);
    res = 1;
    sizes = N;
    for(int i = 0; i < M; i++){
      scanf("%d", &input);
      teams[i] = input;
    }
    for(int i = 0; i < N; i++){
      scanf("%d", &input);
      tables[i] = pair<int, int>(input, i);
    }
    //sort(teams.begin(), teams.end(), greater<pair<int,int> >());
    sort(tables.begin(), tables.end(), greater<pair<int,int> >());
    for(int i  = 0; i < M; i++){
      if(teams[i] <= sizes){
	count = 1;
	for(int j = 0; j < N && count <= teams[i]; j++){
	  if(tables[j].first){
	    tables[j].first--;
	    if(!tables[j].first)
	      sizes--;
	    resp[i].push_back(tables[j].second);
	    count++;
	  }
	}
      }
      else{
	res = 0;
	break;
      }
    }
    
    if(res){
      printf("1\n");
      for(int i = 0; i < M; i++){
	sort(resp[i].begin(), resp[i].end());
	for(int j = 0; j < resp[i].size(); j++){
	  if(j == resp[i].size()-1)
	    printf("%d\n", resp[i][j]+1);
	  else
	    printf("%d ", resp[i][j]+1);
	}
      }
    }
    else
      printf("0\n");
    scanf("%d %d", &M, &N);
  }
  return 0;
}
