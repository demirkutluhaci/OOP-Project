#include "ProfessionalDevelopmentCourses.h"

// Default Constructor
ProfessionalDevelopmentCourse::ProfessionalDevelopmentCourse() {
    courseName = "undefined";
    instructor = "undefined";
    totalCapacity = 0;
    numberOfEnrolledStudents = 0;
    courseRate = 0.0;
    totalDuration = 0;
    price = 0.0;
    level = "undefined";
    discountRate = 0.0;
    prerequisites = { "-", "-", "-", "-", "-" };
    isCertificationOffered = false;
    topicsCovered = { "-", "-", "-", "-", "-" };
}

// Parametrized Constructor
ProfessionalDevelopmentCourse::ProfessionalDevelopmentCourse(string courseName, string instructor, int totalCapacity,
    int numberOfEnrolledStudents, double courseRate, int totalDuration, double price, string level,
    double discountRate, array<string, 5> prerequisites, bool isCertificationOffered,
    array<string, 5> topicsCovered)
    : OnlineCourse(courseName, instructor, totalCapacity, numberOfEnrolledStudents, courseRate, totalDuration,
        price, level, discountRate, prerequisites) {

    this->isCertificationOffered = isCertificationOffered;
    this->topicsCovered = topicsCovered;
}

// Copy Constructor
ProfessionalDevelopmentCourse::ProfessionalDevelopmentCourse(const ProfessionalDevelopmentCourse& other)
    : OnlineCourse(other) {

    this->isCertificationOffered = other.isCertificationOffered;
    this->topicsCovered = other.topicsCovered;
}

// Destructor
ProfessionalDevelopmentCourse::~ProfessionalDevelopmentCourse(){}

// displayInfo Implementation
void ProfessionalDevelopmentCourse::displayInfo() {
    OnlineCourse::displayInfo();
    cout << "Certification Offered: " << (isCertificationOffered ? "Yes" : "No") << endl;
    cout << "Topics Covered: ";
    displayTopicsCovered();
}

// checkCapacity Implementation
bool ProfessionalDevelopmentCourse::checkCapacity() {
    if (numberOfEnrolledStudents >= totalCapacity) {
        return false; // Kapasite dolmuþ
    }
    return true;
}

// addStudent Implementation
void ProfessionalDevelopmentCourse::addStudent() {
    if (checkCapacity()) {
        numberOfEnrolledStudents++;
    }
    else {
        cout << "Course is full, cannot add more students." << endl;
    }
}


// getIsCertificationOffered Implementation
bool ProfessionalDevelopmentCourse::getIsCertificationOffered() {
    return isCertificationOffered;
}

// setTopicsCovered Implementation
void ProfessionalDevelopmentCourse::setTopicsCovered(int index, string topic) {
    if (index >= 0 && index < 5) {
        topicsCovered[index] = topic;
    }
}

// displayTopicsCovered Implementation
void ProfessionalDevelopmentCourse::displayTopicsCovered() {
    for (int i = 0; i < 5; i++) {
        cout << topicsCovered[i];
        if (i < 4) {
            cout << ", ";
        }
    }
    cout << endl;
}

