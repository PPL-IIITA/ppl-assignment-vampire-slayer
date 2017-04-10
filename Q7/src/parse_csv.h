#ifndef _parse_csv_h
#define _parse_csv_h

#include "girl.h"
#include "boy.h"

class parse_csv {
  public:
    std::vector<girl *> Add_Girls();
    std::vector<boy *> Add_Boys();
    std::vector<gift *> Add_Gifts();
};

#endif
