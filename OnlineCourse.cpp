// OnlineCourse.cpp
#include "OnlineCourse.h"

// Default Constructor
OnlineCourse::OnlineCourse() {
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
}

// Parametrized Constructor
OnlineCourse::OnlineCourse(string courseName, string instructor, int totalCapacity, int numberOfEnrolledStudents,
    double courseRate, int totalDuration, double price, string level,
    double discountRate, array<string, 5> prerequisites) {

    this->courseName = courseName;
    this->instructor = instructor;
    this->totalCapacity = totalCapacity;
    this->numberOfEnrolledStudents = numberOfEnrolledStudents;
    this->courseRate = courseRate;
    this->totalDuration = totalDuration;
    this->price = price;
    this->level = level;
    this->discountRate = discountRate;
    this->prerequisites = prerequisites;
}

// Copy Constructor
OnlineCourse::OnlineCourse(const OnlineCourse& other) {
    this->courseName = other.courseName;
    this->instructor = other.instructor;
    this->totalCapacity = other.totalCapacity;
    this->numberOfEnrolledStudents = other.numberOfEnrolledStudents;
    this->courseRate = other.courseRate;
    this->totalDuration = other.totalDuration;
    this->price = other.price;
    this->level = other.level;
    this->discountRate = other.discountRate;
    this->prerequisites = other.prerequisites;
}

// Destructor
OnlineCourse::~OnlineCourse() {}

// checkCapacity Implementation
bool OnlineCourse::checkCapacity() {
    if (numberOfEnrolledStudents >= totalCapacity) {
        return false; // Kapasite dolmuþ
    }
    return true;
}

// displayPrerequisites Implementation
void OnlineCourse::displayPrerequisites() {
    cout << "Prerequisites for the course:" << endl;
    for (const auto& prerequisite : prerequisites) {
        if (!prerequisite.empty() && prerequisite != "-") {
            cout << prerequisite << endl;
        }
    }
}
//display Info 
void OnlineCourse::displayInfo() {
    cout << "Displaying information for Online Course (base class)." << endl;
    cout << "Course Name: " << courseName << endl;
    cout << "Instructor: " << instructor << endl;
    cout << "Total Capacity: " << totalCapacity << endl;
    cout << "Enrolled Students: " << numberOfEnrolledStudents << endl;
    cout << "Course Rate: " << courseRate << endl;
    cout << "Duration: " << totalDuration << " hours" << endl;
    cout << "Price: $" << price << endl;
    cout << "Level: " << level << endl;
    cout << "Discount Rate: " << discountRate << "%" << endl;
    displayPrerequisites(); // Prerequisites bilgisi ekleniyor
}



// addStudent Implementation
void OnlineCourse::addStudent() {
    if (checkCapacity()) {
        numberOfEnrolledStudents++;
    }
    else {
        cout << "Course is full, cannot add more students." << endl;
    }
}

// Getter method for price
double OnlineCourse::getPrice() {
    return price;
}
double OnlineCourse::getDiscountRate() {
    return discountRate;
}

int OnlineCourse::getNumberOfEnrolledStudents() {
    return numberOfEnrolledStudents;
}

string OnlineCourse::getCourseName() {
    return courseName;
}
double OnlineCourse::getCourseRate() {
    return courseRate;
}

// Setter for courseRate
void OnlineCourse::setCourseRating(double rating) {
    if (rating < 1.0 || rating > 5.0) {
        cout << "Invalid rating. Please provide a value between 1 and 5." << endl;
        return;
    }
    courseRate = rating;
    cout << "Course rating set to " << rating << " for " << courseName << endl;
}

// operator overloading definiton
ostream& operator<<(ostream& os, const OnlineCourse& course) {
    os << "Displaying information for Online Course (base class):\n"
        << "Course Name: " << course.courseName << "\n"
        << "Instructor: " << course.instructor << "\n"
        << "Total Capacity: " << course.totalCapacity << "\n"
        << "Enrolled Students: " << course.numberOfEnrolledStudents << "\n"
        << "Course Rate: " << course.courseRate << "\n"
        << "Duration: " << course.totalDuration << " hours\n"
        << "Price: $" << course.price << "\n"
        << "Level: " << course.level << "\n"
        << "Discount Rate: " << course.discountRate * 100 << "%\n"
        << "Remaining Capacity: " << course.totalCapacity - course.numberOfEnrolledStudents << "\n"
        << "Prerequisites: ";

    for (const auto& prereq : course.prerequisites) {
        if (!prereq.empty()) { // Boþ olmayan öðeleri yazdýr
            os << prereq << ", ";
        }
    }
    os.seekp(-2, ios_base::end); // Sondaki virgülü ve boþluðu sil
    os << "\n";

    return os;
}

// Getter for courseRate (average rating)
double OnlineCourse::getAverageRating() {
    return courseRate;
}

// Getter for ratingCount
int OnlineCourse::getRatingCount() {
    return ratingCount;
}

// Setter for courseRate (average rating)
void OnlineCourse::setAverageRating(double newRating) {
    courseRate = newRating;
}

// Setter for ratingCount
void OnlineCourse::setRatingCount(int newCount) {
    ratingCount = newCount;
}

