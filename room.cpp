#include "room.hpp"

// TODO Room implementation (define room member functions below)
void Room::set_event(event* e){
    this->room_event = e;
}
void Room::clear_event(){
    delete this->room_event;
    this->room_event = nullptr;
}
bool Room::has_event(){
    if(this->room_event!=nullptr){
        return true; //event
    }
    return false; //no event
}