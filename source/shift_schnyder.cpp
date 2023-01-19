/*
Shift (FPP) and Schnyder layout comparison.
*/

#include "ogdf/planarlayout/FPPLayout.h"
#include "ogdf/planarlayout/SchnyderLayout.h"
#include "ogdf/basic/graph_generators.h"
#include "ogdf/fileformats/GraphIO.h"

using namespace ogdf;

int main() {
  Graph G;
  int n = 20;
  int m = 3 * n - 4;
  randomPlanarTriconnectedGraph(G, n, m);

  GraphAttributes GA_shift(G);
  FPPLayout shift;
  shift.call(GA_shift);
  std::ofstream fout_shift("shift.svg");
  GraphIO::drawSVG(GA_shift, fout_shift);

  GraphAttributes GA_schnyder(G);
  SchnyderLayout schnyder;
  schnyder.call(GA_schnyder);
  std::ofstream fout_schnyder("schnyder.svg");
  GraphIO::drawSVG(GA_schnyder, fout_schnyder);

  return 0;
}
