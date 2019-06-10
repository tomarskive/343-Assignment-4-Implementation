#include "business.h"
#include "BinTree.h"

// ---------------------getFirstName() -----------------------------------------
// Constructs the first name, last name and the month of the actor.
//
Business::Business()
{
    
}

// ---------------------getFirstName() -----------------------------------------
// Constructs the first name, last name and the month of the actor.
//
Business::~Business()
{
    
}

// ---------------------buildCustomers() -----------------------------------------
// Creates a hashtable to store each customer.
//
void Business::buildCustomers(HashTable<Customer>& customerList)
{
    fstream input;
    input.open("data4customers.txt");
    Customer* customer;
    while(!input.eof())
    {
        string customerID, lastName, firstName;
        
        input >> customerID;
        input >> lastName;
        input >> firstName;
        customer = new Customer(firstName, lastName, customerID);
        customerList.insert(customer);
    }
}

// ---------------------buildMovies() -----------------------------------------
// 
//
void Business::buildMovies(set<Movie*> movies[])
{
    fstream input;
    input.open("data4movies.txt");
    
    while(!inout.eof())
    {
        string scanInput;
        getline(input, scanInput);
        
        singstream lineInput(scanInput);
        
        getline(lineInput, scanInput, ',');
        char type = scanInput[0];
        //creating movie using movie factory
        Movie* newMovie = MovieFactory::createMovie(type);
        
        //if else statement to set stock, director, year etc
    }
}