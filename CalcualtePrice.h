#pragma once

/*
    Template Function:
    - Farklý veri tipleriyle çalýþabilen genel bir fonksiyon tanýmlamak için kullanýlýr.
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