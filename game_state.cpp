#include "game_state.hpp"
#include <iostream>
int game_state::get_player_x()const{
    return player_x;
}
int game_state::get_player_y()const{
    return player_y;
}
bool game_state::is_confused(){
    return confused;
}
int game_state::get_lives()const{
    return this->lives;
}
int game_state::get_wumpus_x()const{
    return this->wumpus_x;
}
int game_state::get_wumpus_y()const{
    return this->wumpus_y;
}

void game_state::reduce_lives(){
    this->lives--;
}
void game_state::set_player_x(int x){
    this->player_x = x;
}
void game_state::set_player_y(int y){
    this->player_y = y;
}
void game_state::set_wumpus_x(int x){
    this->wumpus_x = x;
}
void game_state::set_wumpus_y(int y){
    this->wumpus_y = y;
}

void game_state::print_lives()const{
    std::cout<< "Lives remaining: " << this->lives << std::endl;
}