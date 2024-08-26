#ifndef ROOM_MANAGER_H
#define ROOM_MANAGER_H

#include "RoomController.h"

class RoomManager {
public:
    // Métodos públicos para manejar salas
    void addRoom();
    void listRooms();
    void updateRoom();
    void deleteRoom();
    void manageRooms();

private:
    // Métodos privados para la entrada del usuario
    void getInput(int& number, int& seatCount, float& price);
    void getRoomIndex(int& index);
};

#endif // ROOM_MANAGER_H
