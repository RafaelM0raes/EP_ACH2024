#include "base.h"

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



