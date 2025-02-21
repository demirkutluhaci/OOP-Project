#include "Cart.h"
#include "CalcualtePrice.h"
using namespace std;

// Default Constructor
Cart::Cart() : selectedCount(0), isConfirmed(false), purchasedCount(0) {
    selectedCourses.fill(nullptr);
    for (int i = 0; i < 3; ++i) {
        purchasedCourses[i] = nullptr;
    }
}

// Parametrized Constructor
Cart::Cart(int selectedCount, bool isConfirmed)
    : selectedCount(selectedCount), isConfirmed(isConfirmed), purchasedCount(0) {
    selectedCourses.fill(nullptr);
    for (int i = 0; i < 3; ++i) {
        purchasedCourses[i] = nullptr;
    }
}

// Destructor
Cart::~Cart() {
    cout << "Destructor-Cart." << endl;
}

// Method to add a course to the cart
bool Cart::addCourse(OnlineCourse* course) {
    if (selectedCount >= 3) {
        cout << "Cannot add course: Cart is full." << endl;
        return false;
    }
    for (int i = 0; i < selectedCount; ++i) {
        if (selectedCourses[i] == course) {
            cout << "Cannot add course: Already in cart." << endl;
            return false;
        }
    }
    selectedCourses[selectedCount++] = course;
    cout << "Course added to cart: " << course->getCourseName() << endl;
    return true;
}

// Method to remove a course from the cart
bool Cart::removeCourse(OnlineCourse* course) {
    if (isConfirmed) {
        cout << "Cannot remove course: Cart is confirmed." << endl;
        return false;
    }
    for (int i = 0; i < selectedCount; ++i) {
        if (selectedCourses[i] == course) {
            for (int j = i; j < selectedCount - 1; ++j) {
                selectedCourses[j] = selectedCourses[j + 1];
            }
            //silinen kursun olduðu yerden itibaren diziyi sola kaydýrmaya çalýþtým ama...
            selectedCourses[--selectedCount] = nullptr;
            cout << "Course removed from cart: " << course->getCourseName() << endl;
            return true;
        }
    }
    cout << "Course not found in cart." << endl;
    return false;
}

// Method to confirm the cart and enroll courses to the student
void Cart::confirmCart(Student& student) {
    if (isConfirmed) {
        cout << "Cart is already confirmed." << endl;
        return;
    }
    for (int i = 0; i < selectedCount; ++i) {
        if (!student.enrollInCourse(*selectedCourses[i])) {
            cout << "Failed to enroll in course: " << selectedCourses[i]->getCourseName() << endl;
        }
    }
    isConfirmed = true;
    cout << "Cart confirmed." << endl;
}

// Method to view the cart contents and prices
void Cart::viewCart() {
    cout << "Cart Details:\n";
    if (selectedCount == 0) {
        cout << "Cart is empty.\n";
        return;
    }
    double totalPriceBefore = 0.0f, totalPriceAfter = 0.0f;
    for (int i = 0; i < selectedCount; i++) {
        OnlineCourse* course = selectedCourses[i];
        // Use the template function to calculate the price after discount
        double priceAfter = calculateDiscountedPrice(course);
        double priceBefore = course->getPrice();  // Get original price
        totalPriceBefore += priceBefore;
        totalPriceAfter += priceAfter;

        cout << course->getCourseName() << " - "
            << "Price Before Discount: $" << priceBefore
            << ", Price After Discount: $" << priceAfter << endl;
    }

    cout << "Total Price Before Discount: $" << totalPriceBefore << endl;
    cout << "Total Price After Discount: $" << totalPriceAfter << endl;
}

// Simulate payment
void Cart::simulatePayment() {
    for (int i = 0; i < selectedCount; ++i) {
        purchasedCourses[purchasedCount++] = selectedCourses[i];
    }
    selectedCount = 0; // Clear the cart after payment
    cout << "Payment simulated successfully. Courses moved to purchased list." << endl;
}

// Get courses currently in the cart
OnlineCourse** Cart::getCourses(int& count)  {
    count = selectedCount;
    return const_cast<OnlineCourse**>(selectedCourses.data());
}

// Get purchased courses
OnlineCourse** Cart::getPurchasedCourses(int& count) {
    count = purchasedCount;
    return purchasedCourses;
}

// Setter and Getter methods
OnlineCourse* Cart::getSelectedCourse(int index) {
    if (index >= 0 && index < 3) {
        return selectedCourses[index];
    }
    return nullptr;
}

void Cart::setSelectedCourse(int index, OnlineCourse* course) {
    if (index >= 0 && index < 3) {
        selectedCourses[index] = course;
    }
}

int Cart::getSelectedCount() {
    return selectedCount;
}

void Cart::setSelectedCount(int count) {
    if (count >= 0 && count <= 3) {
        selectedCount = count;
    }
}

bool Cart::getIsConfirmed() {
    return isConfirmed;
}

void Cart::setIsConfirmed(bool confirmed) {
    isConfirmed = confirmed;
}
