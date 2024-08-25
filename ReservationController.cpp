#include "ReservationController.h"
#include <stdexcept>

ReservationController& ReservationController::getInstance() {
    static ReservationController instance;
    return instance;
}

ReservationController::ReservationController() {}

void ReservationController::addReservation(const Reservation& reservation) {
    reservations.push_back(reservation);
}

Reservation ReservationController::getReservation(int index) const {
    if (index >= 0 && index < reservations.size()) {
        return reservations[index];
    }
    throw std::out_of_range("Index out of range");
}

void ReservationController::updateReservation(int index, const Reservation& reservation) {
    if (index >= 0 && index < reservations.size()) {
        reservations[index] = reservation;
    }
    else {
        throw std::out_of_range("Index out of range");
    }
}

void ReservationController::deleteReservation(int index) {
    if (index >= 0 && index < reservations.size()) {
        reservations.erase(reservations.begin() + index);
    }
    else {
        throw std::out_of_range("Index out of range");
    }
}

size_t ReservationController::getReservationCount() const {
    return reservations.size();
}
