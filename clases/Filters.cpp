
#include <iostream>
#include <vector>
#include <algorithm>
#include "Controller.h"
#include "Media.h"
#include "Series.h"
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
  MediaVector filter_by_series_alpha(MediaVector midias, bool alphabetical = true)
  {
    sort(midias.begin(), midias.end(), [](Media *a, Media *b)
         { return a->get_id() > b->get_id(); });
    if (!alphabetical)
      reverse(midias.begin(), midias.end());
    int i = 0;
    for (Media *media : midias)
    {
      Series *series = dynamic_cast<Series *>(media);
      SeriesVector vector_series = series->get_series();
      if (alphabetical)
      {
        sort(vector_series.begin(), vector_series.end(), [](Media *a, Media *b)
             { return a->get_title() < b->get_title(); });
      }
      else
      {
        sort(vector_series.begin(), vector_series.end(), [](Media *a, Media *b)
             { return a->get_title() > b->get_title(); });
      }
      series->set_series(vector_series);
      midias[i] = series;
      i++;
    }

    return midias;
  };
}