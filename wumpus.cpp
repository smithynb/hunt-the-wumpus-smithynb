#include "wumpus.hpp"

// TODO Wumpus implementation (define wumpus member functions below)
void wumpus::trigger(game_state& g){
    g.reduce_lives();
    std::cout << "You woke up the wumpus and it killed you!" 
    << std::endl << std::endl;
    g.print_lives();
}
void wumpus::percept(){
    std::cout << "You smell a terrible stench." << std::endl;
}
void wumpus::print_char()const{
    std::cout<<'w';
}
bool wumpus::is_wumpus()const{
    return true;
}