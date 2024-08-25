#ifndef RESERVATION_H
#define RESERVATION_H

#include "Movie.h"
#include "TheaterRoom.h"
#include "Schedule.h"

class Reservation {
private:
    Movie movie;
    TheaterRoom room;
    Schedule schedule;
    int bookingNumber;

public:
    Reservation(Movie movie, TheaterRoom room, Schedule schedule, int bookingNumber);

    Movie getMovie() const;
    TheaterRoom getRoom() const;
    Schedule getSchedule() const;
    int getBookingNumber() const;

    void setMovie(const Movie& movie);
    void setRoom(const TheaterRoom& room);
    void setSchedule(const Schedule& schedule);
    void setBookingNumber(int bookingNumber);
};

#endif // RESERVATION_H
