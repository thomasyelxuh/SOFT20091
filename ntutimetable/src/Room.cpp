#include "Room.h"

// Constructor
Room::Room(std::string name, int cap) 
    : roomName(name), capacity(cap) {}

// Getters
std::string Room::getRoomName() const { return roomName; }
int Room::getCapacity() const { return capacity; }