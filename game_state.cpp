#include "game_state.hpp"

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

void game_state::reduce_lives(){
    this->lives--;
}
void game_state::set_player_x(int x){
    this->player_x = x;
}
void game_state::set_player_y(int y){
    this->player_y = y;
}