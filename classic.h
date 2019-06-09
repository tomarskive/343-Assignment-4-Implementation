//--------------------------classic.h-------------------------------------------
//Created by Kathleen Guinee CSS343 Section B
//Created: 5/22/2019
//Last Modification: 5/22/2019
//------------------------------------------------------------------------------
//Purpose: This is the header file for a classic class that inherits from
//movie.h . This class instantiates and compares different movie objects in
//order to allow for storing of all objects in the correct order.
//------------------------------------------------------------------------------
//Notes:
//this class uses polymorphism to override the equality and comparison
//operators. The functions in the parent class for ==, !=, < and > are virtual.
//------------------------------------------------------------------------------

#ifndef CLASSIC_H
#define CLASSIC_H
#include "movie.h"
#include <typeinfo>
#include <string>

using namespace std;

class Classic : public Movie
{
  friend ostream & operator<<(ostream &, const Classic &);
public:
  //default constructor for movie of type classic. Initializes values
  // to 0 or Null;
  Classic();

  //constructor that takes in all of the information neeed to create a classic
  //movie object.
  Classic(int stock, string directorFirstName, string directorLastName,
    string title, string actorFirstName, string actorLastName,
    int month, int year);
  //default destructor. No extra memory should be allocated for this, so this
  //does nothing.
  //~Classic();

  //overrides the parent class's getStock function since a classic object
  //may have more than one instance of the same movie and the total stock
  //will be the sum of the instance's stock attributes.
  int getStock();

  //returns a string that contains the major actor's first name
  string getMajorActorFirstName();

  //returns a string that contains the major actor's last name
  string getMajorActorLastName();

  //prints out all of the data stored in this obect in the proper order.
  void display();

  NodeData& operator=(const NodeData &);
  //Overloaded equality operator. Compares two classic movies. Returns true if they are equal
  bool operator==(const NodeData &) const;

  //Overloaded inequality operator. Compares two classic movies. Returns false if they are equal.
  bool operator!=(const NodeData&) const;

  //Overloaded < operator. compares two classic movies. Returns true if
  //lhs movie is less than rhs movie.
  bool operator<(const NodeData &) const;

  //Overloaded > operator. Compares two classic movies. Returns true if  lhs
  // movie is greater than rhs movie.
  bool operator>(const NodeData &) const;
  bool operator<=(const NodeData &) const;
  bool operator>=(const NodeData &) const;

private:

  //private string that stores the major actor's first name.
  string majorActorFirstName;

  //private string that stores the major actor's last name;
  string majorActorLastName;

  //private int that stores the month (1-12)
  int month;
};

#endif
