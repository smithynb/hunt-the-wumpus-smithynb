#include <iostream>

#include "game.hpp"
#include "gold.hpp"
#include "bats.hpp"
#include "stalactites.hpp"
#include "wumpus.hpp"
#include "escape_rope.hpp"
#include "arrow.hpp"

// game implementation

game::game(int width, int height, bool debug) :
		width(width),
		height(height),
		debug(debug) {
	// TODO Create the game board: 2D vector of room objects
	rooms.resize(width);
	for(int i=0;i<width;i++){
		rooms.at(i).resize(height);
	}

	// TODO Randomly insert events (2 bats, 2 stalactites, 1 wumpus, 1 gold,
	// 2 arrows, 1 escape rope) into the board

	//these are all the same but the only thing differing
	//is the number of objects to place and the type
	//2 bats
	int placed_objects = 0;
	while(placed_objects<2){
		//allocate new object
		event* b = new bats;
		//store to empty room
		place_random_empty(b);
		placed_objects++;
	}
	//2 stalactites
	placed_objects=0;
	while(placed_objects<2){
		event* s = new stalactites;
		place_random_empty(s);
		placed_objects++;
	}
	//wumpus
	event* w = new wumpus;
	place_random_empty(w);

	//find the wumpus
	/*
	for(int i=0;i<width;i++){
		for(int j=0;j<height;j++){
			if(rooms.at(i).at(j).check_wumpus()){
				gs.set_wumpus_x(i);
				gs.set_wumpus_y(j);
			}
		}
	}
	*/

	//gold
	event* g = new gold;
	place_random_empty(g);
	//2 arrows
	placed_objects=0;
	while(placed_objects<2){
		event* a = new arrow;
		place_random_empty(a);
		placed_objects++;
	}
	//escape rope
	event* r = new escape_rope;
	place_random_empty(r);
	
	//find the rope
	for(int i=0;i<width;i++){
		for(int j=0;j<height;j++){
			if(rooms.at(i).at(j).check_rope()){
				gs.set_player_x(i);
				gs.set_player_y(j);
				rope_x = i;
				rope_y = j;
			}
		}
	}
	

}

void game::display_game() const{
	std::cout << std::endl << std::endl;
	std::cout << "Arrows remaining: " << gs.get_num_arrows() << std::endl;

	std::string row_border = "--";
	for (int i = 0; i < this->width; ++i) {
		row_border += "-----";
	}

	std::cout << row_border << std::endl;
	for (int i = 0; i < this->height; ++i) {
		std::cout << "||";
		for (int j = 0; j < this->width; ++j) {
			/*i is y 
			j is x
			I thought it was the other way around and was 
			ripping out my hair for 15 minutes over this*/

			// The first char indicates whether there is a player in the room
			// at row index i, column index j. TODO If the room contains the
			// player, print an asterisk ("*")
			if(i==gs.get_player_y() && j==gs.get_player_x()){
				std::cout << "*";
			}
			// TODO else, print a space (" ")
			else{
				std::cout << " ";
			}
			// The next char indicates the event in the room.

			// TODO If debug mode is disabled OR the room at location <i, j>
			// does not have an event, print a space (" ")
			// For example:
			// if (!this->debug || <i, j> ROOM DOES NOT HAVE EVENT) {
			// 	std::cout << " ";
			// }
			//
			if(!this->debug || !rooms.at(j).at(i).has_event()){
				std::cout << " ";
			}
			// TODO else, print the room's debug symbol. There are a few ways to
			// do this. You can use polymorphism, or an event could have a
			// char debug_symbol member variable and some sort of
			// get_debug_symbol() member function that you could call here
			// to get the character and print it.
			else{
				rooms.at(j).at(i).print_char();
			}

			std::cout << " ||";
		}
		std::cout << std::endl;
		std::cout << row_border << std::endl;
	}

	//example output (when finished): 
	// ----------------------
	// || P || G || P ||   ||
	// ----------------------
	// ||   || W ||   || S ||
	// ----------------------   
	// ||   ||   ||   || S ||
	// ----------------------   
	// ||*  ||   ||   ||   ||
	// ----------------------
}

bool game::check_win() const{
	// TODO Delete the below placeholder code. Return true if the player
	// has won the game. Return false otherwise.
	if(gs.has_gold() && 
	rooms.at(gs.get_player_x()).at(gs.get_player_y()).check_rope()){
		std::cout << "You win!" << std::endl;
		return true;
	}
	return false;
}

