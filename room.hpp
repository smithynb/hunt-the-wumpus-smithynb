#ifndef ROOM_HPP
#define ROOM_HPP

#include "event.hpp"
#include "game_state.hpp"

// Room interface
class Room {
private: 
	// TODO private members
	event* room_event = nullptr;
public:
	// TODO public members

	/*
	Name: set_event (setter)
	Description: sets event to point to an 
	object of a derived class of event
	Parameters:
		e (event*): event 
	*/
	void set_event(event* e);

	/*
	Name: clear_event
	Description: frees the event object from the heap
	and sets room_event to nullptr
	*/
	void clear_event();

	/*
	Name: has_event
	Description: returns true if the room isn't empty
	Returns: true if room_event isn't nullptr (bool)
	*/
	bool has_event()const;

	/*
	Name: print_char
	Description: calls the print_char of the room's event
	*/
	void print_char()const;

	/*
	Name: trigger
	Description: calls the trigger function of 
	the room's event and pass the game as reference
	Parameters:
		g (game_state&): the variables and functions of the "game state"
	*/
	void trigger(game_state& g);

	/*
	Name: check_rope
	Description: checks if the room has the rope event
	Returns: (bool) true if the room has a rope
	*/
	bool check_rope()const;

	/*
	Name: percept
	Description: calls the percept function of the event if any
	*/
	void percept();

	/*
	Name: check_wumpus
	Description: calls the is_wumpus function 
	Returns: (bool) true if the room has wumpus
	*/
	bool check_wumpus()const;

	/*
	Name: free_event
	Description: delete the event and set nullptr
	*/
	void free_event();

	/*
	Name: check_remove
	Description: checks if the room has gold/arrow
	Returns (bool) true if the room has gold/arrow
	*/
	bool check_remove()const;

};

#endif
