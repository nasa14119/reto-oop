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
void file_setup(MediaVector &media)
{
  string values[6];
  string line;
  string path_movies = utils::get_file_path("../movies.csv");
  string path_series = utils::get_file_path("../series.csv");

  ifstream file_movie(path_movies);
  if (!file_movie.is_open())
  {
    throw "Error reading file";
  }
  while (getline(file_movie, line))
  {
    stringstream ss(line);
    int i = 0;
    while (getline(ss, values[i], ','))
    {
      i++;
    }
    media.emplace_back(new Movies(values[0], values[1], values[2], stoi(values[3]), stof(values[4]), values[5]));
  }
  file_movie.close();
};
int main()
{
  // utils::clear();
  MediaVector media;
  file_setup(media);
  Controller control(&media);
  // control.print_movies();
  MediaVector filter_movies = filters::filter_by_title(media);
  Controller::print_movies(&filter_movies);
  return 0;
}