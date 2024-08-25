#include "ScheduleController.h"
#include <stdexcept>

ScheduleController& ScheduleController::getInstance() {
    static ScheduleController instance;
    return instance;
}

ScheduleController::ScheduleController() {}

void ScheduleController::addSchedule(const Schedule& schedule) {
    schedules.push_back(schedule);
}

Schedule ScheduleController::getSchedule(int index) const {
    if (index >= 0 && index < schedules.size()) {
        return schedules[index];
    }
    throw std::out_of_range("Index out of range");
}

void ScheduleController::updateSchedule(int index, const Schedule& schedule) {
    if (index >= 0 && index < schedules.size()) {
        schedules[index] = schedule;
    }
    else {
        throw std::out_of_range("Index out of range");
    }
}

void ScheduleController::deleteSchedule(int index) {
    if (index >= 0 && index < schedules.size()) {
        schedules.erase(schedules.begin() + index);
    }
    else {
        throw std::out_of_range("Index out of range");
    }
}

size_t ScheduleController::getScheduleCount() const {
    return schedules.size();
}
