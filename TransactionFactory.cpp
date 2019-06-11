#include "transactionFactory.h"
#include <fstream>

// ---------------------Default Constructor -----------------------------------------
// Constructs the first name, last name and the month of the actor.
//
TransactionFactory::TransactionFactory()
{
    
}

// ---------------------Destructor -----------------------------------------
// Constructs the first name, last name and the month of the actor.
//
TransactionFactory::~TransactionFactory()
{
 
}

// ---------------------createTransaction -----------------------------------------
// ADDED HASHTABLE INTO PARAMETER, CHANGE HEADER
//
static Transaction* createTransaction(ifstream& in, HashTable<customer>& customer)
{
    //set all transactions to NULL initially to reset
    HistoryTrans *history = NULL;
    //need istream to read the type
    
    //if else statement for borrow, return, history, inventory
}

