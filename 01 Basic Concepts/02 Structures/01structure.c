#include <stdio.h>
#include <string.h>

// Define a structure named 'student'
struct student {
    char name[50]; // Student's name
    int roll;      // Roll number
    int dob;       // Date of birth
};

int main() {
    struct student stul; // Declare a variable of type 'student'

    printf("What is the name of the student? ");
    scanf("%s", stul.name);

    printf("\nWhat is the roll no of %s? ", stul.name);
    scanf("%d", &stul.roll);

    printf("\nWhat is the date of birth (DDMMYYYY) of %s? ", stul.name);
    scanf("%d", &stul.dob);

    // Print the details
    printf("\nRoll number: %d\nName: %s\nDate of Birth: %d\n", stul.roll, stul.name, stul.dob);

    return 0; // Successful execution
}
