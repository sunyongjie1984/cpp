#ifndef C_DERIVE
#define C_DERIVE

#include "base.h"
class c_derive : public c_base {
public:
    // void apple()          { std::cout << "apple in derive" << std::endl; }
    virtual void orange() { std::cout << "orange in derive" << std::endl; }
    // void apple();
    // virtual void orange();
};

#endif
