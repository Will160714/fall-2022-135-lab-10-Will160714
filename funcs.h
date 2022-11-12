#pragma once
#include "time.h"
#include <string>

bool compare(Time time1, Time time2);
bool compareTimeSlots(TimeSlot slot1, TimeSlot slot2);
int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);
Time addMinutes(Time time0, int min);
std::string getTimeSlot(TimeSlot ts);
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);
bool timeOverlap(TimeSlot ts1, TimeSlot ts2); 
