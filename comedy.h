//--------------------------classic.h-------------------------------------------
//Created by Kathleen Guinee CSS343 Section B
//Created: 5/22/2019
//Last Modification: 5/22/2019
//------------------------------------------------------------------------------
//Purpose: This is the header file for a comedy class that inherits from
//movie.h . This class instantiates and compares different movie objects in
//order to allow for storing of all objects in the correct order.
//------------------------------------------------------------------------------
//Notes:

//this class uses polymorphism to override the equality and comparison
//operators. The functions in the parent class for ==, !=, < and > are virtual.
//------------------------------------------------------------------------------

#ifndef COMEDY_H
#define COMEDY_H
using namespace std;

class Classic : public Movie
{

public:
  //default constructor for movie of type comedy. Initializes values
  // to 0 or Null;
  Comedy();

  //constructor that takes in all of the information neeed to create a comedy
  //movie object. This will
  Comedy(int stock, string directorFirstName, string directorLastName,
    string title, string actorFirstName, string actorLastName, int year);
  //default destructor. No extra memory should be allocated for this, so this
  //does nothing.
  ~Comedy();

  //prints out all of the data stored in this obect in the proper order.
  void display();

  //Overloaded equality operator. Compares two comedy movies.
  //Returns true if they are equal
  bool operator==(const Movie&) const;

  //Overloaded inequality operator. Compares two comedy movies.
  //Returns false if they are equal.
  bool operator!=(const Movie&) const;

  //Overloaded < operator. compares two comedy movies. Returns true if
  //lhs movie is less than rhs movie.
  bool operator<(const Movie&) const;

  //Overloaded > operator. Compares two comedy movies. Returns true if  lhs
  // movie is greater than rhs movie.
  bool operator>(const Movie&) const;

private:
  //all atributes are the same as the parent class.
};
#endif
