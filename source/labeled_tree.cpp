#include "ogdf/basic/graph_generators.h"
#include "ogdf/fileformats/GraphIO.h"
#include "ogdf/tree/TreeLayout.h"

using namespace ogdf;

int main() {
  Graph G;
  randomTree(G, 50);

  GraphAttributes GA(G,
      GraphAttributes::nodeGraphics |
      GraphAttributes::edgeGraphics |
      GraphAttributes::nodeLabel);

  TreeLayout tl;
  tl.call(GA);

  for (node v : G.nodes) {
      GA.label(v) = to_string(v->index());
  }

  std::ofstream fout("labeled_tree.svg");
  GraphIO::SVGSettings settings;
  settings.fontColor("#FFFFFF");
  GraphIO::drawSVG(GA, fout, settings);

  return 0;
}
