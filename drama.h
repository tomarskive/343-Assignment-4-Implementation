//--------------------------drama.h-------------------------------------------
//Created by Kathleen Guinee CSS343 Section B
//Created: 6/09/2019
//Last Modification: 6/09/2019
//------------------------------------------------------------------------------
//Purpose: This is the header file for a classic class that inherits from
//movie.h . This class instantiates and compares different movie objects in
//order to allow for storing of all objects in the correct order.
//------------------------------------------------------------------------------
//Notes:
//this class uses polymorphism to override the equality and comparison
//operators. The functions in the parent class for ==, !=, < and > are virtual.
//------------------------------------------------------------------------------

#ifndef DRAMA_H
#define DRAMA_H
#include "movie.h"
#include <typeinfo>
#include <string>

using namespace std;

class Drama : public Movie
{
  friend ostream & operator<<(ostream &, const Drama &);
public:
  //default constructor for movie of type classic. Initializes values
  // to 0 or Null;
  Drama();

  //constructor that takes in all of the information neeed to create a classic
  //movie object.
  Drama(int stock, string directorFirstName, string directorLastName,
    string title, int year);
  //default destructor. No extra memory should be allocated for this, so this
  //does nothing.
  //~Drama();

  //overrides the parent class's getStock function since a classic object
  //may have more than one instance of the same movie and the total stock
  //will be the sum of the instance's stock attributes.
//  virtual int getStock();

  //prints out all of the data stored in this obect in the proper order.
  void display();

  void serialize(ostream& output) const;

  NodeData& operator=(const NodeData &);

  //Overloaded equality operator. Compares two classic movies. Returns true if they are equal
  bool operator==(const NodeData &) const;

  //Overloaded inequality operator. Compares two classic movies. Returns false if they are equal.
  bool operator!=(const NodeData&) const;

  //Overloaded < operator. compares two classic movies. Returns true if
  //lhs movie is less than rhs movie.
  bool operator<(const NodeData &other) const;

  //Overloaded > operator. Compares two classic movies. Returns true if  lhs
  // movie is greater than rhs movie.
  bool operator>(const NodeData &other) const;
  bool operator<=(const NodeData &) const;
  bool operator>=(const NodeData &) const;

private:

};

#endif
