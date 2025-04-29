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
  if (MENU_USER::DISPLAY_ALL || MENU_USER::DISPLAY_MOVIES)
  {
    Controller::print_movies(&movies);
  }
  if (MENU_USER::DISPLAY_ALL || MENU_USER::DISPLAY_SERIES)
  {
    Controller::print_movies(&movies);
  }
}
void User::get_file_data()
{
  utils::get_data_movies(movies, "../mydata.csv");
  ifstream series_part = utils::get_data_movies("../mydata.csv");
  utils::get_data_series(series_part, series);
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
void User::save_movie()
{
}
Media *User::search_movie(MediaVector source_movies)
{
  MediaVector results;
  while (results.size() != 1)
  {
    cout << "Enter id or the movie's name: ";
    string inp;
    getline(cin, inp);
    utils::clear();
    results.clear();
    for (Media *movie : source_movies)
    {
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
  }
  save_file << "series" << "\n";
  for (int i = 0; i < series.size(); i++)
  {
    save_file << series[i]->serialized_data();
  }

  save_file.close();
}