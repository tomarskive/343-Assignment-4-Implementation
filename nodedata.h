#ifndef NODEDATA_H
#define NODEDATA_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

// simple class containing one string to use for testing
// not necessary to comment further

class NodeData {
	friend ostream & operator<<(ostream &, const NodeData &);

public:
	NodeData();          // default constructor, data is set to an empty string
	virtual ~NodeData();
	//NodeData(const string &);      // data is set equal to parameter
	//NodeData(const NodeData &);    // copy constructor

	virtual void display();// = 0;
	virtual int getStock();// = 0;
	// set class data from data file
	// returns true if the data is set, false when bad data, i.e., is eof
	// virtual bool setData(istream&) = 0;
	//
	 virtual bool operator==(const NodeData &);// const = 0;
	 virtual bool operator!=(const NodeData&);// const = 0;
	 virtual bool compare(const NodeData& other) ;//const = 0;
	 virtual NodeData& operator=(const NodeData &) ;//= 0;
	 virtual bool operator<(const NodeData &) const;// = 0;
	 virtual bool operator>(const NodeData &) const;// = 0;
	 virtual bool operator<=(const NodeData &) const;// = 0;
	 virtual bool operator>=(const NodeData &) const;// = 0;

private:
	string data;
};

#endif
