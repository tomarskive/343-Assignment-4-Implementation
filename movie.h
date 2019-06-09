// -------------------------------- movie.h ------------------------------------
// Kaya Peng 1762918 CSS 343 Section B
// 05/21/2019
// 05/22/2019
// -----------------------------------------------------------------------------
// Purpose: This is the header file for the movie class. Movie is a parent class
// and 3 three children class: comendy, drama, and classic. This class provides
// an interface for the children classes.
// -----------------------------------------------------------------------------
// Note: This class uses virtual as a way to provide an interface for its childen
// This contains all of the attributes that the children would use (as protected
// attributes)
// -----------------------------------------------------------------------------

#ifndef MOVIE_H
#define MOVIE_H
#include<string>
#include "nodedata.h"
using namespace std;

class Movie : public NodeData
{
    friend ostream & operator<<(ostream &, const Movie &);

    public:
        Movie();
        Movie(int stock, string directorFirstName, string directorLastName, string title, int year); // creates a movie object with stock, director, title, and year
      //  ~Movie(); // destroys the movie object

        virtual void display() = 0;

        // virtual NodeData* copyHelp(Classic*) = 0;
        virtual bool compare(const NodeData& other) const;
         virtual NodeData& operator=(const NodeData &) =0;
         virtual void copyHelp(const NodeData &);
         virtual int getStock(); // returns the stock for the movie
         virtual void serialize(ostream& output) const = 0;
        //string getDirector(); // returns the director's name for that drama
       // string getTitle(); // returns the title of the movie
       // int getYear(); // returns the year of the drama released
      //  void increaseStock(); // increase the stock for that movie

      // virtual function that acts only as an interface. checks if 2 movie objects are equal to each other
        virtual bool operator==(const NodeData &) const = 0;
        // virtual function that acts only as an interface. checks if 2 movie objects are not equal to each other
        virtual bool operator!= (const NodeData&) const = 0;

        // virtual function that acts only as an interface. checks if rhs object isi smaller than rhs
        virtual bool operator<(const NodeData &) const = 0;
        virtual bool operator> (const NodeData&) const = 0; // virtual function that acts only as an interface. checks if the lhs object is bigger than rhs
        virtual bool operator<=(const NodeData &) const = 0;
        virtual bool operator>=(const NodeData &) const = 0;

    protected:
        int stock; // stock of the movie
        string directorFirstName; // director's first name
        string directorLastName; // director's last name
        string title; // movie title
        int year; // the year hte movie was released
};

#endif // MOVIE_H
