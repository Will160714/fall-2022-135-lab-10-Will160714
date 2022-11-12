#include "funcs.h"
#include <string>

bool compare(Time time1, Time time2){
    if(time1.m == time2.m && time1.h == time2.h)
        return true;
    else
        return false;
}

bool compareTimeSlots(TimeSlot slot1, TimeSlot slot2){
    if(slot1.movie.title == slot2.movie.title && slot1.movie.duration == slot2.movie.duration && slot1.movie.genre == slot2.movie.genre && compare(slot1.startTime, slot2.startTime))
        return true;
    else 
        return false;
}

int minutesSinceMidnight(Time time){
    return time.h * 60 + time.m;
}

int minutesUntil(Time earlier, Time later){
    if(earlier.m > later.m){
        return (later.h -1 - earlier.h) * 60 + ((later.m + 60) - earlier.m );
    }
    return (later.h - earlier.h) * 60 + (later.m - earlier.m);
}

Time addMinutes(Time time0, int min){
    int minutes = time0.m + min;
    int hrs = time0.h;
    if(minutes >= 60){
        hrs = (minutes / 60) + hrs;
        minutes = minutes % 60;
    }
    Time time1 = {hrs, minutes};
    return time1;
}

std::string getTimeSlot(TimeSlot ts){
    Time end = addMinutes(ts.startTime, ts.movie.duration);
    std::string minute = std::to_string(end.m);
    std::string startMin = std::to_string(ts.startTime.m);

    if(ts.startTime.m < 10){
        startMin = "0" + std::to_string(ts.startTime.m);
    }

    if(end.m < 10){
        minute = "0" + std::to_string(end.m);
    }

    std::string g;
    switch (ts.movie.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }

    return ts.movie.title + " " + g + " (" + std::to_string(ts.movie.duration) + " min) " + "[starts at " + std::to_string(ts.startTime.h) + ":" + startMin + ", ends by " + std::to_string(end.h) + ":" + minute + "]";
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
    TimeSlot answer = {nextMovie, addMinutes(ts.startTime, ts.movie.duration)};
    return answer;
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2){
    if(minutesSinceMidnight(ts1.startTime) < minutesSinceMidnight(ts2.startTime)){
        if(minutesUntil(ts1.startTime, ts2.startTime) < ts1.movie.duration)
            return true;
        else
            return false;
    }
    else if(minutesSinceMidnight(ts1.startTime) > minutesSinceMidnight(ts2.startTime)){
        if(minutesUntil(ts2.startTime, ts1.startTime) < ts2.movie.duration)
            return true;
        else
            return false;
    }
    else
        return true;
}
