#ifndef MOVIE_MANAGER_H
#define MOVIE_MANAGER_H

#include "MovieController.h"
#include <string>

class MovieManager {
public:
    // Métodos públicos para manejar películas
    void addMovie();
    void listMovies();
    void updateMovie();
    void deleteMovie();
    void manageMovies();

private:
    // Métodos privados para la entrada del usuario
    void getInput(std::string& name, int& year, int& duration, std::string& country, std::string& review);
    void getMovieIndex(int& index);
};

#endif // MOVIE_MANAGER_H
