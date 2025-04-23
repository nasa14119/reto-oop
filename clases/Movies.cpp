#ifndef MOVIES
#define MOVIES
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
    cout << "|" << setw(3) << "ID" << setw(2) << "|";
    cout << setw(15) << "Title" << setw(10) << "|";
    cout << setw(11) << "Gender" << setw(5) << "|";
    cout << setw(11) << "Duration" << setw(3) << "|";
    cout << "  Score |";
    cout << setw(14) << "Comments...";
    cout << endl;
  }
  void print()
  {
    cout << "|" << left << setw(4) << id << "|";
    cout << left << setw(24) << title << "|";
    cout << setw(15) << " " + gender << "|";
    cout << setw(13) << to_string(duration) + " min" << "|";
    cout << setw(8) << score << "|";
    cout << comments;
    cout << endl;
  }
};
#endif