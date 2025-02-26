#include "StudentLinkedList.h"
#include "debugmalloc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

studentdata_t *readStudentsFromFile(FILE *input)
{
    int ret;
    studentdata_t *studentlist= NULL;
    studentdata_t *current;

    while((ret= readOneStudentFromFile(&current, input))==1)
    {
         appendStudentToFrontOfList(&studentlist, current);
    }
    if(ret!=1)
    {
        freeStudent(current);
    }
    return studentlist;
}

void freeAllStudents(studentdata_t *studentlist)
{
    studentdata_t *current = NULL;
    while((current=studentlist) != NULL)
    {
        studentlist=studentlist->next;
        free(current->name);
        free(current->phonenum);
        free(current);
    }
}


void appendStudentToFrontOfList(studentdata_t **studentlist, studentdata_t *current)
{
    if(*studentlist == NULL)
    {
        *studentlist = current;
    }
    else
    {
        studentdata_t *temp = *studentlist;
        *studentlist = current;
        current->next = temp;
    }
}

int readOneStudentFromFile(studentdata_t **studentFromList, FILE *input)
{
    *studentFromList = (studentdata_t*)malloc(sizeof(studentdata_t));

    if(*studentFromList==NULL)
    {
        return -1;
    }
    (*studentFromList)->name=NULL;
    (*studentFromList)->phonenum=NULL;


    if(fscanf(input, "%d;", &(*studentFromList)->id)== EOF)
    {
        return 0;
    }

    (*studentFromList)->name = readStringInputFromFile(input);
    if(  (*studentFromList)->name==0)
    {
        return 0;
    }


    (*studentFromList)->phonenum = readStringInputFromFile(input);
    if(  (*studentFromList)->phonenum==0)
    {
        return 0;
    }


    (*studentFromList)->next=NULL;

    return 1;
}

char *readStringFromFile(FILE *input)
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


void freeStudent(studentdata_t *studentlist)
{
    if(studentlist==NULL)
    {
        return;
    }
    free(studentlist->name);
    free(studentlist->phonenum);

    free(studentlist);
}

void printListofStudents(studentdata_t *studentlist)
{
    studentdata_t *current=studentlist;
    if(current==NULL)
    {
        printf("Empty List\n");
    }
    while(current != NULL)
    {
        printf("%d;%s;%s\n",
               current->id,
               current->name,
               current->phonenum);
        current = current->next;
    }
}

void printStudentListIntoFile(studentdata_t *studentlist, FILE *input)
{
    studentdata_t *current=studentlist;
    if(current==NULL)
    {
        printf("Empty List\n");
    }

        while(current != NULL)
    {
        fprintf(input,"%d;%s;%s\n",
               current->id,
               current->name,
               current->phonenum);
        current = current->next;
    }
}



