#ifndef LANGUAGECOURSES_H
#define LANGUAGECOURSES_H
#pragma once
#include "OnlineCourse.h"

class LanguageCourses : public OnlineCourse {
private:
    string foreignLanguage;
    bool isNativeSpeaker;

public:
    // Default Constructor
    LanguageCourses();

    // Parametrized Constructor
    LanguageCourses(string courseName, string instructor, int totalCapacity, int numberOfEnrolledStudents,
        double courseRate, int totalDuration, double price, string level, double discountRate,
        array<string, 5> prerequisites, string foreignLanguage, bool isNativeSpeaker);

    // Copy Constructor
    LanguageCourses(const LanguageCourses& other);

    // Overridden Methods
    void displayInfo() override;  // Display course information including language details
    bool checkCapacity() override; // Check if there's room for more students
    void addStudent() override;  // Add a student to the course

    // Accessor and Mutator Methods
    void setForeignLanguage(string language);
    string getForeignLanguage();

    void setIsNativeSpeaker(bool native);
    bool getIsNativeSpeaker();

    // Destructor
    ~LanguageCourses() override;
};

#endif // LANGUAGECOURSES_H


