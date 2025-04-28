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
#include "const.h"
using namespace std;
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
  Controller control(&media, &series, &user);
  // control.menu();
  user.save_movie(media[0]);
  user.save_serie(series[5]);
  return 0;
}