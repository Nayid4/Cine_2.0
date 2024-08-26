#include "SchedulesManager.h"
#include <iostream>

void SchedulesManager::addSchedule() {
    std::string day, startTime, endTime;

    getInput(day, startTime, endTime);

    Schedule schedule(day, startTime, endTime);
    ScheduleController::getInstance().addSchedule(schedule);

    std::cout << "Horario agregado exitosamente.\n";
}

void SchedulesManager::listSchedules() {
    ScheduleController& controller = ScheduleController::getInstance();
    size_t count = controller.getScheduleCount();

    if (count == 0) {
        std::cout << "No hay horarios disponibles.\n";
        return;
    }

    std::cout << "\n===== Lista de Horarios =====\n";
    for (size_t i = 0; i < count; ++i) {
        Schedule schedule = controller.getSchedule(i);
        std::cout << i + 1 << ". Dia: " << schedule.getDay()
            << "\n   Hora de inicio: " << schedule.getStartTime()
            << "\n   Hora de fin: " << schedule.getEndTime() << "\n\n";
    }
}

void SchedulesManager::updateSchedule() {
    ScheduleController& controller = ScheduleController::getInstance();
    size_t count = controller.getScheduleCount();

    if (count == 0) {
        std::cout << "No hay horarios para actualizar.\n";
        return;
    }

    listSchedules();

    int index;
    getScheduleIndex(index);

    if (index < 0 || index >= count) {
        std::cout << "Indice no valido.\n";
        return;
    }

    std::string day, startTime, endTime;

    getInput(day, startTime, endTime);

    Schedule updatedSchedule(day, startTime, endTime);
    controller.updateSchedule(index, updatedSchedule);

    std::cout << "Horario actualizado exitosamente.\n";
}

void SchedulesManager::deleteSchedule() {
    ScheduleController& controller = ScheduleController::getInstance();
    size_t count = controller.getScheduleCount();

    if (count == 0) {
        std::cout << "No hay horarios para eliminar.\n";
        return;
    }

    listSchedules();

    int index;
    getScheduleIndex(index);

    if (index < 0 || index >= count) {
        std::cout << "Indice no valido.\n";
        return;
    }

    controller.deleteSchedule(index);
    std::cout << "Horario eliminado exitosamente.\n";
}

void SchedulesManager::manageSchedules() {
    int choice = 0;
    while (choice != 5) {
        std::cout << "\n===== Gestion de Horarios =====\n";
        std::cout << "1. Agregar Horario\n";
        std::cout << "2. Listar Horarios\n";
        std::cout << "3. Actualizar Horario\n";
        std::cout << "4. Eliminar Horario\n";
        std::cout << "5. Volver\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> choice;

        switch (choice) {
        case 1: addSchedule(); break;
        case 2: listSchedules(); break;
        case 3: updateSchedule(); break;
        case 4: deleteSchedule(); break;
        case 5: std::cout << "Volviendo al menu principal...\n"; break;
        default: std::cout << "Opción invalida. Intente de nuevo.\n";
        }
    }
}

void SchedulesManager::getInput(std::string& day, std::string& startTime, std::string& endTime) {
    std::cout << "Ingrese el dia: ";
    std::cin.ignore();
    std::getline(std::cin, day);

    std::cout << "Ingrese la hora de inicio (formato HH:MM): ";
    std::getline(std::cin, startTime);

    std::cout << "Ingrese la hora de fin (formato HH:MM): ";
    std::getline(std::cin, endTime);
}

void SchedulesManager::getScheduleIndex(int& index) {
    std::cout << "Ingrese el numero del horario que desea: ";
    std::cin >> index;
    --index; // Ajustar para índice basado en 0
}
