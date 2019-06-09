#include "moviefactory.h"

MovieFactory::MovieFactory()
{

}

Movie* MovieFactory::createMovie(string in)
{
  string input = in;
  Movie* M;

  string movieType = "";
  string stock = "";
  stringstream temp;
  stringstream directorName;
  string directorFirstName = "";
  string directorLastName = "";
  string title = "";
  int year = 0;

  stringstream ss(input);
  getline(ss, movieType, ',');

  getline(ss, stock, ',');
  //temp>>stock;
//  getline(ss, directorName, ',');
  //getline(ss, directorLastName, ',');
  ss>>directorFirstName;
  ss>>directorLastName;
  directorLastName.pop_back();
  getline(ss, title, ',');
  //directorName>>directorFirstName;
//  directorName>>directorLastName;

  // cout<<"inside movie factory "<<"\n\n";
  // cout<<"movie type: "<<movieType<<endl;
  // cout<<"stock: "<<stock<<endl;
  // cout<<"director First Name: "<<directorFirstName<<endl;
  // cout<<"director Last Name: "<< directorLastName<<endl;
  // cout<<"title: "<<title<<endl;

  if(movieType == "D")
  {
    ss>>year;
    M = new Drama(stoi(stock), directorFirstName, directorLastName, title, year);
    return M;
  }

  if(movieType == "C")
  {
    string majorActorFirstName = "";
    string majorActorLastName = "";
    int month = 0;
    ss>>majorActorFirstName;
    ss>>majorActorLastName;
    ss>>month;
    ss>>year;

    // cout<<"actor first name: "<< majorActorFirstName<<endl;
    // cout<<"actor last name: "<< majorActorLastName<<endl;
    // cout<<"month: "<< month<<endl;
    // cout<<"year: "<< year<<endl;

    M = new Classic( stoi(stock),  directorFirstName, directorLastName,
         majorActorFirstName, majorActorLastName, title, month, year);
  }
  return M;
}
