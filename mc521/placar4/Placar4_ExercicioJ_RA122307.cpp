#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>

using namespace std;

string zero = "YYYYYYN",
  um = "NYYNNNN",
  dois = "YYNYYNY",
  tres = "YYYYNNY",
  quatro = "NYYNNYY",
  cinco = "YNYYNYY", 
  seis = "YNYYYYY", 
  sete = "YYYNNNN", 
  oito = "YYYYYYY", 
  nove = "YYYYNYY";

vector<string> original;
vector<int> queimado(7);

int fazPerm(string led, string target, vector<int> q){

  int res = 0;
  for (int i = 0; i < 7; i++){
    if(target[i] == 'Y' && queimado[i]){
      return 0;
    }
  }

  for (int i = 0; i < 7; i++){
    if(led[i] == 'Y' && queimado[i])
      led[i] = 'N';
  }
  string base = led;

  if(led == target){
    queimado = q;
    return 1;
  } 

  for (int i = 0; i < 7 && !res; i++){
    if(led[i] == 'Y'){
      led[i] = 'N';
      q[i] = 1;
      res = fazPerm(led, target, q);
      q[i] = 0;
      led = base;
    }
  }
  return res;
}

int verificaMenor(string led, int upperbound){
  //string ledLocal, temp;
  int cont, res;
  vector<int> q = queimado;

  vector<string>::reverse_iterator rit = original.rbegin();
  rit = rit+(9-upperbound);
  cont = upperbound;

  //for(; rit != original.rend(); rit++){
  res = fazPerm(*rit, led, q);
  if(res)
    return cont;
    // cont--;
    //}
  return -1;
}

int recursive(vector<string> leds, int inic, int i, int cases){

  vector<int> q = queimado;
  int res, res1;
  if((inic < 0 && i < cases) || i > cases)
    return 0;
  if(inic >= 0 && i == cases)
    return 1;

  if(inic >= 0){
    res = verificaMenor(leds[i], inic);
    if(res == -1){
      queimado = q;
      return 0;
    }
    else{
      if(res == 0 && i == cases-1 && inic == 0)
	return 1;
      res1 = recursive(leds, res-1, i+1, cases);
      if(!res1){
	inic = res-1;
	queimado = q;
      }
      else
	return res1;
    }
  }
  return 0;
}

int main(){

  int cases, res;
  string led;
  original.push_back(zero);
  original.push_back(um);
  original.push_back(dois);
  original.push_back(tres);
  original.push_back(quatro);
  original.push_back(cinco);
  original.push_back(seis);
  original.push_back(sete);
  original.push_back(oito);
  original.push_back(nove);

  res = 0;
  cases = 0;
  while(scanf("%d", &cases) != EOF && cases){
    vector<string> leds;

    for(int i = 0; i < cases; i++){
      cin>>led;
      leds.push_back(led);
      led.clear();
    }

    for(int i = 0; i < 7; i++)
      queimado[i] = 0;
    //queimado.clear();
    //vector<int> q = queimado;
    res = 0;
    for(int i = 9; i >= 0 && !res; i--)
      res = recursive(leds, i, 0, cases);
    
    if(!res)
      printf("MISMATCH\n"); 
    else
      printf("MATCH\n"); 
  }
  
  return 0;
}
