#include "process_data.h"

bool cmp_happiness(girl *a, girl *b) {
  return a->Get_Couple_Happiness() > b->Get_Couple_Happiness();
}

bool cmp_compatibility(girl *a, girl *b) {
  return a->Get_Couple_Compatibility() < b->Get_Couple_Compatibility();
}

void process_data::Allocate_Boyfriends(std::vector <girl *> &Girl, std::vector <boy *> &Boy) {
  std::cout << "Updating log file \'Logfile.log\', please wait.\n";
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

void process_data::Perform_Breakups(std::vector <girl *> &Girl, int k) {
  std::sort(Girl.begin(), Girl.end(), cmp_happiness);
  std::reverse(Girl.begin(), Girl.end());
  k = (k > Girl.size()) ? Girl.size() : k;
  puts("Performing breakups, please wait.");
  for (int i = 0; i < k; i++) {
    Girl[i]->Perform_Breakup();
  }
  puts("Done. \'Logfile.log\' updated with details of breakups.");
}

void process_data::Perform_Breakups_Based_On_t(std::vector <girl *> &Girl, int t) {
  puts("Performing breakups based on t, please wait.");
  for (int i = 0; i < Girl.size(); i++) {
    if (Girl[i]->Get_Couple_Happiness() < t) {
      Girl[i]->Perform_Breakup();
    }
  }
  puts("Done. \'Logfile.log\' updated with details of breakups.");
}

void process_data::Find_Girlfriends(std::vector <boy *> &Boy, std::vector <girl *> &Girl) {
  puts("Finding girlfriends using linked-list.");
  for (int i = 0; i < Boy.size(); i++) {
    if (Boy[i]->Has_Girlfriend()) {
      std::cout << Boy[i]->Get_Name() << " has a girlfriend. She is " << (Boy[i]->Get_Girlfriend())->Get_Name() << "." << "\n";
    } else {
      std::cout << "No girlfriend found for " << Boy[i]->Get_Name() << "." << "\n";
    }
  }
}

void process_data::Find_Girlfriends_Hash(std::map <std::string, int> &m, std::vector <girl *> &Girl) {
  puts("Finding girlfriends using hashing.");
  std::map <std::string, int> :: iterator it;
  for (it = m.begin(); it != m.end(); it++) {
    if (Girl[(*it).second - 1]->Has_Boyfriend()) {
      std::cout << (*it).first << " has a girlfriend. She is " << (Girl[(*it).second - 1]->Get_Name()) << "." << "\n";
    }
  }
}

void process_data::Find_Girlfriends_Binary_Search(std::vector <std::string> &v, std::vector <girl *> &Girl) {
  puts("Finding girlfriends using binary search.");
  for (int i = 0; i < Girl.size(); i++) {
    if (Girl[i]->Has_Boyfriend()) {
      std::vector <std::string> :: iterator it = lower_bound(v.begin(), v.end(), (Girl[i]->Get_Boyfriend())->Get_Name());
      std::cout << (*it) << " has a girlfriend. She is " << (Girl[i]->Get_Name()) << "." << "\n";
    }
  }
}
