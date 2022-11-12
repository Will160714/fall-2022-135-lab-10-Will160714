#pragma once
#include <string>

class Time { 
public:
    int h;
    int m;
};

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

class Movie { 
public: 
    std::string title;
    Genre genre;    
    int duration;    
};

class TimeSlot { 
public: 
    Movie movie;     
    Time startTime; 
};

