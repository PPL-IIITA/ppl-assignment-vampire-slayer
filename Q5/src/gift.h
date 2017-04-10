#ifndef _gift_h
#define _gift_h

#include "luxury_gift.h"
#include "utility_gift.h"

class gift {
  private:
    double Price;
    double Value;
    luxury_gift *Luxury_Gift;
    utility_gift *Utility_Gift;
  public:
    gift(double, double, std::string, int, int, double, std::string);
    double Get_Price();
    double Get_Value();
    bool Is_Luxury_Gift();
};

#endif
