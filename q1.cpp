#include "src/process_data.h"
#include "src/parse_csv.h"

int main() {
  parse_csv Parser;
  std::vector<girl *> Girl = Parser.Add_Girls();
  std::vector<boy *> Boy = Parser.Add_Boys();
  std::vector<gift *> Gift = Parser.Add_Gifts();
  process_data Processor;
  Processor.Allocate_Boyfriends(Girl, Boy);
  Processor.Print_Couples(Girl);
  return 0;
}
