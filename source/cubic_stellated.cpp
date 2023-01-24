#include <ogdf/basic/graph_generators.h>
#include <ogdf/basic/extended_graph_alg.h>
#include <ogdf/planarlayout/SchnyderLayout.h>
#include <ogdf/fileformats/GraphIO.h>
#include <ogdf/basic/CombinatorialEmbedding.h>
#include <ogdf/basic/DualGraph.h>

using namespace ogdf;

void randomTPC(Graph &G, int numberOfNodes) {
  int numberOfEdges = 3 * numberOfNodes / 2;
  randomPlanarTriconnectedGraph(G, numberOfNodes, numberOfEdges);
}

int main(int argc, const char * argv[]) {
  Graph G;
  GraphAttributes GA(G, GraphAttributes::nodeGraphics |
                        GraphAttributes::edgeGraphics |
                        GraphAttributes::nodeStyle |
                        GraphAttributes::edgeStyle);

  // Generate graph.
  randomTPC(G, 20);
  planarEmbed(G);
  CombinatorialEmbedding CE(G);

  // Color originial graph blue.
  for (node v : G.nodes) GA.fillColor(v) = "#0000FF";
  for (edge e : G.edges) GA.strokeColor(e) = "#0000FF";

  // Stellate.
  // First copy.
  std::vector<face> faces;
  for (face f : CE.faces) faces.push_back(f);

  std::vector<std::vector<adjEntry>> entries(faces.size());
  for (std::size_t i = 0; i < faces.size(); ++i) {
    for (adjEntry adj : faces[i]->entries) entries[i].push_back(adj);
  }

  // Then modify.
  for (std::size_t i = 0; i < faces.size(); ++i) {
    node vf = G.newNode();
    GA.fillColor(vf) = "#FF0000";

    for (adjEntry adj : entries[i]) {
      edge ef = G.newEdge(vf, adj->theNode());
      GA.strokeColor(ef) = "#FF0000";
    }
  }

  // Find SchnyderLayout.
  SchnyderLayout sl;
  sl.callFixEmbed(GA);

  // Print.
  std::ofstream of("cubic_stellated.svg");
  GraphIO::drawSVG(GA, of);

  return 0;
}
