#ifndef USER
#define USER
#include "../utils.h"
#include "Movies.cpp"
#include "Controller.cpp"
#include <fstream>
using namespace std;
extern const string MOVIES_str;
extern const string SERIES_str;
class User
{
private:
  MediaVector videos;

public:
  User(/* args */);
  void save_movie();
  void save_serie();
  void rank_serie();
  void rank_movie();
  void save_to_file();
  void get_file_data();
};
void User::get_file_data()
{
  utils::get_data_movies(videos, "../mydata.csv");
  Controller::print_movies(&videos);
};
User::User(/* args */)
{
  get_file_data();
}
#endif