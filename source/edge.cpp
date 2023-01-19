/*
A graph `G` with two vertices `u` and `v` and an edge `e` directed from `u` to `v`.
*/

#include "ogdf/basic/Graph.h"

// Hier lebt alles von OGDF.
using namespace ogdf;

int main() {
  Graph G;
  node u = G.newNode();
  node v = G.newNode();
  edge e = G.newEdge(u, v);
  return 0;
}
