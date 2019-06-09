// ----------------------- movieFactory.h --------------------------------------
// Team: Nhi Tran - Kaya Peng - Chelsea Ip - Kathleen Guinee
// Course: CSS 343 Section B
// Creation day: 05/21/2019
// Last Modified: 05/22/2019 by Nhi
// -----------------------------------------------------------------------------
// Purpose: This is the header file for the MovieFactory class.
// Determine the type of movie to add to inventory
// -----------------------------------------------------------------------------
// Factory Design Pattern:: use a static movie method to create & return
// specific movie instance, hiding the instance class from user.
// -----------------------------------------------------------------------------

#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "movie.h"
#include "classic.h"
#include "drama.h"

using namespace std;

class MovieFactory {
public:
	MovieFactory();		// Constructor
	//~MovieFactory();	// Destructor

	// Instantiating coresponding Movie object
	//static Movie* createMovie(ifstream& in);
	static Movie* createMovie(string in);

};
#endif