bool game::check_lose() const{
	// TODO Delete the below placeholder code. Return true if the player
	// has lost the game. Return false otherwise.
	if(gs.get_lives()==0){
		std::cout << "You lose!" << std::endl;
		return true;
	}
	//std::cout << "game::check_lose() is not implemented..." << std::endl;
	return false;
}

bool game::is_direction(char c) {
	return c == 'w' ||
		c == 'a' ||
		c == 's' ||
		c == 'd';
}

char game::to_lower(char direction) {
	if (direction >= 'A' && direction <= 'Z') {
		return direction + ('a' - 'A');
	}
	return direction;
}

bool game::can_move_in_direction(char direction) {
	// TODO Delete the below placeholder code. Return true if the player can
	// move in the given direction ('w' for up, 'a' for left, 's' for down,
	// 'd' for right). Return false otherwise. The player can move in the
	// given direction so long as it wouldn't cause them to move off the
	// grid.

	//check bounds in the array relative to the player's current position
	//don't need to check corners
	//use width and height variables
	if(direction=='a'){
		if(gs.get_player_x()-1>=0){
			return true;
		}
	}
	else if(direction=='d'){
		if(gs.get_player_x()+1<=width-1){
			return true;
		}
	}

	else if(direction=='s'){
		if(gs.get_player_y()+1<=height-1){
			return true;
		}
	}
	else if(direction=='w'){
		if(gs.get_player_y()-1>=0){
			return true;
		}
	}
	//if move is illegal
	return false;
	
}

bool game::is_valid_action(char action) {
	if (this->is_direction(action)) {
		char direction = action;
		return this->can_move_in_direction(direction);
	} else if (action == 'f') {
		return gs.get_num_arrows() > 0;
	}
	return false;
}

void game::print_action_error(char action) {
	if (this->is_direction(action)) {
		std::cout << "You can't move in that direction!" << std::endl <<
			std::endl;
	} else if (action == 'f') {
		std::cout << "You're out of arrows!" << std::endl << std::endl;
	} else {
		std::cout << std::endl << "That's an invalid input!" << std::endl
			<< std::endl;
	}
}

char game::get_player_action() {
	char action;
	bool first = true;
	do {
		if (!first) {
			char previous_action = action;
			this->print_action_error(previous_action);
		}
		first = false;

		std::cout << std::endl << std::endl << "What would you like to do?" <<
			std::endl << std::endl;
		std::cout << "w: move up" << std::endl;
		std::cout << "a: move left" << std::endl;
		std::cout << "s: move down" << std::endl;
		std::cout << "d: move right" << std::endl;
		std::cout << "f: fire an arrow" << std::endl;

		std::cin >> action;
		action = this->to_lower(action);
	} while (!this->is_valid_action(action));

	return action;
}

char game::get_arrow_fire_direction() {
	char direction;
	bool first = true;
	do {
		if (!first) {
			std::cout << std::endl << "That's an invalid input!" <<
				std::endl << std::endl;
		}
		first = false;

		std::cout << std::endl << std::endl <<
			"What direction would you like to fire the arrow?" << std::endl <<
			std::endl;
		std::cout << "w: up" << std::endl;
		std::cout << "a: left" << std::endl;
		std::cout << "s: down" << std::endl;
		std::cout << "d: right" << std::endl;

		std::cin >> direction;
		direction = this->to_lower(direction);
	} while (!this->is_direction(direction));

	return direction;
}

void game::move_up() {
	// TODO Delete the below placeholder code. Move the player up one
	// space in the grid, however you choose to do that.
	gs.set_player_y(gs.get_player_y()-1);
	//std::cout << "game::move_up() is not implemented..." << std::endl;
}

void game::move_down() {
	// TODO Delete the below placeholder code. Move the player down one
	// space in the grid, however you choose to do that.
	gs.set_player_y(gs.get_player_y()+1);
	//std::cout << "game::move_down() is not implemented..." << std::endl;
}

void game::move_left() {
	// TODO Delete the below placeholder code. Move the player left one
	// space in the grid, however you choose to do that.
	gs.set_player_x(gs.get_player_x()-1);
	//std::cout << "game::move_left() is not implemented..." << std::endl;
}

void game::move_right() {
	// TODO Delete the below placeholder code. Move the player right one
	// space in the grid, however you choose to do that.
	gs.set_player_x(gs.get_player_x()+1);
	//std::cout << "game::move_right() is not implemented..." << std::endl;
}

void game::move(char direction) {
	if (direction == 'w') {
		this->move_up();
	} else if (direction == 'a') {
		this->move_left();
	} else if (direction == 's') {
		this->move_down();
	} else {
		this->move_right();
	}
}

