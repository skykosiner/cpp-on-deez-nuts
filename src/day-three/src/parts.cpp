#include "../lib/parts.h"
#include "../lib/utils.h"
#include <string>

namespace parts {
int part_one() {
  std::vector<std::string> lines = utils::read_file("../day_three.input");
  int sum = 0;

  for (size_t y = 0; y < lines.size(); y++) {
    const std::string &row = lines[y];
    bool bad = false;

    for (size_t x = 0; x < row.size(); x++) {
      if (std::isdigit(row[x])) {
        std::string number;
        size_t start = x;

        while (x < row.length() && std::isdigit(row[x])) {
          number += row[x];
          x++;
        }

        bool has_symbol = false;
        for (size_t i = start; i < x; i++) {
          auto adj = utils::get_adj(y, i);
          for (const auto &[adj_y, adj_x] : adj) {
            if (adj_y >= 0 && adj_y < static_cast<int>(lines.size()) &&
                adj_x >= 0 && adj_x < static_cast<int>(lines[adj_y].length())) {
              if (utils::is_symbol(lines[adj_y][adj_x])) {
                has_symbol = true;
                break;
              }
            }
          }

          if (has_symbol) {
            break;
          }
        }

        if (has_symbol) {
          sum += std::stoi(number);
        }
      }
    }
  }

  return sum;
}

int part_two() {
  std::vector<std::string> lines = utils::read_file("../day_three.test");
  std::vector<Gear> gears;
  int sum = 0;

  for (size_t y = 0; y < lines.size(); y++) {
    for (size_t x = 0; x < lines[y].size(); x++) {
      if (lines[y][x] == '*') {
        gears.push_back({y, x});
      }
    }
  }

  for (Gear gear : gears) {
  }

  return sum;
}
} // namespace parts
