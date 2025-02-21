#ifndef SOFTWARECOURSES_H
#define SOFTWARECOURSES_H

#include "OnlineCourse.h"

class SoftwareCourses : public OnlineCourse {
private:
    string programmingLanguage;  // Programming language used in the course
    string developmentEnvironment;  // Development environment (e.g., IDE or platform)

public:
    // Default Constructor
    SoftwareCourses();

    // Parametrized Constructor
    SoftwareCourses(string courseName, string instructor, int totalCapacity, int numberOfEnrolledStudents,
        double courseRate, int totalDuration, double price, string level,
        double discountRate, array<string, 5> prerequisites,
        string programmingLanguage, string developmentEnvironment);

    // Copy Constructor
    SoftwareCourses(const SoftwareCourses& other);

    // Overridden Virtual Methods
    void displayInfo() override;
    bool checkCapacity() override;
    void addStudent() override;

    // Getter and Setter Methods for programmingLanguage and developmentEnvironment
    void setProgrammingLanguage(string language);
    string getProgrammingLanguage() const;
    void setDevelopmentEnvironment(string environment);
    string getDevelopmentEnvironment() const;

    // Destructor
    ~SoftwareCourses();
};

#endif // SOFTWARECOURSES_H
