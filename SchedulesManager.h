#ifndef SCHEDULESMANAGER_H
#define SCHEDULESMANAGER_H

#include "ScheduleController.h"
#include <string>

class SchedulesManager {
public:
    // M�todos p�blicos para manejar horarios
    void addSchedule();
    void listSchedules();
    void updateSchedule();
    void deleteSchedule();
    void manageSchedules();

private:
    // M�todos privados para la entrada del usuario
    void getInput(std::string& day, std::string& startTime, std::string& endTime);
    void getScheduleIndex(int& index);
};

#endif // SCHEDULESMANAGER_H
