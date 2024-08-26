#include "Reservation.h"

Reservation::Reservation(Movie movie, Room room, Schedule schedule, int bookingNumber)
    : movie(movie), room(room), schedule(schedule), bookingNumber(bookingNumber) {}

Movie Reservation::getMovie() const {
    return movie;
}

Room Reservation::getRoom() const {
    return room;
}

Schedule Reservation::getSchedule() const {
    return schedule;
}

int Reservation::getBookingNumber() const {
    return bookingNumber;
}

void Reservation::setMovie(const Movie& movie) {
    this->movie = movie;
}

void Reservation::setRoom(const Room& room) {
    this->room = room;
}

void Reservation::setSchedule(const Schedule& schedule) {
    this->schedule = schedule;
}

void Reservation::setBookingNumber(int bookingNumber) {
    this->bookingNumber = bookingNumber;
}
