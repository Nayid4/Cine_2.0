#ifndef ROOMCONTROLLER_H
#define ROOMCONTROLLER_H

#include "Room.h"
#include <vector>

class RoomController {
public:
    static RoomController& getInstance();

    void addRoom(const Room& room);
    Room getRoom(int index) const;
    void updateRoom(int index, const Room& room);
    void deleteRoom(int index);
    size_t getRoomCount() const;

private:
    RoomController();
    std::vector<Room> rooms;
};

#endif // THEATEROOMCONTROLLER_H
