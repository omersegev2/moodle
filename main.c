#include <stdio.h>
#include "university.h"
#include "error_handling.h"

//COLORS
#define RED "\033[0;31m"
#define RESET_COLOR "\033[0m"

static int getUserChoice();

int main() {
    char *name = "moodle";
    int choice = 0;

    University moodle = universityCreate(name);
    
    printf("\nWelcome to the University Management System!\n");

    while(choice != 10){
        choice = getUserChoice();

        switch (choice) {
        case 1:
            HANDLE_ERROR(addStudent(moodle));
            // addStudent(moodle);
            break;
        case 2:
            HANDLE_ERROR(removeStudent(moodle));
            break;
        case 3:
            HANDLE_ERROR(editStudent(moodle));
            break;
        case 4:
            printStudents(moodle);
            break;
        case 5:
            HANDLE_ERROR(addCourse(moodle));
            break;
        case 6:
            HANDLE_ERROR(removeCourse(moodle));
            break;
        case 7:
            HANDLE_ERROR(editCourse(moodle));
            break;
        case 8:
            printCourses(moodle);
            break;
        case 9:
            printAvgGrade(moodle);
            break;
        case 10:
            printf("Please come back soon!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }

    universityDestory(moodle);
    return 0;
}

/**
 * Function: getUserChoice
 * --------------------------
 * 
 * Displays a menu of options and prompts the user to select a choice by inputting a number.
 * Returns the user's choice as an integer.
 * 
 * @return: an integer representing the user's choice.   
 */
static int getUserChoice(){
    int choice = 0;

    while(1){
        
        printf("Please selcet an option:\n");
        printf(RED"1.%s Add a student\n",RESET_COLOR);
        printf(RED"2.%s Remove a student\n",RESET_COLOR);
        printf(RED"3.%s Edit a student\n",RESET_COLOR);
        printf(RED"4.%s Desplay all students\n",RESET_COLOR);
        printf(RED"5.%s Add a course\n",RESET_COLOR);
        printf(RED"6.%s Remove a course\n",RESET_COLOR);
        printf(RED"7.%s Edit a course\n",RESET_COLOR);
        printf(RED"8.%s Display all courses\n",RESET_COLOR);
        printf(RED"9.%s Calculate a student's average grade\n",RESET_COLOR);
        printf(RED"10.%s Quit\n\n",RESET_COLOR);

        printf("Insert your choice: ");
        printf(RED);
        
        if(scanf("%d", &choice) != 1){
            printf(RESET_COLOR);
            printf("Invalid choice. Please enter a number (1-10).\n");
            scanf("%*s");
            continue;;
        } else {
            break;
        }
    }

    printf(RESET_COLOR);
    printf("\n");

    return choice;
}

