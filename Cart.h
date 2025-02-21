#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <array>
#include "OnlineCourse.h"
#include "Student.h"
#include "CalcualtePrice.h"

using namespace std;

class Cart {
private:
    bool isConfirmed; // Cart confirmation status
    array<OnlineCourse*, 3> selectedCourses; // Maximum 3 courses
    int selectedCount; // Current number of selected courses

    OnlineCourse* purchasedCourses[3]; // Array to store purchased courses
    int purchasedCount; // Count of purchased courses

public:
    // Default Constructor
    Cart();

    // Parametrized Constructor
    Cart(int selectedCount, bool isConfirmed);

    // Methods to add, remove, and confirm courses
    bool addCourse(OnlineCourse* course);
    bool removeCourse(OnlineCourse* course);
    void confirmCart(Student& student);
    void viewCart(); // Display prices before and after discount

    // New methods
    void simulatePayment(); // Simulate payment process
    OnlineCourse** getCourses(int& count); // Get current cart courses
    OnlineCourse** getPurchasedCourses(int& count); // Get purchased courses

    // Setter and Getter methods
    OnlineCourse* getSelectedCourse(int index);
    void setSelectedCourse(int index, OnlineCourse* course);

    int getSelectedCount();
    void setSelectedCount(int count);

    bool getIsConfirmed();
    void setIsConfirmed(bool confirmed);

    // Destructor
    ~Cart();

    // Template method for calculating discounted price
    template <typename T>
    double calculateDiscountedPrice(T* course) {
        // Ensure course is valid
        if (course == nullptr) {
            cout << "Invalid course!" << endl;
            return 0.0;
        }
        // Calculate the discounted price using the course's price and discount rate
        double discountedPrice = course->getPrice() * (1 - course->getDiscountRate() / 100);
        return discountedPrice;
    }
};

