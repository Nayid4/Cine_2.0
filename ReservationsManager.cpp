#include "ReservationsManager.h"
#include <iostream>
#include <stdexcept>

void ReservationsManager::addReservation() {
    int movieIndex = getMovieIndex();
    if (movieIndex < 0) return;

    int roomIndex = getRoomIndex();
    if (roomIndex < 0) return;

    Movie movie = MovieController::getInstance().getMovie(movieIndex);
    Room room = RoomController::getInstance().getRoom(roomIndex);

    Reservation reservation(movie, room, Schedule("15", "10:00", "11:00"), 0); // Temporalmente, se inicializa con valores predeterminados
    getReservationInput(reservation);

    ReservationController::getInstance().addReservation(reservation);

    std::cout << "Reserva agregada exitosamente.\n";
}

void ReservationsManager::listReservations() const {
    ReservationController& controller = ReservationController::getInstance();
    size_t count = controller.getReservationCount();

    if (count == 0) {
        std::cout << "No hay reservas disponibles.\n";
        return;
    }

    std::cout << "\n===== Lista de Reservas =====\n";
    for (size_t i = 0; i < count; ++i) {
        Reservation reservation = controller.getReservation(i);
        std::cout << i + 1 << ". Pelicula: " << reservation.getMovie().getName()
            << ", Sala: " << reservation.getRoom().getNumber()
            << ", Fecha: " << reservation.getSchedule().getDay()
            << ", Hora: " << reservation.getSchedule().getStartTime()
            << " - " << reservation.getSchedule().getEndTime()
            << ", Número de reserva: " << reservation.getBookingNumber()
            << '\n';
    }
}

void ReservationsManager::updateReservation() {
    int index = getReservationIndex();
    if (index < 0) return;

    int movieIndex = getMovieIndex();
    if (movieIndex < 0) return;

    int roomIndex = getRoomIndex();
    if (roomIndex < 0) return;

    Movie movie = MovieController::getInstance().getMovie(movieIndex);
    Room room = RoomController::getInstance().getRoom(roomIndex);

    Reservation updatedReservation(movie, room, Schedule("15", "10:00", "11:00"), 0); // Inicializa con valores predeterminados
    getReservationInput(updatedReservation);

    ReservationController::getInstance().updateReservation(index, updatedReservation);

    std::cout << "Reserva actualizada exitosamente.\n";
}

void ReservationsManager::deleteReservation() {
    int index = getReservationIndex();
    if (index < 0) return;

    ReservationController::getInstance().deleteReservation(index);
    std::cout << "Reserva eliminada exitosamente.\n";
}

void ReservationsManager::manageReservations() {
    int choice = 0;
    while (choice != 5) {
        std::cout << "\n===== Gestion de Reservas =====\n";
        std::cout << "1. Agregar Reserva\n";
        std::cout << "2. Listar Reservas\n";
        std::cout << "3. Actualizar Reserva\n";
        std::cout << "4. Eliminar Reserva\n";
        std::cout << "5. Volver\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> choice;

        switch (choice) {
        case 1: addReservation(); break;
        case 2: listReservations(); break;
        case 3: updateReservation(); break;
        case 4: deleteReservation(); break;
        case 5: std::cout << "Volviendo al menu principal...\n"; break;
        default: std::cout << "Opcion inválida. Intente de nuevo.\n";
        }
    }
}

int ReservationsManager::getMovieIndex() const {
    MovieController& movieController = MovieController::getInstance();
    size_t count = movieController.getMovieCount();

    if (count == 0) {
        std::cout << "No hay películas disponibles.\n";
        return -1;
    }

    std::cout << "Peliculas disponibles:\n";
    for (size_t i = 0; i < count; ++i) {
        Movie movie = movieController.getMovie(i);
        std::cout << i + 1 << ". " << movie.getName() << " (" << movie.getYear() << ")\n";
    }

    int choice;
    std::cout << "Seleccione el numero de la película: ";
    std::cin >> choice;
    if (choice < 1 || choice > static_cast<int>(count)) {
        std::cout << "Seleccion no válida.\n";
        return -1;
    }

    return choice - 1;
}

int ReservationsManager::getRoomIndex() const {
    RoomController& roomController = RoomController::getInstance();
    size_t count = roomController.getRoomCount();

    if (count == 0) {
        std::cout << "No hay salas disponibles.\n";
        return -1;
    }

    std::cout << "Salas disponibles:\n";
    for (size_t i = 0; i < count; ++i) {
        Room room = roomController.getRoom(i);
        std::cout << i + 1 << ". Sala " << room.getNumber()
            << ", Asientos: " << room.getSeatCount()
            << ", Precio: " << room.getPrice() << '\n';
    }

    int choice;
    std::cout << "Seleccione el número de la sala: ";
    std::cin >> choice;
    if (choice < 1 || choice > static_cast<int>(count)) {
        std::cout << "Seleccion no valida.\n";
        return -1;
    }

    return choice - 1;
}

int ReservationsManager::getReservationIndex() const {
    listReservations();
    ReservationController& controller = ReservationController::getInstance();
    size_t count = controller.getReservationCount();

    int index;
    std::cout << "Ingrese el numero de la reserva a modificar/eliminar: ";
    std::cin >> index;
    if (index < 1 || index > static_cast<int>(count)) {
        std::cout << "Indice no valido.\n";
        return -1;
    }

    return index - 1;
}

void ReservationsManager::getReservationInput(Reservation& reservation) const {
    std::string day, startTime, endTime;
    int bookingNumber;

    std::cout << "Ingrese el día de la reserva (Formato: YYYY-MM-DD): ";
    std::cin.ignore();
    std::getline(std::cin, day);

    std::cout << "Ingrese la hora de inicio (HH:MM): ";
    std::getline(std::cin, startTime);

    std::cout << "Ingrese la hora de fin (HH:MM): ";
    std::getline(std::cin, endTime);

    std::cout << "Ingrese el número de reserva: ";
    std::cin >> bookingNumber;

    Schedule schedule(day, startTime, endTime);
    reservation.setSchedule(schedule);
    reservation.setBookingNumber(bookingNumber);
}