void game::fire_arrow_up() {
	// TODO Delete the below placeholder code. Fire the arrow upward, killing
	// the wumpus if it hits it or making the wumpus "wake up" and move
	// randomly if it misses
	
	std::cout << "game::fire_arrow_up is not implemented..." << std::endl;
}

void game::fire_arrow_down() {
	// TODO Delete the below placeholder code. Fire the arrow downward, killing
	// the wumpus if it hits it or making the wumpus "wake up" and move
	// randomly if it misses
	
	std::cout << "game::fire_arrow_down is not implemented..." << std::endl;
}

void game::fire_arrow_left() {
	// TODO Delete the below placeholder code. Fire the arrow leftward, killing
	// the wumpus if it hits it or making the wumpus "wake up" and move
	// randomly if it misses
	
	std::cout << "game::fire_arrow_left is not implemented..." << std::endl;
}

void game::fire_arrow_right() {
	// TODO Delete the below placeholder code. Fire the arrow rightward, killing
	// the wumpus if it hits it or making the wumpus "wake up" and move
	// randomly if it misses
	
	std::cout << "game::fire_arrow_right is not implemented..." << std::endl;
}

void game::fire_arrow(char direction) {
	if (direction == 'w') {
		this->fire_arrow_up();
	} else if (direction == 'a') {
		this->fire_arrow_left();
	} else if (direction == 's') {
		this->fire_arrow_right();
	} else {
		this->fire_arrow_down();
	}

	gs.use_arrow();
}

void game::play_game(){
	while (!this->check_win() && !this->check_lose()) {
		// Print game board
		this->display_game();

		// TODO Display precepts around player's location
		//percept
		check_adjacent();
		// Ask player for their action
		char action = this->get_player_action();

		// Process action
		if (this->is_direction(action)) {
			// W/A/S/D = move player
			char direction = action;
			this->move(direction);
		} else {
			// F = prompt for arrow fire direction and fire arrow
			char direction = this->get_arrow_fire_direction();
			this->fire_arrow(direction);
		}

		// TODO If the user is on a space with an event, trigger its encounter
		if(rooms.at(gs.get_player_x()).at(gs.get_player_y()).has_event()){
			rooms.at(gs.get_player_x()).at(gs.get_player_y()).trigger(gs);
		}

		/*
		Checks after a trigger modifies the gamestate.
		Using modifications to gamestate to trigger game events
		because I can't directly pass the game object itself as a parameter
		*/

		//Remove gold/arrow from board on pickup
		if(rooms.at(gs.get_player_x()).at(gs.get_player_y()).check_remove()){ 
			rooms.at(gs.get_player_x()).at(gs.get_player_y()).free_event();
		}
		//When player dies
		if(gs.respawn()){
			respawn();
		}
	}
}

void game::place_random_empty(event* e){
	bool found = false;
	int x,y;
	//this is probably so inefficient 
	//but I don't know a more efficient algorithm atm
	while(!found){
		x = rand()%width;
		y = rand()%height;
		//no event then return
		if(!rooms.at(x).at(y).has_event()){
			found = true;
		}
	}
	rooms.at(x).at(y).set_event(e);
}

void game::check_adjacent(){
	//validate left, right, up, down directions
	//and then call the percept() of events in those rooms
	if(can_move_in_direction('w')){
		rooms.at(gs.get_player_x()).at(gs.get_player_y()-1).percept();
	}
	if(can_move_in_direction('s')){
		rooms.at(gs.get_player_x()).at(gs.get_player_y()+1).percept();
	}
	if(can_move_in_direction('a')){
		rooms.at(gs.get_player_x()-1).at(gs.get_player_y()).percept();
	}
	if(can_move_in_direction('d')){
		rooms.at(gs.get_player_x()+1).at(gs.get_player_y()).percept();
	}
	
}

void game::cleanup(){
	for(int i=0;i<width;i++){
		for(int j=0;j<height;j++){
				//checking happens in the function already
				rooms.at(i).at(j).free_event();
		}
	}
}

void game::respawn(){
	if(gs.has_gold()){
		event* g = new gold;
		place_random_empty(g);
		gs.set_gold(false);
	}
	if(gs.get_num_arrows()>0){
		for(int i=0;i<=gs.get_num_arrows();i++){
			event* a = new arrow;
			place_random_empty(a);
			gs.use_arrow();
		}
	}
	if(rooms.at(gs.get_player_x()).at(gs.get_player_y()).check_wumpus()){
		event* w = new wumpus;
		place_random_empty(w);
		rooms.at(gs.get_player_x()).at(gs.get_player_y()).free_event();
	}
	gs.set_player_x(rope_x);
	gs.set_player_y(rope_y);
}