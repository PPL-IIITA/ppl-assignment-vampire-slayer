#include "girl.h"

girl::girl(std::string Name, std::string Type, int Attractiveness, double Budget, double Intelligence) {
  this->Name = Name;
  this->Type = Type;
  this->Attractiveness = Attractiveness;
  this->Budget = Budget;
  this->Intelligence = Intelligence;
  this->Happiness = 0.0;
  this->Boyfriend = NULL;
  (this->Gift).clear();
}

void girl::Update_Happiness() {
  double amt = 0.0;
  if (Type == "Choosy") {
    for (int i = 0; i < Gift.size(); i++) {
      if (Gift[i]->Is_Luxury_Gift()) {
        amt += (2 * Gift[i]->Get_Value());
      } else {
        amt += Gift[i]->Get_Price();
      }
    }
    Happiness = 100 * log(amt);
  } else if (Type == "Normal") {
    for (int i = 0; i < Gift.size(); i++) {
      amt += Gift[i]->Get_Price();
      amt += Gift[i]->Get_Value();
    }
    Happiness = amt;
  } else if (Type == "Desperate") {
    for (int i = 0; i < Gift.size(); i++) {
      amt += Gift[i]->Get_Price();
    }
    Happiness = pow(1.5, amt);
  }
}

double girl::Get_Happiness() {
  Update_Happiness();
  return Happiness;
}

double girl::Get_Couple_Happiness() {
  if (Boyfriend != NULL) {
    Update_Happiness();
    return (Happiness + Boyfriend->Get_Happiness());
  } else {
    return Happiness;
  }
}

bool girl::Has_Boyfriend() {
  return (Boyfriend != NULL) ? true : false;
}

void girl::Receive_Gift(gift *Gift) {
  (this->Gift).push_back(Gift);
}

double girl::Get_Intelligence() {
  return Intelligence;
}

void girl::Allocate_Boyfriend(std::vector<boy *> &Boy) {
  if (Boyfriend == NULL) {
    for (int i = 0; i < Boy.size(); i++) {
      if ((! Boy[i]->Has_Girlfriend()) && Attractiveness >= Boy[i]->Get_Attraction_Required() && Budget <= Boy[i]->Get_Budget()) {
        Boyfriend = Boy[i];
        Boyfriend->Add_Girlfriend(this);
        std::fstream out;
        out.open("Logfile.log", std::fstream::app);
        time_t now = time(0);
        char *dt = ctime(&now);
        out << "Girl " << Name << " is committed to " << Boyfriend->Get_Name() << " at " << dt << "\n";
	out.close();
        break;
      }
    }
  }
}

void girl::Perform_Breakup() {
  if (Boyfriend != NULL) {
    (this->Gift).clear();
    std::fstream out;
    out.open("Logfile.log", std::fstream::app);
    time_t now = time(0);
    char *dt = ctime(&now);
    out << "Girl " << Name << " broke up with " << Boyfriend->Get_Name() << " at " << dt << "\n";
    out.close();
    Boyfriend = NULL;
  }
}

int girl::Get_Attractiveness() {
  return Attractiveness;
}

double girl::Get_Couple_Compatibility() {
  double ret = 0.0;
  if (Boyfriend != NULL) {
    ret += abs(Attractiveness - Boyfriend->Get_Attractiveness());
    ret += abs(Budget - Boyfriend->Get_Budget());
    ret += abs(Intelligence - Boyfriend->Get_Intelligence());
    ret += abs(Happiness - Boyfriend->Get_Happiness());
  }
  return ret;
}

void girl::Print_Couple() {
  std::cout << "Girl : " << Name << ", Boy : " << Boyfriend->Get_Name() << "\n";
}

std::string girl::Get_Name() {
  return Name;
}

double girl::Get_Budget() {
  return Budget;
}
