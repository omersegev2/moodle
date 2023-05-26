#include <stdio.h>
#include <string.h>
#include "course.h"

#define MAX_LEN 100

//COLORS
#define RED "\033[0;31m"
#define RESET_COLOR "\033[0m"

struct Course {
    int id;
    char *name;
    struct Course* next;
};

Course course_create(char* name, int id){

    Course new_course = (Course)malloc(sizeof(struct Course));
    if(new_course == NULL) return NULL;

    new_course->name = (char *)malloc(strlen(name)+1);
    if(new_course->name == NULL) {
        free(new_course);
        return NULL;
    }

    strcpy(new_course->name,name);
    new_course->id = id;
    new_course->next = NULL;

    return new_course;
}

result insertCourseAtEnd(Course *C){

    char name[MAX_LEN];
    int id = 0;

    printf("Please enter course name: ");
    scanf(" %[^\n]", name);

    printf("Please enter course id: ");
    while(1){
        if(scanf("%d", &id) == 1){
            break;
        } else {
            while (getchar() != '\n') {}
            printf("Invalid id. Please enter course id: ");
        }
    }

    if(findCourseById(*C,id) != NULL){
        printf("Error: Course with id:%d already exist.\n",id);
        return DATA_ALREADY_EXISTS;
    }

    Course new_course = course_create(name, id);
    if(new_course == NULL) return OUT_OF_MEMORY;
    
    if(*C == NULL){
        *C = new_course;
        printf("Course inserted successfully.\n\n");
        return SUCCESS;
    }

    Course curr = *C;
    Course prev = *C;

    while(curr != NULL){
        prev = curr;
        curr = curr->next;
    }

    new_course->next = prev->next;
    prev->next = new_course;
    
    printf("Course inserted successfully.\n\n");
    return SUCCESS;
}

result removeCourseById(Course *C){
    
    if(*C == NULL) return NULL_ARG;

    int id = 0;
    Course curr = *C, prev = *C;

    printf("Please enter Course id: ");
    scanf("%d", &id);

    while(curr != NULL){
        if(curr->id == id){
            if(curr == *C){
                *C = curr->next;
            } else {
                prev->next = curr->next;
            }
        course_destroy(curr);
        printf("Course with id:%d has been deleted from the list.\n", id);
        return SUCCESS;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("\nError: Course with id:%d not found in the list.\n", id);
    return DATA_NOT_FOUND;
}

void course_destroy(Course C){
    if(C == NULL) return;

    free(C->name);
    free(C);
}

void coursesPrint(Course C){
    Course curr = C;
    while(curr != NULL){
        printf("Course name:%s \n",curr->name);
        printf("Course id:%d \n",curr->id);
        curr = curr->next;
    }
    printf("\n");
}

Course findCourseById(Course head, int id){
    if(head == NULL) return NULL;

    if(head->id == id) return head;

    return findCourseById(head->next, id);
}

result editCourseById(Course C){

    if(C == NULL) return NULL_ARG;

    int id = 0;
    Course curr = C, prev = C;

    printf("Please enter Course id: ");
    scanf("%d", &id);

    while(curr != NULL){
        if(curr->id == id){
            curr = edit_course(curr);
        return SUCCESS;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("\nError: Course with id:%d not found in the list\n", id);
    return DATA_NOT_FOUND;

}

Course edit_course(Course C){
 
    if(C == NULL) return NULL;

    char name[MAX_LEN];
    int choice = 0;
    int id = 0;

    while(1){
        printf("Please selcet an option:\n");
        printf(RED"1.%s Edit Course name\n",RESET_COLOR);
        printf(RED"2.%s Edit Course id\n",RESET_COLOR);
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
            printf("Insert new Course name: ");
            scanf(" %[^\n]", name);
            strcpy(C->name,name);
            printf("Course change successfully.\n");
            break;
        case 2:
            printf("Enter course id: ");
            if (scanf("%d", &id) != 1) {
                while (getchar() != '\n') {}
                printf("Invalid id, Please try again.\n");
                break;
            }
            printf("Student change successfully.\n");
            break;
        case 3:
            return C;
        default:
            printf("Invalid choice, Please try again.\n");
            break;
    }
    return NULL;
}

