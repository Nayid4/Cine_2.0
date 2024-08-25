#ifndef SCHEDULECONTROLLER_H
#define SCHEDULECONTROLLER_H

#include "Schedule.h"
#include <vector>

class ScheduleController {
public:
    static ScheduleController& getInstance();

    void addSchedule(const Schedule& schedule);
    Schedule getSchedule(int index) const;
    void updateSchedule(int index, const Schedule& schedule);
    void deleteSchedule(int index);
    size_t getScheduleCount() const;

private:
    ScheduleController();
    std::vector<Schedule> schedules;
};

#endif // SCHEDULECONTROLLER_H
