/* 
 * File:   business.h
 * Author: ipchelsea
 */

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "movie.h"
#include "transaction.h"
#include "customer.h"
#ifndef BUSINESS_H
#define	BUSINESS_H

class Business
{
public:
    
    //default constructor
    Business();
    
    //destructor
    ~Business();
    
    //takes an array of BST holding movie pointers.
    //opens necessary file and process all the different movies.
    void buildMovies(set<Movie*> movies[]);
    
    //takes a hash table containing all the customers by references
    //opens necessary file and process all the different customers.
    void buildCustomers(HashTable<Customer>&);
    
    //processtrans method is missing
};

#endif	/* BUSINESS_H */

