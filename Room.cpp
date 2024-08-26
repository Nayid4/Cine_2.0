#include "Room.h"

Room::Room(int number, int seatCount, float price)
    : number(number), seatCount(seatCount), price(price) {}

int Room::getNumber() const {
    return number;
}

int Room::getSeatCount() const {
    return seatCount;
}

float Room::getPrice() const {
    return price;
}

void Room::setNumber(int number) {
    this->number = number;
}

void Room::setSeatCount(int seatCount) {
    this->seatCount = seatCount;
}

void Room::setPrice(float price) {
    this->price = price;
}
