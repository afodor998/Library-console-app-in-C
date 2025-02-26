#include "CoreFunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "debugmalloc.h"
#include "StudentLinkedList.h"
#include "LinkedList.h"
#include "CoreFunctions.h"

int addStudent(){

    system("cls");
    fflush(stdin);

    studentdata_t student;

    FILE *fp = fopen("Student_Records.txt", "a+");
    if(fp != NULL)
    {
        do
        {
         do
            {
                printf("Enter Student ID (can't be negative or 0): ");
                scanf("%d",&student.id);
                fflush(stdin);
                if(student.id<=0)
                {
                    printf("\nInvalid ID, try again\n");
                }
            }while(student.id<=0);

        if(studentIdCheck(student.id)==0)
        {
            printf("Enter Student Name: ");
            student.name=readStringFromStdin();
            fflush(stdin);

            printf("Enter Student phone number: ");
            student.phonenum=readStringFromStdin();
            fflush(stdin);

            fprintf(fp, "%d;%s;%s\n",
                student.id,
                student.name,
                student.phonenum);

            printf("Record successfully added\n\n");
            free(student.name);
            free(student.phonenum);
        }
        else
        {
            printf("Another student already has this ID, try again\n\n");
        }
        }while(studentIdCheck(student.id)!=0);
    }
    fclose(fp);

    fflush(stdin);
    printf("Press a key to return to Book Management Page");
    getch();

    return 3;
}

int modifyStudent(){

    system("cls");
    fflush(stdin);
    int givenStudentId;
    char *newnumber;

    printf("Enter the ID of the Student whose phone number you wish to change: ");
    scanf("%d",&givenStudentId);
    fflush(stdin);
    FILE *fp = fopen("Student_Records.txt", "rt");
    if(fp== NULL)
    {
        perror("ERROR");
        return -1;
    }

    studentdata_t *listOfStudents=readStudentsFromFile(fp);
    studentdata_t *current=listOfStudents;
    if(listOfStudents==NULL)
    {
        return -1;
    }

   fclose(fp);

   while(current != NULL)
    {
        if(current->id==givenStudentId)
        {
             printf("\nold record: %d, %s, %s\n",current->id,current->name, current->phonenum);
            printf("\nEnter the new phone number: ");
            newnumber=readStringFromStdin();
            free(current->phonenum);
            current->phonenum=newnumber;
            printf("new record: %d, %s, %s\n\n\nModification successful\n",current->id,current->name, current->phonenum);
            break;
        }
        current = current->next;
    }
    if(current==NULL)
    {
        printf("\nNo student found with given ID\n\n");
    }
    saveStudentDataIntoFile(listOfStudents);

    printf("Press a key to return to Book Management Page");
    getch();
    freeAllStudents(listOfStudents);

   return 3;
}

int rentedbyStudent(){
    system("cls");
    fflush(stdin);
    int foundbook=0;
    int givenstudentid;

    printf("Enter the ID of the student whose books you wish to see: ");
    scanf("%d", &givenstudentid);
    if(studentExists(givenstudentid)==0)
    {
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
            if((current->where)==givenstudentid)
            {
                printf("=========================\nBook's id: %d\nBook's Title: %s\nBook's Author: %s\nYear of publication: %d\nBook's Category: %s\n=========================\n\n",
               current->id,
               current->title,
               current->autname,
               current->year,
               current->category);
               foundbook++;
            }
            current=current->next;
        }

        freeAllBooks(listOfBooks);
    }
    else
    {
        printf("\nNo student found with this ID");
    }
    if(foundbook==0)
    {
        printf("This student has no rented books\n");
    }

    printf("Press a key to return to Book Management Page");
    getch();
    return 3;
}
