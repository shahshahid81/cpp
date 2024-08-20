#include <iostream>
#include "Movies.h"

Movie *Movies::find_movie(const std::string &movie_name)
{
  for (auto &movie : movies)
  {
    if (movie.is_movie_name_equal(movie_name))
    {
      return &movie;
    }
  }
  return nullptr;
}

bool Movies::add_movie(std::string movie_name, std::string rating, int watch_count)
{
  if (find_movie(movie_name) != nullptr)
  {
    return false;
  }

  movies.push_back(Movie{movie_name, rating, watch_count});
  return true;
}

bool Movies::increment_watched(std::string movie_name)
{
  Movie *movie = find_movie(movie_name);
  if (movie == nullptr)
  {
    return false;
  }

  movie->increment_movie_watch_count(movie_name);
  return true;
}

void Movies::display() const
{
  std::cout << "------------------------------" << std::endl;
  std::cout << "Current Movies List: " << std::endl;
  for (const auto &movie : movies)
  {
    movie.display();
  }
  std::cout << "------------------------------" << std::endl;
}
