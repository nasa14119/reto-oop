#include <iostream>
#include <vector>
#include "utils.h"
#include <fstream>
#include <sstream>
#include "clases/Movies.cpp"
#include "clases/Media.h"
#include "clases/Controller.h"
#include "clases/Filters.cpp"
#include "clases/User.h"
#include "clases/Series.h"
using namespace std;
const string MOVIES_str = "movies";
const string SERIES_str = "series";
void file_setup(MediaVector &media)
{
  utils::get_data_movies(media, "../movies.csv");
};
int main()
{
  MediaVector media;
  file_setup(media);
  User user;
  Controller control(&media, &user);
  return 0;
}