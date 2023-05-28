#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "course.h"
#include "course_grade.h"
#include "error_handling.h"

typedef struct Student *Student;

/**
 * Function: student_creat
 * --------------------------
 * 
 *   Allocates memory for a new student and initializes its members with the input values
 *
 *   @param name - the name of the student
 *   @param id - the id of the student
 *   @param num_of_courses - the number of the courses that the student is enrolled in.
 *   @param C - the head of Course linked list.
 *
 *   @returns: a pointer to the newly created student, or NULL if there was an error
 */
Student student_create(char* name, int id, int num_of_courses, Course C);

/**
 * Function: student_destroy
 * --------------------------
 * 
 *   Frees all memory used by the linked list of students.
 * 
 *   @param S - the linked list of student to be destroyed
 * 
 *   @returns: void
 */
void student_destroy(Student S);

/**
 * Function: insertStudentAtEnd
 * --------------------------
 * 
 *   Inserts a new student node with the given details at the end of the linked list pointed to by *S.
 * 
 *   @param S - a pointer to the head of the linked list Student      
 *   @param C - a pointer to the head of the linked list Course
 *   @param curr_num_courss - the current number of Courses in the university.
 * 
 *   @returns: Result
 */
result insertStudentAtEnd(Student *S, Course C, int curr_num_courses);

/**
 * Function: findStudentById
 * --------------------------
 * 
 *   Recursively searches the input linked list for the Student with the given id
 * 
 *   @param S - pointer to the head of the linked list to search
 *   @param id - the id of the game to search for
 * 
 *   @returns: a pointer to the Student with the given id, or NULL if not found
 */
Student findStudentById(Student S,int id);

/**
 * Function: removeStudentById
 * --------------------------
 * 
 *   Remove a Student node from the linked list with the given id.
 * 
 *   @param S - A pointer to the head node of the linked list.
 *   @param id - the id of the student to search for
 * 
 *   @returns: Result
 */
result removeStudentById(Student *S);

/**
 * Function: editStudentById
 * --------------------------
 *
 *   edit a studnet node from the university.
 * 
 *   @param S - A pointer to the head node of the Student linked list.
 *   @param C - A pointer to the head node of the Course linked list.
 * 
 *   @returns: Result
 */
result editStudentById(Student *S, Course C);

/**
 * Function: studentsPrint
 * --------------------------
 * 
 *   This function prints the names and grades of all the students in the university,
 *   If the list is empty, the function prints an appropriate message.
 * 
 *   @param S - a pointer to the head of the Student linked list.
 *  
 *   @returns: void
 */
void studentsPrint(Student S);

/**
 * Function: printAvgGrade
 * --------------------------
 * 
 *   Prints the average grade for a given student.
 * 
 *   @param S - a pointer to the head of the Student linked list.  
 *
 *   @returns: void
 */
void printAvgGradeById(Student S);

/**
 * Function: removeGradeFromStudent
 * --------------------------
 *   remove course grade from student by id.
 *   
 *   @param S - A pointer to the head node of the Student linked list.
 *   @param course_id - a course id that we want to remove from the student.
 * 
 *   @returns: void
 */
void removeGradeFromStudent(Student *S, int course_id);

#endif //__STUDENT_H__
