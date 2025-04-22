#include "Session.h"

// Constructor
Session::Session(Module mod, Room rm, int start) 
    : module(mod), room(rm), startTime(start) {}

// Getters
std::string Session::getModuleName() const { return module.getModuleName(); }
std::string Session::getRoom() const { return room.getRoomName(); }
int Session::getStartTime() const { return startTime; }