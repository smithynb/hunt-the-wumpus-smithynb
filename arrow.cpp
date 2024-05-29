#include "arrow.hpp"

// TODO Arrow implementation (define arrow member functions below)
void arrow::trigger(game_state& g){
    g.pickup_arrow();
    std::cout << "You picked up an arrow!" << std::endl;
}
void arrow::percept(){
    std::cout << "You see an arrow on the ground in an adjacent room."
    << std::endl;
}
void arrow::print_char()const{
    std::cout<<'a';
}
bool arrow::to_remove()const{
    return true;
}
