#ifndef CONTROLLER
#define CONTROLLER
#include <iomanip>
#include <vector>
#include "Media.h"
#include "Movies.cpp"
using namespace std;
class Controller
{
private:
  MediaVector *movies;

public:
  Controller(MediaVector *vector_media) : movies(vector_media)
  {
  }
  void print_movies()
  {
    Movies::design();
    for (Media *media : (*movies))
    {
      media->print();
    };
  }
  static void print_movies(MediaVector *sorted_movies)
  {
    Movies::design();
    for (Media *media : (*sorted_movies))
    {
      media->print();
    };
  }
};
#endif