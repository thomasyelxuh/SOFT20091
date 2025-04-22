#ifndef ROOM_H
#define ROOM_H

#include <string>

class Room {
private:
    std::string roomName;
    int capacity;

public:
    Room(std::string name, int cap) : roomName(name), capacity(cap) {}

    std::string getRoomName() const { return roomName; }
    int getCapacity() const { return capacity; }
};

#endif