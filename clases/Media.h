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
    this->id = id;
    this->title = title;
    this->gender = gender;
    this->comments = comments;
    this->duration = duration;
    this->score = score;
  };
  // Methods
  bool match_str(std::string);
  // Abstract methods
  virtual void print() = 0;
  virtual std::string serialized_data() = 0;
  // Setters
  virtual void set_rank();
  virtual void set_comment();
  void set_rank(float score) { this->score = score; };
  std::string get_score_str();
  // Getters
  float get_score() { return score; };
  std::string get_id() { return id; };
  int get_duration() { return duration; };
  std::string get_gender() { return gender; };
  std::string get_title() { return title; };
};
#endif