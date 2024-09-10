#ifndef split_me_daddy_h
#define split_me_daddy_h

#include <string>
#include <vector>

struct Game {
  int id;
};

struct Colors {
  int red;
  int green;
  int blue;
};

std::vector<std::string> split_string_for_sets(const std::string &input);
std::vector<std::string> split_string_for_set(const std::string &input);
std::string extract_color(const std::string &input);
int collect_colors(const std::vector<std::string> sets);

#endif
