#include <iostream>
#include <sstream>

#include "split_me_daddy.h"

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

int collect_colors(const std::vector<std::string> sets) {
  int sum = 0;
  int max_red = 0;
  int max_blue = 0;
  int max_green = 0;

  for (std::string set : sets) {
    std::vector<std::string> single_item = split_string_for_set(set);

    for (std::string set : single_item) {
      int value = std::stoi(set.substr(0, *" "));
      std::string color = extract_color(set);

      if (color == "red") {
        if (max_red == 0 || max_red < value) {
          max_red = value;
        }
      } else if (color == "blue") {
        if (max_blue == 0 || max_blue < value) {
          max_blue = value;
        }
      } else if (color == "green") {
        if (max_green == 0 || max_green < value) {
          max_green = value;
        }
      }
    }
  }

  sum += max_red * max_blue * max_green;

  return sum;
};
