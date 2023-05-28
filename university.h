#ifndef __UNIVERSITY_H__
#define __UNIVERSITY_H__

#include "course.h"
#include "student.h"
#include "error_handling.h"

typedef struct University *University;

/**
 * Function: universityCreate
 * --------------------------
 * 
 *   Allocates memory for a new University and initializes its members with the input values
 *
 *   @param name - the name of the University
 *   
 *   @returns: a pointer to the newly created University, or NULL if there was an error
 */
University universityCreate(char *name);

/**
 * Function: universityDestroy
 * --------------------------
 * 
 *   Frees all memory used by the university.
 * 
 *   @param U - the struct of university to be destroyed
 * 
 *   @returns: void
 */
void universityDestory(University U);

/**
 * Function: addStudent
 * --------------------------
 * 
 *   Inserts a new student node to the university.
 *   
 *   @param U - the struct of university.    
 *   
 *   @returns: Result 
 */
result addStudent(University U);

/**
 * Function: removeStudent
 * --------------------------
 * 
 *   Remove a studnet node from the university.
 * 
 *   @param U - the struct of university.
 * 
 *   @returns: Result
 */
result removeStudent(University U);

/**
 * Function: editStudent
 * --------------------------
 * 
 *   edit a studnet node from the university.
 * 
 *   @param U - the struct of university.
 * 
 *   @returns: Result
 */
result editStudent(University U);

/**
 * Function: printAvgGrade
 * --------------------------
 * 
 *   Prints the average grade for a given student.
 * 
 *   @param U - the struct of university.  
 *
 *   @returns: void
 */
void printAvgGrade(University U);

/**
 * Function: printStudents
 * --------------------------
 * 
 *   This function prints the names and grades of all the students in the university,
 *   If the list is empty, the function prints an appropriate message.
 * 
 *   @param U - the struct of university.
 *  
 *   @returns: void
 */
void printStudents(University U);

/**
 * Function: addCourse
 * --------------------------
 * 
 *   Inserts a new course node to the university.
 *   
 *   @param U - the struct of university.    
 *   
 *   @returns: Result 
 */
result addCourse(University U);

/**
 * Function: removeCourse
 * --------------------------
 * 
 *   Remove a Course node from the university.
 *   and also remove CourseGrade from all students.
 * 
 *   @param U - the struct of university.
 * 
 *   @returns: Result
 */
result removeCourse(University U);

/**
 * Function: editCourse
 * --------------------------
 * 
 *   edit a course node from the university.
 * 
 *   @param U - the struct of university.
 * 
 *   @returns: Result
 */
result editCourse(University U);

/**
 * Function: printCourses
 * --------------------------
 * 
 *   This function prints the names and id of all the courses in the university,
 *   If the list is empty, the function prints an appropriate message.
 * 
 *   @param U - the struct of university.
 *  
 *   @returns: void
 */
void printCourses(University U);

#endif //__UNIVERSITY_H__
