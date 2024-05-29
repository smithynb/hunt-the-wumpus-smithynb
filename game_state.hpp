#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

//for the purpose of passing game state variables between rooms
//could also just use a struct lol
class game_state{
private:
    int player_x;
    int player_y;
    bool confused = false;
    int confused_duration = 0;
    bool has_gold = false;
    int lives = 3;

    int wumpus_x;
    int wumpus_y;
public:
    //getters
    int get_player_x()const;
    int get_player_y()const;
    bool is_confused();
    int get_lives()const;
    int get_wumpus_x()const;
    int get_wumpus_y()const;
    //setters
    void reduce_lives();
    void set_player_x(int x);
    void set_player_y(int y);
    void confuse();
    void set_wumpus_x(int x);
    void set_wumpus_y(int y);

    //print
    void print_lives()const;

};

#endif