#include "boy.h"
#include "girl.cpp"

boy::boy(std::string Name, std::string Type, int Attractiveness, int Attraction_Required, double Budget, double Intelligence) {
  this->Name = Name;
  this->Type = Type;
  this->Attractiveness = Attractiveness;
  this->Attraction_Required = Attraction_Required;
  this->Budget = Budget;
  this->Intelligence = Intelligence;
  this->Girlfriend = NULL;
  (this->Gift).clear();
};

int boy::Get_Attraction_Required() {
  return Attraction_Required;
}

double boy::Get_Budget() {
  return Budget;
}

double boy::Give_Gifts(std::vector<gift *> &Gift_Basket) {
  std::fstream out;
  out.open("Logfile.log", std::fstream::app);
  if (Girlfriend != NULL) {
    double cost = Girlfriend->Get_Budget();
    if (Type == "Miser") {
      for (int i = 0; i < Gift_Basket.size(); i++) {
        if (Budget_Spent >= cost) {
          break;
        }
        if (Gift_Basket[i] != NULL) {
          time_t now = time(0);
          char *dt = ctime(&now);
          out << Name << " gifted " << Girlfriend->Get_Name() << " a gift worth " << Gift_Basket[i]->Get_Price() << " at " << dt << "\n";
          Gift.push_back(Gift_Basket[i]);
          Girlfriend->Receive_Gift(Gift_Basket[i]);
          Budget_Spent += Gift_Basket[i]->Get_Price();
          Gift_Basket[i] = NULL;
        }
      }
      Budget = std::max(Budget, Budget_Spent);
    } else if (Type == "Generous") {
      int flag = 0;
      for (int i = 0; i < Gift_Basket.size(); i++) {
        if (Budget_Spent >= cost) {
          flag = 1;
        }
        if (Gift_Basket[i] != NULL) {
          if (flag) {
            if (Gift_Basket[i]->Get_Price() + Budget_Spent <= Budget) {
              time_t now = time(0);
              char *dt = ctime(&now);
              out << Name << " gifted " << Girlfriend->Get_Name() << " a gift worth " << Gift_Basket[i]->Get_Price() << " at " << dt << "\n";
              Gift.push_back(Gift_Basket[i]);
              Girlfriend->Receive_Gift(Gift_Basket[i]);
              Budget_Spent += Gift_Basket[i]->Get_Price();
              Gift_Basket[i] = NULL;
            } else {
              break;
            }
          } else {
            time_t now = time(0);
            char *dt = ctime(&now);
            out << Name << " gifted " << Girlfriend->Get_Name() << " a gift worth " << Gift_Basket[i]->Get_Price() << " at " << dt << "\n";
            Gift.push_back(Gift_Basket[i]);
            Girlfriend->Receive_Gift(Gift_Basket[i]);
            Budget_Spent += Gift_Basket[i]->Get_Price();
            Gift_Basket[i] = NULL;
          }
        }
      }
      Budget = std::max(Budget, Budget_Spent);
    } else if (Type == "Geek") {
      int flag = 0;
      for (int i = 0; i < Gift_Basket.size(); i++) {
        if (Budget_Spent >= cost) {
          flag = 1;
        }
        if (Gift_Basket[i] != NULL) {
          if (flag) {
            if (Gift_Basket[i]->Is_Luxury_Gift()) {
              if (Gift_Basket[i]->Get_Price() + Budget_Spent <= Budget) {
                time_t now = time(0);
                char *dt = ctime(&now);
                out << Name << " gifted " << Girlfriend->Get_Name() << " a gift worth " << Gift_Basket[i]->Get_Price() << " at " << dt << "\n";
                Gift.push_back(Gift_Basket[i]);
                Girlfriend->Receive_Gift(Gift_Basket[i]);
                Budget_Spent += Gift_Basket[i]->Get_Price();
                Gift_Basket[i] = NULL;
              } else {
                break;
              }
            }
          } else {
            time_t now = time(0);
            char *dt = ctime(&now);
            out << Name << " gifted " << Girlfriend->Get_Name() << " a gift worth " << Gift_Basket[i]->Get_Price() << " at " << dt << "\n";
            Gift.push_back(Gift_Basket[i]);
            Girlfriend->Receive_Gift(Gift_Basket[i]);
            Budget_Spent += Gift_Basket[i]->Get_Price();
            Gift_Basket[i] = NULL;
          }
        }
      }
      Budget = std::max(Budget, Budget_Spent);
    }
  }
  out.close();
}

void boy::Add_Girlfriend(girl *Girlfriend) {
  if (this->Girlfriend == NULL) {
    this->Girlfriend = Girlfriend;
  }
}

bool boy::Has_Girlfriend() {
  return (Girlfriend != NULL) ? true : false;
}

double boy::Get_Happiness() {
  Happiness = 0.0;
  if (Girlfriend != NULL) {
    if (Type == "Miser") {
      Happiness = Budget - Budget_Spent;
    } else if (Type == "Generous") {
      Happiness = Girlfriend->Get_Happiness();
    } else if (Type == "Geek") {
      Happiness = Girlfriend->Get_Intelligence();
    }
  }
  return Happiness;
}

int boy::Get_Attractiveness() {
  return Attractiveness;
}

double boy::Get_Intelligence() {
  return Intelligence;
}

std::string boy::Get_Name() {
  return Name;
}
