#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>
#include <iterator>

class Song
{
  friend std::ostream &operator<<(std::ostream &os, const Song &s);
  std::string name;
  std::string artist;
  int rating;

public:
  Song() = default;
  Song(std::string name, std::string artist, int rating)
      : name{name}, artist{artist}, rating{rating} {}
  std::string get_name() const
  {
    return name;
  }
  std::string get_artist() const
  {
    return artist;
  }
  int get_rating() const
  {
    return rating;
  }

  bool operator<(const Song &rhs) const
  {
    return this->name < rhs.name;
  }

  bool operator==(const Song &rhs) const
  {
    return this->name == rhs.name;
  }
};

std::ostream &operator<<(std::ostream &os, const Song &s)
{
  os << std::setw(20) << std::left << s.name
     << std::setw(30) << std::left << s.artist
     << std::setw(2) << std::left << s.rating;
  return os;
}

void display_menu()
{
  std::cout << "\nF - Play First Song" << std::endl;
  std::cout << "N - Play Next song" << std::endl;
  std::cout << "P - Play Previous song" << std::endl;
  std::cout << "A - Add and play a new Song at current location" << std::endl;
  std::cout << "L - List the current playlist" << std::endl;
  std::cout << "===============================================" << std::endl;
  std::cout << "Enter a selection (Q to quit): " << std::endl;
}

void play_current_song(const Song &song)
{
  std::cout << "\nCurrent Song:" << std::endl;
  std::cout << song << std::endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song)
{

  std::cout << std::endl;
  for (const auto &song : playlist)
  {
    std::cout << song << std::endl;
  }

  play_current_song(current_song);
}

void go_to_previous(std::__1::list<Song>::iterator &current_song, std::__1::list<Song> &playlist)
{
  if (current_song == playlist.begin())
  {
    current_song = playlist.end();
  }
  // std::advance(current_song, -1);
  current_song--;

  play_current_song(*current_song);
}

int main()
{

  std::list<Song> playlist{
      {"God's Plan", "Drake", 5},
      {"Never Be The Same", "Camila Cabello", 5},
      {"Pray For Me", "The Weekend and K. Lamar", 4},
      {"The Middle", "Zedd, Maren Morris & Grey", 5},
      {"Wait", "Maroone 5", 4},
      {"Whatever It Takes", "Imagine Dragons", 3}};

  std::list<Song>::iterator current_song = playlist.begin();

  char choice;
  do
  {
    display_menu();
    std::cin >> choice;
    choice = tolower(choice);
    int n = playlist.size();

    if (choice == 'l')
    {
      display_playlist(playlist, *current_song);
    }
    else if (choice == 'f')
    {
      current_song = playlist.begin();
      play_current_song(*current_song);
    }
    else if (choice == 'n')
    {
      current_song++;
      // std::advance(current_song, 1);
      if (current_song == playlist.end())
      {
        current_song = playlist.begin();
      }
      play_current_song(*current_song);
    }
    else if (choice == 'p')
    {
      go_to_previous(current_song, playlist);
    }
    else if (choice == 'a')
    {
      std::string song, artist;
      int rating;
      // Since we are using getline, to avoid any issues, we are calling clear and ignore to remove old unread data from stream so that getline will read new data properly
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Song:";
      std::getline(std::cin, song);

      std::cout << "Artist:";
      std::getline(std::cin, artist);

      std::cout << "Rating:";
      std::cin >> rating;

      playlist.insert(current_song, Song{song, artist, rating});
      go_to_previous(current_song, playlist);
    }
    else if (choice != 'q')
    {
      std::cout << "Invalid Input. Try Again." << std::endl;
    }

  } while (choice != 'q');

  std::cout << "Thanks for listening!" << std::endl;
  return 0;
}
