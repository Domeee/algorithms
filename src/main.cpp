#include "bfs.h"
#include "dijkstra.h"
#include <cstring>
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " -a <algorithm>\n";
    return 1;
  }

  if (std::strcmp(argv[1], "-a") == 0) {
    if (std::strcmp(argv[2], "bfs") == 0) {
      run_bfs_algorithm();
    }
    if (std::strcmp(argv[2], "dijkstra") == 0) {
      run_dijkstra_algorithm();
    } else {
      std::cerr << "Unknown algorithm: " << argv[2] << "\n";
      return 1;
    }
  } else {
    std::cerr << "Invalid option: " << argv[1] << "\n";
    return 1;
  }

  return 0;
}
