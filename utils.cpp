#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>
#include "utils.h"
#include "clases/Movies.cpp"
using namespace std;
extern const string MOVIES_str;
extern const string SERIES_str;
string utils::get_file_path(string str)
{
  filesystem::path file(str);
  return filesystem::canonical(file);
};
void utils::clear()
{
  cout << "\033[2J\033[H" << flush;
};
MediaVector utils::get_data_movies(MediaVector &medias, string str)
{
  string path_movies = utils::get_file_path(str);
  string values[6];
  string line;
  ifstream file_movie(path_movies);
  if (!file_movie.is_open())
  {
    throw "Error reading file";
  }
  while (getline(file_movie, line))
  {
    if (line == MOVIES_str)
    {
      break;
    }
    stringstream ss(line);
    int i = 0;
    while (getline(ss, values[i], ','))
    {
      i++;
    }
    medias.emplace_back(new Movies(values[0], values[1], values[2], stoi(values[3]), stof(values[4]), values[5]));
  }
  file_movie.close();
  return medias;
};