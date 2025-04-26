#include "Controller.h"
#include "User.h"
#include "Movies.cpp"
using namespace std;
Controller::Controller(MediaVector *vector_media, User *user) : movies(vector_media), user(user)
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

void Controller::menu_user()
{
  utils::clear();
  std::cout << "1. Save Movie" << "\n";
  std::cout << "2. Save Serie" << "\n";
  std::cout << "3. Rank Movie" << "\n";
  std::cout << "4. Rank Serie" << "\n";
}

Media * Controller::get_index_movies(){
  utils::clear(); 
  int i = 1; 
  for (Media *media : (*movies)){
    cout<<i<<"."; 
    media->print();
    i++; 
  }
  cout<<"Which one of these would you like to save?"<<"\n"; 
  int answer; 
  cin>>answer; 
  return movies->at(answer); 
}
Media * Controller::get_index_series(){
  utils::clear(); 
  int i = 1; 
  for (Media *media : (*series)){
    cout<<i<<"."; 
    media->print();
    i++; 
  }
  cout<<"Which one of these would you like to save?"<<"\n"; 
  int answer; 
  cin>>answer; 
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