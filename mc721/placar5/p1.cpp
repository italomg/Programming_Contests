#include<bits/stdc++.h>

using namespace std;

int main(){

  map<string, char> morse = {{".-", 'A'}, 
			     {"-...", 'B'},
			     {"-.-.", 'C'},
			     {"-..", 'D'},
			     {".", 'E'},
			     {"..-.", 'F'},
			     {"--.", 'G'},
			     {"....", 'H'},
			     {"..", 'I'},
			     {".---", 'J'},
			     {"-.-", 'K'},
			     {".-..", 'L'},
			     {"--", 'M'},
			     {"-.", 'N'},
			     {"---", 'O'},
			     {".--.", 'P'},
			     {"--.-", 'Q'},
			     {".-.", 'R'},
			     {"...", 'S'},
			     {"-", 'T'},
			     {"..-", 'U'},
			     {"...-", 'V'},
			     {".--", 'W'},
			     {"-..-", 'X'},
			     {"-.--", 'Y'},
			     {"--..", 'Z'},
			     {"-----", '0'},
			     {".----", '1'},
			     {"..---", '2'},
			     {"...--", '3'},
			     {"....-", '4'},
			     {".....", '5'},
			     {"-....", '6'},
			     {"--...", '7'},
			     {"---..", '8'},
			     {"----.", '9'},
			     {".-.-.-", '.'},
			     {"--..--", ','},
			     {"..--..", '?'},
			     {".----.", '\''},
			     {"-.-.--", '!'},
			     {"-..-.", '/'},
			     {"-.--.", '('},
			     {"-.--.-", ')'},
			     {".-...", '&'},
			     {"---...", ':'},
			     {"-.-.-.", ';'},
			     {"-...-", '='},
			     {".-.-.", '+'},
			     {"-....-", '-'},
			     {"..--.-", '_'},
			     {".-..-.", '"'},
			     {".--.-.", '@'}};

  int message = 1, test = 0, last_space = 0;
  char morse_char;
  cin>>test;
  getchar();
  while(test--){

    string symb, res;
    morse_char = getchar();
    while(morse_char != '\n'){

      if(morse_char == ' ' && last_space){
	res += ' ';
	last_space = 0;
      }
      else if(morse_char == ' '){
	res += morse[symb];
	last_space = 1;
	symb = "";
      }
      else{
	symb += morse_char;
	last_space = 0;
      }      

      morse_char = getchar();
    }

    res += morse[symb];
    printf("Message #%d\n", message++);
    for(int k = 0; k < res.size(); k++){
      if(res[k])
	printf("%c", res[k]);
    }
    puts("");
    //cout<<"Message #"<<message++<<endl<<res<<endl;
    if(test)
      puts("");
  }


  return 0;
}
