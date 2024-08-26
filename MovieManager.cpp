#include "MovieManager.h"
#include <iostream>
#include <stdexcept>

void MovieManager::addMovie() {
    std::string name, country, review;
    int year, duration;

    getInput(name, year, duration, country, review);

    Movie movie(name, year, duration, country, review);
    MovieController::getInstance().addMovie(movie);

    std::cout << "Película agregada exitosamente.\n";
}

void MovieManager::listMovies() {
    MovieController& controller = MovieController::getInstance();
    size_t count = controller.getMovieCount();

    if (count == 0) {
        std::cout << "No hay películas disponibles.\n";
        return;
    }

    std::cout << "\n===== Lista de Películas =====\n";
    for (size_t i = 0; i < count; ++i) {
        Movie movie = controller.getMovie(i);
        std::cout << i + 1 << ". " << movie.getName()
            << " (" << movie.getYear() << ")\n"
            << "   Duración: " << movie.getDuration() << " min\n"
            << "   País: " << movie.getCountry() << "\n"
            << "   Reseña: " << movie.getReview() << "\n\n";
    }
}

void MovieManager::updateMovie() {
    MovieController& controller = MovieController::getInstance();
    size_t count = controller.getMovieCount();

    if (count == 0) {
        std::cout << "No hay películas para actualizar.\n";
        return;
    }

    listMovies();

    int index;
    getMovieIndex(index);

    if (index < 0 || index >= count) {
        std::cout << "Índice no válido.\n";
        return;
    }

    std::string name, country, review;
    int year, duration;

    getInput(name, year, duration, country, review);

    Movie updatedMovie(name, year, duration, country, review);
    controller.updateMovie(index, updatedMovie);

    std::cout << "Película actualizada exitosamente.\n";
}

void MovieManager::deleteMovie() {
    MovieController& controller = MovieController::getInstance();
    size_t count = controller.getMovieCount();

    if (count == 0) {
        std::cout << "No hay películas para eliminar.\n";
        return;
    }

    listMovies();

    int index;
    getMovieIndex(index);

    if (index < 0 || index >= count) {
        std::cout << "Índice no válido.\n";
        return;
    }

    controller.deleteMovie(index);
    std::cout << "Película eliminada exitosamente.\n";
}

void MovieManager::manageMovies() {
    int choice = 0;
    while (choice != 5) {
        std::cout << "\n===== Gestión de Películas =====\n";
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
        case 5: std::cout << "Volviendo al menú principal...\n"; break;
        default: std::cout << "Opción inválida. Intente de nuevo.\n";
        }
    }
}

void MovieManager::getInput(std::string& name, int& year, int& duration, std::string& country, std::string& review) {
    std::cout << "Ingrese el nombre de la película: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Ingrese el año de la película: ";
    std::cin >> year;

    std::cout << "Ingrese la duración de la película (minutos): ";
    std::cin >> duration;

    std::cout << "Ingrese el país de origen de la película: ";
    std::cin.ignore();
    std::getline(std::cin, country);

    std::cout << "Ingrese la reseña de la película: ";
    std::getline(std::cin, review);
}

void MovieManager::getMovieIndex(int& index) {
    std::cout << "Ingrese el número de la película que desea: ";
    std::cin >> index;
    --index; // Ajustar para índice basado en 0
}
