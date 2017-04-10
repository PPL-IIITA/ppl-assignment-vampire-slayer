#ifndef _girl_h
#define _girl_h

#include <bits/stdc++.h>
#include "common_header.h"
#include "gift.h"

class girl {
  private:
    std::string Name;
    std::string Type;
    int Attractiveness;
    double Budget;
    double Intelligence;
    double Happiness;
    boy *Boyfriend;
    std::vector<gift *> Gift;
  public:
    girl(std::string, std::string, int, double, double);
    void Update_Happiness();
    double Get_Happiness();
    double Get_Couple_Happiness();
    bool Has_Boyfriend();
    void Receive_Gift(gift *);
    double Get_Intelligence();
    void Allocate_Boyfriend(std::vector<boy *> &);
    int Get_Attractiveness();
    double Get_Couple_Compatibility();
    void Print_Couple();
    std::string Get_Name();
    double Get_Budget();
};

#endif
