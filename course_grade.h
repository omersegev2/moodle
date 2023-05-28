#ifndef __COURSE_GRADE_H__
#define __COURSE_GRADE_H__

#include "course.h"

typedef struct CourseGrade *CourseGrade;

CourseGrade course_grade_create(Course curr, int id, float grade);

CourseGrade buildCourseGrade(Course course, int num_of_courses);

void course_grade_destroy(CourseGrade Cg);

void gradePrint(CourseGrade Cg);

void printAvg(CourseGrade Cg, int num_of_courses);

result removeGradeById(CourseGrade *Cg, int course_id);

#endif //__COURSE_GRADE_H__

