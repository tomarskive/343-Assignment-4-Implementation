//--------------------------return.h-------------------------------------------
//Created by Kathleen Guinee CSS343 Section B
//Created: 5/22/2019
//Last Modification: 5/22/2019
//------------------------------------------------------------------------------
//Purpose: This is the header file for a Return class that inherits from
//transaction.h  This class instantiates a return object, that acts as a
//function and allows for a customer to borrow a movie.
//------------------------------------------------------------------------------
//Notes:
//this class uses polymorphism to override print and doTransaction. Parent class
//is transaction.
//------------------------------------------------------------------------------

#ifndef RETURN_H
#define RETURN_H

using namespace std;

class Return : Transaction
{
public:
  //default constructor. Initializes all values to NULL or zero.
  Return(int customerID, string mediaType);

  //default destructor. No memory allocated
  ~Return();

  //Overides the parent's print.  Prints this transaction (return)
  void print();

  //overrides the parent class, performs the transaction, which is, in this
  //case, incrementing the "stock" of a movie by 1.
  void doTransaction();
}
