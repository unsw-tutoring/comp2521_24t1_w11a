#include "Graph.h"

struct graph {
    int nV;
    bool **adj;
};

Graph GraphNew(int nV) {
    Graph g = malloc(sizeof(struct graph));

    g->nV = nV;

    g->adj = malloc(sizeof(bool *) * nV);
    for (int i = 0; i < nV; i++) {
        g->adj[i] = calloc(nV, sizeof(bool));
    }

    return g;
}
