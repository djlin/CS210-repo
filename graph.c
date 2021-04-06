#include "graph.h"

void initialize_graph(graph *g, bool directed)
{
  int i;
  g->nvertices = 0;
  g->nedges = 0;
  g->directed = directed;

  for(i=0; i<=MAXV; i++)
    g->degree[i] = 0;
  for(i=0; i<=MAXV; i++)
    g->edges[i] =  NULL;
}

void read_graph(graph *g, bool directed)
{
  int i;        // counter
  int m;        // number of edges
  int x, y;     // vertices in edge (x,y)

  initialize_graph(g, directed);

  scanf("%d %d", &(g->nvertices), &m);

  for(i=1; i<=m; i++) {
    scanf("%d %d", &x, &y);
    insert_edge(g, x, y, directed);
  }
}

void insert_edge(graph *g, int x, int y, bool directed) 
{ 
  edgenode *p; /* temporary pointer */

  p = malloc(sizeof(edgenode));   // allocate edgenode storage

  p->weight = 0;
  p->y = y;
  p->next = g->edges[x];

  g->edges[x] = p;                // insert at head of list
  g->degree[x]++;

  if (!directed) { 
    insert_edge(g, y, x, true); 
  } else {
    g->nedges++;
  }
}

void print_graph(graph  *g)
{
  int i; // counter
  edgenode *p; // temporary pointer

  for (i = 1; i <= g->nvertices; i++) {
    printf("%d: ", i);
    p = g->edges[i];
    while (p != NULL) {
      printf(" %d", p->y);
      p = p->next;
    }
    printf("\n");
  }
}
