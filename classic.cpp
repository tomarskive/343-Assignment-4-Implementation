#include "classic.h"

Classic::Classic(int stock, string directorFirstName, string directorLastName,
  string title, string actorFirstName, string actorLastName,
  int month, int year) : Movie(stock, directorFirstName,directorLastName,
  title, year)
{
  this->majorActorFirstName = actorFirstName;
  this->majorActorLastName = actorLastName;
  this->month = month;
}

Classic::~Classic()
{

}

 Movie& Classic::operator=(const Classic & rhsMovie)
{
  if(this == &rhsMovie)
  {
    return *this;
  }
  this->stock = rhsMovie.stock;
  this->directorFirstName = rhsMovie.directorFirstName;
  this->directorLastName = rhsMovie.directorLastName;
  this->title = rhsMovie.title;
  this->year = rhsMovie.year;
  this->month = rhsMovie.month;
  this->majorActorFirstName = rhsMovie.majorActorFirstName;
  this->majorActorLastName = rhsMovie.majorActorLastName;
  return *this;
}

ostream& operator<<(ostream& output, const Classic& movie) {
  	output << movie.stock << " " << movie.directorFirstName << " ";
    output << movie.directorLastName << " " << movie.title <<" ";
    output << movie.majorActorFirstName << " " << movie.majorActorLastName
    << " " << movie.month << " " << movie.year;
  	return output;
  }
