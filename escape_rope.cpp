#include "escape_rope.hpp"

// TODO Escape rope implementation (define escape_rope member functions below)
void escape_rope::trigger(game_state& g){
    //std::cout << "rope trigger" << std::endl;
}
void escape_rope::print_char()const{
    std::cout<<'r';
}
bool escape_rope::is_rope()const{
    return true;
}