In this project, you are expected to create a console application for online courses. In this application, the 
student should be able to view the registered courses and their details. The student can add selected 
course(s) to their cart. Since an actual payment system is not in place, the payment section will be 
simulated. After entering payment information, the student will see a message indicating the payment was 
successful. The student should also be able to view the courses they have purchased. 
To structure this, first, create a class called OnlineCourse. This class should include pure virtual methods 
such as displayInfo(), addStudent(), and checkCapacity(), along with data members such as course name, 
instructor, total capacity, number of enrolled students, course rates, total duration, price, level, discount 
rate, and prerequisites. 
Afterward, 
use 
this 
class 
to 
create 
SoftwareCourses, 
LanguageCourses, 
and 
ProfessionalDevelopmentCourses classes. The SoftwareCourses class should have additional data members 
for programming language and development environment used in the course. The LanguageCourses class 
should include data members for the foreign language being taught and information on whether the 
instructor is a native speaker. The ProfessionalDevelopmentCourses class should have data members 
indicating if the course provides certification and the topics covered.  
You are also required to create a fourth course type similar to these classes. Assessment will be based on 
the creativity and uniqueness of the class and concept. 
You need to write a discount calculation function. However, this function does not belong to any specific 
class and should be able to operate on courses of any type. It should take the course as a parameter. It 
should return the newly calculated discounted price. 
You are also expected to create Student and Cart classes. The Student class should store information such 
as student name, surname, email address, and courses they are enrolled in. However, these data members 
should not be directly accessible. In the Cart class, an array should hold the selected courses. The cart 
should allow adding, removing, and confirming courses. Once confirmed, courses cannot be removed from 
the cart. A student can enroll in a maximum of three courses, and cannot enroll in a course they have 
already registered for. After courses are added to the cart, the new price for each course will be calculated 
based on its own discount rate. When the student clicks the 'View Cart' option, both the prices before and 
after the discount will be displayed, and the total price will be calculated based on the discounted prices. 
Once the cart is confirmed, the courses should be added to the student's enrolled courses. 
Additionally, students should be able to rate the courses they have taken between 1 and 5. The new ratings 
should be added to the average rating of the courses. 
You are required to design an appropriate menu based on these operations. The program should not 
terminate until the user wants to close it. 


