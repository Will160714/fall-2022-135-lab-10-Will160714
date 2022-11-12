#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

TEST_CASE("Task A"){
    CHECK(minutesSinceMidnight({10, 0}) == 600);
    CHECK(minutesSinceMidnight({0,5}) == 5);
    CHECK(minutesSinceMidnight({0,0}) == 0);
    CHECK(minutesSinceMidnight({13,4}) == 784);
    CHECK(minutesUntil({10, 30}, {13, 40}) == 190);
    CHECK(minutesUntil({0,20}, {5,10}) == 290);
    CHECK(minutesUntil({0,0},{0,0}) == 0);
}

TEST_CASE("Task B"){
    CHECK(compare(addMinutes({10, 5}, 165),{12, 50}));
    CHECK(compare(addMinutes({10, 5}, 0),{10,5}));
    CHECK(compare(addMinutes({0,0}, 30),{0,30}));
}

TEST_CASE("Task C"){
    CHECK(getTimeSlot({{"Testing", COMEDY, 100},{0,0}}) == "Testing COMEDY (100 min) [starts at 0:00, ends by 1:40]");
    CHECK(getTimeSlot({{"Back to the Future", ACTION, 116},{9, 15}}) == "Back to the Future ACTION (116 min) [starts at 9:15, ends by 11:11]");
    CHECK(getTimeSlot({{"", THRILLER, 50},{12, 10}}) == " THRILLER (50 min) [starts at 12:10, ends by 13:00]");
}

TEST_CASE("Task D"){
    CHECK(compareTimeSlots(scheduleAfter({{"Testing", COMEDY, 100},{0,0}},{"Back to the Future", ACTION, 116}), {{"Back to the Future", ACTION, 116}, {1,40}}));
    CHECK(compareTimeSlots(scheduleAfter({{"Testing", COMEDY, 0},{0,0}},{"", DRAMA, 126}), {{"", DRAMA, 126}, {0,0}}));
    CHECK(compareTimeSlots(scheduleAfter({{"Testing", COMEDY, 20},{1,50}},{"V2", ROMANCE, 0}), {{"V2", ROMANCE, 0}, {2,10}}));
}

TEST_CASE("Task E"){
    CHECK(timeOverlap({{"Test", COMEDY, 100},{0,0}}, {{"Test2", ACTION, 100}, {0,0}}));
    CHECK(timeOverlap({{"Test", COMEDY, 100},{10,0}}, {{"Test2", ACTION, 100}, {11,15}}));
    CHECK(timeOverlap({{"Test", COMEDY, 100},{10,0}}, {{"Test2", ACTION, 100}, {9,20}}));
}