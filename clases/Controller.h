#ifndef CONTROLLER
#define CONTROLLER

#include <vector>
#include <iostream>
#include "Media.h"

// Declaración adelantada de User
class User;

class Controller
{
private:
  MediaVector *movies;
  User *user;

public:
  Controller(MediaVector *vector_media, User *user);
  void print_movies();
  void menu_user();
  static void print_movies(MediaVector *sorted_movies);
};

#endif