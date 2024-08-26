#ifndef RESERVATIONSMANAGER_H
#define RESERVATIONSMANAGER_H

#include "ReservationController.h"
#include "MovieController.h"
#include "RoomController.h"

class ReservationsManager {
public:
    void addReservation();
    void listReservations() const;
    void updateReservation();
    void deleteReservation();
    void manageReservations();

private:
    int getMovieIndex() const;
    int getRoomIndex() const;
    int getReservationIndex() const;
    void getReservationInput(Reservation& reservation) const;
};

#endif // RESERVATIONSMANAGER_H
