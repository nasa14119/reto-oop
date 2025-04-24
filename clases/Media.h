#ifndef MEDIA
#define MEDIA
#include <iomanip>
#include <vector>
#include <sstream>
class Media;
using MediaVector = std::vector<Media *>;
class Media
{
protected:
  std::string id, title, gender, comments;
  int duration;
  float score;

public:
  Media(std::string const id, std::string const title, std::string const gender, int const duration, float const score, std::string const comments)
  {
    Media::id = id;
    Media::title = title;
    Media::gender = gender;
    Media::comments = comments;
    Media::duration = duration;
    Media::score = score;
  };
  virtual void print() = 0;
  int get_score() { return score; };
  float get_duration() { return duration; };
  std::string get_score_str()
  {
    std::ostringstream out;
    out << std::fixed << std::setprecision(0) << score;
    std::string res = out.str();
    int decimal = static_cast<int>(score * 10) % 10;
    if (decimal > 0)
    {
      res += ".";
      res += std::to_string(decimal);
    }
    return res;
  };
  std::string get_gender() { return gender; };
  std::string get_title() { return title; };
  virtual std::string serialized_data() = 0;
};
#endif