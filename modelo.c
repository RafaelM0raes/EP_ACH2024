//--------------------------------------------------------------
// COLOQUE OS NOMES DOS RESPONS�VEIS AQUI: blablabla E blablabla
//--------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;


/* Estrutura para representar elementos de uma lista ligada de vertices */
typedef struct aux{
  int vertice;
  float peso;
  struct aux* prox;
} Aresta;


/* Estrutura para representar nosso grafo usando matriz de adjacencia binaria */
typedef struct {
  int numVertices;
  int numArestas;
  Aresta** A;
} Grafo;


bool inicializaGrafo(Grafo* g, int vertices){
  if (g==NULL || vertices<1) return false;
  g->numVertices = vertices+1;
  g->numArestas = 0;
  int x, y;
  g->A = (Aresta**) malloc(sizeof(Aresta*)*(vertices+1));
  for (x=0; x<vertices+1; x++){
    g->A[x] = NULL;
  }
  return true;
}

bool liberaGrafo(Grafo* g){
  if (g==NULL) return false;
  int x;
  Aresta *atual, *apagar;
  for (x=0; x<g->numVertices; x++){
    atual = g->A[x];
    while (atual){
      apagar = atual;
      atual = atual->prox;
      free(apagar);
    }
  }
  free(g->A);
  g->numVertices = 0;
  g->numArestas = 0;
  g->A = NULL;
  return true;
}

bool insereArestaAux(Grafo* g, int v1, int v2, int peso){
    if (g == NULL) return false;
    if (v1 >= g->numVertices | v2 >= g->numVertices | v1 <= 0 | v2 <= 0) return false;

    Aresta *a = (Aresta*)malloc(sizeof(Aresta));
    a->peso = peso;
    a->vertice = v2;
    a->prox = NULL;
    if (g->A[v1] == NULL) {
        g->A[v1] = a;
    } else {
        Aresta* ant = (Aresta*)malloc(sizeof(Aresta));
        ant = g->A[v1];
        while (ant->prox){
            ant = ant->prox;
        }
        ant->prox = a;
    }
    return true;
}

bool insereAresta(Grafo* g, int v1, int v2, int peso){
    if (g == NULL) {
        printf("NULL Graph.\n");
        return false;
    };
    if (v1 >= g->numVertices | v2 >= g->numVertices | v1 <= 0 | v2 <= 0) return false;

    g->numArestas++;

    if (insereArestaAux(g, v1, v2, peso) & insereArestaAux(g, v2, v1, peso)) return true;
    return false;
}

void printGrafo(Grafo* g){
    if (g == NULL) return;
    for (int i = 1; i < g->numVertices; i++){
        printf("Vertice: {%d}", i); 
        Aresta *a = (Aresta*)malloc(sizeof(Aresta));
        a = g->A[i];
        while (a){
            printf(" -> | {%d} peso: {%f} |", a->vertice, a->peso);
            a = a->prox;
        }
        printf("\n");
    }
}

// INFORME O NRO DO GRUPO CONFORME PLANILHA DIVULGADA
int grupo() {
  return 0;
}

// ######### ESCREVA O NROUSP AQUI
int nroUSP1() {
    return 0;
}

// E O SEGUNDO NROUSP AQUI, SE HOUVER
int nroUSP2() {
    return 0;
}

// elemento da lista de resposta - NAO ALTERE ESTA DEFINICAO
typedef struct estr {
      int adj; // elemento do caminho
      struct estr *prox;
} NO;




// funcao principal
NO *caminho(int N, int A, int ijpeso[], int ganhos[], int inicio, int fim, int* dinheiro){
	NO* resp = NULL;

	Grafo* g = (Grafo*)malloc(sizeof(Grafo));
	inicializaGrafo(g, N);
	for (int i = 1; i<=A; i++){
		insereAresta(g, ijpeso[i], ijpeso[i+1], ijpeso[i+2]);
	}




	return resp;
}



//---------------------------------------------------------
// use main() para fazer chamadas de teste ao seu programa
//---------------------------------------------------------
int main() {


	// aqui vc pode incluir codigo de teste - mas n�o precisa entregar isso

	// exemplo de teste trivial

	int N=3; // grafo de 3 v�rtices numerados de 1..3
	int ganhos[] = {10, 5, 15}; // o ganho em cada cidade 

	// ao criar o grafo, lembre-se de criar um vetor de vertices de tamanho N+1
	// e despreze o indice zero do vetor

	int A = 3; // 3 arestas 
	int ijpeso[] = {1,2,10, 2,3,20, 3,1,10};

	int inicio = 1;
	int fim = 3;
	int dinheiro = 50;

	// o EP sera testado com uma serie de chamadas como esta
	NO* teste = NULL;
	teste = caminho(N, A, ijpeso, ganhos, inicio, fim, &dinheiro);

}

// por favor nao inclua nenhum c�digo abaixo da fun��o main()
