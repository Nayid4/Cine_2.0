#include "RoomManager.h"
#include <iostream>
#include <stdexcept>

void RoomManager::addRoom() {
    int number, seatCount;
    float price;

    getInput(number, seatCount, price);

    TheaterRoom room(number, seatCount, price);
    TheaterRoomController::getInstance().addTheaterRoom(room);

    std::cout << "Sala agregada exitosamente.\n";
}

void RoomManager::listRooms() {
    TheaterRoomController& controller = TheaterRoomController::getInstance();
    size_t count = controller.getTheaterRoomCount();

    if (count == 0) {
        std::cout << "No hay salas disponibles.\n";
        return;
    }

    std::cout << "\n===== Lista de Salas =====\n";
    for (size_t i = 0; i < count; ++i) {
        TheaterRoom room = controller.getTheaterRoom(i);
        std::cout << i + 1 << ". Sala No. " << room.getNumber()
            << "\n   Asientos: " << room.getSeatCount()
            << "\n   Precio: $" << room.getPrice() << "\n\n";
    }
}

void RoomManager::updateRoom() {
    TheaterRoomController& controller = TheaterRoomController::getInstance();
    size_t count = controller.getTheaterRoomCount();

    if (count == 0) {
        std::cout << "No hay salas para actualizar.\n";
        return;
    }

    listRooms();

    int index;
    getRoomIndex(index);

    if (index < 0 || index >= count) {
        std::cout << "Índice no válido.\n";
        return;
    }

    int number, seatCount;
    float price;

    getInput(number, seatCount, price);

    TheaterRoom updatedRoom(number, seatCount, price);
    controller.updateTheaterRoom(index, updatedRoom);

    std::cout << "Sala actualizada exitosamente.\n";
}

void RoomManager::deleteRoom() {
    TheaterRoomController& controller = TheaterRoomController::getInstance();
    size_t count = controller.getTheaterRoomCount();

    if (count == 0) {
        std::cout << "No hay salas para eliminar.\n";
        return;
    }

    listRooms();

    int index;
    getRoomIndex(index);

    if (index < 0 || index >= count) {
        std::cout << "Índice no válido.\n";
        return;
    }

    controller.deleteTheaterRoom(index);
    std::cout << "Sala eliminada exitosamente.\n";
}

void RoomManager::manageRooms() {
    int choice = 0;
    while (choice != 5) {
        std::cout << "\n===== Gestión de Salas =====\n";
        std::cout << "1. Agregar Sala\n";
        std::cout << "2. Listar Salas\n";
        std::cout << "3. Actualizar Sala\n";
        std::cout << "4. Eliminar Sala\n";
        std::cout << "5. Volver\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> choice;

        switch (choice) {
        case 1: addRoom(); break;
        case 2: listRooms(); break;
        case 3: updateRoom(); break;
        case 4: deleteRoom(); break;
        case 5: std::cout << "Volviendo al menú principal...\n"; break;
        default: std::cout << "Opción inválida. Intente de nuevo.\n";
        }
    }
}

void RoomManager::getInput(int& number, int& seatCount, float& price) {
    std::cout << "Ingrese el número de la sala: ";
    std::cin >> number;

    std::cout << "Ingrese la cantidad de asientos: ";
    std::cin >> seatCount;

    std::cout << "Ingrese el precio de la sala: ";
    std::cin >> price;
}

void RoomManager::getRoomIndex(int& index) {
    std::cout << "Ingrese el número de la sala que desea: ";
    std::cin >> index;
    --index; // Ajustar para índice basado en 0
}
