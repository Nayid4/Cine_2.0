#ifndef THEATEROOMCONTROLLER_H
#define THEATEROOMCONTROLLER_H

#include "TheaterRoom.h"
#include <vector>

class TheaterRoomController {
public:
    static TheaterRoomController& getInstance();

    void addTheaterRoom(const TheaterRoom& room);
    TheaterRoom getTheaterRoom(int index) const;
    void updateTheaterRoom(int index, const TheaterRoom& room);
    void deleteTheaterRoom(int index);
    size_t getTheaterRoomCount() const;

private:
    TheaterRoomController();
    std::vector<TheaterRoom> rooms;
};

#endif // THEATEROOMCONTROLLER_H
