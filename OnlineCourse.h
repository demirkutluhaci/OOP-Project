#ifndef ONLINECOURSE_H // Header guard
#define ONLINECOURSE_H

/*
    Abstract Class:
    - En az bir saf sanal fonksiyon (pure virtual function) içerir.
    - Doðrudan nesne oluþturulamaz, türetilmiþ sýnýflar tarafýndan kullanýlýr.
    - Ortak arayüz saðlar, türetilmiþ sýnýflar bu arayüzü override etmek zorundadýr.
*/

#include <iostream>
#include <array>
#include <string>

using namespace std;

// Abstract Base Class
class OnlineCourse {
protected:
    string courseName;
    string instructor;
    int totalCapacity;
    int numberOfEnrolledStudents;
    double courseRate;
    int totalDuration;
    double price;
    string level;
    double discountRate;
    array<string, 5> prerequisites; // Fixed-size prerequisites array

    int ratingCount=50;    // Number of ratings received


public:
    // Default Constructor
    OnlineCourse();

    // Parametrized Constructor without const and references
    OnlineCourse(string, string, int, int, double, int, double, string, double, array<string, 5> prerequisites);

    // Copy Constructor
    OnlineCourse(const OnlineCourse& other);

    // Pure Virtual Methods (No bodies)
    virtual void displayInfo() = 0;  // Display course information
    virtual bool checkCapacity() = 0; // Check if there's room for more students
    virtual void addStudent() = 0; // Add a student to the course

    // Accessor Method for prerequisites
    void displayPrerequisites();

    // getter price for discount calcualtions
    double getPrice();
    double getDiscountRate();

    //getter
    int getNumberOfEnrolledStudents();
    string getCourseName();
    double getCourseRate();

    // Setter for courseRate
    void setCourseRating(double rating);

    // Virtual Destructor
    virtual ~OnlineCourse();

    //operator overloading
    friend ostream& operator<<(ostream& os, const OnlineCourse& course);



    // Methods for rating
    double getAverageRating();  // Getter for average rating
    int getRatingCount();       // Getter for the number of ratings
    void setAverageRating(double newRating);  // Setter for average rating
    void setRatingCount(int newCount);        // Setter for the number of ratings

};

#endif // ONLINECOURSE_H