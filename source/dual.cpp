#include "ogdf/basic/extended_graph_alg.h"
#include "ogdf/basic/graph_generators.h"

using namespace ogdf;

int main() {
  Graph G;
  randomPlanarTriconnectedGraph(G, 20, 40);

  planarEmbed(G);
  CombinatorialEmbedding CE(G);

  DualGraph DG(CE);
  const Graph& dual = DG.getGraph();

  for (node v_dual : dual.nodes)
    face f = DG.primalFace(v_dual);

  for (face f : CE.faces)
    node v_dual = DG.dualNode(f);

  for (face f_dual : DG.faces)
    node v = DG.primalNode(f_dual);

  return 0;
}
