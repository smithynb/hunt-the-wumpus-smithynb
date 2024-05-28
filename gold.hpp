#ifndef GOLD_HPP
#define GOLD_HPP
#include "event.hpp"

// TODO Gold interface (define the gold class and declare its member functions
// below)
class gold : public event{
private:
public:
    void trigger(game_state& g);
    void percept();
    void print_char()const;
};

#endif
