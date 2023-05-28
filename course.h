#ifndef __COURSE_H__
#define __COURSE_H__

#include <stdlib.h>
#include "error_handling.h"


typedef struct Course *Course;

Course course_create(char* name, int id);

result insertCourseAtEnd(Course *C);

result removeCourseById(Course *C, int id);

result editCourseById(Course *C);

void course_destroy(Course C);

Course edit_course(Course C);

void coursesPrint(Course C);

Course findCourseById(Course head, int id);


#endif //__COURSE_H__
