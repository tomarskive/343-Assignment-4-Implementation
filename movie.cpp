#include "movie.h"

Movie::Movie()
{
  this->stock = 0;
  this->directorFirstName = "";
  this->directorLastName = "";
  this->title = "";
  this->year = 0;
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

  bool Movie::operator==(const NodeData &rhs) const
  {
    if(typeid(*this)!= typeid(rhs))
    {
      return false;
    }
    return compare(rhs);
  }
  bool Movie::compare(const NodeData& other) const
  {
    const Movie& otherMovie = dynamic_cast<const Movie&>(other);

    return(stock == otherMovie.stock && directorFirstName == otherMovie.directorFirstName
    && directorLastName == otherMovie.directorLastName && title == otherMovie.title
    && year == otherMovie.year);
  }
   int Movie::getStock()
   {
     return stock;
   }

  void Movie::copyHelp(const NodeData &other)
  {

    const Movie& otherMovie = dynamic_cast<const Movie&>(other);
    this->stock = otherMovie.stock;
    this->directorFirstName = otherMovie.directorFirstName;
    this->directorLastName = otherMovie.directorLastName;
    this->title = otherMovie.title;
    this->year = otherMovie.year;
  }
// Movie::~Movie()
// {
//
// }
// Movie& Movie::operator=(const Movie &other)
// {
//   return *this;
// }
/*
ostream& operator<<(ostream& output, const Movie& movie) {
  	output << movie.stock << " " << movie.directorFirstName << " ";
    output << movie.directorLastName << " " << movie.title <<" ";
    output << movie.year;
  	return output;
  }*/
