#ifndef BATS_HPP
#define BATS_HPP
#include "event.hpp"

// TODO Bats interface (define the bats class and declare its member functions
// below)
class bats : public event{
private:
public:
    void trigger();
    void percept();
};

#endif
