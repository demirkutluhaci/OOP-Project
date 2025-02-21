
/*
* HACI MAHMUT DEMÝRKUTLU
* 2000003606
* OOP Term Project
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Student.h"
#include "Cart.h"
#include "OnlineCourse.h"
#include "SoftwareCourses.h"
#include "LanguageCourses.h"
#include "ProfessionalDevelopmentCourses.h"
#include "PerformingArtsCourse.h"
using namespace std;



//                         --------------------------------------------------------TEST CODES in the extension------------------------------------------------------------ -

/* 

//int main() {



    //cout << "SOFTWARE COURSES TEST<<"<<endl;
    //// Prerequisites list
    //array<string, 5> prerequisites = { "Basic Programming", "Data Structures", "Algorithms", "Object-Oriented Programming", "Database Management" };

    //// SoftwareCourses nesnesi oluþturuluyor
    //SoftwareCourses softwareCourse(
    //    "C++ Programming",    // Course name
    //    "Dr. John Smith",     // Instructor
    //    30,                   // Total capacity
    //    25,                   // Number of enrolled students
    //    4.5,                  // Course rate (out of 5)
    //    40,                   // Total duration (in hours)
    //    150.0,                // Price
    //    "Intermediate",       // Level (e.g., Beginner, Intermediate, Advanced)
    //    0.1,                  // Discount rate (e.g., 10% discount)
    //    prerequisites,        // Prerequisites
    //    "C++",                // Programming language
    //    "Visual Studio"       // Development environment
    //);

    //// Kurs bilgilerini görüntüle
    //softwareCourse.displayInfo();

    //// Kapasiteyi kontrol et
    //if (softwareCourse.checkCapacity()) {
    //    cout << "The course has available slots for more students." << endl;
    //}
    //else {
    //    cout << "The course is full." << endl;
    //}


    //// Güncellenmiþ kurs bilgilerini görüntüle
    //softwareCourse.displayInfo();

    //cout << "END OF 1ST COURSE" << endl;
    //cout << "-------------------------" << endl;

    //cout << "TESTING OVERLOADED OPERATOR" << endl;

    //// Parametrized constructor ile obje oluþturma
    //array<string, 5> prerequisites2 = { "Basic Programming", "Data Structures", "Algorithms", "OOP", "Software Engineering" };
    //array<string, 5> topics = { "Advanced C++", "Design Patterns", "Multithreading", "Networking", "Database Systems" };
    //ProfessionalDevelopmentCourse advancedCourse("Advanced C++", "John Doe", 30, 25, 4.5, 40, 299.99, "Advanced", 0.1, prerequisites2, true, topics);

    //// operator<< fonksiyonunu test etme
    //cout << advancedCourse << endl;


    //cout << "------------" << endl;
    //cout << "PERFORMING ARTS COURSE TEST" << endl;

    //// Prerequisites array
    //array<string, 5> prequsiteteT = { "Basic acting skills", "Introduction to theater", "Voice modulation techniques", "Stage presence basics", "Improvisation skills" };

    //// Default constructor
    //PerformingArtsCourse defaultCourse;
    //defaultCourse.displayInfo();
    //cout << endl;
    //
    //// Parametrized constructor
    //array<string, 3> guestSpeakers = { "Jane Smith", "Robert Brown", "-" };
    //PerformingArtsCourse paramCourse(
    //    "Advanced Acting Techniques",
    //    "John Doe",
    //    30,
    //    25,
    //    4.8,
    //    40,
    //    299.99,
    //    "Advanced",
    //    10.0,
    //    prequsiteteT,
    //    "Drama",
    //    guestSpeakers,
    //    5
    //);
    //paramCourse.displayInfo();
    //cout << endl;

    //// Test addStudent method
    //for (int i = 0; i < 6; ++i) {
    //    paramCourse.addStudent();
    //}
    //cout << endl;

    //// Test stageChallenge method
    //paramCourse.stageChallenge();
    //cout << endl;
    //--------------------------------------------------------------------------------------------------------------------------------------------
 */


