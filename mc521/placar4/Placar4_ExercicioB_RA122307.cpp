#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main(){

  long long int bins[9];
  //cin>>c1>>g1>>b1>>c2>>g2>>b2>>c3>>g3>>b3
  unsigned long long int sum, mini;
  int p1, p2, p3;
  char ch1, ch2, ch3;
  char lix[3] = {'B', 'G', 'C'};
  char str1[3], str2[3];
  while(cin>>bins[0]>>bins[1]>>bins[2]>>bins[3]>>bins[4]>>bins[5]>>bins[6]>>bins[7]>>bins[8]){
    ch1 = 'Z';
    ch2 = 'Z';
    ch3 = 'Z';
    mini = -1;
    sum = -1;
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
	if(j != i){
	  p1 = i;
	  p2 = j+3;
	  p3 = (3-i-j)+6;
	  sum = 0;
	  for(int k = 0; k < 9; k++){
	    if(k != p1 && k != p2 && k != p3){
	      sum += bins[k];
	    }
	  }
	}
	if(sum == mini){
	  str1[0] = ch1;
	  str1[1] = ch2;
	  str1[2] = ch3;
	  str2[0] = lix[p1];
	  str2[1] = lix[p2%3];
	  str2[2] = lix[p3%3];	  
	  if(strncmp(str1, str2, 3)>0){
	    ch1 = lix[p1];
	    ch2 = lix[p2%3];
	    ch3 = lix[p3%3];
	  }
	}
	else if(sum < mini){
	  mini = sum;
	  ch1 = lix[p1];
	  ch2 = lix[p2%3];
	  ch3 = lix[p3%3];
	}
      }
    }
    cout<<ch1<<ch2<<ch3<<" "<<mini<<endl;
  }
  
  return 0;
}
