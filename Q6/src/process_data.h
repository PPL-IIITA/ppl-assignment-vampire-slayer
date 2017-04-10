#ifndef _process_data_h
#define _process_data_h

#include "girl.h"
#include "boy.h"

class process_data {
  public:
    void Allocate_Boyfriends(std::vector<girl *> &, std::vector<boy *> &);
    void Exchange_Gifts(std::vector<gift *> &, std::vector<boy *> &);
    void Print_Happiest_Couples(std::vector<girl *> &);
    void Print_Most_Compatible_Couples(std::vector<girl *> &);
    void Print_Couples(std::vector<girl *> &);
    void Perform_Breakups(std::vector<girl *> &, int);
    void Perform_Breakups_Based_On_t(std::vector<girl *> &, int);
};

#endif
