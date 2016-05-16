#include <bits/stdc++.h>

using namespace std;

int main(){

  int km = 0, leak = 0, new_km = 0, new_leak = 0, aux = 0;
  double res = 0, final_res = 0;
  int finish = 0, gas = 0, consumption = 0, new_consumption = 0;
  string event;
  getline(cin, event);
  if(event.find("Fuel") > 0){
    new_km = strtol(event.c_str(), NULL, 10);
    consumption = atoi(event.substr(event.rfind(" ")).c_str());
    //consumption /= 100.0;
  }
  while(km || consumption && !event.empty()){

    if(finish){
      printf("%.03f\n", max(res, final_res));
      finish = gas = aux = 0;
      km = leak = new_km = new_leak = 0;
      res = final_res = consumption = new_consumption = 0.0;
    }
    if(gas){
      gas = 0;
      final_res = max(res, final_res);
      res = 0;
    }
    if(event.find("Fuel") != string::npos){
      new_km = strtol(event.c_str(), NULL, 10);
      new_consumption = atoi(event.substr(event.rfind(" ")).c_str());
      //new_consumption /= 100.0;
    }
    else if(event.find("Goal") != string::npos ){
      new_km = strtol(event.c_str(), NULL, 10);
      finish = 1;
    }
    else if(event.find("Leak") != string::npos){
      new_km = strtol(event.c_str(), NULL, 10);
      new_leak = leak + 1;
    }
    else if(event.find("Gas") != string::npos){
      new_km = strtol(event.c_str(), NULL, 10);
      gas = 1;
    }
    else if(event.find("Mechanic") != string::npos){
      new_km = strtol(event.c_str(), NULL, 10);
      new_leak = 0;
    }

    int dist = new_km - km;
    
    res = res + dist*leak + (dist*consumption)/100.0;
    km = new_km;
    leak = new_leak;
    consumption = new_consumption;    
    
    getline(cin, event);
  }

  return 0;
}
