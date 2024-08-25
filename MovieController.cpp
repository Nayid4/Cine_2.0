#include "MovieController.h"
#include <stdexcept>

MovieController& MovieController::getInstance() {
    static MovieController instance;
    return instance;
}

MovieController::MovieController() {}

void MovieController::addMovie(const Movie& movie) {
    movies.push_back(movie);
}

Movie MovieController::getMovie(int index) const {
    if (index >= 0 && index < movies.size()) {
        return movies[index];
    }
    throw std::out_of_range("Index out of range");
}

void MovieController::updateMovie(int index, const Movie& movie) {
    if (index >= 0 && index < movies.size()) {
        movies[index] = movie;
    }
    else {
        throw std::out_of_range("Index out of range");
    }
}

void MovieController::deleteMovie(int index) {
    if (index >= 0 && index < movies.size()) {
        movies.erase(movies.begin() + index);
    }
    else {
        throw std::out_of_range("Index out of range");
    }
}

size_t MovieController::getMovieCount() const {
    return movies.size();
}
