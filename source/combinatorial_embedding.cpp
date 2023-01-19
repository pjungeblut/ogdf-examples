#include "ogdf/basic/extended_graph_alg.h"
#include "ogdf/basic/graph_generators.h"

using namespace ogdf;

int main() {
  Graph G;
  randomPlanarTriconnectedGraph(G, 20, 40);

  planarEmbed(G);
  CombinatorialEmbedding CE(G);

  for (face f : CE.faces) {
    for (adjEntry adj : f->entries) {
      std::cout << adj->theEdge() << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
