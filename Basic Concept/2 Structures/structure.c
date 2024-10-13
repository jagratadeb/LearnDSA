#include <stdio.h>
#include <string.h>

struct student{
    char name[50];
    int roll;
};

int main(){
    struct student stu1;
    stu1.roll = 2305;
    strcpy(stu1.name, "John Doe");
    printf("Roll number: %d\nName: %s\n", stu1.roll, stu1.name);
    return 0;
}