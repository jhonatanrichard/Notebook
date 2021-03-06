/* 

Autor: Jhonatan Ríchard Raphael
Data: 15/07/2012
Descrição: Encontra o vértice centro da árvore (esse conjunto de vértices centro pode ter tamanho 1 ou 2). 

Obs.: Um vértice centro v possui a excentrecidade mínima na árvore, ou seja, sua localização na árvore faz com que a distancia dos outros vértices para v seja mínima.

Solução: remove todos os nós folhas do grafo utilizando DFS até que haja 1 ou 2 vértices restantes.
Início indexação vetor: 1
Complexidade: ? ... Ω(V+E) e O(V²+E)

*/ 


#include <stdio.h>
#include <string.h>

#include <vector>
#include <iostream>

using namespace std;

#define MAX 101

vector<int> G[MAX];
int centro[MAX];
int vis[MAX];

int n;		// número de vértices 

void dfs(int s,int nivel,int &restante)
{
	unsigned int i;
	int v;
	
	bool folha = true;	// admite-se que esse vértice é uma folha
	int nfilhos = 0;	// numero de vertices adjacentes de um nó

	vis[s] = 1;

	for(i=0;i<G[s].size();i++)
	{
		v = G[s][i];
		
		if(vis[v] == 0 && centro[v] == 0)	// se não foi visitado e não foi excluído
		{
			folha = false;	// raiz não é um vértice folha
			
			if(nivel == 0)	// se sou a raiz, marco quantos filhos eu tenho
				nfilhos++;
				
			dfs(v,nivel+1,restante);	
		}
	}
	if(folha)	// se é uma folha
	{
		centro[s] = 1;	// exclui o vértice s do conjunto de vértices centro
		restante--;	// mais um nó excluído
	}
	
	if(nivel == 0 && nfilhos < 2)	// se eu sou a raiz e tenho menos que 2 filhos, então sou folha
		centro[s] = 1;		// exclui o vértice s do conjunto de vértices centro
}

// Retorna o identificador de um vértice folha
int acha_centro()
{
	int i;
	int raiz = 1;	// se a árvore tem um ou dois nós, o vértice 1 ou 2 é o centro

	memset(centro+1,0,n*4);	// todos os vértices são centros
	
	int restante = n;	// pega o número de vértices ainda não eliminados
	
	while(restante > 2)
	{		
		// faz a nova busca
		memset(vis+1,0,n*4);	
		dfs(raiz,0,restante);

		// procura algum outro vértice ainda não excluído da árvore para ser a raiz da próxima busca
		for(i=1;i<=n;i++)
			if(centro[i] == 0)	
			{
				raiz = i;
				break;
			}
	}
	return raiz;	// retorna a raiz da última busca
}
