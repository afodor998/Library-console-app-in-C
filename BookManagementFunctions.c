#include "CoreFunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "debugmalloc.h"
#include "LinkedList.h"
#include "StudentLinkedList.h"
#include "CoreFunctions.h"

int addBook(){

    system("cls");
    bookdata_t book;

    FILE *fp = fopen("Book_Records.txt", "at");
    if(fp != NULL)
    {
        do
        {
         do
            {
                printf("Enter Book ID (can't be negative or 0): ");
                scanf("%d",&book.id);
                fflush(stdin);
                if(book.id<=0)
                {
                    printf("\nInvalid ID, try again\n");
                }
            }while(book.id<=0);

        if(bookIdCheck(book.id)==0)
        {
            fflush(stdin);
            printf("Enter Book Title: ");
            book.title=readStringFromStdin();
            fflush(stdin);

            printf("Enter Book's Author: ");
            book.autname=readStringFromStdin();
            fflush(stdin);

            do
            {
                printf("Enter the year the book was published (between 0 and 2022): ");
                scanf("%d",&book.year);
                fflush(stdin);
                if(book.year>2022||book.year<0)
                {
                    printf("\nInvalid year, try again\n");
                }
            }while(book.year>2022||book.year<0);

            printf("Enter Book Category: ");
            book.category=readStringFromStdin();
            fflush(stdin);

            book.where=0;

            fprintf(fp, "%d;%s;%s;%d;%s;%d\n",
                book.id,
                book.title,
                book.autname,
                book.year,
                book.category,
                book.where);

            printf("Record successfully added\n\n");
            free(book.autname);
            free(book.category);
            free(book.title);
        }
        else
        {
            printf("Another book already has this ID, try again\n\n");
        }
        }while(bookIdCheck(book.id)!=0);
    }
    fclose(fp);
    printf("Press a key to return to Book Management Page");
    getch();

    return 2;
}

int listBook(){

    system("cls");
     FILE *fp = fopen("Book_Records.txt", "rt");
    if(fp== NULL)
    {
        perror("ERROR");
        return -1;
    }

    bookdata_t *listOfBooks=readBooksFromFile(fp);
    if(listOfBooks==NULL)
    {
        return -1;
    }

    fclose(fp);

    printList(listOfBooks);

    freeAllBooks(listOfBooks);

    printf("\n\nPress a key to return to Book Management Page");
    getch();
    return 2;
}

int bookAvailability(){
    system("cls");
    int givenid;
    printf("Enter the ID of the book you wish to see: ");
    scanf("%d", &givenid);

     FILE *fp = fopen("Book_Records.txt", "rt");
    if(fp== NULL)
    {
        perror("HIBA: Fajl megynyitasa sikertelen");
        exit(-1);
    }

    bookdata_t *listOfBooks=readBooksFromFile(fp);
    bookdata_t *current= listOfBooks;

    fclose(fp);

    while(current != NULL)
    {
        if(current->id==givenid)
        {
            if(current->where==0)
            {
                printf("\nThis book is still in the library");

            }
            else if(current->where!=0)
            {
                printf("\nThis book is at another student: ");
                printStudent(current->where);
            }
            break;
        }
        current = current->next;
    }
    if(current==NULL)
    {
        printf("No book with given id");
    }
    printf("\nPress a key to return to Book Management Page");
    getch();
    freeAllBooks(listOfBooks);
    return 2;
}

int deleteBook(){

    system("cls");
    int givenid;
    printf("Enter the ID of the book you wish to delete: ");
    scanf("%d", &givenid);

    FILE *fp = fopen("Book_Records.txt", "rt");
    if(fp== NULL)
    {
        perror("HIBA: Fajl megynyitasa sikertelen");
        exit(-1);
    }
    bookdata_t *listOfBooks=readBooksFromFile(fp);
    fclose(fp);

    bookdata_t *current= listOfBooks;
    bookdata_t *previous=NULL;

    while (current != NULL && current->id != givenid)
    {
    previous = current;
    current = current->next;
    }


    if (current == NULL)
    {
    }
    else if (previous == NULL)
    {
        bookdata_t *newfirst = current->next;
        free(current->title);
        free(current->autname);
        free(current->category);
        free(current);
        listOfBooks = newfirst;
    }
    else
    {
        previous->next = current->next;
        free(current->title);
        free(current->autname);
        free(current->category);
        free(current);
    }

    saveBookDataIntoFile(listOfBooks);

    printf("\nAction successfully executed\n\n");
    printf("Press a key to return to Book Management Page");
    getch();
    freeAllBooks(listOfBooks);

   return 2;
}

int modifyBook(){

    system("cls");
    int givenBookId;
    char *newtitle;
    char *newautname;
    int newyear;
    char *newcategory;

    printf("Enter the ID of the Book you wish to modify: ");
    scanf("%d",&givenBookId);
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
        if(current->id==givenBookId)
        {
            printf("old record: %d, %s, %s, %d, %s\n",current->id,current->title, current->autname, current->year, current->category);
            printf("\nEnter the new title: ");
            newtitle=readStringFromStdin();
            free(current->title);
            current->title=newtitle;
            printf("\nEnter the new Author's name: ");
            newautname=readStringFromStdin();
            free(current->autname);
            current->autname=newautname;
            fflush(stdin);
            printf("\nEnter the new Year of publication: ");
            scanf("%d", &newyear);
            current->year=newyear;
            fflush(stdin);
            printf("\nEnter the new Category: ");
            newcategory=readStringFromStdin();
            free(current->category);
            current->category=newcategory;
            printf("\nnew record: %d, %s, %s, %d, %s\n\n\nModification successful\n\n",current->id,current->title, current->autname, current->year, current->category);
            break;


        }
        current = current->next;
    }

    if(current==NULL)
    {
        printf("\nNo book found with given ID\n");
    }

   saveBookDataIntoFile(listOfBooks);

    printf("Press a key to return to Book Management Page");
    getch();

    freeAllBooks(listOfBooks);

   return 2;
}

int rentBook(){

    system("cls");
    int givenBookId;
    int studentId;

    printf("Enter the ID of the Book you wish to rent: ");
    scanf("%d",&givenBookId);
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
        if(current->id==givenBookId)
        {
            if((current->where)==0)
            {
                printf("\nEnter Student ID: ");
                scanf("%d", &studentId);
                if(studentExists(studentId)==0)
                {
                current->where=studentId;
                }
                else
                {
                    printf("\nNo student with this ID");
                }

            }
            else
            {
                printf("\nThis book is already rented to another student\n");

            }
            break;
        }
        current = current->next;
    }
    if(current==NULL)
    {
        printf("\nNo book found with given ID\n");
    }
    saveBookDataIntoFile(listOfBooks);

    printf("\nBook successfully rented");
    printf("\nPress a key to return to Book Management Page");
    getch();
    freeAllBooks(listOfBooks);

   return 2;
}

int listRentals(){
    system("cls");
     FILE *fp = fopen("Book_Records.txt", "rt");
    if(fp== NULL)
    {
        perror("ERROR");
        return -1;
    }
    bookdata_t *listOfBooks=readBooksFromFile(fp);
    if(listOfBooks==NULL)
    {
        return -1;
    }
    fclose(fp);
    bookdata_t *current = listOfBooks;

    while(current != NULL)
    {
        if((current->where)!=0)
        {
            printf("The book '%s' (id: %d) is rented by: ", current->title, current->id);
            printStudent(current->where);
        }
        current=current->next;
    }
    freeAllBooks(listOfBooks);
    printf("\nPress a key to return to Book Management Page");
    getch();
    return 2;
}


