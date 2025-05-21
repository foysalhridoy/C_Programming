#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 50
#define MAX_NAME_LENGTH 50
#define TOTAL_CLASSES 20

// Structure for storing student information
struct Student {
    int studentID;            // Student ID
    char name[MAX_NAME_LENGTH]; // Student name
    int attendanceCount;      // Number of classes attended
};

// Function prototypes
void addStudent(struct Student students[], int *studentCount);
void markAttendance(struct Student students[], int studentCount);
void viewAttendanceReport(struct Student students[], int studentCount);
void searchStudentAttendance(struct Student students[], int studentCount);
void displayMenu();
float calculateAttendancePercentage(int attended, int totalClasses);

int main() {
    struct Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To consume the newline character after integer input

        switch (choice) {
            case 1:
                addStudent(students, &studentCount);
                break;

            case 2:
                markAttendance(students, studentCount);
                break;

            case 3:
                viewAttendanceReport(students, studentCount);
                break;

            case 4:
                searchStudentAttendance(students, studentCount);
                break;

            case 5:
                printf("Exiting the Attendance System. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\nClass Attendance Report System\n");
    printf("1. Add Student\n");
    printf("2. Mark Attendance\n");
    printf("3. View Attendance Report\n");
    printf("4. Search Student Attendance\n");
    printf("5. Exit\n");
}

// Function to add a student to the system
void addStudent(struct Student students[], int *studentCount) {
    if (*studentCount >= MAX_STUDENTS) {
        printf("Maximum number of students reached.\n");
        return;
    }

    printf("Enter student ID: ");
    scanf("%d", &students[*studentCount].studentID);
    printf("Enter student name: ");
    getchar(); // Clear the newline character from input buffer
    fgets(students[*studentCount].name, MAX_NAME_LENGTH, stdin);
    students[*studentCount].name[strcspn(students[*studentCount].name, "\n")] = 0; // Remove trailing newline character
    students[*studentCount].attendanceCount = 0;
    (*studentCount)++;
    printf("Student added successfully.\n");
}

// Function to mark attendance for a student
void markAttendance(struct Student students[], int studentCount) {
    int studentID;
    int found = 0;

    printf("Enter student ID to mark attendance: ");
    scanf("%d", &studentID);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].studentID == studentID) {
            students[i].attendanceCount++;
            printf("Attendance marked for %s. Total attendance: %d\n", students[i].name, students[i].attendanceCount);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student ID not found.\n");
    }
}

// Function to view all students' attendance along with their monthly percentage
void viewAttendanceReport(struct Student students[], int studentCount) {
    if (studentCount == 0) {
        printf("No students in the system.\n");
        return;
    }

    printf("\nAttendance Report:\n");
    for (int i = 0; i < studentCount; i++) {
        float percentage = calculateAttendancePercentage(students[i].attendanceCount, TOTAL_CLASSES);
        printf("Student ID: %d | Name: %s | Attendance: %d | Percentage: %.2f%%\n",
                students[i].studentID, students[i].name, students[i].attendanceCount, percentage);
    }
}

// Function to search for a student's attendance by their student ID
void searchStudentAttendance(struct Student students[], int studentCount) {
    int studentID;
    int found = 0;

    printf("Enter student ID to search attendance: ");
    scanf("%d", &studentID);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].studentID == studentID) {
            float percentage = calculateAttendancePercentage(students[i].attendanceCount, TOTAL_CLASSES);
            printf("Student ID: %d | Name: %s | Attendance: %d | Percentage: %.2f%%\n",
                    students[i].studentID, students[i].name, students[i].attendanceCount, percentage);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }
}

// Function to calculate attendance percentage
float calculateAttendancePercentage(int attended, int totalClasses) {
    return (float)attended / totalClasses * 100;
}
