#include "parse_csv.h"

std::vector<girl *> parse_csv::Add_Girls() {
  std::vector<girl *> ret;
  std::ifstream in;
  in.open("Girls.csv", std::ios::in);
  if (! in) {
    std::cout << "\'Girls.csv\' could not be opened.\nExiting.\n";
    exit(0);
  }
  while (! in.eof()) {
    std::string Ignore;
    std::string Name;
    std::string Type;
    int Attractiveness;
    double Budget;
    double Intelligence;
    in >> Name >> Ignore
       >> Type >> Ignore
       >> Attractiveness >> Ignore
       >> Budget >> Ignore
       >> Intelligence;
    girl *Girl = new girl(Name, Type, Attractiveness, Budget, Intelligence);
    ret.push_back(Girl);
  }
  in.close();
  return ret;
}

std::vector<boy *> parse_csv::Add_Boys() {
  std::vector<boy *> ret;
  std::ifstream in;
  in.open("Boys.csv", std::ios::in);
  if (! in) {
    std::cout << "\'Boys.csv\' could not be opened.\nExiting.\n";
    exit(0);
  }
  while (! in.eof()) {
    std::string Ignore;
    std::string Name;
    std::string Type;
    int Attractiveness;
    int Attraction_Required;
    double Budget;
    double Intelligence;
    in >> Name >> Ignore
       >> Type >> Ignore
       >> Attractiveness >> Ignore
       >> Attraction_Required >> Ignore
       >> Budget >> Ignore
       >> Intelligence;
    boy *Boy = new boy(Name, Type, Attractiveness, Attraction_Required, Budget, Intelligence);
    ret.push_back(Boy);
  }
  in.close();
  return ret;
}

std::vector<gift *> parse_csv::Add_Gifts() {
  std::vector<gift *> ret;
  std::ifstream in;
  in.open("Gifts.csv", std::ios::in);
  if (! in) {
    std::cout << "\'Gifts.csv\' could not be opened.\nExiting.\n";
    exit(0);
  }
  while (! in.eof()) {
    std::string Ignore;
    double Price;
    double Value;
    std::string Type;
    int Difficulty_to_Obtain;
    int Luxury_Rating;
    double Utility_Value;
    std::string Utility_Class;
    in >> Price >> Ignore
       >> Value >> Ignore
       >> Type >> Ignore
       >> Difficulty_to_Obtain >> Ignore
       >> Luxury_Rating >> Ignore
       >> Utility_Value >> Ignore
       >> Utility_Class;
    gift *Gift = new gift(Price, Value, Type, Difficulty_to_Obtain, Luxury_Rating, Utility_Value, Utility_Class);
    ret.push_back(Gift);
  }
  in.close();
  return ret;
}
