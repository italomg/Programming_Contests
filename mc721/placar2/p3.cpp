#include<bits/stdc++.h>

using namespace std;

int main(){

  int N;
  cin>>N;

  while(N){

    priority_queue<int, vector<int>, std::greater<int> > numbers;
    int top1, top2, input, sum, cost = 0;
    
    for(int i = 0; i < N; i++){
      cin>>input;
      numbers.push(input);
    }

    while(numbers.size() > 1){
      top1 = numbers.top();
      numbers.pop();
      top2 = numbers.top();
      numbers.pop();

      sum = top1 + top2;
      numbers.push(sum);

      cost += sum;
    }
    cout<<cost<<endl;
    cin>>N;
  }

  return 0;
}
