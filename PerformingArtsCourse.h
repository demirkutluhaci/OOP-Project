#ifndef PERFORMINGARTSCOURSE_H
#define PERFORMINGARTSCOURSE_H

#include "OnlineCourse.h"
#include <array>
#include <string>

using namespace std;

// PerformingArtsCourse class inherits from OnlineCourse.
// It adds specific attributes like focusArea, guestSpeakers, and numberOfPerformances.
class PerformingArtsCourse : public OnlineCourse {
private:
    string focusArea; // The main subject or theme of the course.
    array<string, 3> guestSpeakers; // Names of guest speakers (up to 3).
    int numberOfPerformances; // Number of performances included in the course.

public:
    // Default Constructor: Initializes with default values.
    PerformingArtsCourse();

    // Parametrized Constructor: Used to set all attributes of the course.
    PerformingArtsCourse(string courseName, string instructor, int totalCapacity,
        int numberOfEnrolledStudents, double courseRate,
        int totalDuration, double price, string level,
        double discountRate, array<string, 5> prerequisites,
        string focusArea, array<string, 3> guestSpeakers,
        int numberOfPerformances);

    // Overridden Method: Displays all information about the course.
    void displayInfo() override;

    // Overridden Method: Checks if there is room for more students.
    bool checkCapacity() override;

    // Adds a student if there is capacity.
    void addStudent() override;


//UNIQUE METHODS OF UNIQUE COURSE

    // This method gives students a random theme, character, and situation to perform.
    // It helps improve creativity and improvisation skills.
    void stageChallenge();


    // Unique Method: Lists the guest speakers for the course.
    void listGuestSpeakers();

    // Destructor: Cleans up when the object is destroyed.
    ~PerformingArtsCourse();
};

#endif