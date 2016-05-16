#include<iostream>

using namespace std;


int main(){

  long int R, C, N, aux, arifR, arifC;
  int no = 0;
  long int r[10005], c[10005];
  cin>>R>>C>>N;
  while(R != 0 && C != 0 && N != 0){
    for(long int k = 0; k < R+2; k++){
      r[k] = 0;
      c[k] = 0;
    }
    for(long int k = 0; k < N; k++){
      cin>>aux;
      r[aux+1] = 1;
      cin>>aux;
      c[aux+1] = 1;
    }
    r[0] = 1;
    r[R+1] = 1;
    c[0] = 1;
    c[C+1] = 1;
    cin>>arifR>>arifC;
    no++;
    arifR++;
    arifC++;
    if((!r[arifR] && !c[arifC]) || (!r[arifR-1] && !c[arifC]) || (!r[arifR+1] && !c[arifC]) || (!r[arifR] && !c[arifC-1]) || (!r[arifR] && !c[arifC+1]))
      cout<<"Case "<<no<<": Escaped again! More 2D grid problems!"<<endl;
    else
      cout<<"Case "<<no<<": Party time! Let's find a restaurant!"<<endl;
    cin>>R>>C>>N;
  }

}
