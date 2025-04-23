#ifndef MEDIA
#define MEDIA
#include <iomanip>
#include <vector>
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
  std::string get_gender() { return gender; };
  std::string get_title() { return title; };
};
#endif