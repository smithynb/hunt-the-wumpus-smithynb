#include "stalactites.hpp"

// TODO Stalactites implementation (define stalactites member functions below)
void stalactites::trigger(game_state& g){
    if(rand()%2==1){
        std::cout<<"Stalactites fall and kill you!" << std::endl;
        g.reduce_lives();
        g.print_lives();
    }
}
void stalactites::percept(){
    //placeholder
    std::cout << "You hear water dripping." << std::endl;
}
void stalactites::print_char()const{
    std::cout<<'s';
}