#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//book data
typedef struct _bookdata_t
{
    int id;
    char *title;
    char *autname;
    int year;
    char *category;
    int where;
    struct _bookdata_t *next;

}bookdata_t;

bookdata_t *readBooksFromFile(FILE *input);
void freeAllBooks(bookdata_t *booklist);

void appendBookToFrontOfList(bookdata_t **booklist, bookdata_t *newbook);

int readOneBookFromFile(bookdata_t **booklist, FILE *input);

char *readStringInputFromFile(FILE *input);

void freeBook(bookdata_t *booklist);

void printList(bookdata_t *booklist);

void printListIntoFile(bookdata_t *booklist, FILE *input);



#endif // LINKEDLIST_H_INCLUDED
