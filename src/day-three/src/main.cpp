#include "../lib/utils.h"
#include <iostream>

int part_one() {
  std::vector<std::string> lines = read_file("../day_three.test");

  for (std::string line : lines) {
    std::cout << line << "\n";
  }

  return 0;
}

int main() {
  part_one();
  return 0;
}
