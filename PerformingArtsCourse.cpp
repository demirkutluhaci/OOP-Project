#include "PerformingArtsCourse.h"
#include <iostream>

using namespace std;

// Default Constructor
// Initializes focusArea to \"undefined\", guestSpeakers to empty values, and numberOfPerformances to 0.
PerformingArtsCourse::PerformingArtsCourse() : OnlineCourse() {
    focusArea = "undefined";
    guestSpeakers = { "-", "-", "-" };
    numberOfPerformances = 0;
    cout << "PerformingArtsCourse-default constructor" << endl;
}

// Parametrized Constructor
// Initializes all attributes using parameters. Calls the base class constructor for common attributes.
PerformingArtsCourse::PerformingArtsCourse(string courseName, string instructor, int totalCapacity,
    int numberOfEnrolledStudents, double courseRate,
    int totalDuration, double price, string level,
    double discountRate, array<string, 5> prerequisites,
    string focusArea, array<string, 3> guestSpeakers,
    int numberOfPerformances)
    : OnlineCourse(courseName, instructor, totalCapacity, numberOfEnrolledStudents, courseRate,
        totalDuration, price, level, discountRate, prerequisites) {
    this->focusArea = focusArea;
    this->guestSpeakers = guestSpeakers;
    this->numberOfPerformances = numberOfPerformances;
}

// Overridden Method: Displays detailed information about the course.
void PerformingArtsCourse::displayInfo() {
    cout << "Performing Arts Course Details:" << endl;
    cout << "Course Name: " << courseName << endl;
    cout << "Instructor: " << instructor << endl;
    cout << "Focus Area: " << focusArea << endl;
    cout << "Total Capacity: " << totalCapacity << endl;
    cout << "Enrolled Students: " << numberOfEnrolledStudents << endl;
    cout << "Course Rate: " << courseRate <<  endl;
    cout << "Duration: " << totalDuration << " hours" << endl;
    cout << "Price: $" << price << endl;
    cout << "Level: " << level << endl;
    cout << "Discount Rate: " << discountRate << "%" << endl;
    cout << "Number of Performances: " << numberOfPerformances << endl;
    displayPrerequisites();
    listGuestSpeakers();
}

// Checks if the course has available capacity.
bool PerformingArtsCourse::checkCapacity() {
    return numberOfEnrolledStudents < totalCapacity;
}

// Adds a student if capacity allows. Displays appropriate message.
void PerformingArtsCourse::addStudent() {
    if (checkCapacity()) {
        numberOfEnrolledStudents++;
        cout << "Student successfully enrolled!" << endl;
    }
    else {
        cout << "Course is full, enrollment not possible." << endl;
    }
}

 //Stage Challenge method implementation
 //This method selects a random theme, character, and situation from predefined arrays.
 //It encourages students to create a short performance based on the selected prompts.
 // students practice creativity and improvisation.
 //It uses three predefined arrays: themes, characters, and situations.
 //The method randomly selects one item from each array to create a unique challenge.
 //Students must create a performance based on these random prompts.

void PerformingArtsCourse::stageChallenge() {
    // Predefined themes for the challenge
    array<string, 5> themes = { "A magical forest", "A courtroom drama",
                               "A futuristic city", "A comedy of errors",
                               "A silent movie style scene" };

    // Predefined characters
    array<string, 5> characters = { "A lost traveler", "A mysterious detective",
                                   "A clumsy chef", "A singing robot",
                                   "A mischievous ghost" };

    // Predefined situations
    array<string, 5> situations = { "Preparing for an important audition",
                                   "Rehearsing with a difficult partner",
                                   "Dealing with stage fright",
                                   "A sudden power outage during a performance",
                                   "An unexpected twist in a play" };

    // Select random elements
    string theme = themes[rand() % themes.size()];
    string character = characters[rand() % characters.size()];
    string situation = situations[rand() % situations.size()];

    // Output the challenge to students
    cout << "Stage Challenge: Perform a scene based on the following prompts!" << endl;
    cout << "Theme: " << theme << endl;
    cout << "Character: " << character << endl;
    cout << "Situation: " << situation << endl;
}


// Lists all guest speakers for the course.
void PerformingArtsCourse::listGuestSpeakers() {
    cout << "Guest Speakers for this Course:" << endl;
    for (const auto& speaker : guestSpeakers) {
        if (!speaker.empty() && speaker != "-") {
            cout << "- " << speaker << endl;
        }
    }
}

// Destructor: Indicates when the object is being destroyed.
PerformingArtsCourse::~PerformingArtsCourse() {
    cout << "PerformingArtsCourse destructor" << endl;
}
