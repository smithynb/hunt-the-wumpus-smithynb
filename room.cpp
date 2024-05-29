#include "room.hpp"

// TODO Room implementation (define room member functions below)
void Room::set_event(event* e){
    this->room_event = e;
}
void Room::clear_event(){
    delete this->room_event;
    this->room_event = nullptr;
}
bool Room::has_event()const{
    if(this->room_event!=nullptr){
        return true; //event
    }
    return false; //no event
}
void Room::print_char()const{
    this->room_event->print_char();
}
void Room::trigger(game_state& g){
    this->room_event->trigger(g);
}
bool Room::check_rope()const{
    if(this->room_event!=nullptr && this->room_event->is_rope()){
        return true;
    }
    return false;
}
void Room::percept(){
    if(this->room_event!=nullptr){
        this->room_event->percept();
    }
}
bool Room::check_wumpus()const{
    if(this->room_event!=nullptr && this->room_event->is_wumpus()){
        return true;
    }
    return false;
}
void Room::free_event(){
    if(this->has_event()){
        delete this->room_event;
        this->room_event = nullptr;
    }
    
}