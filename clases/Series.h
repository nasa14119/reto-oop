#ifndef SERIES
#define SERIES
#include "Media.h"
#include <vector>
using namespace std;
class Serie : public Media
{
public:
  using Media::Media;
  void print();
  string serialized_data();
};
using SeriesVector = vector<Serie *>;
class Series : public Media
{
protected:
  SeriesVector series;
  using Media::Media;

public:
  void add_serie(std::string const id, std::string const title, std::string const gender, int const duration, float const score, std::string const comments);
  void add_serie(Serie *);
  static void design();
  void print();
  string serialized_data();
  SeriesVector get_series() { return series; };
  void set_series(SeriesVector series) { this->series = series; };
};
#endif