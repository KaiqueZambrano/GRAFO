#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct adjacencia {
    int vertice;
    int peso;
    struct adjacencia* prox;
} ADJ;

typedef struct vertice {
    ADJ* cabeca;
} VERTICE;

typedef struct grafo {
    int qtdVertices;
    int qtdArestas;
    VERTICE* adj;
} GRAFO;

GRAFO* criarGrafo(int qtdVertices) {
    GRAFO* g = (GRAFO*)malloc(sizeof(GRAFO));
    VERTICE* v = (VERTICE*)malloc(qtdVertices * sizeof(VERTICE));

    g->qtdVertices = qtdVertices;
    g->qtdArestas = 0;
    g->adj = v;

    for(int i = 0; i < qtdVertices; i++)
        g->adj[i].cabeca = NULL;

    return g;
}

ADJ* criarAdj(int vertice, int peso) {
    ADJ* a = (ADJ*)malloc(sizeof(ADJ));
    
    a->vertice = vertice;
    a->peso = peso;
    a->prox = NULL;

    return a;
}

bool criarAresta(GRAFO* g, int verticePartida, int verticeDestino, int peso) {
    if(g == NULL)
        return false;
    
    if(verticeDestino >= g->qtdVertices)
        return false;
    else if(verticeDestino < 0)
        return false;
    else if(verticePartida < 0)
        return false;

    ADJ* a = criarAdj(verticeDestino, peso);

    a->prox = g->adj[verticePartida].cabeca;
    g->adj[verticePartida].cabeca = a;

    g->qtdArestas++;

    return true;
}

void imprime(GRAFO* g) {
    printf("Vertices: %d, Arestas: %d. \n", g->qtdVertices, g->qtdArestas);
    
    for(int i = 0; i < g->qtdVertices; i++) {
        printf("v%d: ", i);
        
        ADJ* a = g->adj[i].cabeca;
        while(a != NULL) {
            printf("v%d(%d) ", a->vertice, a->peso);
            a = a->prox;
        }

        printf("\n");
    }
}

int main(void) {

    // exercicio: criar grafo de acordo com slide, obter o peso total de 1 a 5
    GRAFO* g = criarGrafo(5);
    
    int p1;
    scanf("%d", &p1);
    criarAresta(g, 0, 2, p1);

    int p2;
    scanf("%d", &p2);
    criarAresta(g, 2, 1, p2);

    int p3;
    scanf("%d", &p3);
    criarAresta(g, 2, 3, p3);

    int p4;
    scanf("%d", &p4);
    criarAresta(g, 3, 1, p4);

    int p5;
    scanf("%d", &p5);
    criarAresta(g, 1, 4, p5);

    int p6;
    scanf("%d", &p6);
    criarAresta(g, 4, 3, p6);

    int pt = p1 + p2 + p3 + p4 + p5 + p6;
    printf("Peso total: %d \n", pt);
    imprime(g);

    return 0;
}