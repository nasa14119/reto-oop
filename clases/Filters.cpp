#ifndef FILTERS
#define FILTERS
#include <iostream>
#include <vector>
#include <algorithm>
#include "Controller.cpp"
#include "Media.h"
using std::string;
namespace filters
{
  MediaVector filter_by_score(MediaVector midias, bool orderAcendent = true)
  {
    if (orderAcendent)
    {
      sort(midias.begin(), midias.end(), [](Media *a, Media *b)
           { return a->get_score() > b->get_score(); });
    }
    else
    {
      sort(midias.begin(), midias.end(), [](Media *a, Media *b)
           { return a->get_score() < b->get_score(); });
    }
    return midias;
  };
  MediaVector filter_by_duration(MediaVector midias, bool orderAcendent = true)
  {
    if (orderAcendent)
    {
      sort(midias.begin(), midias.end(), [](Media *a, Media *b)
           { return a->get_duration() < b->get_duration(); });
    }
    else
    {
      sort(midias.begin(), midias.end(), [](Media *a, Media *b)
           { return a->get_duration() > b->get_duration(); });
    }

    return midias;
  };
  MediaVector filter_by_gender(MediaVector midias, bool alphabetical = true)
  {
    if (alphabetical)
    {
      sort(midias.begin(), midias.end(), [](Media *a, Media *b)
           { return a->get_gender() < b->get_gender(); });
    }
    else
    {
      sort(midias.begin(), midias.end(), [](Media *a, Media *b)
           { return a->get_gender() > b->get_gender(); });
    }

    return midias;
  };
  MediaVector filter_by_title(MediaVector midias, bool alphabetical = true)
  {
    if (alphabetical)
    {
      sort(midias.begin(), midias.end(), [](Media *a, Media *b)
           { return a->get_title() < b->get_title(); });
    }
    else
    {
      sort(midias.begin(), midias.end(), [](Media *a, Media *b)
           { return a->get_title() > b->get_title(); });
    }

    return midias;
  };
}
#endif