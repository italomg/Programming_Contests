#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<cctype>

using namespace std;

int tamSeq,queries;
int freq[200005];
int inicPos[200005];
int seqInput[200005];
int sTree[1000000];

void montaArvore(int nodeNumber , int inic, int fim){

  if(inic == fim) {
    sTree[nodeNumber] = freq[seqInput[inic]];
    return ;
  }

  int md = (inic + fim) / 2;
  int n1 = (2 * nodeNumber) + 1;
  int n2 = n1 + 1;
  montaArvore(n1, inic , md) ;
  montaArvore(n2, md + 1, fim);


  if(sTree[n1] >= sTree[n2]) 
    sTree[nodeNumber] = sTree[n1];
  else 
    sTree[nodeNumber] = sTree[n2];
}

int makeQuery(int nodeNumber, int inic, int fim, int inic1, int fim2) {

  int ret ;

  if(fim < inic1 || inic > fim2) 
    return -1;
  if(inic >= inic1 && fim <= fim2) 
    return sTree[nodeNumber];

  int noesq = (2 * nodeNumber) + 1;
  int nodir = (2 * nodeNumber) + 2;
  int meio = (inic + fim) / 2;
  int res1 = makeQuery(noesq, inic, meio , inic1, fim2);
  int res2 = makeQuery(nodir, meio + 1, fim, inic1, fim2);
  if(res1 == -1) 
    ret = res2;
  if(res2 == -1) 
    ret = res1;
  if(res1 >= res2) 
    ret = res1;
  else 
    ret = res2;
  return ret;
}

int main(){

  int i;
  while(scanf("%d", &tamSeq) == 1) {

    if(tamSeq == 0) 
      break;

    scanf("%d", &queries);
    memset(freq, 0, sizeof(freq));
    memset(inicPos, -1, sizeof(freq));


    for(i = 0; i < tamSeq; i ++) {
      scanf("%d", &seqInput[i]) ;
      seqInput[i] += 100000;
      freq[seqInput[i]] ++ ;
      if(freq[seqInput[i]] == 1) 
	inicPos[seqInput[i]] = i;
   
    }


    montaArvore(0, 0, tamSeq - 1);
    int nInp1,nInp2;
    for(i = 0; i < queries; i ++) {
      scanf("%d %d", &nInp1, &nInp2);
      nInp1--;
      nInp2--;
      if(seqInput[nInp1] == seqInput[nInp2]) {
	printf("%d\n", nInp2 - nInp1 + 1);
	continue;
      }
   
      int resp ;
      int op1 = freq[seqInput[nInp1]] - nInp1 + inicPos[seqInput [nInp1]];
      int op2 = nInp2 - inicPos[seqInput[nInp2]] + 1;

      if(op1 > op2) 
	resp = op1;
      else 
	resp = op2;

      int lim1 = inicPos[seqInput[nInp1]] + freq[seqInput[nInp1]] ;
      int lim2 = inicPos[seqInput[nInp2]] - 1;
      if(lim1 <= lim2) {
	int var = makeQuery(0, 0, tamSeq - 1, lim1, lim2);
	if(var > resp) 
	  resp = var;     
      }

      printf("%d\n", resp);

    }

  }
  return 0;
}
