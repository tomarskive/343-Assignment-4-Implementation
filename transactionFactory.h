// ----------------------- transactionFactory.h --------------------------------
// Team: Nhi Tran - Kaya Peng - Chelsea Ip - Kathleen Guinee
// Course: CSS 343 Section B
// Creation day: 05/21/2019
// Last Modified: 05/22/2019 by Kathleen
// -----------------------------------------------------------------------------
// Purpose: This is the header file for the TransactionFactory class.
// Determine the type of transaction to complete Transaction()
// -----------------------------------------------------------------------------
// Factory Design Pattern:: use a static factory method to create & return
// specific factory command instance, hiding the implementation class from user.
// -----------------------------------------------------------------------------

#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H
#include <iostream>

using namespace std;

class MovieFactory
{
public:
  // Default Constructor
  TransactionFactory();
  // Default Destructor
  ~TransactionFactory();

  // Instantiating coresponding transaction object
  static Transaction* createTransaction(ifstream& in);

};
#endif
