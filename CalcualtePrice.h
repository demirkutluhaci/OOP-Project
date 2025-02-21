#pragma once

/*
    Template Function:
    - Farkl� veri tipleriyle �al��abilen genel bir fonksiyon tan�mlamak i�in kullan�l�r.
 */

// Non-Member discount calculation function
template <typename T>
double calculateDiscountedPrice(T* course) {
    // Ensure course is valid
    if (course == nullptr) {
        cout << "Invalid course!" << endl;
        return 0.0;
    }
    // Calculate the discounted price using the course's price and discount rate
    double discountedPrice = course.getPrice() * (1 - course.getDiscountRate() / 100);
    return discountedPrice;
}