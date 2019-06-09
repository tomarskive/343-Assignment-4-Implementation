#include "comedy.h"

// --------------------- Default Constructor -----------------------------------------
// Constructs the first name, last name and the month of the actor.
// 
Comedy::Comedy(int stock, string directorFirstName, string directorLastName,
  string title, string actorFirstName, string actorLastName,
  int month, int year) : Movie(stock, directorFirstName,directorLastName,
  title, year)
{
  this->majorActorFirstName = actorFirstName;
  this->majorActorLastName = actorLastName;
  this->month = month;
}

// --------------------- Empty Constructor -----------------------------------------
// Constructs an empty string for the first name, last name and month of actor.
// 
 Comedy::Comedy() : Movie()
 {
   this->majorActorFirstName = "";
   this->majorActorLastName = "";
   this->month = 0;
 }

 // --------------------- getStock() -----------------------------------------
// Returns the current stock of each movie
// 
 int Comedy::getStock()
 {
   return stock;
 }

 // ---------------------getMajorActorFirstName()-----------------------------------------
// Returns the actor's first name
// 
string Comedy::getMajorActorFirstName()
{
  return majorActorFirstName;
}

// --------------------- getMajorActorLastName() -----------------------------------------
// Returns the actor's last name
// 
string Comedy::getMajorActorLastName()
{
  return majorActorLastName;
}

// --------------------- operator== -----------------------------------------
// Returns true if movies are the same, else false.
// 
bool Comedy::operator==(const NodeData & other) const
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
  const Comedy& otherMovie2 = dynamic_cast<const Comedy&>(other);
  return(majorActorFirstName == otherMovie2.majorActorFirstName ||
    majorActorLastName == otherMovie2.majorActorLastName ||
    month == otherMovie2.month);

}

// --------------------- Copy Constructor -----------------------------------------
// Creates a deep cop[y of the binary search tree
// 
bool Comedy::operator!=(const NodeData& other) const
{
  return !(*this==other);
}

// --------------------- Copy Constructor -----------------------------------------
// Creates a deep cop[y of the binary search tree
// 
bool Comedy::operator<(const NodeData &other) const
{

  //cout<<"HERE"<<endl;
  const Comedy& otherMovie = dynamic_cast<const Comedy&>(other);

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

// ---------------------operator> -----------------------------------------
// Returns true if movie year and month is greater, else false.
// 
bool Comedy::operator>(const NodeData &other) const
{

    //cout<<"HERE"<<endl;
    const Comedy& otherMovie = dynamic_cast<const Comedy&>(other);

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

// ---------------------Operator<=( -----------------------------------------
// Returns true if movie is <= than the other
// 
bool Comedy::operator<=(const NodeData &other) const
{
  return !((*this) > other);
}

// ---------------------operator>= -----------------------------------------
// Returns true if movie is >= than the other
// 
bool Comedy::operator>=(const NodeData &other) const
{
  return !(*this < other);
}

// ---------------------operator= -----------------------------------------
// Assignment operator, which compares the actor's first name and last.
// 
NodeData& Comedy::operator=(const NodeData &other)
{

  if(typeid(*this)!= typeid(other))
  {
    cout<<"type mismatch"<<endl;
    return *this;
  }
  const Movie& otherMovie = dynamic_cast<const Movie&>(other);
  Movie::copyHelp(otherMovie);

  const Comedy& otherMovie2 = dynamic_cast<const Comedy&>(other);
  this->majorActorFirstName = otherMovie2.majorActorFirstName;
  this->majorActorLastName = otherMovie2.majorActorLastName;
  this->month = otherMovie2.month;
  return *this;
}

// --------------------- display()-----------------------------------------
// Display function prints the stock, director and actor's information.
// 
void Comedy::display()
{
  cout << stock << " " << directorFirstName << " ";
  cout << directorLastName << " " << title <<" ";
  cout << majorActorFirstName << " " << majorActorLastName;
  cout << " " << month << " " << year << endl;
}

// --------------------- serialize -----------------------------------------
// Outputs the stock, directorLastName, majorActorFirstName and month
// 
void Comedy::serialize(ostream& output) const
{
  output << stock << " " << directorFirstName << " ";
  output << directorLastName << " " << title <<" ";
  output << majorActorFirstName << " " << majorActorLastName
  << " " << month << " " << year;
}

// --------------------- Operator<< -----------------------------------------
// Prints movie's stock, first name, last name, title and date of movie
// 
ostream& operator<<(ostream& output, const Comedy& movie) {
  	output << movie.stock << " " << movie.directorFirstName << " ";
    output << movie.directorLastName << " " << movie.title <<" ";
    output << movie.majorActorFirstName << " " << movie.majorActorLastName
    << " " << movie.month << " " << movie.year;
  	return output;
  }
