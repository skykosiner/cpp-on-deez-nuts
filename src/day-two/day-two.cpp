#include <cctype>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

struct Game {
  int id;
};

bool replace(std::string &str, const std::string &from, const std::string &to) {
  size_t start_pos = str.find(from);
  if (start_pos == std::string::npos)
    return false;
  str.replace(start_pos, from.length(), to);
  return true;
}

std::vector<std::string> split_string_for_sets(const std::string &input) {
  std::vector<std::string> result;

  std::size_t colonPos = input.find(':');
  if (colonPos != std::string::npos) {
    std::string valuesPart = input.substr(colonPos + 1);

    std::stringstream ss(valuesPart);
    std::string segment;

    while (std::getline(ss, segment, ';')) {
      result.push_back(segment);
    }
  }

  return result;
}

std::vector<std::string> split_string_for_set(const std::string &input) {
  std::vector<std::string> result;
  std::stringstream ss(input);
  std::string segment;

  while (std::getline(ss, segment, ',')) {
    result.push_back(segment);
  }

  return result;
}

std::string extract_color(const std::string &input) {
  std::istringstream ss(input);
  std::string number, color;

  // Extract the first part (the number) into 'number'
  ss >> number;

  // Extract the second part (the color) into 'color'
  ss >> color;

  return color;
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
  std::ifstream infile("./day-two.input");
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

int main() {
  std::cout << part_one() << "\n";
  return 0;
}
