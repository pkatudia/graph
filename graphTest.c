#include "graph.h"

/***********  API  ************* 
 *
 * Graph * CreateGraph(int total);
 * void printGraph(Graph *g);
 * Graph * deleteGraph(Graph *g);
 * void AddEdge(Graph *g, int src, int dest, int IS_DIRECTED);
 * void DelEdge(Graph *g, int src, int dest, int IS_DIRECTED);
 * int isEdgePresent(Graph *g, int src, int dest);
 * int addNewVertices(Graph *g);
 */

#define IS_DIRECTED YES


int main()
{
  Graph *g;
  int V=5;
  g = CreateGraph(V);
  //printGraph(g);
  addEdge(g,1,2,IS_DIRECTED);
  addEdge(g,0,1,IS_DIRECTED);
  addEdge(g,2,3,IS_DIRECTED);
  addEdge(g,3,4,IS_DIRECTED);
  addEdge(g,4,1,IS_DIRECTED);
  addEdge(g,1,3,IS_DIRECTED);
  addEdge(g,1,4,IS_DIRECTED);
  addEdge(g,2,4,IS_DIRECTED);
  addEdge(g,2,0,IS_DIRECTED);

  printGraph(g);
  delEdge(g,2,0,IS_DIRECTED);
  delEdge(g,2,3,IS_DIRECTED);
  printGraph(g);

  /* Validation */
  if(isEdgePresent(g,2,3))
  {
    abort();
  }

  printf("v=%d\n", addNewVertices(g));

  /* Validation */
  if(g->total < V)
  {
    abort();
  }

  printf("v=%d\n", addNewVertices(g));
  printf("v=%d\n", addNewVertices(g));

  addEdge(g,5,1,IS_DIRECTED);
  addEdge(g,5,2,IS_DIRECTED);
  addEdge(g,5,3,IS_DIRECTED);
  addEdge(g,7,3,IS_DIRECTED);
  addEdge(g,7,3,IS_DIRECTED);
  addEdge(g,10,3,IS_DIRECTED);
  addEdge(g,20,333,IS_DIRECTED);
  addEdge(NULL,20,333,IS_DIRECTED);
  printGraph(g);

  /* Validation */
  if(isEdgePresent(g,10,3) || isEdgePresent(g,20,333))
  {
    abort();
  }

  /* Validation */
#ifndef IS_DIRECTED
  if(!isEdgePresent(g,3,7))
  {
    abort();
  }
#endif

  Graph *g1 = NULL;
  int V1 = addNewVertices(g1);
  if(V1 == 0)
  {
    abort();
  }

  return 0;
}

