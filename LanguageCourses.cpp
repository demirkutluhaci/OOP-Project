#include "LanguageCourses.h"
#include <iostream>

using namespace std;

// Default Constructor
LanguageCourses::LanguageCourses() : OnlineCourse() {
    foreignLanguage = "undefined";
    isNativeSpeaker = false;
    cout << "Default Constructor - LanguageCourses" << endl;
}

// Parametrized Constructor
LanguageCourses::LanguageCourses(string courseName, string instructor, int totalCapacity, int numberOfEnrolledStudents,
    double courseRate, int totalDuration, double price, string level, double discountRate,
    array<string, 5> prerequisites, string foreignLanguage, bool isNativeSpeaker)
    : OnlineCourse(courseName, instructor, totalCapacity, numberOfEnrolledStudents, courseRate, totalDuration, price, level, discountRate, prerequisites) {
    this->foreignLanguage = foreignLanguage;
    this->isNativeSpeaker = isNativeSpeaker;
    cout << "Parametrized Constructor - LanguageCourses" << endl;
}

// Copy Constructor
LanguageCourses::LanguageCourses(const LanguageCourses& other) : OnlineCourse(other) {
    this->foreignLanguage = other.foreignLanguage;
    this->isNativeSpeaker = other.isNativeSpeaker;
    cout << "Copy Constructor - LanguageCourses" << endl;
}

// displayInfo over ride
void LanguageCourses::displayInfo() {
    OnlineCourse::displayInfo();
    displayPrerequisites();
    cout << "Foreign Language: " << foreignLanguage << endl;
    cout << "Instructor is a native speaker: " << (isNativeSpeaker ? "Yes" : "No") << endl;
}

// checkCapacity over ride
bool LanguageCourses::checkCapacity() {
    return numberOfEnrolledStudents < totalCapacity;
}

// addStudent over ride
void LanguageCourses::addStudent() {
    if (checkCapacity()) {
        numberOfEnrolledStudents++;
        cout << "Student added. Current number of enrolled students: " << numberOfEnrolledStudents << endl;
    }
    else {
        cout << "Cannot add student. The course is full." << endl;
    }
}

// Accessor and Mutator for foreignLanguage
void LanguageCourses::setForeignLanguage(string language) {
    foreignLanguage = language;
}
string LanguageCourses::getForeignLanguage() {
    return foreignLanguage;
}
// Accessor and Mutator for isNativeSpeaker
void LanguageCourses::setIsNativeSpeaker(bool native) {
    isNativeSpeaker = native;
}
bool LanguageCourses::getIsNativeSpeaker() {
    return isNativeSpeaker;
}

// Destructor
LanguageCourses::~LanguageCourses() {
    cout << "Destructor - LanguageCourses" << endl;
}
