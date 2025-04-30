#ifndef USER
#define USER

#include "../utils.h"
#include <map>
#include <vector>
#include <string>
#include "Media.h"
#include "../const.h"
using std::string, std::map;
// Declaración adelantada de Controller
class Controller;

class User
{
private:
  MediaVector movies;
  MediaVector series;
  map<string, Media *> keys;

public:
  User();
  void get_file_data();
  void save_movie(Media *);
  void save_movie();
  Media *search_movie(MediaVector);
  Media *search_serie(MediaVector);
  void save_serie(Media *);
  void rank_movie(Media *);
  void rank_serie(Media *);
  void save_to_file();
  void print(MENU_USER);
  bool contains(Media *);
  bool contains(string);
  ~User();
};

#endif