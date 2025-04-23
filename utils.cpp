#include <iostream>
#include <filesystem>
#include "utils.h"
using namespace std;

string utils::get_file_path(string str)
{
  filesystem::path file(str);
  return filesystem::canonical(file);
}
void utils::clear()
{
  cout << "\033[2J\033[H" << flush;
};
