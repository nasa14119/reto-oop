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
void file_setup(MediaVector &media, MediaVector &series)
{
  utils::get_data_movies(media, "../movies.csv");
  utils::get_data_series(series, "../series.csv");
};
int main()
{
  MediaVector media;
  MediaVector series;
  file_setup(media, series);
  User user;
  Controller control(&media, &user);
  return 0;
}