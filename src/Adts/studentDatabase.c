#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynarray.h"

#define MAX_NAME_LENGTH 50

// Define the student structure
// I want it to have: id, name, age, and grade.
struct Student{
    int age;
    int id ;
    int grade;
    char* name;
};

// typedef for struct Student *
typedef struct Student *student;

// makeStudent function (if you give the right parameters, initialize the struct Student correctly
static student makeStudent(int age, int id, int grade, char *studentname) {
  student p = malloc(sizeof(struct student));
  assert(p != NULL);

  p->age = age;
  p->id = id;
  p->grade = grade;
  COPYNAME(p->name, studentname);

  return p;
}

// ask the user n times, about the student details, and save them all to the dynamic array d.
void addStudent (dynarray d, int n) {
  for (int i = 0; i < n; i++) {
      int age;
      int id;
      int grade;
      char *studentname;
      printf ("Enter the student age: ");
      scanf ("%d", &age);
      printf ("Enter the student id: ");
      scanf ("%d", &id);
      printf ("Enter the student grade: ");
      scanf ("%d", &grade);
      printf ("Enter the student name: ");
      scanf ("%s", studentname);
      dynarray_push (d, makeStudent (age, id, grade, studentname));
  }
}

// Function to display all students in the database (TODO)
void displayAll(dynarray d, dynarray_foreachf displayOne){
  
}

// Function to save students to a file

// Function to load students from a file

// Function to free memory allocated for the database (TODO)
void freeMemory(dynarray d) {
  dynarray_free(d);
}
