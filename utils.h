#ifndef UTILS
#define UTILS
#include <iostream>
#include <filesystem>
#include "clases/Media.h"
using namespace std;
extern const string MOVIES_str;
extern const string SERIES_str;
class utils
{
public:
  static string get_file_path(string str);
  static void clear();
  static MediaVector get_data_movies(MediaVector &, string);
  static MediaVector get_data_series(MediaVector &, string);
  static void center_text(const string &, int = 85, string = "\n");
  static int get_dato_int(int, int);
  static int get_dato_int(int);
};
#endif
