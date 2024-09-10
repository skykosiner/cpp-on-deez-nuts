#include <cctype>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "split/split_me_daddy.h"

bool replace(std::string &str, const std::string &from, const std::string &to) {
  size_t start_pos = str.find(from);
  if (start_pos == std::string::npos)
    return false;
  str.replace(start_pos, from.length(), to);
  return true;
}

bool parse_items(std::vector<std::string> sets) {
  std::map<std::string, int> limits = {
      {"red", 12},
      {"green", 13},
      {"blue", 14},
  };

  for (std::string set : sets) {
    std::vector<std::string> single_item = split_string_for_set(set);

    for (std::string single : single_item) {
      int value = std::stoi(single.substr(0, *" "));
      std::string color = extract_color(single);
      auto max = limits.find(color);

      if (value > max->second) {
        return false;
      }
    }
  }

  return true;
}

int part_one() {
  std::ifstream infile("../day_two.input");
  std::vector<Game> games;
  size_t sum = 0;

  if (!infile) {
    std::cout << "it's joever\n";
    return -1;
  }

  std::string line;

  while (getline(infile, line)) {
    std::string id = line.substr(0, line.find(":"));
    replace(id, "Game ", "");

    std::vector<std::string> sets = split_string_for_sets(line);
    if (parse_items(sets))
      games.push_back(Game{std::stoi(id)});
  }

  for (Game game : games) {
    sum += game.id;
  }

  return sum;
}

int part_two() {
  std::ifstream infile("../day_two.input");
  std::vector<Game> games;
  std::vector<int> sum_list;
  int final_sum = 0;

  if (!infile) {
    std::cout << "it's joever\n";
    return -1;
  }

  std::string line;
  std::vector<int> sums;

  while (getline(infile, line)) {
    std::string id = line.substr(0, line.find(":"));
    replace(id, "Game ", "");
    std::vector<std::string> sets = split_string_for_sets(line);
    int sum = collect_colors(sets);
    sum_list.push_back(sum);
  }

  for (int sum : sum_list) {
    final_sum += sum;
  }

  return final_sum;
}

int main() {
  std::cout << part_one() << "\n";
  std::cout << part_two() << "\n";

  return 0;
}
