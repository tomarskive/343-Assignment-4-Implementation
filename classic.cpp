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

 Classic::Classic() : Movie()
 {
   this->majorActorFirstName = "";
   this->majorActorLastName = "";
   this->month = 0;
 }

 int Classic::getStock()
 {
   return stock;
 }

string Classic::getMajorActorFirstName()
{
  return majorActorFirstName;
}

string Classic::getMajorActorLastName()
{
  return majorActorLastName;
}

bool Classic::operator==(const NodeData & other) const
{
  if(typeid(*this)!= typeid(other))
  {
    return false;
  }

  // const Movie& otherMovie = dynamic_cast<const Movie&>(other);

  if(!Movie::compare(other))
  {
    return false;
  }
  const Classic& otherMovie2 = dynamic_cast<const Classic&>(other);
  return(majorActorFirstName == otherMovie2.majorActorFirstName ||
    majorActorLastName == otherMovie2.majorActorLastName ||
    month == otherMovie2.month);

}
bool Classic::operator!=(const NodeData& other) const
{
  return !(*this==other);
}


bool Classic::operator<(const NodeData &other) const
{

  //cout<<"HERE"<<endl;
  const Classic& otherMovie = dynamic_cast<const Classic&>(other);

  if(this->year < otherMovie.year)
  {
    return true;
  }

  if(this->year == otherMovie.year)
  {
    //cout<<"got here"<<endl;
    if(this->month < otherMovie.month)
    {
      return true;
    }
    if(this->month == otherMovie.month)
    {
      if((this->majorActorFirstName + " " + this->majorActorLastName) <
      (otherMovie.majorActorFirstName + " " + otherMovie.majorActorLastName))
      {
        return true;
      }
    }
  }
  return false;
}

bool Classic::operator>(const NodeData &other) const
{

    //cout<<"HERE"<<endl;
    const Classic& otherMovie = dynamic_cast<const Classic&>(other);

    if(this->year > otherMovie.year)
    {
      return true;
    }

    if(this->year == otherMovie.year)
    {
      //cout<<"got here"<<endl;
      if(this->month > otherMovie.month)
      {
        return true;
      }
      if(this->month == otherMovie.month)
      {
        if((this->majorActorFirstName + " " + this->majorActorLastName) >
        (otherMovie.majorActorFirstName + " " + otherMovie.majorActorLastName))
        {
          return true;
        }
      }
    }
  return false;
}

bool Classic::operator<=(const NodeData &other) const
{
  return !((*this) > other);
}

bool Classic::operator>=(const NodeData &other) const
{
  return !(*this < other);
}

NodeData& Classic::operator=(const NodeData &other)
{

  if(typeid(*this)!= typeid(other))
  {
    cout<<"type mismatch"<<endl;
    return *this;
  }
  const Movie& otherMovie = dynamic_cast<const Movie&>(other);
  Movie::copyHelp(otherMovie);

  const Classic& otherMovie2 = dynamic_cast<const Classic&>(other);
  this->majorActorFirstName = otherMovie2.majorActorFirstName;
  this->majorActorLastName = otherMovie2.majorActorLastName;
  this->month = otherMovie2.month;
  return *this;
}

void Classic::display()
{
  cout << stock << " " << directorFirstName << " ";
  cout << directorLastName << " " << title <<" ";
  cout << majorActorFirstName << " " << majorActorLastName;
  cout << " " << month << " " << year << endl;
}
void Classic::serialize(ostream& output) const
{
  output << stock << " " << directorFirstName << " ";
  output << directorLastName << " " << title <<" ";
  output << majorActorFirstName << " " << majorActorLastName
  << " " << month << " " << year;
}

ostream& operator<<(ostream& output, const Classic& movie) {
  	output << movie.stock << " " << movie.directorFirstName << " ";
    output << movie.directorLastName << " " << movie.title <<" ";
    output << movie.majorActorFirstName << " " << movie.majorActorLastName
    << " " << movie.month << " " << movie.year;
  	return output;
  }