void displayMenu() {
    cout << "\nWelcome to the Online Courses System of Haci!" << endl;
    cout << "1. View All Courses" << endl;
    cout << "2. Add a Course to Cart" << endl;
    cout << "3. View Cart" << endl;
    cout << "4. Simulate Payment" << endl;
    cout << "5. View Purchased Courses" << endl;
    cout << "6. Stage Challenge" << endl;
    cout << "7. Exit" << endl;
    cout << "8. Rate a Course" << endl; 
    cout << "Enter your choice: ";
}

int main() {
    srand(static_cast<unsigned>(time(0))); // Rastgele sayý üretimi için seed

    Student students[] = {
        Student("Ahmet", "Yýlmaz", "ahmet.yilmaz@example.com"),
        Student("Ayse", "Kara", "ayse.kara@example.com"),
        Student("Mehmet", "Demir", "mehmet.demir@example.com"),
        Student("Elif", "Celik", "elif.celik@example.com"),
        Student("Haci", "Mahmut", "hamade@example.com"),
        Student("Ahmet", "Zahid", "azahid@example.com")
    };
    const int studentCount = sizeof(students) / sizeof(students[0]);

    cout << "Select a Student to log in:" << endl;
    for (int i = 0; i < studentCount; ++i) {
        cout << i + 1 << ". " << students[i].getName() << endl;
    }
    int studentIndex;
    cin >> studentIndex;

    if (studentIndex < 1 || studentIndex > studentCount) {
        cout << "Invalid student selection. Exiting..." << endl;
        return 1;
    }

    Student& currentStudent = students[studentIndex - 1];
    Cart cart;
    bool running = true;

    const int MAX_COURSES = 8;
    OnlineCourse* courses[MAX_COURSES];

    courses[0] = new SoftwareCourses("C++ Programming", "John Doe", 30, 10, 4.5, 40, 100, "Beginner", 10,
        { "Basic Computer Knowledge", "Logic" }, "C++", "IDE Setup");
    courses[1] = new SoftwareCourses("Python for Data Science", "Jane Smith", 25, 15, 4.7, 50, 150, "Intermediate", 20,
        { "Basic Python", "Statistics" }, "Python", "Data Analysis");
    courses[2] = new LanguageCourses("Spanish Basics", "Maria Lopez", 25, 20, 4.8, 50, 80, "Beginner", 5,
        { "English Basics" }, "Latin American Spanish", true);
    courses[3] = new LanguageCourses("French for Travelers", "Pierre Dubois", 20, 18, 4.6, 30, 90, "Beginner", 10,
        { "None" }, "Practical French", false);
    courses[4] = new ProfessionalDevelopmentCourse("Time Management", "Alice Smith", 50, 35, 4.7, 20, 50, "Intermediate", 15,
        { "None" }, true, { "Self-Improvement" });
    courses[5] = new ProfessionalDevelopmentCourse("Leadership Skills", "Robert Johnson", 40, 30, 4.8, 25, 100, "Advanced", 20,
        { "None" }, true, { "Team Leadership" });
    courses[6] = new PerformingArtsCourse("Dance and Movement for Beginners", "Sophia Green", 25, 15, 4.6, 40, 150, "Beginner", 10,
        { "None" }, "Contemporary Dance", { "Emily Rivera (Choreographer)", "Marcus Black (Dancer)" }, 3);
    courses[7] = new PerformingArtsCourse("Theatre and Stagecraft for Aspiring Actors", "David Roberts", 30, 20, 4.8, 50, 180, "Intermediate", 15,
        { "Basic Acting", "Public Speaking" }, "Stage Acting", { "Sarah Adams (Director)", "John Clarke (Stage Manager)" }, 5);

    while (running) {
        displayMenu();

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "********************************************************************************" << endl;
            cout << "\nAvailable Courses:" << endl;
            for (int i = 0; i < MAX_COURSES; ++i) {
                cout << i + 1 << ". ";
                courses[i]->displayInfo();  // 'courses[i]' is a pointer to an 'OnlineCourse' object. 
                                            // The '->' operator is used to call the 'displayInfo' function on the object that 'courses[i]' points to.
                cout << endl;
            }
            break;
        }
        case 2: {
            cout << "********************************************************************************" << endl;
            cout << "\nEnter the number of the course to add to your cart: ";
            int courseIndex;
            cin >> courseIndex;
            if (courseIndex > 0 && courseIndex <= MAX_COURSES) {
                cart.addCourse(courses[courseIndex - 1]);
            }
            else {
                cout << "Invalid course number. Please try again." << endl;
            }
            break;
        }
        case 3: {
            cout << "********************************************************************************" << endl;
            cout << "\nViewing your cart:" << endl;
            cart.viewCart();
            break;
        }
        case 4: {
            cout << "********************************************************************************" << endl;
            if (cart.getSelectedCount() == 0) {
                cout << "\nYour cart is empty. Add some courses before proceeding to payment." << endl;
            }
            else {
                cout << "\nSimulating payment..." << endl;
                cart.simulatePayment();
                cout << "Payment successful!" << endl;
            }
            break;
        }
        case 5: {
            cout << "********************************************************************************" << endl;
            cout << "\nPurchased Courses:" << endl;
            int purchasedCount;
            OnlineCourse** purchasedCourses = cart.getPurchasedCourses(purchasedCount);
            if (purchasedCount == 0) {
                cout << "You haven't purchased any courses yet." << endl;
            }
            else {
                for (int i = 0; i < purchasedCount; ++i) {
                    cout << i + 1 << ". ";
                    purchasedCourses[i]->displayInfo();
                    cout << endl;
                }
            }
            break;
        }
        case 6: {
            // just wanted to show my beautiful method
            cout << "********************************************************************************" << endl;
            PerformingArtsCourse a;
            a.stageChallenge();
            cout << "Improvize on this scenario!" << endl;
            break;
        }
// Case 8: Course Rating Feature
// This part allows the user to rate a course they have selected.
// First, the user is asked to enter the course number they want to rate.
// If the course number is valid, the user is then asked to provide a rating between 1 and 5.
// The current average rating and the number of ratings for the selected course are retrieved.
// The new average rating is calculated based on the user's input and updated in the course's data.
// Finally, the updated average rating and rating count are displayed to the user.

        case 8: { // Yeni özellik: Kurs Derecelendirme
            cout << "********************************************************************************" << endl;
            cout << "\nEnter the number of the course you want to rate: ";
            int courseIndex;
            cin >> courseIndex;

            if (courseIndex > 0 && courseIndex <= MAX_COURSES) {
                cout << "Enter your rating for " << courses[courseIndex - 1]->getCourseName()
                    << " (1-5): ";
                int rating;
                cin >> rating;

                if (rating >= 1 && rating <= 5) {
                    double currentRating = courses[courseIndex - 1]->getAverageRating();
                    int currentRatingCount = courses[courseIndex - 1]->getRatingCount();

                    // Yeni ortalama puan hesaplama
                    double newAverageRating = ((currentRating * currentRatingCount) + rating) / (currentRatingCount + 1);
                    courses[courseIndex - 1]->setAverageRating(newAverageRating);
                    courses[courseIndex - 1]->setRatingCount(currentRatingCount + 1);

                    cout << "Thank you! Your rating has been added." << endl;

                    // Yeni ortalama puaný ve puan sayýsýný gösterme
                    cout << "Updated rating for " << courses[courseIndex - 1]->getCourseName() << ":" << endl;
                    cout << "Average Rating: " << courses[courseIndex - 1]->getAverageRating() << endl;
                    cout << "Rating Count: " << courses[courseIndex - 1]->getRatingCount() << endl;

                }
                else {
                    cout << "Invalid rating. Please enter a value between 1 and 5." << endl;
                }
            }
            else {
                cout << "Invalid course number. Please try again." << endl;
            }
            break;
        }
        case 7: {
            cout << "********************************************************************************" << endl;
            running = false;
            break;
        }
 // If the user enters a number that doesn't match any of the valid options (1-8),
 // this block will execute and notify the user that the input is invalid.
 // It then prompts the user to try again by displaying the message.
        default:
            cout << "Invalid option. Please try again." << endl;
            break;
        }
    }

    for (int i = 0; i < MAX_COURSES; ++i) {
        delete courses[i];
    }

    return 0;
}