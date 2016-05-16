#include<iostream>
#include<string>
#include<deque>
#include<list>

using namespace std;

string origin, dest;

void calcStack(deque<char> output, deque<char> stack, string rest, int pdest, int porig){

  if(output.size() == dest.size()*2){
    if(rest == dest)
      for(deque<char>::iterator it = output.begin(); it < output.end(); it++){
	if(it == output.end()-1)
	  cout<<*it<<endl;
	else
	  cout<<*it<<" ";
      }
    return;
  }

  int flag = 0;
  if((int)origin.find(dest[pdest], porig) >= 0){
    output.push_back('i');
    stack.push_back(origin[porig]);
    calcStack(output, stack, rest, pdest, porig+1);
    flag = 1;
  }
  if(flag){
    output.pop_back();
    stack.pop_back();
  }
  if(stack.size() > 0 && stack.back() == dest[pdest]){
    output.push_back('o');
    rest.push_back(stack.back());
    stack.pop_back();
    calcStack(output, stack, rest, pdest+1, porig);
  }

}

int main(){

  deque<char> output;
  string rest;
  deque<char> stack;

  while(cin>>origin>>dest){
    cout<<"[\n";
    if(origin.size() == dest.size())
      calcStack(output, stack, rest, 0, 0);
    cout<<"]\n";
  }

  return 0;
}
