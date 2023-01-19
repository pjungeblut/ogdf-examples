/*
Random graph at random positions.
*/

#include "ogdf/basic/GraphAttributes.h"
#include "ogdf/basic/graph_generators.h"
#include "ogdf/fileformats/GraphIO.h"

using namespace ogdf;

int main() {
  Graph G;
  GraphAttributes GA (G);
  randomSimpleGraph(G, 50, 200);

  for (auto v : G.nodes) {
    GA.x(v) = randomDouble(0, 1000);
    GA.y(v) = randomDouble(0, 1000);
  }

  std::ofstream fout("random_graph.svg");
  GraphIO::drawSVG(GA, fout);

  return 0;
}
