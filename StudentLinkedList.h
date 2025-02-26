#ifndef STUDENTLINKEDLIST_H_INCLUDED
#define STUDENTLINKEDLIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//student data
typedef struct _studentdata_t
{
    int id;
    char *name;
    char *phonenum;
    struct _studentdata_t *next;

}studentdata_t;

studentdata_t *readStudentsFromFile(FILE *input);

void freeAllStudents(studentdata_t *studentlist);

void appendStudentToFrontOfList(studentdata_t **studentlist, studentdata_t *current);

int readOneStudentFromFile(studentdata_t **StudentOfList, FILE *input);

char *readStringFromFile(FILE *input);

void freeStudent(studentdata_t *studentlist);

void printListofStudents(studentdata_t *studentlist);

void printStudentListIntoFile(studentdata_t *studentlist, FILE *input);


#endif // STUDENTLINKEDLIST_H_INCLUDED
