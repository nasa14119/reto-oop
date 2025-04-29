#pragma once
#include <iostream>
const std::string MOVIES_str = "movies";
const std::string SERIES_str = "series";
enum MENU_USER
{
  DISPLAY_ALL = 1,
  DISPLAY_MOVIES,
  DISPLAY_SERIES,
  MOVIES_EDIT,
  SERIES_EDIT,
  MOVIES_NEW,
  MOVIES_RANK,
  MOVIES_DELETE,
  MOVIES_COMMENT,
  SERIES_NEW,
  SERIES_RANK,
  SERIES_DELETE,
  SERIES_COMMENT,
};
enum FILTERS
{
  ALL = 1,
  SCORE,
  DURATION,
  GENRE,
  ALPHABETICALLY,
};