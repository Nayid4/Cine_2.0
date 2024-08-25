#ifndef MOVIECONTROLLER_H
#define MOVIECONTROLLER_H

#include "Movie.h"
#include <vector>

class MovieController {
public:
    static MovieController& getInstance();

    void addMovie(const Movie& movie);
    Movie getMovie(int index) const;
    void updateMovie(int index, const Movie& movie);
    void deleteMovie(int index);
    size_t getMovieCount() const;

private:
    MovieController();
    std::vector<Movie> movies;
};

#endif // MOVIECONTROLLER_H
