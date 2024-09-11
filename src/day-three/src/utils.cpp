#include "../lib/utils.h"
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

bool is_string_digit(const std::string &str) {
  for (char c : str) {
    if (!std::isdigit(c)) {
      return false;
    }
  }
  return true;
}

namespace utils {
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

std::vector<std::pair<int, int>> get_adj(int y, int x) {
  return {
      {y - 1, x - 1}, {y - 1, x},     {y - 1, x + 1}, {y, x - 1},
      {y, x + 1},     {y + 1, x - 1}, {y + 1, x},     {y + 1, x + 1},
  };
}
bool is_symbol(char c) { return !std::isdigit(c) && c != '.'; }

} // namespace utils
