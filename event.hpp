#ifndef EVENT_HPP
#define EVENT_HPP
#include <iostream>
//#include "game.hpp"
// Event interface
class game; //forward declaration to resolve circular include

class event {
private:
	// TODO private members, if relevant
protected:
	// TODO protected members, if relevant
	
	

	/*
	Name: percept
	Description: prints percept text
	*/
	virtual void percept()=0;

	

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
	virtual void trigger(game& g)=0;
};

#endif
