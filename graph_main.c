#include "graph.h"

int main()
{
  graph g;
  bool directed = false;

  read_graph(&g, directed);
  print_graph(&g);
  return 0;
}
