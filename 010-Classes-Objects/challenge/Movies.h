#ifndef _MOVIES_H_
#define _MOVIES_H_

#include <string>
#include <vector>
#include "Movie.h"

class Movies
{
private:
  std::vector<Movie> movies;
  Movie *find_movie(const std::string &movie_name);

public:
  bool add_movie(std::string movie_name, std::string rating, int watch_count);
  bool increment_watched(std::string movie_name);
  void display() const;
};

#endif