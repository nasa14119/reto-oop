#include "Media.h"
#include "../utils.h"
#include <sstream>
using namespace std;
string Media::get_score_str()
{
  std::ostringstream out;
  out << std::fixed << std::setprecision(1) << score;
  return out.str();
};
void Media::set_rank()
{
  std::cout << "Assing new rank from 1 to 5" << "\n";
  const float new_score = utils::get_dato_float();
  if (new_score < 0)
    return;
  score = new_score;
}
bool Media::match_str(const string inp)
{
  const string to_check = title.substr(0, inp.length());
  if (inp.length() > 3)
  {
    return to_check == inp;
  }
  const string id_ = id.substr(0, inp.length());
  return id_ == inp || to_check == inp;
}