#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Maximum number of students the system can hold
#define MAX_STUDENTS 120

// We define a 'Student' structure
struct Student {
    int id;
    char name[50];
    float gpa;
};

// Declaring functions
void addStudent(struct Student students[], int *count);
void viewStudents(struct Student students[], int count);
void deleteStudent(struct Student students[], int *count);

// Main Function
int main() {
    struct Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    printf("Student Records\n");

    while (1) {
        // Display Menu
        printf("\n1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Delete Student by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        // Input validation
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(students, &studentCount);
                break;
            case 2:
                viewStudents(students, studentCount);
                break;
            case 3:
                deleteStudent(students, &studentCount);
                break;
            case 4:
                printf("Exiting\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

void addStudent(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Error: Database is full!\n");
        return;
    }

    struct Student newStudent;

    printf("\nAdd New Student\n");
    
    // Get ID
    printf("Enter ID (Integer): ");
    scanf("%d", &newStudent.id);

    // Get Name
    printf("Enter Name: ");
    fgets(newStudent.name, 50, stdin);

    newStudent.name[strcspn(newStudent.name, "\n")] = 0;

    // Get GPA
    printf("Enter GPA: ");
    scanf("%f", &newStudent.gpa);

    students[*count] = newStudent;
    (*count)++;

    printf("Student added successfully!\n");
}

void viewStudents(struct Student students[], int count) {
    if (count == 0) {
        printf("\nNo records found.\n");
        return;
    }

    printf("\n--- Student List ---\n");
    printf("%-5s %-25s %-5s\n", "ID", "Name", "GPA"); // Formatting columns

    for (int i = 0; i < count; i++) {
        printf("%-5d %-25s %-5.2f\n", 
               students[i].id, 
               students[i].name, 
               students[i].gpa);
    }
}

void deleteStudent(struct Student students[], int *count) {
    int id, foundIndex = -1;
    
    printf("\nEnter ID to delete: ");
    scanf("%d", &id);

    // Search for the student
    for (int i = 0; i < *count; i++) {
        if (students[i].id == id) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("Student with ID %d not found.\n", id);
    } else {
        // Delete by shifting all subsequent elements one step back
        for (int i = foundIndex; i < (*count) - 1; i++) {
            students[i] = students[i + 1];
        }
        (*count)--; // Decrease the total count
        printf("Student deleted successfully.\n");
    }
}