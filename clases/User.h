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
  void save_movie(MediaVector);
  void delete_movie(Media *);
  void delete_movie();
  void delete_series(Media *);
  void delete_series();
  Media *search_movie(MediaVector, bool = true);
  Media *search_serie(MediaVector, bool = true);
  void save_serie(Media *);
  void save_serie(MediaVector *);
  void rank_movies();
  void rank_series();
  void comment_movies();
  void comment_series();
  void save_to_file();
  void print(MENU_USER);
  bool contains(Media *);
  bool contains(string);
  ~User();
};

#endif