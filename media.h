// ------------------------------ media.h -----------------------------------
// Team: Nhi Tran - Kaya Peng - Chelsea Ip - Kathleen Guinee
// Course: CSS 343 Section B
// Creation day: 05/21/2019
// Last Modified: 05/22/2019
// -----------------------------------------------------------------------------
// Purpose: This is the header file for the Media class.
// Store the list of all the movies in the Store (with stock number & max stock)
// -----------------------------------------------------------------------------
// Specification: Store stock number
// -----------------------------------------------------------------------------
#ifndef MEDIA_H                                       
#define MEDIA_H

using namespace std;

class Media {
public:
	Media();			// Constructor
	~Media();			// Destructor

	// return the number of a movie in stock
	virtual int getStock();
	// add stock when the same movie is returned or added
	void setStock();
	// diplay all the information of a movie
	virtual void display();
}
#endif
