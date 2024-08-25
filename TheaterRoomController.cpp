#include "TheaterRoomController.h"
#include <stdexcept>

TheaterRoomController& TheaterRoomController::getInstance() {
    static TheaterRoomController instance;
    return instance;
}

TheaterRoomController::TheaterRoomController() {}

void TheaterRoomController::addTheaterRoom(const TheaterRoom& room) {
    rooms.push_back(room);
}

TheaterRoom TheaterRoomController::getTheaterRoom(int index) const {
    if (index >= 0 && index < rooms.size()) {
        return rooms[index];
    }
    throw std::out_of_range("Index out of range");
}

void TheaterRoomController::updateTheaterRoom(int index, const TheaterRoom& room) {
    if (index >= 0 && index < rooms.size()) {
        rooms[index] = room;
    }
    else {
        throw std::out_of_range("Index out of range");
    }
}

void TheaterRoomController::deleteTheaterRoom(int index) {
    if (index >= 0 && index < rooms.size()) {
        rooms.erase(rooms.begin() + index);
    }
    else {
        throw std::out_of_range("Index out of range");
    }
}

size_t TheaterRoomController::getTheaterRoomCount() const {
    return rooms.size();
}
