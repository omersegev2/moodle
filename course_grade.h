#ifndef __COURSE_GRADE_H__
#define __COURSE_GRADE_H__

#include "course.h"

typedef struct CourseGrade *CourseGrade;

/**
 * Function: course_grade_creat
 * --------------------------
 * 
 *   Allocates memory for a new course grade and initializes its members with the input values
 *
 *   @param curr - a pointer to the current course
 *   @param id - the id of the course
 *   @param grade - the grade of the course
 * 
 *   @returns: a pointer to the newly created courseGrade, or NULL if there was an error
 */
CourseGrade course_grade_create(Course curr, int id, float grade);

/**
 * Function: buildCourseGrade
 * --------------------------
 *   create new course grade node linked list. 
 *   
 *   @param Course - a pointer to the head of the linked list
 *   @param num_of_courses - a number of courses that insert grade for.      
 * 
 *   @returns: a pointer to the head of the courseGrade linked list.
 */
CourseGrade buildCourseGrade(Course course, int num_of_courses);

/**
 * Function: course_grade_destroy
 * --------------------------
 * 
 *   Frees all memory used by the linked list of courseGrade.
 * 
 *   @param Cg - the linked list of courseGrade to be destroyed
 * 
 *   @returns: void
 */
void course_grade_destroy(CourseGrade Cg);

/**
 * Function: gradePrint
 * --------------------------
 * 
 *   This function prints the course id and grade of all the Courses in student,
 *   If the list is empty, the function prints an appropriate message.
 * 
 *   @param Cg - a pointer to the head of the COurseGrade linked list.
 *  
 *   @returns: void
 */
void gradePrint(CourseGrade Cg);

/**
 * Function: printAvg
 * --------------------------
 * 
 *   Prints the average grade for a given course grade linked list.
 * 
 *   @param Cg - the head of the Course grade linked list.
 *   @param num_of_courses - number of courses to divide by.  
 *
 *   @returns: void
 */
void printAvg(CourseGrade Cg, int num_of_courses);

/**
 * Function: removeGradeById
 * --------------------------
 *   remove grade from by id.
 *   
 *   @param Cg - A pointer to the head node of the courseGrade linked list.
 *   @param course_id - a course id that we want to remove from the CourseGrade lins.
 * 
 *   @returns: void
 */
result removeGradeById(CourseGrade *Cg, int course_id);

#endif //__COURSE_GRADE_H__

