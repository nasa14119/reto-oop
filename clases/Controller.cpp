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
    utils::clear();
    switch (opt)
    {
    case MOVIES_NEW:
      user->save_movie(*movies);
      break;
    case MOVIES_DELETE:
      user->delete_movie();
      break;
    case MOVIES_RANK:
      user->rank_movies();
      break;
    case MOVIES_COMMENT:
      user->comment_movies();
      break;
    default:
      break;
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
    utils::clear();
    switch (opt)
    {
    case SERIES_NEW:
      user->save_serie(series);
      break;
    case SERIES_DELETE:
      user->delete_series();
      break;
    case SERIES_RANK:
      user->rank_series();
      break;
    case SERIES_COMMENT:
      user->comment_series();
      break;
    default:
      break;
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
MediaVector Controller::get_filter_vector(MediaVector medias, FILTERS inp = MOVIES_OPT)
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
  int opt = FILTERS::SCORE + (utils::get_dato_int(4) - 1);
  MediaVector filterVector;
  switch (opt)
  {
  case FILTERS::SCORE:
    filterVector = filters::filter_by_score(medias, is_deseindig);
    break;

  case FILTERS::DURATION:
    filterVector = filters::filter_by_duration(medias, is_deseindig);
    break;

  case FILTERS::GENRE:
    filterVector = filters::filter_by_gender(medias, is_deseindig);
    break;
  case FILTERS::ALPHABETICALLY:
    if (inp != FILTERS::MOVIES_OPT)
    {
      filterVector = filters::filter_by_series_alpha(medias, is_deseindig);
    }
    else
    {
      filterVector = filters::filter_by_title(medias, is_deseindig);
    }
    break;
  default:
    break;
  }
  return filterVector;
};
void Controller::print_filter_by(const int inp)
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
  int opt = FILTERS::SCORE + (utils::get_dato_int(4) - 1);
  MediaVector filterSeries;
  MediaVector filterMovies;
  switch (opt)
  {
  case FILTERS::SCORE:
    if (inp == FILTERS::ALL || inp == FILTERS::MOVIES_OPT)
      filterMovies = filters::filter_by_score(*movies, is_deseindig);
    if (inp == FILTERS::ALL || inp == FILTERS::SERIES_OPT)
      filterSeries = filters::filter_by_score(*series, is_deseindig);
    break;
  case FILTERS::DURATION:
    if (inp == FILTERS::ALL || inp == FILTERS::MOVIES_OPT)
      filterMovies = filters::filter_by_duration(*movies, is_deseindig);
    if (inp == FILTERS::ALL || inp == FILTERS::SERIES_OPT)
      filterSeries = filters::filter_by_duration(*series, is_deseindig);
    break;
  case FILTERS::GENRE:
    if (inp == FILTERS::ALL || inp == FILTERS::MOVIES_OPT)
      filterMovies = filters::filter_by_gender(*movies, is_deseindig);
    if (inp == FILTERS::ALL || inp == FILTERS::SERIES_OPT)
      filterSeries = filters::filter_by_gender(*series, is_deseindig);
    break;
  case FILTERS::ALPHABETICALLY:
    if (inp == FILTERS::ALL || inp == FILTERS::MOVIES_OPT)
      filterMovies = filters::filter_by_title(*movies, is_deseindig);
    if (inp == FILTERS::ALL || inp == FILTERS::SERIES_OPT)
      filterSeries = filters::filter_by_series_alpha(*series, is_deseindig);
    break;
  default:
    break;
  }
  // utils::clear();
  if (inp == FILTERS::MOVIES_OPT || inp == FILTERS::ALL)
    print_movies(&filterMovies);
  if (inp == FILTERS::SERIES_OPT || inp == FILTERS::ALL)
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
    print_filter_by(inp - 3);
    return;
  }
  if (inp != DISPLAY_SERIES)
    print_movies();
  if (inp != DISPLAY_MOVIES)
    print_series();
  utils::await_enter();
  utils::clear();
}