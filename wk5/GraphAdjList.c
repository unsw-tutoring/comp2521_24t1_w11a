#include "Graph.h"

struct node {
    int v;
    struct node *next;
};

struct graph {
    int nV;
    struct node **adj;
};

Graph GraphNew(int nV) {
    Graph g = malloc(sizeof(struct graph));

    g->nV = nV;
    g->adj = calloc(nV, sizeof(struct node *));

    return g;
}

