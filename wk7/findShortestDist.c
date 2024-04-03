#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Graph.h"
#include "Queue.h"

// returns an array containing the shortest
// distance between src and each vertex.
// For an undirected, unweighted graph.
int *findShortestDistance(Graph g, int src) {
   bool *visited = calloc(GraphNumVertices(g), sizeof(bool));
   int *dist = calloc(GraphNumVertices(g), sizeof(int));

   Queue q = QueueNew();
   QueueEnqueue(q, src);
   visited[src] = true;
   dist[src] = 0;

   while (!QueueIsEmpty(q)) {
      int v = QueueDequeue(q);
      for (int i = 0; i < GraphNumVertices(g); i++) {
         if (GraphIsAdjacent(g, v, i) && !visited[i]) {
            visited[i] = true;
            dist[i] = dist[v] + 1;
            QueueEnqueue(q, i);
         }
      }
   }

   QueueFree(q);
   free(visited);

   return dist;
}
