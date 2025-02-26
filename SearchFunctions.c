#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "debugmalloc.h"
#include "LinkedList.h"
#include "CoreFunctions.h"

int searchbyID(){

    system("cls");
    fflush(stdin);
    int givenid;
    printf("Enter the ID of the book you wish to see: ");
    scanf("%d",&givenid);
    fflush(stdin);
    system("cls");

    FILE *fp = fopen("Book_Records.txt", "rt");
    if(fp== NULL)
    {
        perror("ERROR");
        return -1;
    }

    bookdata_t *listOfBooks=readBooksFromFile(fp);
    bookdata_t *current=listOfBooks;
    if(listOfBooks==NULL)
    {
        return -1;
    }

   fclose(fp);

    while(current != NULL)
    {
        if(current->id==givenid){
        printOneBook(current);
        break;
        }
        current = current->next;
    }
    if(current==NULL)
    {
        printf("\nNo book found");
    }
    printf("\nPress a key to return to Search for Book Page");
    getch();
    freeAllBooks(listOfBooks);
    return 4;
}

int searchbyAuthor(){

    system("cls");
    fflush(stdin);
    char *givenauthor;
    int foundbook = 0;
    printf("Enter the Author of the book you wish to see: ");
    givenauthor=readStringFromStdin();
    fflush(stdin);
    system("cls");
    fflush(stdin);


    FILE *fp = fopen("Book_Records.txt", "rt");
    if(fp== NULL)
    {
        perror("ERROR");
        return -1;
    }

    bookdata_t *listOfBooks=readBooksFromFile(fp);
    bookdata_t *current=listOfBooks;
    if(listOfBooks==NULL)
    {
        return -1;
    }

   fclose(fp);

    while(current != NULL)
    {
        if(strcmp(givenauthor, current->autname)==0){
            printOneBook(current);
            foundbook++;
        }
        current = current->next;
    }
    if(foundbook==0)
    {
        printf("\nNo book found");
    }
    printf("\nPress a key to return to Search for Book Page");
    getch();
    freeAllBooks(listOfBooks);
    free(givenauthor);

    return 4;
}

int searchbyTitle(){
    system("cls");
    fflush(stdin);
    char *giventitle;
    int foundbook = 0;
    printf("Enter the Title of the book you wish to see: ");
    giventitle=readStringFromStdin();
    fflush(stdin);
    system("cls");
    fflush(stdin);


    FILE *fp = fopen("Book_Records.txt", "rt");
    if(fp== NULL)
    {
        perror("ERROR");
        return -1;
    }

    bookdata_t *listOfBooks=readBooksFromFile(fp);
    bookdata_t *current=listOfBooks;
    if(listOfBooks==NULL)
    {
        return -1;
    }

   fclose(fp);

    while(current != NULL)
    {
        if(strcmp(giventitle, current->title)==0){
            printOneBook(current);
            foundbook++;
        }
        current = current->next;
    }
    if(foundbook==0)
    {
        printf("\nNo book found");
    }

    printf("\nPress a key to return to Search for Book Page");
    getch();
    freeAllBooks(listOfBooks);
    free(giventitle);
    return 4;
}

int searchbyYear(){

    system("cls");
    fflush(stdin);
    int givenyear;
    int foundbook = 0;
    printf("Enter publication Year: ");
    scanf("%d",&givenyear);
    fflush(stdin);
    system("cls");
    fflush(stdin);


    FILE *fp = fopen("Book_Records.txt", "rt");
    if(fp== NULL)
    {
        perror("ERROR");
        return -1;
    }

    bookdata_t *listOfBooks=readBooksFromFile(fp);
    bookdata_t *current=listOfBooks;
    if(listOfBooks==NULL)
    {
        return -1;
    }

   fclose(fp);

    while(current != NULL)
    {
        if(current->year==givenyear){
            printOneBook(current);
            foundbook++;
        }
        current = current->next;
    }
    if(foundbook==0)
    {
        printf("\nNo book found");
    }

    printf("\nPress a key to return to Search for Book Page");
    getch();
    freeAllBooks(listOfBooks);
    return 4;
}

int searchbyCategory(){
    system("cls");
    fflush(stdin);
    char *givencategory;
    int foundbook = 0;
    printf("Enter the Category of the book you wish to see: ");
    givencategory=readStringFromStdin();
    fflush(stdin);
    system("cls");

    FILE *fp = fopen("Book_Records.txt", "rt");
    if(fp== NULL)
    {
        perror("ERROR");
        return -1;
    }

    bookdata_t *listOfBooks=readBooksFromFile(fp);
    bookdata_t *current=listOfBooks;
    if(listOfBooks==NULL)
    {
        return -1;
    }

   fclose(fp);

    while(current != NULL)
    {
        if(strcmp(givencategory, current->category)==0){
            printOneBook(current);
            foundbook++;
        }
        current = current->next;
    }
    if(foundbook==0)
    {
        printf("\nNo book found");
    }

    printf("\nPress a key to return to Search for Book Page");
    getch();
    freeAllBooks(listOfBooks);
    free(givencategory);
    return 4;
}

