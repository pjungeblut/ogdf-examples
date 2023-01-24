#include <ogdf/basic/graph_generators.h>
#include <ogdf/basic/extended_graph_alg.h>
#include <ogdf/planarlayout/SchnyderLayout.h>
#include <ogdf/fileformats/GraphIO.h>
#include <ogdf/basic/CombinatorialEmbedding.h>
#include <ogdf/basic/DualGraph.h>

using namespace ogdf;

const int width = 700;
const int height = 500;

void stacked(Graph &G, GraphAttributes &GA, node a, node b, node c, int depth) {
  if (depth == 0) return;

  node d = G.newNode();
  G.newEdge(a, d);
  G.newEdge(b, d);
  G.newEdge(c, d);

  GA.x(d) = (GA.x(a) + GA.x(b) + GA.x(c)) / 3.0;
  GA.y(d) = (GA.y(a) + GA.y(b) + GA.y(c)) / 3.0;

  stacked(G, GA, a, b, d, depth - 1);
  stacked(G, GA, b, c, d, depth - 1);
  stacked(G, GA, c, a, d, depth - 1);
}

int main(int argc, const char * argv[]) {
  Graph G;
  GraphAttributes GA(G);

  // Inintial triangle.
  node a = G.newNode();
  node b = G.newNode();
  node c = G.newNode();
  G.newEdge(a, b);
  G.newEdge(b, c);
  G.newEdge(c, a);

  // Initial coordinates.
  GA.x(a) = 0;
  GA.y(a) = 0;
  GA.x(b) = width;
  GA.y(b) = 0;
  GA.x(c) = width / 2;
  GA.y(c) = height;

  // Recursion.
  stacked(G, GA, a, b, c, 3);

  std::ofstream fout("stacked_triangulation.svg");
  GraphIO::drawSVG(GA, fout);

  return 0;
}
