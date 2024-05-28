#include "game_state.hpp"

int game_state::get_player_x(){
    return player_x;
}
int game_state::get_player_y(){
    return player_y;
}
bool game_state::is_confused(){
    return confused;
}
int game_state::get_lives(){
    return this->lives;
}

void game_state::reduce_lives(){
    this->lives--;
}