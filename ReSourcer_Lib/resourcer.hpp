#ifndef RESOURCER_HPP
#define RESOURCER_HPP

#include <vector>
#include <string>

class ReSourcer
{
  ReSourcer();

public:
  static std::vector<char> getItem(std::string id);
  static std::string getItemText(std::string id);
  static size_t itemSize(std::string id);
  static void *rawItem(std::string id);
};

#endif // RESOURCER_HPP
