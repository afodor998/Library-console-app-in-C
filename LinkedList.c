#include "LinkedList.h"
#include "debugmalloc.h"
#include "StudentLinkedList.h"
#include "CoreFunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bookdata_t *readBooksFromFile(FILE *input)
{
    int ret;
    bookdata_t *booklist= NULL;
    bookdata_t *current;

    while((ret= readOneBookFromFile(&current, input))==1)
    {
         appendBookToFrontOfList(&booklist, current);
    }

    if(ret!=1)
    {
        freeBook(current);

    }
    return booklist;
}

void freeAllBooks(bookdata_t *booklist)
{
    bookdata_t *current= NULL;
    while((current=booklist) != NULL)
    {
        booklist=booklist->next;
        free(current->title);
        free(current->autname);
        free(current->category);
        free(current);

    }
}


void appendBookToFrontOfList(bookdata_t **booklist, bookdata_t *current)
{
    if(*booklist == NULL)
    {
        *booklist = current;
    }
    else
    {
        bookdata_t *temp = *booklist;
        *booklist = current;
        current->next = temp;
    }
}

int readOneBookFromFile(bookdata_t **bookFromList, FILE *input)
{
    *bookFromList= (bookdata_t*)malloc(sizeof(bookdata_t));

    if(*bookFromList==NULL)
    {
        return -1;
    }
    (*bookFromList)->title=NULL;
    (*bookFromList)->autname=NULL;
    (*bookFromList)->category=NULL;

    if(fscanf(input, "%d;", &(*bookFromList)->id)== EOF)
    {
        return 0;
    }


    (*bookFromList)->title = readStringInputFromFile(input);
    if(  (*bookFromList)->title==0)
    {
        return 0;
    }


    (*bookFromList)->autname = readStringInputFromFile(input);
    if(  (*bookFromList)->autname==0)
    {
        return 0;
    }

    if(fscanf(input, "%d;", &(*bookFromList)->year)== EOF)
    {
        return 0;
    }

    (*bookFromList)->category = readStringInputFromFile(input);
    if(  (*bookFromList)->category==0)
    {
        return 0;
    }

    if(fscanf(input, "%d", &(*bookFromList)->where)== EOF)
    {
        return 0;
    }


    (*bookFromList)->next=NULL;

    return 1;
}

char *readStringInputFromFile(FILE *input)
{
    char *prev_string_version= NULL;
    char *string=NULL;
    size_t lengthOfString=0;
    int c;

    do
    {
        c = getc(input);
        if(lengthOfString==0 && c == EOF)
        {
            return NULL;
        }
        if(c== EOF || c=='\n'|| c==';')
        {
            c='\0';
        }
        prev_string_version = string;
        lengthOfString++;
        string = malloc(lengthOfString);

        if(string==NULL)
        {
            return NULL;
        }

        int i;
        for(i=0; i< lengthOfString-1; ++i)
        {
            string[i]= prev_string_version[i];
        }
        string[i]=c;

        free(prev_string_version);
    }while(c != '\0');

    return string;
}


void freeBook(bookdata_t *current)
{
    if(current==NULL)
    {
        return;
    }
    free(current->title);
    free(current->autname);
    free(current->category);

    free(current);
}

void printList(bookdata_t *booklist)
{
    bookdata_t *current=booklist;
    if(current==NULL)
    {
        printf("Empty List\n");
    }
        while(current != NULL)
    {

        printf("=========================\nBook's id: %d\nBook's Title: %s\nBook's Author: %s\nYear of publication: %d\nBook's Category: %s\n",
               current->id,
               current->title,
               current->autname,
               current->year,
               current->category);
               //current->where);
               if(current->where==0)
               {
                   printf("Book's Location: Library\n=========================\n\n");

               }
               else
               {
                   printf("Book's Location: ");
                    printStudent(current->where);
                    printf("=========================\n\n");
               }
        current = current->next;
    }

}

void printListIntoFile(bookdata_t *booklist, FILE *input)
{
    bookdata_t *current=booklist;
    if(current==NULL)
    {
        printf("Empty List\n");
    }
        while(current != NULL)
    {

        fprintf(input,"%d;%s;%s;%d;%s;%d\n",
               current->id,
               current->title,
               current->autname,
               current->year,
               current->category,
               current->where);
        current = current->next;
    }
}

