#ifndef __UNIVERSITY_H__
#define __UNIVERSITY_H__

#include "course.h"
#include "student.h"
#include "error_handling.h"

typedef struct University *University;

University universityCreate(char *name);

void universityDestory(University U);

result addStudent(University U);
result removeStudent(University U);
result editStudent(University U);
void printAvgGrade(University U);
void printStudents(University U);

result addCourse(University U);
result removeCourse(University U);
result editCourse(University U);
void printCourses(University U);

#endif //__UNIVERSITY_H__
