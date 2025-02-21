#ifndef PROFESSIONALDEVELOPMENTCOURSES_H
#define PROFESSIONALDEVELOPMENTCOURSES_H
#pragma once
#include "OnlineCourse.h"

class ProfessionalDevelopmentCourse : public OnlineCourse {
private:
    bool isCertificationOffered;
    array<string, 5> topicsCovered; // Fixed-size array for topics covered

public:
    // Default Constructor
    ProfessionalDevelopmentCourse();

    // Parametrized Constructor
    ProfessionalDevelopmentCourse(string courseName, string instructor, int totalCapacity, int numberOfEnrolledStudents,
        double courseRate, int totalDuration, double price, string level, double discountRate,
        array<string, 5> prerequisites,bool isCertificationOffered, array<string, 5> topicsCovered);

    // Copy Constructor
    ProfessionalDevelopmentCourse(const ProfessionalDevelopmentCourse& other);

    // Overridden Methods (No need for 'virtual' keyword here)
    void displayInfo() override;  // Display course information including professional development details
    bool checkCapacity() override; // Check if there's room for more students
    void addStudent() override;  // Add a student to the course

    // Accessor and Mutator Methods
    void setIsCertificationOffered(bool certificationOffered);
    bool getIsCertificationOffered();

    void setTopicsCovered(int index, string topic);
    void displayTopicsCovered();

    // Destructor
    ~ProfessionalDevelopmentCourse() override;
};

#endif // PROFESSIONALDEVELOPMENTCOURSES_H
