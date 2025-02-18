#ifndef EVENT_HPP
#define EVENT_HPP
#include <iostream>
#include "game_state.hpp"

// Event interface 
class event {
private:
	// TODO private members, if relevant
protected:
	// TODO protected members, if relevant
public:
	// TODO public members
	
	/*
	Name: print_char
	Description: print the char for the room for debug
	Probably would've been easier to put it as a variable in room
	*/
	virtual void print_char()const =0;
	/*
	Name: trigger
	Description: triggers the event(if any)
	*/
	virtual void trigger(game_state& g)=0;
	/*
	Name: percept
	Description: prints percept text
	*/
	virtual void percept(){}

	/*
	Name: is_rope
	Description: returns if the event is escape rope
	Returns: true if overrided by escape rope
	*/
	virtual bool is_rope()const;

	/*
	Name: is_wumpus
	Description: returns if the event is a wumpus
	Returns: true if overrided by wumpus
	*/
	virtual bool is_wumpus()const;

	/*
	Name: to_remove
	Description: returns if the event in the room is to be removed
	on trigger
	Returns: (bool)true to delete(arrow,gold), false by default
	*/
	virtual bool to_remove()const;
};

#endif
