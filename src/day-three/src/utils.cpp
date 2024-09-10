#include "../lib/utils.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> read_file(const std::string path) {
  std::vector<std::string> lines;
  std::ifstream infile(path);

  if (!infile) {
    std::cout << "it's joever\n";
    std::exit(-1);
  }

  std::string line;

  while (getline(infile, line)) {
    lines.push_back(line);
  }

  return lines;
}
