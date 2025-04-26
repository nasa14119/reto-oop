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
  MediaVector *series; 
  User *user;

public:
  Controller(MediaVector *vector_media, User *user);
  void print_movies();
  void menu_user();
  Media *get_index_movies(); 
  Media *get_index_series(); 
  static void print_movies(MediaVector *sorted_movies);
};

#endif