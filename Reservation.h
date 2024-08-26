#ifndef RESERVATION_H
#define RESERVATION_H

#include "Movie.h"
#include "Room.h"
#include "Schedule.h"

class Reservation {
private:
    Movie movie;
    Room room;
    Schedule schedule;
    int bookingNumber;

public:
    Reservation(Movie movie, Room room, Schedule schedule, int bookingNumber);

    Movie getMovie() const;
    Room getRoom() const;
    Schedule getSchedule() const;
    int getBookingNumber() const;

    void setMovie(const Movie& movie);
    void setRoom(const Room& room);
    void setSchedule(const Schedule& schedule);
    void setBookingNumber(int bookingNumber);
};

#endif // RESERVATION_H
