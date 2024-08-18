#ifndef _MOVIE_H_
#define _MOVIE_H_

#include <string>

class Movie
{
private:
  std::string movie_name;
  std::string rating;
  int watch_count;

public:
  Movie(const std::string &movie_name, const std::string &rating, const int watch_count);
  Movie(Movie && source);
  void display() const;
  bool is_movie_name_equal(const std::string &movie_name) const;
  void increment_movie_watch_count(const std::string &movie_name);
};

#endif