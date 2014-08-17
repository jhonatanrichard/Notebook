/* 

Autor: Jhonatan Ríchard Raphael
Data: 10/07/2012

Algoritmo: DFS (depth-first-search)
Descrição: Visita todos os vértices de um grafo em profundidade. Imprime o caminho da busca a partir do vértice 's'.
Complexidade: O(V+E)

Estrutura de Dados: lista de adjacências
Início Indexação vetor: 1
Observação: supõe-se grafo conexo.

*/ 


#include <stdio.h>
#include <string.h>

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>

#define INF 0x3f3f3f3f
#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define MAX 101

#define vi vector<int>

using namespace std;



int pai[MAX];
int cor[MAX];
int descob[MAX];
int final[MAX];

int n,m;
int tempo = 0;


// Visita um vértice
void visit(vi G[],int s)
{
	unsigned int i;

	tempo++;
	descob[s] = tempo;
	cor[s] = 1;

	for(i=0;i<G[s].size();i++)
		if(cor[  G[s][i]  ] == 0)
		{
			pai[  G[s][i]  ] = s;
			visit(G,G[s][i]);
		}
		
	cor[s] = 2;
	tempo++;
	final[s] = tempo;
}

// Busca em profundidade
void dfs(vi G[])
{
	// inicializa os predecessores e as cores dos vértices
	memset(pai+1,-1,n*4);
	memset(cor+1,0,n*4);		
	
	tempo = 0;

	for(int i=1;i<=n;i++)
		if(cor[i] == 0)
			visit(G,i);
}
