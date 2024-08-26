#include "MovieManager.h"
#include <iostream>
#include <stdexcept>

void MovieManager::addMovie() {
    std::string name, country, review;
    int year, duration;

    getInput(name, year, duration, country, review);

    Movie movie(name, year, duration, country, review);
    MovieController::getInstance().addMovie(movie);

    std::cout << "Pelicula agregada exitosamente.\n";
}

void MovieManager::listMovies() {
    MovieController& controller = MovieController::getInstance();
    size_t count = controller.getMovieCount();

    if (count == 0) {
        std::cout << "No hay peliculas disponibles.\n";
        return;
    }

    std::cout << "\n===== Lista de Peliculas =====\n";
    for (size_t i = 0; i < count; ++i) {
        Movie movie = controller.getMovie(i);
        std::cout << i + 1 << ". " << movie.getName()
            << " (" << movie.getYear() << ")\n"
            << "   Duracion: " << movie.getDuration() << " min\n"
            << "   Pais: " << movie.getCountry() << "\n"
            << "   Reseña: " << movie.getReview() << "\n\n";
    }
}

void MovieManager::updateMovie() {
    MovieController& controller = MovieController::getInstance();
    size_t count = controller.getMovieCount();

    if (count == 0) {
        std::cout << "No hay peliculas para actualizar.\n";
        return;
    }

    listMovies();

    int index;
    getMovieIndex(index);

    if (index < 0 || index >= count) {
        std::cout << "Indice no valido.\n";
        return;
    }

    std::string name, country, review;
    int year, duration;

    getInput(name, year, duration, country, review);

    Movie updatedMovie(name, year, duration, country, review);
    controller.updateMovie(index, updatedMovie);

    std::cout << "Pelicula actualizada exitosamente.\n";
}

void MovieManager::deleteMovie() {
    MovieController& controller = MovieController::getInstance();
    size_t count = controller.getMovieCount();

    if (count == 0) {
        std::cout << "No hay peliculas para eliminar.\n";
        return;
    }

    listMovies();

    int index;
    getMovieIndex(index);

    if (index < 0 || index >= count) {
        std::cout << "Indice no valido.\n";
        return;
    }

    controller.deleteMovie(index);
    std::cout << "Pelicula eliminada exitosamente.\n";
}

void MovieManager::manageMovies() {
    int choice = 0;
    while (choice != 5) {
        std::cout << "\n===== Gestion de Peliculas =====\n";
        std::cout << "1. Agregar Película\n";
        std::cout << "2. Listar Películas\n";
        std::cout << "3. Actualizar Película\n";
        std::cout << "4. Eliminar Película\n";
        std::cout << "5. Volver\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> choice;

        switch (choice) {
        case 1: addMovie(); break;
        case 2: listMovies(); break;
        case 3: updateMovie(); break;
        case 4: deleteMovie(); break;
        case 5: std::cout << "Volviendo al menu principal...\n"; break;
        default: std::cout << "Opcion invalida. Intente de nuevo.\n";
        }
    }
}

void MovieManager::getInput(std::string& name, int& year, int& duration, std::string& country, std::string& review) {
    std::cout << "Ingrese el nombre de la película: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Ingrese el año de la pelicula: ";
    std::cin >> year;

    std::cout << "Ingrese la duración de la película (minutos): ";
    std::cin >> duration;

    std::cout << "Ingrese el pais de origen de la pelicula: ";
    std::cin.ignore();
    std::getline(std::cin, country);

    std::cout << "Ingrese la reseña de la pelicula: ";
    std::getline(std::cin, review);
}

void MovieManager::getMovieIndex(int& index) {
    std::cout << "Ingrese el numero de la pelicula que desea: ";
    std::cin >> index;
    --index; // Ajustar para índice basado en 0
}
