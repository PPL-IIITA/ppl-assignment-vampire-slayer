#include "src/process_data.h"
#include "src/parse_csv.h"

int main() {
  int t = 5; //t denotes number of gifting days
  parse_csv Parser;
  std::vector<girl *> Girl = Parser.Add_Girls();
  std::vector<boy *> Boy = Parser.Add_Boys();
  std::vector<gift *> Gift = Parser.Add_Gifts();
  process_data Processor;
  Processor.Allocate_Boyfriends(Girl, Boy);
  Processor.Find_Girlfriends(Boy, Girl);
  std::map <std::string, int> m;
  for (int i = 0; i < Girl.size(); i++) {
    if (Girl[i]->Has_Boyfriend()) {
      m[(Girl[i]->Get_Boyfriend())->Get_Name()] = i + 1;
    }
  }
  Processor.Find_Girlfriends_Hash(m, Girl);
  std::vector <std::string> v;
  for (int i = 0; i < Girl.size(); i++) {
    if (Girl[i]->Has_Boyfriend()) {
      v.push_back((Girl[i]->Get_Boyfriend())->Get_Name());
    }
  }
  std::sort(v.begin(), v.end());
  Processor.Find_Girlfriends_Binary_Search(v, Girl);
  return 0;
}
