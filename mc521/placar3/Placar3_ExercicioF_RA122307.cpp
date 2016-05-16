#include<iostream>

using namespace std;

int amigo, inimigo;

int findLider(int *people, int p){
  if(people[p] == p)
    return p;
  return findLider(people, people[p]);
}

void setFriends(int *people, int p1, int p2){
  if(people[p1] == 0 && people[p2] == 0){
    people[p1] = p1;
    people[p2] = p1;
  }
  else if(people[p1] == 0)
    people[p1] = people[p2];
  else if(people[p2] == 0)
    people[p2] = people[p1];
  else if((people[p1] == amigo && people[p2] == inimigo) || (people[p2] == amigo && people[p1] == inimigo))
    cout<<-1<<endl;
  else{
    if(people[p1] == amigo || people[p1] == inimigo)
      people[p2] = people[p1];
    else
      people[p1] = people[p2];
  }
}

void setEnemies(int *people, int p1, int p2){
  if(people[p1] == 0 && people[p2] == 0){
    people[p1] = p1;
    people[p2] = p2;
  }
  else if(people[p1] == people[p2])
    cout<<-1<<endl;
  else if(people[p2] == amigo)
    people[p1] = inimigo;
  else if(people[p2] == inimigo)
    people[p1] = amigo;
  else if(people[p1] == amigo)
    people[p2] = inimigo;
  else if(people[p1] == inimigo)
    people[p2] = amigo;

}

int areFriends(int *people, int p1, int p2){
  if(!people[p1] && !people[p2])
    return 0;
  if(people[p1] == people[p2])
    return 1;
  return 0;
}

int areEnemies(int *people, int p1, int p2){
  if(!people[p1] && !people[p2])
    return 0;
  if(people[p1] == people[p2])
    return 0;
  return 1;  
}


int main(){
  
  int nmbPeople, cmd, p1, p2;
  int people[10005] = {0};
  cin>>nmbPeople;
  cin>>cmd>>p1>>p2;
  amigo = -1;
  inimigo = -1;
  while(cmd != 0 && p1 != 0 && p2 != 0){

    switch(cmd){
    case 1:
      if(amigo == -1)
	amigo = p1;
      setFriends(people, p1, p2);
      break;
    case 2:
      if(inimigo == -1 && amigo == -1){
	inimigo = p1;
	amigo = p2;
      }
      else if(inimigo == -1 && p1 != amigo)
	inimigo = p1;
      else if(inimigo == -1 && p2 != amigo)
	inimigo = p2;
      else{
	cout<<-1<<endl;
	break;
      }	
      setEnemies(people, p1, p2);
      break;
    case 3:
      areFriends(people, p1, p2);
      break;
    case 4:
      areEnemies(people, p1, p2);
      break;
    default:
      break;
    }
    cin>>cmd>>p1>>p2;
  }

  return 0;
}
