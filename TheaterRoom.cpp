#include "TheaterRoom.h"

TheaterRoom::TheaterRoom(int number, int seatCount, float price)
    : number(number), seatCount(seatCount), price(price) {}

int TheaterRoom::getNumber() const {
    return number;
}

int TheaterRoom::getSeatCount() const {
    return seatCount;
}

float TheaterRoom::getPrice() const {
    return price;
}

void TheaterRoom::setNumber(int number) {
    this->number = number;
}

void TheaterRoom::setSeatCount(int seatCount) {
    this->seatCount = seatCount;
}

void TheaterRoom::setPrice(float price) {
    this->price = price;
}
