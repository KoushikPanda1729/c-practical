#include <stdio.h>

// Define the structure
struct employee {
    int employeeId;
    char name[50];
    int age;
    char designation[50];
    float salary;
};

int main() {
    // Create an array of 5 employee objects
    struct employee employees[5];

    // Input details for each employee
    for (int i = 0; i < 5; i++) {
        printf("Enter details for employee %d:\n", i + 1);
        printf("Employee ID: ");
        scanf("%d", &employees[i].employeeId);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Age: ");
        scanf("%d", &employees[i].age);
        printf("Designation: ");
        scanf("%s", employees[i].designation);
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
    }

    // Print details of each employee3
    
    printf("\nEmployee Details:\n");
    for (int i = 0; i < 5; i++) {
        printf("Employee %d:\n", i + 1);
        printf("ID: %d\n", employees[i].employeeId);
        printf("Name: %s\n", employees[i].name);
        printf("Age: %d\n", employees[i].age);
        printf("Designation: %s\n", employees[i].designation);
        printf("Salary: %.2f\n", employees[i].salary);
        printf("\n");
    }

    return 0;
}
