#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<iterator>

using namespace std;

int main(){

  string test;
  vector<vector<string> > vecs;
  vector<int> sizes;
  while(getline(cin,test)){

    vector<string> vec;

    istringstream iss(test);
    copy(istream_iterator<string>(iss),
	 istream_iterator<string>(),
	 back_inserter(vec));
    
    vecs.push_back(vec);

    // if(sizes.size() < vec.size()){
    //   sizes.reserve(vec.size()-);
    //   sizes.resize(vec.size());
    // }

    for(int i = 0; i < vec.size(); i++){
      if(sizes.size() <= i)
	sizes.push_back(vec[i].size());
      else if(vec[i].size() > sizes[i])
	sizes[i] = vec[i].size();
    }
      
  }

  for(int k = 0; k < vecs.size(); k++){
    for(int i = 0; i < vecs[k].size(); i++){
      cout<<vecs[k][i];
      if(i != vecs[k].size()-1){
	if(vecs[k][i].size() < sizes[i]){
	  for(int j = vecs[k][i].size(); j < sizes[i]; j++)
	    cout<<" ";
	}
	cout<<" ";
      }
    }
      cout<<endl;
  }
    
  
  return 0;
}
