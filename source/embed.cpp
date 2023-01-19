#include "ogdf/basic/extended_graph_alg.h"
#include "ogdf/basic/graph_generators.h"

using namespace ogdf;

int main() {
  Graph G;
  randomSimpleGraph(G, 50, 100);

  // If true:
  // Order of adjEntries encodes planar embedding.
  bool isPlanar = planarEmbed(G);
  return 0;
}
