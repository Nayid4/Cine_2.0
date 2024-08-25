#ifndef RESERVATIONCONTROLLER_H
#define RESERVATIONCONTROLLER_H

#include "Reservation.h"
#include <vector>

class ReservationController {
public:
    static ReservationController& getInstance();

    void addReservation(const Reservation& reservation);
    Reservation getReservation(int index) const;
    void updateReservation(int index, const Reservation& reservation);
    void deleteReservation(int index);
    size_t getReservationCount() const;

private:
    ReservationController();
    std::vector<Reservation> reservations;
};

#endif // RESERVATIONCONTROLLER_H
