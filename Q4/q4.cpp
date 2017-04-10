#include "src/process_data.h"
#include "src/parse_csv.h"

int main() {
  int k = 5; //k denotes the number of couples breaking up
  parse_csv Parser;
  std::vector<girl *> Girl = Parser.Add_Girls();
  std::vector<boy *> Boy = Parser.Add_Boys();
  std::vector<gift *> Gift = Parser.Add_Gifts();
  process_data Processor;
  Processor.Allocate_Boyfriends(Girl, Boy);
  Processor.Exchange_Gifts(Gift, Boy);
  Processor.Perform_Breakups(Girl, k);
  return 0;
}
