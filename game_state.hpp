#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

//for the purpose of passing game state variables between rooms
class game_state{
private:
    int player_x;
    int player_y;
    bool confused = false;
    int confused_duration = 0;
    int lives = 3;

    int wumpus_x;
    int wumpus_y;
public:
    //getters
    int get_player_x();
    int get_player_y();
    bool is_confused();
    int get_lives();
    //setters
    void reduce_lives();
    void set_x();
    void set_y();
    void confuse();

};

#endif