#include<bits/stdc++.h>

using namespace std;

struct request{
  string cor, tam, nome;
};

struct compare{
  inline bool operator() (const request &struct1, const request &struct2){
    if(struct1.cor > struct2.cor)
      return false;
    else if(struct1.cor < struct2.cor)
      return true;
    if(struct1.tam < struct2.tam)
      return false;
    else if(struct1.tam > struct2.tam)
      return true;
    if(struct1.nome > struct2.nome)
      return false;
    else if(struct1.nome < struct2.nome)
      return true;
    return true;
  }
};

int main(){

  int N;
  cin>>N;

  while(N){

    vector<struct request> all_requests;

    for(int i = 0; i < N; i++){
      struct request temp;
      //getline(cin, temp.nome);
      getchar();
      getline(cin, temp.nome);
      cin>>temp.cor>>temp.tam;
      all_requests.push_back(temp);
    }

    sort(all_requests.begin(), all_requests.end(), compare());

    for(int i = 0; i < N; i++)
      cout<<all_requests[i].cor<<" "<<all_requests[i].tam<<" "<<all_requests[i].nome<<endl;
          
    cin>>N;
    if(N)
      puts("");
  }

  return 0;
}
