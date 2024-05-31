#include "base.h"
#include "graph.c"

//**********************************//
// Funcionamento do algoritmo para achar o caminho ate o destino
// 1. Inicia colorindo o ponro de inicio, prechendo quanto de dinheiro tem e botando o vazio no array de anterior
// 2. Busca uma aresta que e possivel de avancar, ou seja, tem dinheiro e ainda nao foi visitado nessa iteracao
// 3. Na nova aresta repete o processo 1 e 2.
// 4. Repete esse processo ate se achar o fim ou chegar num caminho sem saida, por nao ter dinheiro ou ser um no folha
// 5. Caso nao tenha achado o caminho, retorna usando a tabela de anterior para o ultimo no, limpa todas as informacoes do no que foi voltado, visitando o proximo no disponivel dele.
// 6. Caso sejam testados todos os caminhos possiveis e nao seja encontrado um caminho valido, isso vai ser verdade quando terminar todos os caminhos do primeiro no. 


typedef struct estr {
      int adj; // elemento do caminho
      struct estr *prox;
} NO;


void buscarCaminho()


int main(){
    Grafo g;
    if (!(inicializaGrafo(&g, 5))) printf("Error Initializing.\n");
    if (!(insereAresta(&g, 1, 2, 10))) printf("Error Inserting\n");
    if (!(insereAresta(&g, 3, 1, 10))) printf("Error Inserting\n");
    printGrafo(&g);
    return 1;

}