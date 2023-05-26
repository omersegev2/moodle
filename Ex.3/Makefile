CC = gcc
FLAGS = -Wall --pedantic-errors

SRCS = course.c course_grade.c main.c student.c university.c error_handling.c

OBJS = $(SRCS:.c=.o)

all: main
	./main

main: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o main

error_handling.o: error_handling.c error_handling.h
	$(CC) $(FLAGS) -c error_handling.c

course_grade.o: course_grade.c course_grade.h error_handling.h
	$(CC) $(FLAGS) -c course_grade.c 

course.o: course.c course.h error_handling.h
	$(CC) $(FLAGS) -c course.c 

student.o: student.c course_grade.h course.h student.h error_handling.h
	$(CC) $(FLAGS) -c student.c 

university.o: university.c course.h student.h error_handling.h
	$(CC) $(FLAGS) -c university.c 

clean:
	rm -f $(OBJS) main