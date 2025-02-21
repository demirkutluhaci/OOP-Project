#include "SoftwareCourses.h"
#include <iostream>

using namespace std;

// Default Constructor
SoftwareCourses::SoftwareCourses() : OnlineCourse() {
    programmingLanguage = "undefined";
    developmentEnvironment = "undefined";
    cout << "Default Constructor-Software Courses" << endl;
}

// Parametrized Constructor
SoftwareCourses::SoftwareCourses(string courseName, string instructor, int totalCapacity, int numberOfEnrolledStudents,
    double courseRate, int totalDuration, double price, string level,
    double discountRate, array<string, 5> prerequisites,
    string programmingLanguage, string developmentEnvironment)
    : OnlineCourse(courseName, instructor, totalCapacity, numberOfEnrolledStudents, courseRate, totalDuration, price, level, discountRate, prerequisites) {
    this->programmingLanguage = programmingLanguage;
    this->developmentEnvironment = developmentEnvironment;
    cout << "Parametrized Constructor-Software Courses" << endl;
}

// Copy Constructor
SoftwareCourses::SoftwareCourses(const SoftwareCourses& other) : OnlineCourse(other) {
    this->programmingLanguage = other.programmingLanguage;
    this->developmentEnvironment = other.developmentEnvironment;
}

// displayInfo Implementation
void SoftwareCourses::displayInfo() {
    // Displaying course info
    OnlineCourse::displayInfo();
    cout << "Programming Language: " << programmingLanguage << endl;
    cout << "Development Environment: " << developmentEnvironment << endl;
}

// checkCapacity Implementation
bool SoftwareCourses::checkCapacity() {
    // Inherits checkCapacity from OnlineCourse but can be overridden if needed
    return OnlineCourse::checkCapacity();
}

// addStudent Implementation
void SoftwareCourses::addStudent() {
    // Calls base class method for adding a student
    OnlineCourse::addStudent();
}

// Getter and Setter for programmingLanguage

void SoftwareCourses::setProgrammingLanguage(string language) {
    programmingLanguage = language;
}

string SoftwareCourses::getProgrammingLanguage() const {
    return programmingLanguage;
}

// Getter and Setter for developmentEnvironment
void SoftwareCourses::setDevelopmentEnvironment(string environment) {
    developmentEnvironment = environment;
}

string SoftwareCourses::getDevelopmentEnvironment() const {
    return developmentEnvironment;
}

// Destructor
SoftwareCourses::~SoftwareCourses() {
    cout << "Destrcutor-Software Course " << endl;
}

