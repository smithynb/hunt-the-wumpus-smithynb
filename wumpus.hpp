#ifndef WUMPUS_HPP
#define WUMPUS_HPP
#include "event.hpp"

// TODO Wumpus interface (define the wumpus class and declare its member
// functions below)
class wumpus : public event{
private:
public:
    void trigger(game_state& g);
    void percept();
    void print_char()const;
};

#endif
