#ifndef _boy_h
#define _boy_h

#include <bits/stdc++.h>
#include "common_header.h"
#include "gift.h"

class boy {
  private:
    std::string Name;
    std::string Type;
    int Attractiveness;
    int Attraction_Required;
    double Budget;
    double Intelligence;
    double Budget_Spent;
    double Happiness;
    girl *Girlfriend;
    std::vector<gift *> Gift;
  public:
    boy(std::string, std::string, int, int, double, double);
    int Get_Attraction_Required();
    double Get_Budget();
    double Give_Gifts(std::vector<gift *> &);
    void Add_Girlfriend(girl *);
    bool Has_Girlfriend();
    double Get_Happiness();
    int Get_Attractiveness();
    double Get_Intelligence();
    std::string Get_Name();
    void Allocate_Girlfriend(std::vector<girl *> &Girl);
};

#endif
