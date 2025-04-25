#include "Series.h"
#include "Media.h"
#include <iostream>
#include "../utils.h"
using namespace std;
string Serie::serialized_data()
{
  string data = "";
  data += (id + ",");
  data += (title + ",");
  data += (gender + ",");
  data += (to_string(duration) + ",");
  data += (get_score_str() + ",");
  data += (comments);
  data += "\n";
  return data;
};
void Serie::print()
{
  cout << "|" << left << setw(4) << string(4, ' ') << "|";
  cout << left << setw(32) << title << "|";
  cout << setw(9) << " " + gender << "|";
  cout << setw(9) << to_string(duration) + " min" << "|";
  cout << setw(4) << get_score_str() << "|";
  cout << comments;
  cout << endl;
};
void Series::design()
{
  utils::center_text("--------Series--------");
  cout << "|" << setw(3) << "ID" << setw(2) << "|";
  cout << left << setw(32) << "Chapter" << "|";
  cout << left << setw(9) << "Genre" << "|";
  cout << left << setw(9) << "Duration" << "|";
  cout << left << setw(4) << "Rank" << "|";
  cout << left << setw(14) << "Comments...";
  cout << "\n";
  cout << endl;
}
void Series::print()
{
  const string id_str = ("----------" + id) + "---------";
  utils::center_text(id_str);
  cout << "|" << left << setw(4) << id << "|";
  // Espacio en blanco donde van los capitulos
  cout << left << setw(32) << " " << "|";
  cout << setw(9) << " " + gender << "|";
  cout << setw(9) << to_string(duration) + " min" << "|";
  cout << get_score_str();
  cout << "\n";
  cout << "|" << string(82, '-') << "|" << "\n";
  for (Serie *value : series)
  {
    value->print();
  }
  cout << endl;
}
void Series::add_serie(Serie *new_serie)
{
  series.emplace_back(new_serie);
}
void Series::add_serie(std::string const id, std::string const title, std::string const gender, int const duration, float const score, std::string const comments)
{
  this->duration += duration;
  this->score = (this->score + score) / 2;
  series.emplace_back(new Serie(id, title, gender, duration, score, comments));
}
string Series::serialized_data()
{
  string data = "";
  for (Serie *chapter : series)
  {
    data += chapter->serialized_data();
  }
  return data;
}