#include <fstream>
#include "User.h"
#include "Controller.h" // Incluye Controller solo en el archivo fuente
#include "../const.h"
User::User()
{
  get_file_data();
}
void User::print(MENU_USER option)
{
  if (option == MENU_USER::DISPLAY_ALL || option == MENU_USER::DISPLAY_MOVIES)
  {
    Controller::print_movies(&movies);
  }
  if (option == MENU_USER::DISPLAY_ALL || option == MENU_USER::DISPLAY_SERIES)
  {
    Controller::print_series(&series);
  }
}
void User::get_file_data()
{
  utils::get_data_movies(movies, "../mydata.csv");
  ifstream series_part = utils::get_data_movies("../mydata.csv");
  utils::get_data_series(series_part, series);
  for (Media *media : movies)
  {
    keys[media->get_id()] = media;
  }
  for (Media *media : series)
  {
    keys[media->get_id()] = media;
  }
}
User::~User()
{
  save_to_file();
};
void User::save_movie(Media *movie)
{
  this->movies.push_back(movie);
  // Implementación para guardar una película
  save_to_file();
}
bool User::contains(Media *media) { return keys.contains(media->get_id()); };
bool User::contains(string str) { return keys.contains(str); };
void User::save_movie()
{
  cout << "Discover movies:" << "\n";
  cout << "1. Order by" << "\n";
  cout << "2. Search" << "\n";
  cout << "3. Print by ID" << "\n";
}
Media *User::search_movie(MediaVector source_movies)
{
  MediaVector results;
  while (results.size() != 1)
  {
    cout << "Enter id or the movie's name: ";
    string inp;
    getline(cin, inp);
    if (inp == "q")
      exit(0);
    utils::clear();
    results.clear();
    for (Media *movie : source_movies)
    {
      if (User::contains(movie))
        continue;
      const string id = (movie->get_id()).substr(0, inp.length());
      if (inp.length() <= 3 && inp == id)
      {
        results.push_back(movie);
        movie->print();
        continue;
      }
      string check = (movie->get_title()).substr(0, inp.length());
      if (check == inp)
      {
        results.push_back(movie);
        movie->print();
      }
    }
    if (results.empty())
    {
      cout << "No movie found try again\n";
      results.clear();
    }
  }
  return results[0];
}
Media *User::search_serie(MediaVector source_series)
{
}
void User::save_serie(Media *serie)
{
  this->series.push_back(serie);
  // Implementación para guardar una serie
  save_to_file();
}

void User::rank_movie(Media *movie)
{
  // Implementación para rankear una película
  float new_score = movie->get_score();
  cout << "What would you rate the movie?" << "\n";
  float answer;
  cin >> answer;
  new_score = (new_score + answer) / 2;
  movie->set_score(new_score);
}

void User::rank_serie(Media *serie)
{
  // Implementación para rankear una serie
  float new_score = serie->get_score();
  cout << "What would you rate the series?" << "\n";
  float answer;
  cin >> answer;
  new_score = (new_score + answer) / 2;
  serie->set_score(new_score);
}

void User::save_to_file()
{
  string file_path = utils::get_file_path("../mydata.csv");
  ofstream save_file(file_path);
  save_file << "movies" << "\n";
  for (int i = 0; i < movies.size(); i++)
  {
    save_file << movies[i]->serialized_data();
    keys[movies[i]->get_id()] = movies[i];
  }
  save_file << "series" << "\n";
  for (int i = 0; i < series.size(); i++)
  {
    save_file << series[i]->serialized_data();
    keys[series[i]->get_id()] = series[i];
  }
  save_file.close();
}