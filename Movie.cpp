#include "Movie.h"

Movie::Movie(std::string name, int year, int duration, std::string country, std::string review)
    : name(name), year(year), duration(duration), country(country), review(review) {}

std::string Movie::getName() const {
    return name;
}

int Movie::getYear() const {
    return year;
}

int Movie::getDuration() const {
    return duration;
}

std::string Movie::getCountry() const {
    return country;
}

std::string Movie::getReview() const {
    return review;
}

void Movie::setName(const std::string& name) {
    this->name = name;
}

void Movie::setYear(int year) {
    this->year = year;
}

void Movie::setDuration(int duration) {
    this->duration = duration;
}

void Movie::setCountry(const std::string& country) {
    this->country = country;
}

void Movie::setReview(const std::string& review) {
    this->review = review;
}
