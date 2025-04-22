#ifndef SESSION_H
#define SESSION_H

#include "Module.h"
#include "Room.h"

class Session {
private:
    Module module;
    Room room;
    int startTime; // 24-hour format

public:
    Session(Module mod, Room rm, int start) : module(mod), room(rm), startTime(start) {}

    std::string getModuleName() const { return module.getModuleName(); }
    std::string getRoom() const { return room.getRoomName(); }
    int getStartTime() const { return startTime; }
};

#endif