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
    bool gold = false;
    int lives = 3;
    int num_arrows = 0;
    bool respawn_player = false; //player killed by stalactites or wumpus

    //int wumpus_x;
    //int wumpus_y;
    bool relocate_wumpus=false;
public:
    //getters
    int get_player_x()const;
    int get_player_y()const;
    bool is_confused();
    int get_lives()const;
    /*int get_wumpus_x()const;
    int get_wumpus_y()const;*/
    bool has_gold()const;
    int get_num_arrows()const;
    bool respawn();
    //setters
    void reduce_lives();
    void set_player_x(int x);
    void set_player_y(int y);
    void confuse();
    /*void set_wumpus_x(int x);
    void set_wumpus_y(int y);*/
    void set_gold(bool x);
    void pickup_arrow();
    void use_arrow();

    //print
    void print_lives()const;

};

#endif