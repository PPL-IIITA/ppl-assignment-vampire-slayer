#include "src/process_data.h"
#include "src/parse_csv.h"

int main() {
  parse_csv Parser;
  std::vector<girl *> Girl = Parser.Add_Girls();
  std::vector<boy *> Boy = Parser.Add_Boys();
  std::vector<gift *> Gift = Parser.Add_Gifts();
  process_data Processor;
  puts("Sorting boys by budget.");
  Processor.Sort_Boys_By_Budget(Boy);
  puts("Sorting girls by attractiveness");
  Processor.Sort_Girls_By_Attractiveness(Girl);
  int i = 0, j = 0, turn = 0;
  puts("Assigning girlfriends and boyfriends in turns, please wait.");
  while (i < Girl.size() && j < Boy.size()) {
    if (turn == 0) {
      Girl[i++]->Allocate_Boyfriend(Boy);
    } else {
      Boy[j++]->Allocate_Girlfriend(Girl);
    }
    turn ^= 1;
  }
  puts("Done. Logfile updated with details.");
  Processor.Print_Couples(Girl);
  return 0;
}
