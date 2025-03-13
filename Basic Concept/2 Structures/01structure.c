#include <stdio.h>
#include <string.h>

// Define a structure named 'student'
struct student
{
    char name[50]; // Array to hold the student's name
    int roll;      // Integer to hold the student's roll number
};

int main()
{
    struct student stu1;           // Declare a variable of type 'student'
    stu1.roll = 2305;              // Assign a roll number to stu1
    strcpy(stu1.name, "John Doe"); // Assign a name to stu1 using strcpy function

    // Print the roll number and name of the student
    printf("Roll number: %d\nName: %s\n", stu1.roll, stu1.name);

    return 0; // Return 0 to indicate successful execution
}
