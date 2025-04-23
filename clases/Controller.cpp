#ifndef CONTROLLER
#define CONTROLLER
#include <iomanip>
#include <vector>
#include "Media.h"
using namespace std;
class Controller
{
private:
  MediaVector *medias;

public:
  Controller(MediaVector *vector_media) : medias(vector_media)
  {
  }
  void print()
  {
    for (Media *media : *medias)
    {
      media->print();
    };
  }
};
#endif