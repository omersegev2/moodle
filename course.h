#ifndef __COURSE_H__
#define __COURSE_H__

#include <stdlib.h>
#include "error_handling.h"


typedef struct Course *Course;

/**
 * Function: course_creat
 * --------------------------
 * 
 *   Allocates memory for a new course and initializes its members with the input values
 *
 *   @param name - the name of the student
 *   @param id - the id of the student
 * 
 *   @returns: a pointer to the newly created course, or NULL if there was an error
 */
Course course_create(char* name, int id);

/**
 * Function: course_destroy
 * --------------------------
 * 
 *   Frees all memory used by the linked list of courses.
 * 
 *   @param S - the linked list of course to be destroyed
 * 
 *   @returns: void
 */
void course_destroy(Course C);

/**
 * Function: insertCourseAtEnd
 * --------------------------
 * 
 *   Inserts a new course node with the given details at the end of the linked list pointed to by *C.
 *   @param C - a pointer to the head of the linked list      
 * 
 *   @returns: Result
 */
result insertCourseAtEnd(Course *C);

/**
 * Function: removeCourseByTitle
 * --------------------------
 * 
 *   Remove a Course node from the linked list with the given title.
 * 
 *   @param C - A pointer to the head node of the linked list.
 *   @param id - the id of the Course to search for
 * 
 *   @returns: Result
 */
result removeCourseById(Course *C, int id);

/**
 * Function: editCourseById
 * --------------------------
 *
 *   edit a course node from the university.
 * 
 *   @param C - A pointer to the head node of the Course linked list.
 * 
 *   @returns: Result
 */
result editCourseById(Course *C);

/**
 * Function: edit_course
 * --------------------------
 *
 *   helper to the function editCourseById.
 *   change name for the course and return the node after the update.
 *   
 *   @param C - A pointer to a node that we want to edit.
 * 
 *   @returns: updated course
 */
Course edit_course(Course C);

/**
 * Function: coursesPrint
 * --------------------------
 * 
 *   This function prints the names and id of all the Courses in the university,
 *   If the list is empty, the function prints an appropriate message.
 * 
 *   @param S - a pointer to the head of the Course linked list.
 *  
 *   @returns: void
 */
void coursesPrint(Course C);

/**
 * Function: findCourseById
 * --------------------------
 * 
 *   Recursively searches the input linked list for the Course with the given id
 * 
 *   @param S - pointer to the head of the linked list to search
 *   @param id - the id of the course to search for
 * 
 *   @returns: a pointer to the Course with the given id, or NULL if not found
 */
Course findCourseById(Course head, int id);


#endif //__COURSE_H__
