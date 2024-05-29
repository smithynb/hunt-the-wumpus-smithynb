#include "bats.hpp"

// TODO Bats implementation (define bats member functions below)
void bats::trigger(game_state& g){
    g.confuse();
    std::cout << "Super bats confuse you!" 
    << std::endl << std::endl;
}
void bats::percept(){
    //placeholder
    std::cout << "You hear wings flapping." << std::endl;
}
void bats::print_char()const{
    std::cout<<'b';
}