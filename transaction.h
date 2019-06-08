// -------------------------------- transaction.h ------------------------------------
// Kaya Peng 1762918 CSS 343 Section B
// 05/21/2019
// 05/22/2019
// -----------------------------------------------------------------------------
// Purpose: This is the header file for the Transaction class. This class is a
// parent class for borrow, return, and history children class. This class
// provides methods for the children classes to calculate the different
// transactions.
// -----------------------------------------------------------------------------
// Note: This class uses virtual as a way to provide an interface for its childen
// This contains all of the attributes that the children would use (as protected
// attributes)
// -----------------------------------------------------------------------------

#ifndef TRANSACTION_H
#define TRANSACTION_H

using namespace std;

class Transaction
{
    public:
        // creates a transaction class
        Transaction();

        // destroys the transaction class and frees any allocated memory
        virtual ~Transaction();

        // virtual function that acts only as an interface.
        //displays the different transaction information
        virtual void displayTransaction() = 0 const;

        // virtual function that acts only as an interface.
        //calculates the different transactions
        virtual void doTransaction() = 0 const;

    protected:
        // differentiate the different types of transactions
        string transactionType;

        // a pointer that points to what movie we're transaction on
        Movie* movie;
};

#endif // TRANSACTION_H
