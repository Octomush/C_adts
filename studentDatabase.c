#include <stdio.h>
#include <stdlib.h>
#include "dynamicArray.h"

#define MAX_NAME_LENGTH 50

// Define the student structure
// I want it to have: id, name, age, and grade.
struct Student{
    int age;
    int id ;
    int grade;
    char* name;
    struct Student* next;
};

// Function to add a student to the database (TODO)
// struct Student* toAdd = pointer to the struct Student
// struct Student** database = array of struct Student pointers

void addStudent (struct Student** database, Student newStudent) {
    insertElement(database,newStudent);
}

// Function to display all students in the database (TODO)
void displayAll(struct Student** database){
    struct Student* curr = *database;
    if (curr == NULL){
        return;
    }
    while (curr != NULL) {
        printf("age: ");
        printf("%d", curr->age);
        printf("id: ");
        printf("%d", curr->id);
        printf("grade: ");
        printf("%d", curr->grade);
        printf("name: ");
        printf("%s", curr->name);
        curr = curr->next;
    }

}

// Function to save students to a file

// Function to load students from a file

// Function to free memory allocated for the database (TODO)
void freeMemory(struct Student** database) {
    freeArray(database);
}

int main() {
  struct Student *studentDatabase = NULL;
  int numStudents = 0;



  //Example:
  // addStudent(&studentDatabase, &numStudents);
}