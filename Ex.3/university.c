#include <string.h>
#include <stdio.h>
#include "university.h"

#define MAX_STUDENT 100
#define MAX_COURSE 10

struct University{
    char *name;
    int num_courses;
    int num_students;
    struct Course *courses;
    struct Student *students;
};

University universityCreate(char *name){

    University new_uni = (University)malloc(sizeof(struct University));
    if(new_uni == NULL){
        return NULL;
    }

    new_uni->name = (char *)malloc(strlen(name)+1);
    if(new_uni->name == NULL){
        free(new_uni);
        return NULL;
    }

    strcpy(new_uni->name,name);
    new_uni->courses = NULL;
    new_uni->students = NULL;
    new_uni->num_courses = 0;
    new_uni->num_students = 0;

    return new_uni;
}

void universityDestory(University U){

    if(U == NULL) return;

    if(U->courses != NULL){
        course_destroy(U->courses); 
    }
    if(U->students != NULL){
        student_destroy(U->students);
    }

    free(U->name);
    free(U);
}

result addStudent(University U){

    if(U == NULL) return NULL_ARG;

    result res = insertStudentAtEnd(&U->students, U->courses, U->num_courses);
    
    
    U->num_students++;
    return res;

}

result removeStudent(University U){

    if(U == NULL) return NULL_ARG;

    if(U->students == NULL) {
        printf("Error: there is no students in the list.");
        return LIST_EMPTY;
    }

    result res = removeStudentById(&U->students);

    // if(res != SUCCESS) {
    //     HANDLE_ERROR(res);
    //     return FAILURE;
    // }

    U->num_students--;
    return res;
}

result editStudent(University U){

    if(U == NULL) return NULL_ARG;

    if(U->students == NULL) {
        printf("Error: there is no students in the list.");
        return LIST_EMPTY;
    }

    result res = editStudentById(U->students, U->courses);

    if(res != SUCCESS) {
        HANDLE_ERROR(res);
        return FAILURE;
    }

    return SUCCESS;
}

void printAvgGrade(University U){
    printAvgGradeById(U->students);
}

result addCourse(University U){
     if(U == NULL) return NULL_ARG;

    result res = insertCourseAtEnd(&U->courses);
    
    // if(res != SUCCESS){
    //     HANDLE_ERROR(res);
    //     return;
    // } 
    U->num_courses++;

    return res;
}

result removeCourse(University U){
    if(U == NULL) return NULL_ARG;

    if(U->courses == NULL) {
        printf("Error: there is no courses in the list.");
        return LIST_EMPTY;
    }

    result res = removeCourseById(&U->courses);

    // if(res != SUCCESS){
    //     HANDLE_ERROR(res);
    //     return;
    // } 

    U->num_courses--;
    return res;
}

result editCourse(University U){

    if(U == NULL) return NULL_ARG;

    if(U->courses == NULL) {
        printf("Error: there is no courses in the list.");
        return LIST_EMPTY;
    }

    result res = editCourseById(U->courses);

    return res;
}

void printStudents(University U){
    studentsPrint(U->students);
}

void printCourses(University U){
    coursesPrint(U->courses);
}

