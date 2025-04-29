#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>
#include "utils.h"
#include "clases/Movies.cpp"
#include "clases/Series.h"
#include "const.h"
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
  system("clear");
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
    cerr << "File load error" << endl;
    throw "Error reading file";
  }
  while (getline(file_movie, line))
  {
    if (line == SERIES_str)
      break;
    if (line == MOVIES_str)
      continue;
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
ifstream utils::get_data_movies(string str)
{
  string path_movies = utils::get_file_path(str);
  string values[6];
  string line;
  ifstream file_movie(path_movies);
  if (!file_movie.is_open())
  {
    cerr << "File load error" << endl;
    throw "Error reading file";
  }
  while (getline(file_movie, line))
  {
    if (line == SERIES_str)
      break;
  }
  return file_movie;
};
MediaVector utils::get_data_series(MediaVector &medias, string str)
{
  string path_series = utils::get_file_path(str);
  string values[6];
  string line;
  string id;
  ifstream file_series(path_series);
  if (!file_series.is_open())
  {
    cerr << "File load error" << endl;
    throw "Error reading file";
  }
  while (getline(file_series, line))
  {
    stringstream ss(line);
    int i = 0;
    while (getline(ss, values[i], ','))
    {
      i++;
    }
    Series *series_back = nullptr;
    if (!medias.empty())
    {
      series_back = dynamic_cast<Series *>(medias.back());
    }
    if (values[0] != id)
    {
      id = values[0];
      medias.emplace_back(new Series(values[0], values[1], values[2], stoi(values[3]), stof(values[4]), values[5]));
      series_back = dynamic_cast<Series *>(medias.back());
      series_back->add_serie(values[0], values[1], values[2], stoi(values[3]), stof(values[4]), values[5]);
      continue;
    }
    series_back->add_serie(values[0], values[1], values[2], stoi(values[3]), stof(values[4]), values[5]);
  }
  file_series.close();
  return medias;
};
MediaVector utils::get_data_series(ifstream &file_series, MediaVector &medias)
{
  string values[6];
  string line;
  string id;
  if (!file_series.is_open())
  {
    cerr << "File load error" << endl;
    cerr << "Error in get_series" << endl;
    throw "Error reading file";
  }
  while (getline(file_series, line))
  {
    stringstream ss(line);
    int i = 0;
    while (getline(ss, values[i], ','))
    {
      i++;
    }
    Series *series_back = nullptr;
    if (!medias.empty())
    {
      series_back = dynamic_cast<Series *>(medias.back());
    }
    if (values[0] != id)
    {
      id = values[0];
      medias.emplace_back(new Series(values[0], values[1], values[2], stoi(values[3]), stof(values[4]), values[5]));
      series_back = dynamic_cast<Series *>(medias.back());
      series_back->add_serie(values[0], values[1], values[2], stoi(values[3]), stof(values[4]), values[5]);
      continue;
    }
    series_back->add_serie(values[0], values[1], values[2], stoi(values[3]), stof(values[4]), values[5]);
  }
  file_series.close();
  return medias;
};
void utils::center_text(const string &str, int total_size, string end)
{
  int padding = (total_size - str.length()) / 2;
  (padding % 2 != 0) && padding++;
  cout << right << setw(padding + str.length()) << str << setw(padding) << end;
}
int utils::get_dato_int(int min, int max)
{
  int result;
  string inp;
  while (true)
  {
    cout << "value(" << min << "," << max << "): ";
    cin >> inp;
    try
    {
      stoi(inp);
      result = stoi(inp);
    }
    catch (const std::exception &e)
    {
      cout << "Error in value type" << "\n";
      continue;
    }
    if (result < min || result > max)
    {
      cout << "Value is not an option" << "\n";
      result = 0;
      continue;
    }
    break;
  }
  return result;
}
int utils::get_dato_int(int max)
{
  int result;
  string inp;
  while (true)
  {
    cout << "value(1," << max << "): ";
    cin >> inp;
    if (inp == "q")
      exit(0);
    try
    {
      stoi(inp);
      result = stoi(inp);
    }
    catch (const std::exception &e)
    {
      cout << "Error in value type" << "\n";
      continue;
    }
    if (result < 1 || result > max)
    {
      cout << "Value is not an option" << "\n";
      result = 0;
      continue;
    }
    break;
  }
  return result;
}
void utils::await_enter()
{
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cin.get();
  clear();
}