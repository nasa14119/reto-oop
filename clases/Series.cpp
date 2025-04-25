#include "Series.h"
#include "Media.h"
#include <iostream>
#include "../utils.h"
using namespace std;
void Serie::print()
{
  cout << "|" << left << setw(4) << string(4, ' ') << "|";
  cout << left << setw(24) << title << "|";
  cout << setw(15) << " " + gender << "|";
  cout << setw(13) << to_string(duration) + " min" << "|";
  utils::center_text(get_score_str(), 8, "|");
  cout << comments;
  cout << endl;
};
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
void Series::design()
{
  utils::center_text("--------Series--------");
  cout << "|" << setw(3) << "ID" << setw(2) << "|";
  cout << setw(15) << "Chapter" << setw(10) << "|";
  cout << setw(11) << "Genere" << setw(5) << "|";
  cout << setw(11) << "Duration" << setw(3) << "|";
  cout << "  Score |";
  cout << setw(14) << "Comments...";
  cout << "\n";
  cout << endl;
}
void Series::print()
{
  const string id_str = ("----------" + id) + "----------";
  utils::center_text(id_str);
  cout << "|" << left << setw(4) << id << "|";
  cout << left << setw(24) << " " << "|";
  cout << setw(15) << " " + gender << "|";
  cout << setw(13) << to_string(duration) + " min" << "|";
  utils::center_text(get_score_str(), 8, "|");
  cout << endl;
}
void Series::add_serie(Serie *new_serie)
{
  series.emplace_back(new_serie);
}
void Series::add_serie(std::string const id, std::string const title, std::string const gender, int const duration, float const score, std::string const comments)
{
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