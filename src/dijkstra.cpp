#include "dijkstra.h"
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

static std::vector<int>
dijkstra(const std::vector<std::vector<std::pair<int, int>>> &graph,
         int start) {
  std::vector<int> distances(graph.size(), std::numeric_limits<int>::max());
  distances[start] = 0;

  auto compare = [](const std::pair<int, int> &a,
                    const std::pair<int, int> &b) {
    return a.second > b.second;
  };

  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      decltype(compare)>
      queue(compare);

  queue.push({start, 0});

  while (!queue.empty()) {
    int current_vertex = queue.top().first;
    int current_distance = queue.top().second;
    queue.pop();

    // Ignore this path if we have already found a shorter path to this vertex
    if (current_distance > distances[current_vertex]) {
      continue;
    }

    for (const auto &edge : graph[current_vertex]) {
      int neighbor = edge.first;
      int distance = edge.second;
      int distance_through_current = current_distance + distance;

      if (distance_through_current < distances[neighbor]) {
        distances[neighbor] = distance_through_current;
        queue.push({neighbor, distance_through_current});
      }
    }
  }

  return distances;
}

static void print_distances(const std::vector<int> &distances) {
  for (size_t i = 0; i < distances.size(); ++i) {
    std::cout << "Distance from start to vertex " << i << ": " << distances[i]
              << std::endl;
  }
}

void run_dijkstra_algorithm() {
  std::vector<std::vector<std::pair<int, int>>> graph = {
      {{1, 4}, {2, 1}}, {{3, 1}}, {{1, 2}, {3, 5}, {4, 8}}, {{4, 2}}, {}};

  std::vector<int> distances = dijkstra(graph, 0);
  print_distances(distances);

  /* Expected output:
    Distance from start to vertex 0: 0
    Distance from start to vertex 1: 3
    Distance from start to vertex 2: 1
    Distance from start to vertex 3: 4
    Distance from start to vertex 4: 6
  */
}
