#include <iostream>
#include "Movie.h"

Movie::Movie(const std::string &movie_name, const std::string &rating, const int watch_count)
    : movie_name{movie_name}, rating{rating}, watch_count{watch_count}
{
}

Movie::Movie(Movie &&source)
{
  movie_name = std::move(source.movie_name);
  rating = std::move(source.rating);
  watch_count = source.watch_count;

  source.movie_name = "";
  source.rating = "";
  source.watch_count = 0;
}

void Movie::display() const
{
  std::cout << "\nName: " << movie_name << std::endl;
  std::cout << "Rating: " << rating << std::endl;
  std::cout << "Watch Count: " << watch_count << std::endl;
}

bool Movie::is_movie_name_equal(const std::string &movie_name) const
{
  return movie_name == this->movie_name;
}

void Movie::increment_movie_watch_count(const std::string &movie_name)
{
  this->watch_count++;
}
