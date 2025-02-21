#pragma once
#include <string>
#include <array>
#include "OnlineCourse.h"

using namespace std;

class Student {
private:
    string name;
    string surname;
    string email;
    array<OnlineCourse*, 3> enrolledCourses; // Maximum 3 courses
    int enrolledCourseCount; // Current number of enrolled courses

public:
    // Default Constructor
    Student();
    // Parametrized Constructor
    Student(string name, string surname, string email);

    // Getter methods
    string getName();
    string getSurname();
    string getEmail();
    int getEnrolledCourseCount();

    // Enrollment-related methods
    bool enrollInCourse(OnlineCourse& course);
    bool isEnrolledInCourse(OnlineCourse& course);
    void rateCourse(OnlineCourse& course, double rating); // Rate a course between 1 and 5
    void listEnrolledCourses(); // Print enrolled courses

    // Destructor
    ~Student();
};


