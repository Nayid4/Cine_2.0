#include "MovieManager.h"
#include <iostream>
#include <stdexcept>

void MovieManager::addMovie() {
    std::string name, country, review;
    int year, duration;

    getInput(name, year, duration, country, review);

    Movie movie(name, year, duration, country, review);
    MovieController::getInstance().addMovie(movie);

    std::cout << "Pel�cula agregada exitosamente.\n";
}

void MovieManager::listMovies() {
    MovieController& controller = MovieController::getInstance();
    size_t count = controller.getMovieCount();

    if (count == 0) {
        std::cout << "No hay pel�culas disponibles.\n";
        return;
    }

    std::cout << "\n===== Lista de Pel�culas =====\n";
    for (size_t i = 0; i < count; ++i) {
        Movie movie = controller.getMovie(i);
        std::cout << i + 1 << ". " << movie.getName()
            << " (" << movie.getYear() << ")\n"
            << "   Duraci�n: " << movie.getDuration() << " min\n"
            << "   Pa�s: " << movie.getCountry() << "\n"
            << "   Rese�a: " << movie.getReview() << "\n\n";
    }
}

void MovieManager::updateMovie() {
    MovieController& controller = MovieController::getInstance();
    size_t count = controller.getMovieCount();

    if (count == 0) {
        std::cout << "No hay pel�culas para actualizar.\n";
        return;
    }

    listMovies();

    int index;
    getMovieIndex(index);

    if (index < 0 || index >= count) {
        std::cout << "�ndice no v�lido.\n";
        return;
    }

    std::string name, country, review;
    int year, duration;

    getInput(name, year, duration, country, review);

    Movie updatedMovie(name, year, duration, country, review);
    controller.updateMovie(index, updatedMovie);

    std::cout << "Pel�cula actualizada exitosamente.\n";
}

void MovieManager::deleteMovie() {
    MovieController& controller = MovieController::getInstance();
    size_t count = controller.getMovieCount();

    if (count == 0) {
        std::cout << "No hay pel�culas para eliminar.\n";
        return;
    }

    listMovies();

    int index;
    getMovieIndex(index);

    if (index < 0 || index >= count) {
        std::cout << "�ndice no v�lido.\n";
        return;
    }

    controller.deleteMovie(index);
    std::cout << "Pel�cula eliminada exitosamente.\n";
}

void MovieManager::manageMovies() {
    int choice = 0;
    while (choice != 5) {
        std::cout << "\n===== Gesti�n de Pel�culas =====\n";
        std::cout << "1. Agregar Pel�cula\n";
        std::cout << "2. Listar Pel�culas\n";
        std::cout << "3. Actualizar Pel�cula\n";
        std::cout << "4. Eliminar Pel�cula\n";
        std::cout << "5. Volver\n";
        std::cout << "Seleccione una opci�n: ";
        std::cin >> choice;

        switch (choice) {
        case 1: addMovie(); break;
        case 2: listMovies(); break;
        case 3: updateMovie(); break;
        case 4: deleteMovie(); break;
        case 5: std::cout << "Volviendo al men� principal...\n"; break;
        default: std::cout << "Opci�n inv�lida. Intente de nuevo.\n";
        }
    }
}

void MovieManager::getInput(std::string& name, int& year, int& duration, std::string& country, std::string& review) {
    std::cout << "Ingrese el nombre de la pel�cula: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Ingrese el a�o de la pel�cula: ";
    std::cin >> year;

    std::cout << "Ingrese la duraci�n de la pel�cula (minutos): ";
    std::cin >> duration;

    std::cout << "Ingrese el pa�s de origen de la pel�cula: ";
    std::cin.ignore();
    std::getline(std::cin, country);

    std::cout << "Ingrese la rese�a de la pel�cula: ";
    std::getline(std::cin, review);
}

void MovieManager::getMovieIndex(int& index) {
    std::cout << "Ingrese el n�mero de la pel�cula que desea: ";
    std::cin >> index;
    --index; // Ajustar para �ndice basado en 0
}
