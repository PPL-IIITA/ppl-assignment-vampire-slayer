#include "gift.h"

gift::gift(double Price, double Value, std::string Type, int Difficulty_to_Obtain, int Luxury_Rating, double Utility_Value, std::string Utility_Class) : luxury_gift(Difficulty_to_Obtain, Luxury_Rating), utility_gift(Utility_Value, Utility_Class) {
  this->Price = Price;
  this->Value = Value;
  if (Type == "Luxury Gift") {
    this->Luxury_Gift = new luxury_gift(Difficulty_to_Obtain, Luxury_Rating);
  } else if (Type == "Utility Gift") {
    this->Utility_Gift = new utility_gift(Utility_Value, Utility_Class);
  } else {
    this->Luxury_Gift = NULL;
    this->Utility_Gift = NULL;
  }
}

double gift::Get_Price() {
  return Price;
}

double gift::Get_Value() {
  return Value;
}

bool gift::Is_Luxury_Gift() {
  return (Luxury_Gift != NULL) ? true : false;
}

