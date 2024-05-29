#include "gold.hpp"

// TODO Gold implementation (define gold member functions below)
void gold::trigger(game_state& g){
    g.set_gold(true);
    std::cout << "You picked up gold!" << std::endl;
}
void gold::percept(){
    //placeholder
    std::cout << "You see something shimmer nearby."
    << std::endl;
}
void gold::print_char()const{
    std::cout<<'g';
}
bool gold::to_remove()const{
    return true;
}