/* Graph header file
 * Author: Prakash Katudia <prakash.katudia@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>

#define YES 1
#define NO 0

/* Graph represantation 
 *
 * |0| : |1| -> |4|
 * |1| : |2| -> |3|
 * |2| : |0|
 * |3| : |4| -> |2|
 * |4| : |0| -> |1|
 *
 * vertices = 0,1,2,3,4. Total =4
 * each Adjlist has head[own] and connected node [AdjNode]. 
 *
 * AdjNode = data, next
 * AdjList = head of AdjNode
 * Graph = total vertices [int] , array of AdjlistHeads
 */


typedef struct AdjNode{
  int data;
  struct AdjNode *next;
}AdjNode;

typedef struct AdjList{
  struct AdjNode *ListHead;
}AdjList;

typedef struct Graph{
  int total;
  AdjList *array;
}Graph;


/* API */
Graph * CreateGraph(int total);
void printGraph(Graph *g);
Graph * deleteGraph(Graph *g);
void AddEdge(Graph *g, int src, int dest, int IS_DIRECTED);
void DelEdge(Graph *g, int src, int dest, int IS_DIRECTED);
int isEdgePresent(Graph *g, int src, int dest);
int addNewVertices(Graph *g);


Graph * CreateGraph(int total)
{
  /*Init Graph */
  Graph *g = (Graph *)calloc(1, sizeof(Graph));
  g->array = (AdjList *)calloc(total, sizeof(AdjList)); 
  int i=0;
  for(i=0; i<total; i++)
  {
    g->array[i].ListHead = NULL;
  }
  g->total = total;
  return g;
}

void addEdge(Graph *g, int src, int dest, int IS_DIRECTED)
{
  if(g == NULL || src > g->total || dest > g->total )
  {
    return;
  }
  /* Avoiding duplicate data */
  if(isEdgePresent(g,src,dest))
  {
    return;
  }
  AdjNode *head;
  head = g->array[src].ListHead;
  AdjNode *node = (AdjNode *)calloc(1, sizeof(AdjNode));
  node->data = dest;
  node->next = NULL;
  if(head == NULL)
  {
    g->array[src].ListHead = node;
  }else{
    AdjNode *tmp = head;
    while(tmp->next != NULL)
    {
      tmp =tmp->next;
    }
    tmp->next = node;
  }
  if(!IS_DIRECTED){
    addEdge(g, dest, src, 0);
  }
  return;
}


void printGraph(Graph *g)
{
  if(g == NULL)
  {
    printf("Empty\n");
    return;
  }
  printf("\nGraph starts =========\n");
  int i=0;
  for(i =0; i<g->total; i++)
  {
    printf("Print vertice %d: ",i);
    AdjNode *head = g->array[i].ListHead;
    while(head != NULL)
    {
      printf("%d->", head->data);
      head = head->next;
    }
    printf("NULL\n");
  }
  printf("============== Graph End \n");
  return;
}


int isEdgePresent(Graph *g, int src, int dest)
{
  int ret = 0;
  if(g == NULL || src > g->total || dest > g->total )
  {
    return ret;
  }
  AdjNode *head = g->array[src].ListHead;
  while(head != NULL)
  {
    if(head->data == dest)
    {
      ret =1;
      break;
    }
    head = head->next;
  }
  return ret;
}

void delEdge(Graph *g, int src, int dest, int IS_DIRECTED)
{
  if(g == NULL || src > g->total || dest > g->total )
  {
    return;
  }
  AdjNode *head = g->array[src].ListHead;
  if(head == NULL)
  {
    return;
  }
  if(head->data == dest)
  {
    g->array[src].ListHead = head->next;
    head = NULL;
    free(head);
    return;
  }
  AdjNode *prev = head;
  AdjNode *curr = head;
  while(curr != NULL && curr->data != dest)
  {
    prev = curr;
    curr = curr->next;
    break;
  }
  if(curr == NULL)
    return;

  prev->next = curr->next;
  free(curr);
  if(!IS_DIRECTED)
  {
    delEdge(g, dest, src, 0);
  }

  return;
}

int addNewVertices(Graph *g)
{
  if(g == NULL)
  {
    g = CreateGraph(1);
    return g->total;
  }
  int total = g->total + 1;
  AdjList *array = (AdjList *)calloc(total, sizeof(AdjList));
  int i = 0;
  for(i =0; i< g->total; i++)
  {
    array[i] = g->array[i];
  }
  array[i+1].ListHead = NULL;
  g->array = array;
  g->total++;
  return g->total;
}

