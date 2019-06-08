#include "movie.h"

Movie::Movie()
{

}

Movie::Movie(int stock, string directorFirstName, string directorLastName,
  string title, int year)
  {
    this->stock = stock;
    this->directorFirstName = directorFirstName;
    this->directorLastName = directorLastName;
    this->title = title;
    this->year = year;
  }

Movie::~Movie()
{

}
Movie& Movie::operator=(const Movie &other)
{
  return *this;
}
/*
ostream& operator<<(ostream& output, const Movie& movie) {
  	output << movie.stock << " " << movie.directorFirstName << " ";
    output << movie.directorLastName << " " << movie.title <<" ";
    output << movie.year;
  	return output;
  }*/
