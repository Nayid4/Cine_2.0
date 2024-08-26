#include <iostream>
#include <string>
#include "MovieManager.h"
#include "RoomManager.h"
#include "SchedulesManager.h"
#include "ReservationsManager.h"
#include "SalesManager.h"

using namespace std;

void showAbout();

int main() {
    int mainChoice = 0;
    MovieManager movieManager;
    RoomManager roomManager;
    SchedulesManager schedulesManager;
    ReservationsManager reservationManager;
    SalesManager salesManager;

    while (mainChoice != 5) {
        cout << "===== NUEVA CINEMA SA =====\n";
        cout << "1. Archivo\n";
        cout << "2. Mantenimiento\n";
        cout << "3. Reserva\n";
        cout << "4. Venta\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> mainChoice;

        switch (mainChoice) {
        case 1: {
            int archivoChoice = 0;
            while (archivoChoice != 2) {
                cout << "===== Archivo =====\n";
                cout << "1. Acerca de\n";
                cout << "2. Salir\n";
                cout << "Seleccione una opcion: ";
                cin >> archivoChoice;

                switch (archivoChoice) {
                case 1: showAbout(); break;
                case 2: cout << "Saliendo...\n"; break;
                default: cout << "Opcion invalida. Intente de nuevo.\n";
                }
            }
            break;
        }
        case 2: {
            int mantenimientoChoice = 0;
            while (mantenimientoChoice != 4) {
                cout << "\n===== Mantenimiento =====\n";
                cout << "1. Peliculas\n";
                cout << "2. Salas\n";
                cout << "3. Horarios\n";
                cout << "4. Volver\n";
                cout << "Seleccione una opcion: ";
                cin >> mantenimientoChoice;

                switch (mantenimientoChoice) {
                case 1: movieManager.manageMovies(); break;
                case 2: roomManager.manageRooms(); break;
                case 3: schedulesManager.manageSchedules(); break;
                case 4: cout << "Volviendo al menu principal...\n"; break;
                default: cout << "Opcion invalida. Intente de nuevo.\n";
                }
            }
            break;
        }
        case 3: reservationManager.manageReservations(); break;
        case 4: salesManager.manageSales(); break;
        case 5: cout << "Saliendo del sistema...\n"; break;
        default: cout << "Opcion invalida. Intente de nuevo.\n";
        }
    }

    return 0;
}

void showAbout() {
    cout << "\n===== Acerca de =====\n";
    cout << "Este sistema fue desarrollado por Johhny Aguirre.\n";
}

