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
  for (int i = 0; i < t; i++) {
    Processor.Exchange_Gifts(Gift, Boy);
    Processor.Perform_Breakups_Based_On_t(Girl, t);
  }
  Processor.Allocate_Boyfriends(Girl, Boy);
  Processor.Print_Couples(Girl);
  return 0;
}
