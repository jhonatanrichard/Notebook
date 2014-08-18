/* 

Autor: Jhonatan Ríchard Raphael
Data: 11/09/2012

Algoritmo: Articulações
Descrição: Verifica quais vértices de um grafo são articulações
Complexidade: O(V+E)

Estrutura de Dados: lista de adjacências
Início Indexação vetor: 1

- um vértice é uma articulação se sua remoção torna o grafo resultante desconexo 
- um grafo é biconexo se ele não possui articulações

Regras de articulação:

	1. n é raiz: se tem só um filho, não é articulação. Caso contrário, é uma articulação
	2. n é folha: toda folha não é uma articulação
	3. n é um nó interno na árvore: 

	menor[i] = min(nivel[i],nivel[w],menor[x])

	... onde nivel[i] é a ordem de percurso na árvore do vértice i
	... onde nivel[w] para cada w onde existe uma aresta de retorno i,w
	... onde menor[x] para cada filho x de v na árvore geradora

	Agora facilita:

	1. a raiz é uma articulação se e somente se ela tem mais de um filho
	2. um vértice v não-raiz é uma articulação se e somente se v tem um filho x tal que
	   menor[x] >= nivel[v]. 

	... isso quer dizer que um filho não alcança nenhum vértice anterior ao pai dele na árvore, 
	ou seja, se o vértice pai for retirado vai tornar o grafo desconexo
*/

#include <stdio.h>

#define MAX 101

int G[MAX][MAX];	// lista de adjacencias
int d[MAX];		// grau de um vértice
int n,m;
int art[MAX];		// 1 se o vértice i é articulação, 0 caso contrário
int cor[MAX];		// 0-branco (não-visitado), 1-cinza(visitado mas não finalizado) ou 2-preto (finalizado)
int nivel[MAX];		// ordem do vértice i na busca em profundidade
int menor[MAX];  	// min (menor nivel encontrado por uma aresta de retorno, nivel[i], // menor[v] tal que v é adjacente a i)
int pai[MAX];		// pai de um vértice
int cont;	

void visit(int s)
{
	int i;
	int nfilhos = 0;	// número de filhos na árvore de busca

	cor[s] = 1;

	nivel[s] = menor[s] = ++cont;	// seta a ordem de visitação e o menor[i]
	
	for(i=1;i<=d[s];i++) // percorre todos os vértices adjacentes
	{
		v = G[s][i];	// pega o identificador de um vértice adjacente
		
		if(cor[v] == 0)
		{
			nfilhos++;	// mais um filho v para a origem
			pai[v] = s;	// atualiza o pai
			
			// visita o filho
			visit(v);

			// se o nível do filho é menor do que o pai, atualiza
			if(menor[s] > menor[v])
				menor[s] = menor[v];

				
			if(nivel[s] != 1 && menor[v] >= nivel[s])	// testa a condição de articulação
				art[s] = 1;						
		}
		else	{
			if(cor[v] == 1 && pai[s] != v)	// se encontrou uma aresta de retorno
				if(menor[s] > nivel[v])	// atualiza o menor
					menor[s] = nivel[v];
		}			
	}	

	if(nivel[s] == 1 && nfilhos > 1)	// se raiz e tem mais de um fiho, é articulação
		art[s] = 1;

	cor[s] = 2;
}

void dfs()
{
	cont = 0;
	memset(cor+1,0,n*4);
	memset(art+1,0,n*4);

	// inicializa os pais dos vértices
	for(int i=1;i<=n;i++)	pai[i] = i;

	// Chama DFS até que todos os vértices sejam visitados.
	for(int i=1;i<=n;i++)	if(!cor[i])	visit(i);
}

