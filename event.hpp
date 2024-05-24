#ifndef EVENT_HPP
#define EVENT_HPP

// Event interface
class event {
private:
	// TODO private members, if relevant
protected:
	// TODO protected members, if relevant
	
	/*
	Name: trigger
	Description: triggers the event(if any)
	*/
	virtual void trigger()=0;

	/*
	Name: percept
	Description: prints percept text
	*/
	virtual void percept()=0;

public:
	// TODO public members
};

#endif
