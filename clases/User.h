#ifndef USER
#define USER

#include "../utils.h"
#include <vector>
#include <string>
#include "Media.h"

// Declaración adelantada de Controller
class Controller;

class User
{
private:
  MediaVector movies;
  MediaVector series; 

public:
  User();
  void get_file_data();
  void save_movie(Media *);
  void save_serie(Media *);
  void rank_movie();
  void rank_serie();
  void save_to_file();
  void print();
};

#endif