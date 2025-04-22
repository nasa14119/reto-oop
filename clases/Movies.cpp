#include <iostream>
#include "Media.h"
using namespace std;

class Movies : public Media
{
public:
  using Media::Media;
  static void design()
  {
    cout << setw(30) << "----------Movies----------" << "\n";
  }
  void print()
  {
    cout << title << endl;
  }
};