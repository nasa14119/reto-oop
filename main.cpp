#include <iostream>
#include <vector>
#include "utils.h"
#include <fstream>
#include <sstream>
#include "clases/Movies.cpp"
#include "clases/Media.h"
#include "clases/Controller.cpp"
#include "clases/Filters.cpp"
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
  Controller control(&media);
  control.print_movies();
  return 0;
}