#include <fstream>
#include "User.h"
#include "Controller.h" // Incluye Controller solo en el archivo fuente
#include "../const.h"
#include "Series.h"
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
void User::save_movie(MediaVector movies)
{
  cout << "Discover movies:" << "\n";
  cout << "1. Order by" << "\n";
  cout << "2. Print by ID" << "\n";
  const int inp = utils::get_dato_int(2);
  Media *new_movie;
  if (inp != 1)
  {
    Controller::print_movies(&movies);
    new_movie = search_movie(movies);
  }
  else
  {
    new_movie = search_movie(Controller::get_filter_vector(movies, MOVIES_OPT));
  }
  utils::clear();
  cout << "You are going to add this movie:" << "\n";
  new_movie->print();
  if (!utils::confirmation())
  {
    return;
  }
  save_movie(new_movie);
}
void User::delete_movie()
{
  cin.ignore();
  Media *deleting = search_movie(movies, false);
  utils::clear();
  cout << "Your are tring to delete this movie:" << "\n";
  deleting->print();
  if (!utils::confirmation())
  {
    return;
  }
  delete_movie(deleting);
}
void User::delete_movie(Media *errase)
{
  const string errase_id = errase->get_id();
  for (int i = 0; i < movies.size(); ++i)
  {
    Media *element = movies[i];
    if (element->get_id() == errase_id)
    {
      movies.erase(movies.begin() + i);
      break;
    }
  }
  save_to_file();
}
void User::delete_series()
{
  cin.ignore();
  Media *deleting = search_movie(series, false);
  utils::clear();
  cout << "Your are tring to delete this serie:" << "\n";
  deleting->print();
  if (!utils::confirmation())
  {
    return;
  }
  delete_movie(deleting);
}
void User::delete_series(Media *errase)
{
  const string errase_id = errase->get_id();
  for (int i = 0; i < series.size(); ++i)
  {
    Media *element = movies[i];
    if (element->get_id() == errase_id)
    {
      movies.erase(series.begin() + i);
      break;
    }
  }
  save_to_file();
}
Media *User::search_movie(MediaVector source_movies, bool only_new)
{
  if (source_movies.empty())
    return nullptr;
  Controller::print_movies(&source_movies);
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
      if (only_new && User::contains(movie))
        continue;
      if (movie->match_str(inp))
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
Media *User::search_serie(MediaVector source_series, bool only_new)
{
  MediaVector results;
  cin.ignore();
  Controller::print_series(&source_series);
  while (results.size() != 1)
  {
    cout << "Enter id or the chapter's title: ";
    string inp;
    getline(cin, inp);
    if (inp == "q")
      exit(0);
    utils::clear();
    results.clear();
    for (Media *series : source_series)
    {
      if (only_new && User::contains(series))
        continue;
      Series *series_ = dynamic_cast<Series *>(series);
      if (series_->match_in_titles(inp))
      {
        results.push_back(series);
        series->print();
      }
    }
    if (results.empty())
    {
      cout << "No serie found try again\n";
      results.clear();
    }
  }
  return results[0];
}
void User::save_serie(MediaVector *source_series)
{
  cout << "Discover movies:" << "\n";
  cout << "1. Order by" << "\n";
  cout << "2. Print by ID" << "\n";
  const int inp = utils::get_dato_int(2);
  Media *new_serie;
  if (inp != 1)
  {
    new_serie = search_serie(*source_series);
  }
  else
  {
    new_serie = search_serie(Controller::get_filter_vector(*source_series, SERIES_OPT));
  }
  utils::clear();
  cout << "You are going to add this serie:" << "\n";
  new_serie->print();
  if (!utils::confirmation())
  {
    return;
  }
  save_serie(new_serie);
}
void User::save_serie(Media *serie)
{
  this->series.push_back(serie);
  // Implementación para guardar una serie
  save_to_file();
}

void User::rank_movies()
{
  Media *movie = search_movie(movies, false);
  movie->set_rank();
  save_to_file();
}
void User::comment_movies()
{
  Media *movie = search_movie(movies, false);
  movie->set_comment();
  save_to_file();
}
void User::comment_series()
{
  Media *serie = search_movie(series, false);
  serie->set_comment();
  save_to_file();
}
void User::rank_series()
{
  Media *serie = search_serie(series, false);
  serie->set_rank();
  dynamic_cast<Series *>(serie)->update_score();
  save_to_file();
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