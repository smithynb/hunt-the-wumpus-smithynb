#ifndef STALACTITES_HPP
#define STALACTITES_HPP
#include "event.hpp"

// TODO Stalactites interface (define the stalactites class and declare its
// member functions below)
class stalactites : public event{
private:
public:
    void trigger();
    void percept();
    void print_char()const;
};

#endif
