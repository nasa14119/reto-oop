#ifndef MEDIA
#define MEDIA
#include <iomanip>
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
};
#endif