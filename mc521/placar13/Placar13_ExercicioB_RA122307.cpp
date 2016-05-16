#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<cstdlib>

#define MAX 1024

using namespace std;

//No do grafo original
struct node{
  int D, C, F;
};

//No do grafo residual que aponta pro proximo
struct nodef{
  int D, C, prox;
};

//Estrutura do vetor de pais
struct pap{
  int O, D, C;
};

void insere(int *first, int *last, int cur, int tpap, struct nodef *Gf[MAX]);
void remove(int *first, int *last, int cur, int tpap, struct nodef *Gf[MAX]);

int main(){

  int V, E, O, D, o, d, c, path = 1, f, C, total;
  ///////////////////////// INICIALIZACAO //////////////////////////////////////////
  scanf("%d %d", &C, &V);
  while(C != 0 || V != 0){
    struct node temp;
    struct nodef tempf;
    struct node **G;
    G = (struct node**)malloc(MAX*sizeof(*G));
    for(int i = 0; i < MAX; i++){
      G[i] = (struct node*)malloc(MAX*sizeof(*G[i]));
      memset(G[i], -1, MAX*sizeof(struct node*));
    }

    struct nodef **Gf;
    Gf = (struct nodef**)malloc(MAX*sizeof(*Gf));
    for(int i = 0; i < MAX; i++){
      Gf[i] = (struct nodef*)malloc(MAX*sizeof(*Gf[i]));
      memset(Gf[i], -1, MAX*sizeof(struct nodef*));
    }

    int first[MAX], last[MAX];
  
    memset(first, -1, MAX*sizeof(int));
    memset(last, -1, MAX*sizeof(int));
    total = 0;
    for(int i = 1; i <= C; i++){
      scanf("%d", &c);
      total += c;
      //temp.O = o;
      temp.D = i;
      temp.C = c;
      temp.F = 0;

      //tempf.O = o;
      tempf.D = i;
      tempf.C = c;
      tempf.prox = -1;

      if(first[0] == -1){
	first[0] = i;
      }
      else{
	if(last[0] == -1){
	  Gf[0][first[0]].prox = i;
	}
	else{
	  Gf[0][last[0]].prox = i;
	}
	last[0] = i;
      
      }
      G[0][i] = temp;
      Gf[0][i] = tempf;
    }


    //Lendo a entrada tanto para o Grafo G quanto para o Grafo Gf
    for(int i = C+1; i <= V+C; i++){
      scanf("%d", &c);
      for(int j = 0; j < c; j++){
	scanf("%d", &o);
	//temp.O = o;
	temp.D = i;
	temp.C = MAX;
	temp.F = 0;

	//tempf.O = o;
	tempf.D = i;
	tempf.C = MAX;
	tempf.prox = -1;

	if(first[o] == -1){
	  first[o] = i;
	}
	else{
	  if(last[o] == -1){
	    Gf[o][first[o]].prox = i;
	  }
	  else{
	    Gf[o][last[o]].prox = i;
	  }
	  last[o] = i;
      
	}
	G[o][i] = temp;
	Gf[o][i] = tempf;
      }

      temp.D = V+C+1;
      temp.C = 1;
      temp.F = 0;
    
      //tempf.O = o;
      tempf.D = V+C+1;
      tempf.C = 1;
      tempf.prox = -1;

      if(first[i] == -1){
	first[i] = V+C+1;
      }
      else{
	if(last[i] == -1){
	  Gf[i][first[i]].prox = V+C+1;
	}
	else{
	  Gf[i][last[i]].prox = V+C+1;
	}
	last[i] = V+C+1;
      
      }
      G[i][V+C+1] = temp;
      Gf[i][V+C+1] = tempf;
    }
    path = 1;
    ///////////////////////// INICIALIZACAO //////////////////////////////////////////
    O = 0;
    D = V+C+1;
    do{
    
      queue<int> Q; //Queue para o BFS
      int cor[MAX], cur = O, alpha, found; //cor para o BFS, found para saber se existe caminho
      struct pap pai[MAX]; //Vetor que matera o caminho obtido

      memset(pai, -1, MAX*sizeof(struct pap));
      memset(cor, 0, MAX*sizeof(int));
      found = path = 0;
      alpha = MAX;
      Q.push(cur);
      vector<struct node>::iterator it;
      vector<struct nodef>::iterator itf;

      ////////////////////////////// BFS /////////////////////////////////////////////
      while(!Q.empty()){
	cur = Q.front();
	Q.pop();
	cor[cur] = 1;
	if(cur == D){
	  path = 1;
	  break;
	}
	for(int i = first[cur]; i != -1; i = Gf[cur][i].prox){//itf = Gf[cur].begin(); itf != Gf[cur].end(); itf++){

	  if(!cor[i]){
	    if(pai[i].C == -1 && Gf[cur][i].C != -1){
	      pai[i].O = cur;
	      pai[i].D = i;
	      pai[i].C = Gf[cur][i].C;
	      Q.push(i);
	    }
	  }
	}
      }
      ////////////////////////////// BFS /////////////////////////////////////////////


      if(path){
	//Acha o alpha
	cur = D;
	while(cur != O){
	  alpha = min(alpha, pai[cur].C);
	  cur = pai[cur].O;
	}

	//Verifica condicoes e
	//Atualiza o grafo orignal G
	cur = D;
	while(cur != O){
	  int tpap = pai[cur].O;
	  if(G[tpap][cur].C != -1){
	    G[tpap][cur].F += alpha;
	    if(G[tpap][cur].F > 0){

	      insere(first, last, cur, tpap, Gf);

	      Gf[cur][tpap].D = tpap;
	      Gf[cur][tpap].C = G[tpap][cur].F;
	    
	    }
	    else{
	      if(Gf[cur][tpap].C != -1)
		remove(first, last, cur, tpap, Gf);
	    }
	    if(G[tpap][cur].F < G[tpap][cur].C && G[tpap][cur].F != -1){

	      insere(first, last, tpap, cur, Gf);

	      Gf[tpap][cur].D = cur;
	      Gf[tpap][cur].C = G[tpap][cur].C - G[tpap][cur].F;
	    }
	    else{
	      if(Gf[tpap][cur].C != -1)
		remove(first, last, tpap, cur, Gf);
	    }
	  }

	  if(G[cur][tpap].D == tpap){
	    G[cur][tpap].F -= alpha;
	    if(G[cur][tpap].F > 0){

	      insere(first, last, tpap, cur, Gf);

	      Gf[tpap][cur].D = cur;
	      Gf[tpap][cur].C = G[cur][tpap].F;
	    }
	    else{
	      if(Gf[tpap][cur].C != -1)
		remove(first, last, tpap, cur, Gf);
	    }
	    if(G[cur][tpap].F < G[cur][tpap].C && G[cur][tpap].F != -1){

	      insere(first, last, cur, tpap, Gf);

	      Gf[cur][tpap].D = tpap;
	      Gf[cur][tpap].C = G[cur][tpap].C - G[cur][tpap].F;
	    }
	    else{
	      if(Gf[cur][tpap].C != -1)
		remove(first, last, cur, tpap, Gf);
	    }

	  }
	
	  cur = tpap;
	}

      }

    }  while(path); //enquanto houver caminho no grafo residual
  
    int flag = 1;
    f = 0;
    for(int i = 0; i < V; i++)
      if(G[O][i].F != -1)
	f += G[O][i].F;


    if(f == total){
      printf("1\n");
      for(int k = 1; k <= C; k++){
	for(int i = C+1; i <= V+C; i++){
	  if(Gf[i][k].C > 0){
	    if(!flag)
	      putc(' ', stdout);
	    printf("%d", i-C);
	    flag = 0;
	  }
	}
	puts("");
	flag = 1;
      }
    }
    else
      printf("0\n");
    scanf("%d %d", &C, &V);
  }
  
  //Soma os fluxos do vertice de origem

  // printf("\n%d\n", f);

  return 0;
}

void insere(int *first, int *last, int cur, int tpap, struct nodef *Gf[MAX]){
  if(Gf[cur][tpap].C == -1){
    Gf[cur][tpap].prox = -1;
    if(first[cur] == -1){
      first[cur] = tpap;
    }
    else{
      if(last[cur] == -1){
	Gf[cur][first[cur]].prox = tpap;
      }
      else{
	Gf[cur][last[cur]].prox = tpap;
      }
      last[cur] = tpap;
    }
  }
}

void remove(int *first, int *last, int cur, int tpap, struct nodef *Gf[MAX]){
  if(tpap == first[cur]){
    first[cur] = Gf[cur][tpap].prox;
  }
  else{
    for(int i = first[cur]; i != -1; i = Gf[cur][i].prox){
      if(Gf[cur][i].prox == tpap){
	Gf[cur][i].prox = Gf[cur][tpap].prox;
	if(tpap == last[cur]){
	  last[cur] = Gf[cur][i].prox;
	}
	break;
      }
    }
  } 	    
  Gf[cur][tpap].prox = -1;
  Gf[cur][tpap].C = -1;
  Gf[cur][tpap].D = -1;
}
