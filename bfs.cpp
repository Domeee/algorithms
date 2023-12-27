#include "bfs.h"
#include <iostream>
#include <queue>

static void bfs(const std::vector<std::vector<int>> &graph, int start) {
  std::vector<bool> visited(graph.size(), false);
  std::queue<int> queue;

  visited[start] = true;
  queue.push(start);

  while (!queue.empty()) {
    int vertex = queue.front();
    queue.pop();
    std::cout << "Visited: " << vertex << std::endl;

    for (int neighbor : graph[vertex]) {
      if (!visited[neighbor]) {
        visited[neighbor] = true;
        queue.push(neighbor);
      }
    }
  }
}

void run_bfs_algorithm() {
  /*
      0
     / \
    1---2
   /|   |
  3 |   |
   \|   |
    4---5
  */
  std::vector<std::vector<int>> graph = {{1, 2}, {0, 3, 4}, {0, 4},
                                         {1, 5}, {1, 2},    {3}};

  bfs(graph, 0);

  /* Expected output:
    Visited: 0
    Visited: 1
    Visited: 2
    Visited: 3
    Visited: 4
    Visited: 5
  */
}
