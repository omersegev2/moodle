#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"

#define MAX_LEN 100

//COLORS
#define RED "\033[0;31m"
#define RESET_COLOR "\033[0m"

struct Student{
    int id;
    char *name;
    int num_courses;
    struct CourseGrade *grades;
    struct Student* next;
};

// Helpers
static Student edit_student(Student S, Course C);
//


Student student_create(char* name, int id, int num_of_courses, Course C){

    Student new_student = (Student)malloc(sizeof(struct Student));
    if(new_student == NULL) return NULL;
    
    new_student->name = (char *)malloc(strlen(name)+1);
    if(new_student->name == NULL) {
        free(new_student);
        return NULL;
    }

    strcpy(new_student->name,name);
    new_student->id = id;
    new_student->num_courses = num_of_courses;
    new_student->grades = buildCourseGrade(C ,num_of_courses);
    new_student->next = NULL;

    return new_student;
}

void student_destroy(Student head){
    
    if(head == NULL) return;
    
    Student curr = head;
    
    while(curr != NULL){
        
        head = head->next;
        
        free(curr->name);
        course_grade_destroy(curr->grades);
        free(curr);

        curr = head;
    }
}

Student findStudentById(Student S, int id){
    if(S == NULL) return NULL;

    if(S->id == id) return S;
    
    return findStudentById(S->next, id);
}

result insertStudentAtEnd(Student* S, Course C, int curr_num_courses){

    char name[MAX_LEN];
    int id = 0;
    int num_of_courses = 0;
    
    printf("Please enter student name: ");
    scanf(" %[^\n]", name);

    printf("Please enter student id: ");
    while(1){
        if(scanf("%d", &id) == 1){
            break;
        } else {
            while (getchar() != '\n') {}
            printf("Invalid id. Please enter student id: ");
        }
    }

    if(findStudentById(*S,id) != NULL){
        printf("Error: Student with id:%d already exist.\n",id);
        return DATA_ALREADY_EXISTS;
    }

    printf("Please enter number of courses the student is enrolled in: ");
    while (1) {
        scanf("%d", &num_of_courses);
        if(num_of_courses <= curr_num_courses){
            break; 
        } else {
            while (getchar() != '\n') {}
            printf("Invalid number of courses. Please try again: ");
        }
    }

    Student new_stud = student_create(name, id, num_of_courses, C);
    if(new_stud == NULL) return OUT_OF_MEMORY;
    
    if(*S == NULL){
        *S = new_stud;
        printf("Student inserted successfully.\n\n");
        return SUCCESS;
    }

    Student curr = *S;
    Student prev = *S;

    while(curr != NULL){
        prev = curr;
        curr = curr->next;
    }

    new_stud->next = prev->next;
    prev->next = new_stud;
    
    printf("Student inserted successfully.\n\n");
    return SUCCESS;
}

result removeStudentById(Student *S){
    
    if(*S == NULL) return NULL_ARG;

    int id = 0;
    Student curr = *S, prev = *S;

    printf("Please enter student id: ");
    scanf("%d", &id);

    while(curr != NULL){
        if(curr->id == id){
            if(curr == *S){
                *S = curr->next;
            } else {
                prev->next = curr->next;
            }
        free(curr->name);
        course_grade_destroy(curr->grades);
        free(curr);
        
        printf("Student with id:%d has been deleted from the list.\n", id);
        return SUCCESS;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Error: Student with id:%d not found in the list.\n", id);
    return DATA_NOT_FOUND;
}

result editStudentById(Student *S, Course C){

    if(*S == NULL) return NULL_ARG;

    int id = 0;
    Student curr = *S;

    printf("Please enter student id: ");
    scanf("%d", &id);

    while(curr != NULL){
        if(curr->id == id){
            curr = edit_student(curr, C);
        return SUCCESS;
        }
        curr = curr->next;
    }
    printf("\nError: Student with id:%d not found in the list\n", id);
    return DATA_NOT_FOUND;

}

void studentsPrint(Student S){
    Student curr = S;
    if(curr == NULL){
        printf("There is no student in the list.\n");
    }
    while(curr != NULL){
        printf("Student name:%s \n",curr->name);
        printf("Student id:%d \n",curr->id);
        printf("Student num_courses:%d \n",curr->num_courses);

        gradePrint(curr->grades);

        curr = curr->next;
    }
    printf("\n");
}

void printAvgGradeById(Student S){

    int id = 0;

    printf("Please enter student id: ");
    while(1){
        if(scanf("%d", &id) == 1){
            break;
        } else {
            while (getchar() != '\n') {}
            printf("Invalid id. Please enter student id: ");
        }
    }
    Student curr_student = findStudentById(S,id);
    if(curr_student == NULL){
        printf("Error: Student with id:%d not found in the list.\n", id);
        return;
    }
    printAvg(curr_student->grades, curr_student->num_courses);
}

static Student edit_student(Student S, Course C){
    
    if(S == NULL) return NULL;

    char name[MAX_LEN];
    char* new_name;
    int choice = 0;
    int num_of_courses = 0;

    while(1){
        printf("Please selcet an option:\n");
        printf(RED"1.%s Edit student name\n",RESET_COLOR);
        printf(RED"2.%s Edit student grades\n",RESET_COLOR);
        printf(RED"3.%s Return\n",RESET_COLOR);

        printf("Insert your choice: ");
        printf(RED);

        if(scanf("%d", &choice) != 1){
            printf(RESET_COLOR);
            printf("Invalid choice. Please enter a number (1-2).\n");
            scanf("%*s");
            continue;;
        } else {
            break;
        }
    }
    printf(RESET_COLOR);
    printf("\n");

    switch (choice) {
        case 1:
            printf("Insert new student name: ");
            scanf(" %[^\n]", name);

            new_name = (char *)malloc(strlen(name)+1);
            if(new_name == NULL){
                printf("Erorr: out of memory");
                return NULL;
            }
            strcpy(new_name, name);
            free(S->name);
            S->name = new_name;
            printf("Student change successfully.\n");
            break;
        case 2:
            course_grade_destroy(S->grades);

            printf("Enter new number of courses: ");
            if (scanf("%d", &num_of_courses) != 1) {
                while (getchar() != '\n') {}
                printf("Invalid num of courses, Please try again.\n");
                break;
            }
            S->num_courses = num_of_courses;
            S->grades = buildCourseGrade(C,num_of_courses);
            printf("Student change successfully.\n");
            break;
        case 3:
            return S;
        default:
            printf("Invalid choice, Please try again.\n");
            break;
    }
    return NULL;
}

void removeGradeFromStudent(Student *S, int course_id){
    if(*S == NULL) return;

    result res;
    Student curr = *S;

    while(curr != NULL){
        res = removeGradeById(&curr->grades, course_id);
        if(res == SUCCESS){
            curr->grades = NULL;
            curr->num_courses--;
        }
        curr = curr->next;
    }
}

