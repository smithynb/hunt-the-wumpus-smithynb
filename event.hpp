#ifndef EVENT_HPP
#define EVENT_HPP
#include <iostream>
#include "game_state.hpp"
//forward declaration of game_state
//class game_state;
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
	virtual void percept()=0;

	/*
	Name: is_rope
	Description: returns if the event is escape rope
	Returns: true if overrided by escape rope
	*/
	virtual bool is_rope()const;
};

#endif
