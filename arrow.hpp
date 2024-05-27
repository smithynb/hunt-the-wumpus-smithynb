#ifndef ARROW_HPP
#define ARROW_HPP
#include "event.hpp"
// TODO Arrow interface (define the arrow class and declare its member functions
// below)
class arrow : public event{
private:
public:
    void trigger(game& g);
    void percept();
    void print_char()const;
};

#endif
