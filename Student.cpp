#include "Student.h"
#include <iostream>

using namespace std;

// Default Constructor
Student::Student() : name(""), surname(""), email(""), enrolledCourseCount(0) {
    enrolledCourses.fill(nullptr);
}

// Parametrized Constructor
Student::Student(string name, string surname, string email) {
    this->name = name;
    this->surname = surname;
    this->email = email;
    this->enrolledCourseCount = 0;
    this->enrolledCourses.fill(nullptr);
}

// Getter methods
string Student::getName() {
    return name;
}

string Student::getSurname() {
    return surname;
}

string Student::getEmail() {
    return email;
}

int Student::getEnrolledCourseCount() {
    return enrolledCourseCount;
}

// Enrollment-related methods
bool Student::enrollInCourse(OnlineCourse& course) {
    if (enrolledCourseCount >= 3) {
        cout << "Cannot enroll: Maximum course limit reached." << endl;
        return false;
    }
    if (isEnrolledInCourse(course)) {
        cout << "Cannot enroll: Already enrolled in this course." << endl;
        return false;
    }
    enrolledCourses[enrolledCourseCount++] = &course;
    cout << "Enrolled in course: " << course.getCourseName() << endl;
    return true;
}

bool Student::isEnrolledInCourse(OnlineCourse& course) {
    for (int i = 0; i < enrolledCourseCount; ++i) {
        if (enrolledCourses[i] == &course) {
            return true;
        }
    }
    return false;
}

void Student::rateCourse(OnlineCourse& course, double rating) {
    if (rating < 1.0 || rating > 5.0) {
        cout << "Rating must be between 1 and 5." << endl;
        return;
    }
    if (!isEnrolledInCourse(course)) {
        cout << "Cannot rate: Not enrolled in this course." << endl;
        return;
    }
    course.setCourseRating(rating);
    cout << "Rated course " << course.getCourseName() << " with " << rating << " stars." << endl;
}

void Student::listEnrolledCourses() {
    cout << "Enrolled Courses:" << endl;
    for (int i = 0; i < enrolledCourseCount; ++i) {
        cout << "- " << enrolledCourses[i]->getCourseName() << endl;
    }
}

// Destructor
Student::~Student() {
    cout << "Student- Destructor" << endl;
}
