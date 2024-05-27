#ifndef ROOM_HPP
#define ROOM_HPP

#include "event.hpp"

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
	*/
	void trigger();
	/*
	Name: percept
	*/
	
};

#endif
