#ifndef COREFUNCTIONS_H_INCLUDED
#define COREFUNCTIONS_H_INCLUDED

#include "LinkedList.h"
#include "StudentLinkedList.h"

char *readStringFromStdin(void);

int bookIdCheck(int givenID);

int studentIdCheck(int givenID);

int studentExists(int givenid);

void printStudent(int studentid);

int deleteContentsOfBookFile();

void saveBookDataIntoFile(bookdata_t *listOfBooks);

int deleteContentsOfStudentFile();

void saveStudentDataIntoFile(studentdata_t *listOfStudents);

void printOneBook();

void credits();

void stLoadindScreen();

void mainScreen();

void bookLoadindScreen();

void searchLoadingScreen();


#endif // COREFUNCTIONS_H_INCLUDED
