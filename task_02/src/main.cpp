#include <iostream>

#include "network.hpp"

int main() {
  // Create a graph to represent the network
  Network network;

  network.AddVertex(0);
  network.AddVertex(1);
  network.AddVertex(2);
  network.AddVertex(3);

  network.AddEdge(0, 1);
  network.AddEdge(1, 2);
  network.AddEdge(2, 0);
  network.AddEdge(2, 3);

  auto [bridges, cut_vertices] = network.FindBridgesAndCutVertices();

  // Print bridges
  std::cout << "Bridges:" << std::endl;
  for (const auto &bridge : bridges)
    std::cout << bridge.first << " -- " << bridge.second << std::endl;

  // Print cut vertices
  std::cout << "Cut vertices:" << std::endl;
  for (const auto &cut_vertex : cut_vertices)
    std::cout << cut_vertex << std::endl;

  return 0;
}