#include <bits/stdc++.h>

using namespace std;

const int N = 50;

std::string types_girls[] = {"Choosy", "Normal", "Desperate"};
std::string types_boys[] = {"Miser", "Generous", "Geek"};
std::string types_gifts[] = {"Luxury", "Essential", "Utility"};

void generate_girls() {
  ofstream out;
  out.open("Girls.csv", ios::trunc);
  for (int i = 0; i < 26; i++) {
    std::string Name = std::string("A");
    Name += (i + 'A');
    std::string Type = types_girls[rand() % 3];
    int Attractiveness = 5 + rand() % 6;
    double Budget = rand() % 501 + 500;
    double Intelligence = rand() % 51 + 50;
    out << Name << " , "
        << Type << " , "
        << Attractiveness << " , "
        << Budget << " , "
        << Intelligence;
    if (i < 25) {
      out << "\n";
    }
  }
  out.close();
}

void generate_boys() {
  ofstream out;
  out.open("Boys.csv", ios::trunc);
  for (int i = 0; i < 26; i++) {
    for (int j = i; j < 26; j++) {
        std::string Name = std::string("V");
        Name += (i + 'A');
        Name += (j + 'A');
        std::string Type = types_boys[rand() % 3];
        int Attractiveness = 5 + rand() % 6;
        int Attraction_Required = 5 + rand() % 6;
        double Budget = rand() % 501 + 500;
        double Intelligence = rand() % 51 + 50;
        out << Name << " , "
            << Type << " , "
            << Attractiveness << " , "
            << Attraction_Required << " , "
            << Budget << " , "
            << Intelligence;
	if (i == 25 && j == 25);
	else out << "\n";
    }
  }
  out.close();
}

void generate_gifts() {
  ofstream out;
  out.open("Gifts.csv", ios::trunc);
  for (int i = 0; i < 26; i++) {
    for (int j = i; j < 26; j++) {
      double Price = rand() % 501 + 250;
      double Value = Price + rand() % 101;
      std::string Type = types_gifts[rand() % 3];
      int Difficulty_to_Obtain = 1 + rand() % 10;
      int Luxury_Rating = 1 + rand() % 10;
      double Utility_Value = 100 + rand() % 500;
      std::string Utility_Class = std::string("K");
      Utility_Class += (i + 'A');
      Utility_Class += (j + 'A');
      out << Price << " , "
          << Value << " , "
          << Type << " , "
          << Difficulty_to_Obtain << " , "
          << Luxury_Rating << " , "
          << Utility_Value << " , "
          << Utility_Class;
      if (i == 25 && j == 25);
      else out << "\n";
    }
  }
  out.close();
}

int main() {
  srand(time(NULL));
  generate_girls();
  generate_boys();
  generate_gifts();
  return 0;
}
