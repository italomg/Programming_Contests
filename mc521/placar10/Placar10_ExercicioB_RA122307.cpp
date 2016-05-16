#include<cstdio>
#include<cstring>
#include<stack>

using namespace std;


int main(){

  char input[135];
  int tests, correct;
  bool flag;
  scanf("%d", &tests);
  getchar();
  while(tests--){
    stack<char> q;// cha<char>;
    memset(input, 0, 135*sizeof(char));
    fgets(input, 135, stdin);
    
    //scanf("%s", input);
    flag = false;
    for(int i = 0; input[i] != '\n' && input[i] != '\0'; i++){
      if(input[i] == '(' || input[i] == '[')
	q.push(input[i]);
      else if(input[i] == ')' && q.size() && q.top() == '(')
	  q.pop();
      else if(input[i] == ']' && q.size() && q.top() == '[')
	  q.pop();
      else
	flag = true;
    }
    if(q.empty() && !flag)
      printf("Yes\n");
    else
      printf("No\n");
  }  

  return 0;
}
