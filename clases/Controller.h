#ifndef CONTROLLER
#define CONTROLLER

#include <vector>
#include <iostream>
#include "Media.h"
#include "../const.h"

// Declaración adelantada de User
class User;

class Controller
{
private:
  MediaVector *movies;
  MediaVector *series;
  User *user;

public:
  Controller(MediaVector *vector_movies, MediaVector *vector_series, User *user);
  void print_movies();
  void print_series();
  bool menu_user();
  void menu();
  static MediaVector get_filter_vector(MediaVector, FILTERS);
  void print_filter_by(int);
  static void print_movies(MediaVector *);
  static void print_series(MediaVector *);
  Media *get_index_movies();
  Media *get_index_series();
};

#endif