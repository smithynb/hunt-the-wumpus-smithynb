#ifndef ESCAPE_ROPE_HPP
#define ESCAPE_ROPE_HPP
#include "event.hpp"

// TODO Escape rope interface (define the escape_rope class and declare its
// member functions below)
class escape_rope : public event{
private:
public:
    void trigger(game_state& g);
    void percept();
    void print_char()const;
    bool is_rope()const;
};

#endif
