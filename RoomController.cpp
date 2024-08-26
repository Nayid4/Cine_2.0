#include "RoomController.h"
#include <stdexcept>

RoomController& RoomController::getInstance() {
    static RoomController instance;
    return instance;
}

RoomController::RoomController() {}

void RoomController::addRoom(const Room& room) {
    rooms.push_back(room);
}

Room RoomController::getRoom(int index) const {
    if (index >= 0 && index < rooms.size()) {
        return rooms[index];
    }
    throw std::out_of_range("Index out of range");
}

void RoomController::updateRoom(int index, const Room& room) {
    if (index >= 0 && index < rooms.size()) {
        rooms[index] = room;
    }
    else {
        throw std::out_of_range("Index out of range");
    }
}

void RoomController::deleteRoom(int index) {
    if (index >= 0 && index < rooms.size()) {
        rooms.erase(rooms.begin() + index);
    }
    else {
        throw std::out_of_range("Index out of range");
    }
}

size_t RoomController::getRoomCount() const {
    return rooms.size();
}
