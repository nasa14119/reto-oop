#include "Controller.h"
#include "User.h"
#include "Movies.cpp"
#include "Series.h"
#include "Filters.h"
using namespace std;
#include "../const.h"
Controller::Controller(MediaVector *vector_movies, MediaVector *vector_series, User *user) : movies(vector_movies), user(user), series(vector_series)
{
}

void Controller::print_movies()
{
  Movies::design();
  for (Media *media : (*movies))
  {
    media->print();
  };
  std::cout << std::endl;
}
void Controller::print_series()
{
  Series::design();
  for (Media *media : (*series))
  {
    media->print();
  };
  std::cout << std::endl;
}
bool Controller::menu_user()
{
  utils::clear();
  std::cout << "My Data" << "\n";
  std::cout << "1. Display All" << "\n";
  std::cout << "2. Display my movies" << "\n";
  std::cout << "3. Display my series" << "\n";
  std::cout << "4. Edit my movies" << "\n";
  std::cout << "5. Edit my series" << "\n";
  int inp = utils::get_dato_int(5);
  if (inp < 0)
    return false;
  utils::clear();
  if (inp == MOVIES_EDIT)
  {
    std::cout << "1. Save new movie" << "\n";
    std::cout << "2. Delete a movie" << "\n";
    std::cout << "3. Rank a movie" << "\n";
    std::cout << "4. Comment movie" << "\n";
    int opt = MOVIES_NEW + (utils::get_dato_int(4) - 1);
    cout << opt << " : " << MOVIES_NEW;
    if (opt == MOVIES_NEW)
    {
      utils::clear();
      print_movies();
      user->search_movie(*movies);
    }
    utils::clear();
    return true;
  }
  if (inp == SERIES_EDIT)
  {
    std::cout << "1. Save new Serie" << "\n";
    std::cout << "2. Delete serie" << "\n";
    std::cout << "3. Rank a serie" << "\n";
    std::cout << "4. Comment a serie" << "\n";
    int opt = SERIES_NEW + (utils::get_dato_int(4) - 1);
    if (opt == SERIES_NEW)
    {
      utils::clear();
      print_series();
      user->search_serie(*series);
    }
    utils::clear();
    return true;
  }
  user->print((MENU_USER)inp);
  utils::await_enter();
  utils::clear();
  std::cout << std::endl;
  return true;
}

Media *Controller::get_index_movies()
{
  utils::clear();
  int i = 1;
  for (Media *media : (*movies))
  {
    cout << i << ".";
    media->print();
    i++;
  }
  cout << "Which one of these would you like to save?" << "\n";
  int answer;
  cin >> answer;
  return movies->at(answer);
}
Media *Controller::get_index_series()
{
  utils::clear();
  int i = 1;
  for (Media *media : (*series))
  {
    cout << i << ".";
    media->print();
    i++;
  }
  cout << "Which one of these would you like to save?" << "\n";
  int answer;
  cin >> answer;
  return series->at(answer);
}

void Controller::print_movies(MediaVector *sorted_movies)
{
  Movies::design();
  for (Media *media : (*sorted_movies))
  {
    media->print();
  };
  std::cout << std::endl;
}
void Controller::print_series(MediaVector *sorted_series)
{
  Series::design();
  for (Media *media : *sorted_series)
  {
    media->print();
  };
  std::cout << std::endl;
}
void Controller::print_filter_by(const int &inp)
{
  std::string inp_2;
  cout << "Desending(y): ";
  cin.ignore();
  getline(cin, inp_2);
  if (inp_2 == "q")
    exit(0);
  bool is_deseindig = (inp_2 != "n");
  cout << "1. By Score" << "\n";
  cout << "2. By Duration" << "\n";
  cout << "3. By Genre" << "\n";
  cout << "4. By Alphabetcially" << "\n";
  int opt = utils::get_dato_int(4);
  MediaVector filterSeries;
  MediaVector filterMovies;
  switch (opt)
  {
  case 1:
    if (inp == 4 || inp == 5)
      filterMovies = filters::filter_by_score(*movies, is_deseindig);
    if (inp == 4 || inp == 6)
      filterSeries = filters::filter_by_score(*series, is_deseindig);
    break;
  case 2:
    if (inp == 4 || inp == 5)
      filterMovies = filters::filter_by_duration(*movies, is_deseindig);
    if (inp == 4 || inp == 6)
      filterSeries = filters::filter_by_duration(*series, is_deseindig);
    break;
  case 3:
    if (inp == 4 || inp == 5)
      filterMovies = filters::filter_by_gender(*movies, is_deseindig);
    if (inp == 4 || inp == 6)
      filterSeries = filters::filter_by_gender(*series, is_deseindig);
    break;
  case 4:
    if (inp == 4 || inp == 5)
      filterMovies = filters::filter_by_title(*movies, is_deseindig);
    if (inp == 4 || inp == 6)
      filterSeries = filters::filter_by_series_alpha(*series, is_deseindig);
    break;
  default:
    break;
  }
  utils::clear();
  if (inp == 4 || inp == 5)
    print_movies(&filterMovies);
  if (inp == 4 || inp == 6)
    print_series(&filterSeries);
  ;
  utils::await_enter();
}
void Controller::menu()
{
  std::cout << "Main Menu" << "\n";
  std::cout << "1. Print all" << "\n";
  std::cout << "2. Print movies" << "\n";
  std::cout << "3. Print series" << "\n";
  std::cout << "4. Print all by" << "\n";
  std::cout << "5. Print movies by" << "\n";
  std::cout << "6. Print series by" << "\n";
  std::cout << "7. Login as user" << "\n";
  const int inp = utils::get_dato_int(7);
  utils::clear();
  if (inp == 7)
  {
    bool is_runnig = true;
    while (is_runnig)
    {
      is_runnig = menu_user();
    }
    utils::clear();
    return;
  }

  if (inp > 3)
  {
    utils::clear();
    print_filter_by(inp);
    return;
  }
  if (inp != DISPLAY_SERIES)
    print_movies();
  if (inp != DISPLAY_MOVIES)
    print_series();
  utils::await_enter();
  utils::clear();
}