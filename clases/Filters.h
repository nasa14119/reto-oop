#ifndef FILTERS_H
#define FILTERS_H

#include <vector>
#include "Media.h"

namespace filters
{
  MediaVector filter_by_score(MediaVector midias, bool orderAcendent = true);
  MediaVector filter_by_duration(MediaVector midias, bool orderAcendent = true);
  MediaVector filter_by_gender(MediaVector midias, bool alphabetical = true);
  MediaVector filter_by_title(MediaVector midias, bool alphabetical = true);
  MediaVector filter_by_series_alpha(MediaVector midias, bool alphabetical = true);
};

#endif