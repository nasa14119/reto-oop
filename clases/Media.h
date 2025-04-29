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
    this->id = id;
    this->title = title;
    this->gender = gender;
    this->comments = comments;
    this->duration = duration;
    this->score = score;
  };
  virtual void print() = 0;
  float get_score() { return score; };
  std::string get_id() { return id; };
  int get_duration() { return duration; };
  std::string get_score_str()
  {
    std::ostringstream out;
    out << std::fixed << std::setprecision(1) << score; // Mantén 1 decimal siempre
    return out.str();
  };
  std::string get_gender() { return gender; };
  std::string get_title() { return title; };
  virtual std::string serialized_data() = 0;
  void set_score(float score) { this->score = score; };
};
#endif