#include<iostream>
#include<vector>
#include<utility>

using namespace std;


int main(){

  long int m, n, cols, cont, ind, valo;
  while(cin>>m>>n){

    vector<vector<pair<int, int> > > matrix;
    
    for(long int i = 1; i <= m; i++){
      cin>>cols;
      pair<int, int> temp (0, 0);
      vector<pair<int, int> > indices;
      if(cols != 0){
	for(long int j = 1; j <= cols; j++){
	  cin>>ind;
	  get<0>(temp) = ind;
	  get<1>(temp) = 99999;
	  indices.push_back(temp);
	}
	for(vector<pair<int, int> >::iterator it = indices.begin(); it != indices.end(); it++)
	  cin>>get<1>(*it);
      }
      else{
	// get<0>(temp);
	// get<1>(temp) = 99999;
	indices.push_back(temp);
      }
      matrix.push_back(indices);
    }

    // cout<<endl;
    // for(long int i = 0; i < m; i++){
    //   for(vector<pair<int, int> >::iterator it = matrix[i].begin(); it != matrix[i].end(); it++)
    // 	cout<<get<1>(*it)<<" ";
    //   cout<<endl;
    // }
    // cout<<endl;

 
    cout<<n<<" "<<m<<endl;
    for(long int i = 1; i <= n; i++){
      cont = 0;
      vector<int> val;
      vector<int> indices;
      for(long int j = 0; j < m; j++){
	if(get<0>(*matrix[j].begin()) == i){
	  cont++;
	  val.push_back(get<1>(*matrix[j].begin()));
	  indices.push_back(j+1);
	  matrix[j].erase(matrix[j].begin());
	}
      }
      if(cont == 0)
    	cout<<cont<<endl<<endl;
      else{
    	cout<<cont<<" ";
	
    	for(vector<int>::iterator it = indices.begin(); it != indices.end(); it++){
    	  if(it+1 == indices.end())
    	    cout<<*it<<endl;
    	  else
    	    cout<<*it<<" ";
    	}
    	for(vector<int>::iterator it = val.begin(); it != val.end(); it++){
    	  if(it+1 == val.end())
    	    cout<<*it<<endl;
    	  else
    	    cout<<*it<<" ";
    	}
      }
    }
  }
  return 0;
}
