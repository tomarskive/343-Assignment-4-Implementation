#include "bintree.h"
#include "classic.h"
#include "drama.h"
#include "moviefactory.h"

#include <iostream>
#include <iostream>
#include <typeinfo>

using namespace std;
int main()
{
  cout<<"starting tests..."<<endl;

//BinTree test1;
  //cout<<test1<<endl;

  NodeData* movie1 = new Classic(10, "Michael", "Curtiz", "Casablanca", "Ingrid",
  "Bergman", 8, 1942);
  (*movie1).display();
  NodeData* movie2 = new Classic(10, "Michael", "Curtiz", "Casablanca", "Ingrid",
  "Bergman", 8, 1942);
  NodeData* movie3 = new Classic();
  cout<< (*movie2 == *movie1)<<endl;
  cout<<(*movie2 == *movie3)<<endl;

  (*movie2).display();
  *movie3 = *movie2;
  (*movie3).display();
  cout<<(*movie3 != *movie2)<<endl;
  NodeData* movie4 = new Classic();
  cout<<(*movie4 != *movie2)<<endl;

  cout<<(*movie3 < *movie2)<<endl;
  NodeData* movie5 = new Classic(10, "Michael", "Curtiz", "Casablanca", "Ingrid",
  "Bergman", 7, 1942);
  cout<<(*movie5 < *movie2)<<endl;
  cout<<(*movie3 > *movie2)<<endl;
  cout<<(*movie2 > *movie5)<<endl;
  cout<< (*movie2).getStock()<<endl;

  cout<<"\n\n Creating a Bin Tree"<<endl;
  BinTree test1;
  cout<<test1<<endl;
  test1.insert(movie1);
  cout<<test1<<endl;

  cout<<"testing Drama creator"<<endl;
  NodeData* movie6 = new Drama(10, "Barry", "Levinson", "Good Morning Vietnam", 1988);
  cout<< *movie6<<endl;
  cout<<"\n\n"<<endl;
  cout<<"testing movie factory"<<endl;
  NodeData* movie7;
  NodeData* movie8;
  MovieFactory MF;
  movie7 = MF.createMovie("C, 10, Michael Curtiz, Casablanca, Ingrid Bergman 8 1942");
  cout<< *movie7<<endl;
  movie8 = MF.createMovie("D, 10, Barry Levinson, Good Morning Vietnam, 1988");
  cout<< *movie8<<endl;
  return 0;
}
