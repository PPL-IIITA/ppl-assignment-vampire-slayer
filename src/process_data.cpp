#include "process_data.h"

bool cmp_happiness(girl *a, girl *b) {
  return a->Get_Couple_Happiness() > b->Get_Couple_Happiness();
}

bool cmp_compatibility(girl *a, girl *b) {
  return a->Get_Couple_Compatibility() < b->Get_Couple_Compatibility();
}

void process_data::Allocate_Boyfriends(std::vector <girl *> &Girl, std::vector <boy *> &Boy) {
  std::ofstream out;
  out.open("Gifting.log", std::ios::out);
  std::cout << "Creating log file \'Gifting.log\', please wait.\n";
  out.close();
  for (int i = 0; i < Girl.size(); i++) {
    Girl[i]->Allocate_Boyfriend(Boy);
  }
}

void process_data::Exchange_Gifts(std::vector <gift *> &Gift, std::vector <boy *> &Boy) {
  puts("Exchanging Gifts, please wait.");
  for (int i = 0; i < Boy.size(); i++) {
    Boy[i]->Give_Gifts(Gift);
  }
}

void process_data::Print_Happiest_Couples(std::vector <girl *> &Girl) {
  puts("----------------");
  puts("Happiest Couples");
  puts("----------------");
  std::sort(Girl.begin(), Girl.end(), cmp_happiness);
  for (int i = 0; i < Girl.size(); i++) {
    Girl[i]->Print_Couple();
  }
}

void process_data::Print_Most_Compatible_Couples(std::vector <girl *> &Girl) {
  puts("-----------------------");
  puts("Most Compatible Couples");
  puts("-----------------------");
  std::sort(Girl.begin(), Girl.end(), cmp_compatibility);
  for (int i = 0; i < Girl.size(); i++) {
    Girl[i]->Print_Couple();
  }
}

void process_data::Print_Couples(std::vector <girl *> &Girl) {
  puts("---------------");
  puts("List of Couples");
  puts("---------------");
  for (int i = 0; i < Girl.size(); i++) {
    Girl[i]->Print_Couple();
  }
}
