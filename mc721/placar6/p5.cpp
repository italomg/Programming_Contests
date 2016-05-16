#include <bits/stdc++.h>

using namespace std;

vector<int> roman_val = {1, 5, 10, 50, 100, 500, 1000};
vector<int> roman_sub = {0, 1, 1, 10, 10, 100, 100};
map<int, char> roman_map = {{1, 'I'},
			      {5, 'V'},
			      {10, 'X'},
			      {50, 'L'},
			      {100, 'C'},
			      {500, 'D'},
			      {1000, 'M'}};

map<char, int> roman_map_inv = {{'I', 1},
				{'V', 5},
				{'X', 10},
				{'L', 50},
				{'C', 100},
				{'D', 500},
				{'M', 1000}};

string arabic2roman(int arabic){
  string res = "";
  int original = arabic, multiplier = 1000;

  do{
    arabic = (original/multiplier) * multiplier;
    multiplier /= 10;
  }while(arabic == 0);
  original -= arabic;
  
  do{
    while(arabic){
      
      for(int i = 6; i >= 0; i--){
	if(roman_val[i] - roman_sub[i] == arabic){
	  arabic -= roman_val[i] - roman_sub[i];
	  res += roman_map[roman_sub[i]];
	  res += roman_map[roman_val[i]];
	  break;
	}
	else if(roman_val[i] <= arabic){
	  arabic -= roman_val[i];
	  res += roman_map[roman_val[i]];
	  break;
	}
      }
    }

    if(multiplier){
      arabic = (original/multiplier) * multiplier;
      original -= arabic;
      multiplier /= 10;
    }
  }while(original || arabic);
  return res;
}

int roman2arabic(string roman){
  int res = 0;

  for(int i = 0; i < roman.size()-1; i++){
    if(roman_map_inv[roman[i]] < roman_map_inv[roman[i+1]])
      res -= roman_map_inv[roman[i]];
    else
      res += roman_map_inv[roman[i]];
  }
  res += roman_map_inv[roman[roman.size()-1]];
  return res;
}

int main(){

  string input;

  while(cin>>input){
    //cout<<input<<endl;
    if(input[0] == 'I' 
       || input[0] == 'V'
       || input[0] == 'X'
       || input[0] == 'L'
       || input[0] == 'C'
       || input[0] == 'D'
       || input[0] == 'M')
      cout<<roman2arabic(input)<<endl;
    else
      cout<<arabic2roman(stoi(input,NULL))<<endl;
       }


  return 0;
}
