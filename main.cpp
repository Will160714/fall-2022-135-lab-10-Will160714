#include <iostream>
#include "funcs.h"

int main(){
    std::cout << "Task A" << std::endl;
    std::cout << "minutesSinceMidnight({10, 0}) = " << minutesSinceMidnight({10, 0}) << std::endl;
    std::cout << "minutesUntil({10, 30}, {13, 40}) = " << minutesUntil({10, 30}, {13, 40}) << std::endl << std::endl;

    std::cout << "Task B" << std::endl;
    Time b = addMinutes({10, 5}, 165);
    std::cout << "addMinutes({10,5}, 165) = " << b.h << " " << b.m << std::endl << std::endl;

    std::cout << "Task C" << std::endl;
    std::cout << "getTimeSlot({{'Back to the Future', ACTION, 116},{9, 15}}): " << getTimeSlot({{"Back to the Future", ACTION, 116},{9, 15}}) << std::endl << std::endl;

    std::cout << "Task D" << std::endl;
    TimeSlot c = scheduleAfter({{"Testing", COMEDY, 100},{0,0}},{"Back to the Future", ACTION, 116});
    std::cout << "scheduleAfter({{'Testing', COMEDY, 100},{0,0}},{'Back to the Future', ACTION, 116}): " << c.startTime.h << ":" << c.startTime.m << std::endl << std::endl;

    std::cout << "Task E" << std::endl;
    std::cout << "timeOverlap({{'Test', COMEDY, 100},{0,0}}, {{'Test2', ACTION, 100}, {0,0}}): " << timeOverlap({{"Test", COMEDY, 100},{0,0}}, {{"Test2", ACTION, 100}, {0,0}}) << std::endl << std::endl;

}