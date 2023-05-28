#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "course.h"
#include "course_grade.h"
#include "error_handling.h"

typedef struct Student *Student;

Student student_create(char* name, int id, int num_of_courses,Course C);

void student_destroy(Student S);

result insertStudentAtEnd(Student *S, Course C, int curr_num_courses);

Student findStudentById(Student S,int id);

result removeStudentById(Student *S);

result editStudentById(Student *S, Course C);

void studentsPrint(Student S);

void printAvgGradeById(Student S);

void removeGradeFromStudent(Student *S, int course_id);

#endif //__STUDENT_H__
