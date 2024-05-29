#include "game_state.hpp"
#include <iostream>
int game_state::get_player_x()const{
    return player_x;
}
int game_state::get_player_y()const{
    return player_y;
}
bool game_state::is_confused(){
    //similar to respawn,
    //calling this will set it false
    bool temp = this->confused;
    this->confused=false;
    return temp;
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
bool game_state::has_gold()const{
    return this->gold;
}
int game_state::get_num_arrows()const{
    return this->num_arrows;
}
bool game_state::respawn(){
    //when respawning player in game
    //it calls this and makes it false
    bool temp = this->respawn_player;
    this->respawn_player=false;
    return temp;
}
bool game_state::wumpus_dead()const{
    return this->wumpus_killed;
}

void game_state::reduce_lives(){
    this->lives--;
    this->respawn_player=true;
}
void game_state::set_player_x(int x){
    this->player_x = x;
}
void game_state::set_player_y(int y){
    this->player_y = y;
}
void game_state::confuse(){
    this->confused = true;
}
void game_state::set_wumpus_x(int x){
    this->wumpus_x = x;
}
void game_state::set_wumpus_y(int y){
    this->wumpus_y = y;
}
void game_state::set_gold(bool x){
    this->gold=x;
}
void game_state::pickup_arrow(){
    this->num_arrows++;
}
void game_state::use_arrow(){
    this->num_arrows--;
}
void game_state::kill_wumpus(){
    wumpus_killed = true;
}

void game_state::print_lives()const{
    std::cout<< "Lives remaining: " << this->lives << std::endl;
}