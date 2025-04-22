#include <iostream>
#include <vector>
#include "utils.h"
#include <fstream>
#include <sstream>
#include "clases/Movies.cpp"
#include "clases/Media.h"

using namespace std;

constexpr void file_setup(vector<Media *> &media)
{
  string values[6];
  string line;
  string path_movies = utils::get_file_path("../movies.csv");
  string path_series = utils::get_file_path("../series.csv");

  ifstream file_movie(path_movies);
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
};
int main()
{
  vector<Media *> media;
  file_setup(media);
  for (auto movie : media)
  {
    movie->print();
  };
  Movies::design();
  return 0;
}