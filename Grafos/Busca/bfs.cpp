/* 

Autor: Jhonatan Ríchard Raphael
Data: 10/07/2012

Algoritmo: BFS (breadth-first-search)
Descrição: Visita todos os vértices de um grafo em largura. Imprime o caminho da busca a partir do vértice 's'.
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

int n,m;

int pai[MAX];
int cor[MAX];
int dist[MAX];

// Busca em largura
void bfs(vi G[], int s)
{
	queue<int> Q;
	unsigned int u,i;

	// inicializa os predecessores, cor do vértice e distância da origem
	memset(pai+1,-1,n*4);
	memset(cor+1,0,n*4);		
	memset(dist+1,INF,n*4);

	// inicializa os valores da origem
	pai[s] = s;
	cor[s] = 1;	// cor cinza
	dist[s] = 0;

	Q.push(s);
	while( Q.empty() == 0)
	{
		// desinfileira
		u = Q.front();
		Q.pop();

		for(i=0;i<G[u].size();i++)
			if(cor[  G[u][i]  ] == 0)	// se cor branca
			{
				// atualiza as informações
				cor[  G[u][i]  ] = 1;	
				dist[  G[u][i]  ] = dist[u] + 1;
				pai[  G[u][i]  ] = u;

				// enfileira
				Q.push( G[u][i] );
			}
		cor[u] = 2;	// cor preta
	}
}

// Imprime o caminho entre s e v, se houver.
void path(vi G[],int s,int v)
{
	if(v == s)	
		printf("%d ",s);
	else
		if(pai[v] == -1)
			printf("Não existe caminho entre %d e %d\n",s,v);
		else
		{
			path(G,s,pai[v]);
			printf("%d ",v);
		}
}
