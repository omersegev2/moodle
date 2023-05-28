#include <stdlib.h>
#include <stdio.h>

#include "course_grade.h"

struct CourseGrade {
    int course_id;
    struct Course* currentCourse;
    float grade;
    struct CourseGrade* next;
};

CourseGrade course_grade_create(Course curr, int id, float grade){
    
    CourseGrade new_course_grade = (CourseGrade)malloc(sizeof(struct CourseGrade));
    if(new_course_grade == NULL) return NULL;
    
    new_course_grade->currentCourse = curr;
    new_course_grade->course_id = id;
    new_course_grade->grade = grade;
    new_course_grade->next = NULL;

    return new_course_grade; 
}

CourseGrade buildCourseGrade(Course course, int num_of_courses){
    
    float grade = 0;
    int id = 0;
    CourseGrade head = NULL;
    CourseGrade curr = NULL;
    CourseGrade prev = NULL;
    
    for (int i = 0; i < num_of_courses; i++) {

        printf("Please enter course id: ");
        scanf("%d",&id);

        Course curr_course = findCourseById(course, id);
        if(curr_course == NULL) {
            printf("Error: Course not found\n");
            return NULL;
        }

        printf("Please enter course grade (0-100): ");
        scanf("%f",&grade);

        CourseGrade new_grade = course_grade_create(curr_course, id, grade);
        if(new_grade == NULL){
            printf("Error: Out of memory");
            return NULL;
        }

        if(head == NULL){
            head = new_grade;
            curr = head;
            continue;
        }

        while(curr != NULL){
            prev = curr;
            curr = curr->next;
        }
        new_grade->next = prev->next;
        prev->next = new_grade;
    }
    return head;
}

void course_grade_destroy(CourseGrade head){

    if(head == NULL) return;
    
    CourseGrade curr = head;
    
    while(curr != NULL){
        
        head = head->next;
        free(curr);

        curr = head;
    }
}

result removeGradeById(CourseGrade *Cg, int course_id){
    if(*Cg == NULL) return NULL_ARG;

    CourseGrade curr = *Cg;
    CourseGrade prev = *Cg;

    while(curr != NULL){
        if(curr->course_id == course_id){
            prev->next = curr->next;
            free(curr);
            return SUCCESS;
        }
        prev = curr;
        curr = curr->next;
    }

    return DATA_NOT_FOUND;
}

void gradePrint(CourseGrade Cg){
    CourseGrade curr = Cg;
    while(curr != NULL){
        printf("Course id:%d - grade:%.0f\n",curr->course_id ,curr->grade);
        
        curr = curr->next;
    }

}

void printAvg(CourseGrade Cg, int num_of_courses){
    
    CourseGrade curr = Cg;
    int sum = 0;

    if(num_of_courses == 0){
        printf("The average grade is: 0\n");
        return;
    }

    while(curr != NULL){
        sum += curr->grade;
        curr = curr->next;
    }
    printf("The average grade is: %d\n", sum/num_of_courses);
}


