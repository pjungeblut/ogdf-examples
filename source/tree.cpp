#include "ogdf/basic/graph_generators.h"
#include "ogdf/fileformats/GraphIO.h"
#include "ogdf/tree/TreeLayout.h"

using namespace ogdf;

int main() {
  Graph G;
  int n = 50;
  int max_degree = 5; // 0 = no restriction
  int max_width = 10; // 0 = no restriction
  // Last two parameters are optional.
  randomTree(G, n, max_degree, max_width);

  GraphAttributes GA(G);
  TreeLayout tl; // Similar to Reingold+Tilford.
  tl.call(GA);
  std::ofstream fout("tree.svg");
  GraphIO::drawSVG(GA, fout);

  return 0;
}
