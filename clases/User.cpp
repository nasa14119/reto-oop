#ifndef USER
#define USER
#include "../utils.h"
#include "Movies.cpp"
#include <fstream>
using namespace std;
extern const string MOVIES_str;
extern const string SERIES_str;
class User
{
private:
  MediaVector *videos;

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
  string path_user_data = utils::get_file_path("../mydata.csv");
  ifstream user_data_stream(path_user_data);
  string line;
  string values[6];
  while (getline(user_data_stream, line))
  {
    if (line == MOVIES_str)
    {
      continue;
    }
    if (line == SERIES_str)
    {
      break;
    }
    int i = 0;
  }
};
User::User(/* args */)
{
}
#endif