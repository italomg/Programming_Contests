#include<iostream>
#include<cstring>

using namespace std;

int main(){

  long long int tests, prolen, bralen, n;
  char prohib[100], invprohib[100];
  char bracel[20200];
  cin>>tests;

  while(tests--){
    cin>>prohib;
    cin>>bracel;
    prolen = strlen(prohib);
    bralen = strlen(bracel);
    
    //inverte seq proibida
    for(int i = 0; i < prolen; i++){
      invprohib[i] = prohib[prolen-1-i];
    }

    //cout<<prohib<<endl;
    //cout<<invprohib<<endl;
    //cout<<bralen<<endl;
    //escolhe qual seq tem menor lenght
    n = prolen;
    if(prolen > bralen)
      n = bralen;
    strncat(bracel,bracel,n);
    
    //faz o busca por seq proibida no bracel
    if(strstr(bracel,prohib) || strstr(bracel,invprohib))
      cout<<"S"<<endl;
    else
      cout<<"N"<<endl;
    
    for(int i = 0; i < prolen; i++)
      invprohib[i] = 0;
    
  }

  return 0;

}
