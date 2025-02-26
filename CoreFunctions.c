#include "CoreFunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "debugmalloc.h"
#include "LinkedList.h"
#include "StudentLinkedList.h"

int bookIdCheck(int givenID){
    FILE *fc = fopen("Book_Records.txt", "rt");
    if(fc== NULL)
    {
        perror("ERROR");
        return -1;
    }

    bookdata_t *listOfBooks=readBooksFromFile(fc);
    bookdata_t *current=listOfBooks;
    if(listOfBooks==NULL)
    {
        return -1;
    }

   fclose(fc);

    while(current != NULL)
    {
        if(current->id==givenID)
        {
            freeAllBooks(listOfBooks);
            return 1;
        }
        current=current->next;
    }
    freeAllBooks(listOfBooks);
    return 0;
}

int studentIdCheck(int givenID){
    FILE *fc = fopen("Student_Records.txt", "rt");
    if(fc== NULL)
    {
        perror("ERROR");
        return -1;
    }

    studentdata_t *listOfStudents=readStudentsFromFile(fc);
    studentdata_t *current=listOfStudents;
    if(listOfStudents==NULL)
    {
        return -1;
    }

   fclose(fc);

    while(current != NULL)
    {
        if(current->id==givenID)
        {
            freeAllStudents(listOfStudents);
            return 1;
        }
        current=current->next;
    }
    freeAllStudents(listOfStudents);
    return 0;
}

char *readStringFromStdin(void){
    char *prev_string_version= NULL;
    char *string=NULL;
    size_t lengthOfString=0;
    int c;

    do
    {
        c = getchar();
        if(c== EOF || c=='\n')
        {
            c='\0';
        }
        prev_string_version = string;
        lengthOfString++;
        string= malloc(lengthOfString);

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

int studentExists(int givenid){
    FILE *fc = fopen("Student_Records.txt", "rt");
    if(fc== NULL)
    {
        perror("ERROR");
        return -1;
    }
    studentdata_t *listOfStudents=readStudentsFromFile(fc);
    studentdata_t *current=listOfStudents;
    if(listOfStudents==NULL)
    {
        return -1;
    }
    while(current!=NULL)
    {
        if(current->id==givenid)
        {
            freeAllStudents(listOfStudents);
            return 0;
        }
        current=current->next;
    }
    freeAllStudents(listOfStudents);
    return 1;
}

void printStudent(int studentid){
    FILE *fc = fopen("Student_Records.txt", "rt");
    if(fc== NULL)
    {
        perror("ERROR");
        return -1;
    }
    studentdata_t *listOfStudents=readStudentsFromFile(fc);
    studentdata_t *current=listOfStudents;
    if(listOfStudents==NULL)
    {
        return -1;
    }
    while(current!=NULL)
    {
        if(current->id==studentid)
        {
            printf("%s (id: %d)\n", current->name, current->id);
            break;
        }
        current=current->next;
    }
    freeAllStudents(listOfStudents);
}

int deleteContentsOfBookFile(){
    FILE *ft = fopen("Book_Records.txt", "w+");
    if(ft== NULL)
    {
        perror("ERROR");
        return -1;
    }
    fclose(ft);
    return 0;
}

void saveBookDataIntoFile(bookdata_t *listOfBooks){
     if((deleteContentsOfBookFile())==0){
        FILE *fw = fopen("Book_Records.txt", "at");
        if(fw== NULL)
        {
            perror("ERROR");
            return -1;
        }

    printListIntoFile(listOfBooks,fw);
    fclose(fw);
    }
}

int deleteContentsOfStudentFile(){
    FILE *ft = fopen("Student_Records.txt", "w+");
    if(ft== NULL)
    {
        perror("ERROR");
        return -1;
    }
    fclose(ft);
    return 0;
}

void saveStudentDataIntoFile(studentdata_t *listOfStudents){
     if((deleteContentsOfStudentFile())==0){
        FILE *fw = fopen("Student_Records.txt", "at+");
        if(fw== NULL)
        {
            perror("ERROR");
            return -1;
        }

    printStudentListIntoFile(listOfStudents,fw);
    fclose(fw);
    }
}

void printOneBook(bookdata_t *current){
    printf("=========================\nBook's id: %d\nBook's Title: %s\nBook's Author: %s\nYear of publication: %d\nBook's Category: %s\nBook's Location: %d\n=========================\n\n",
               current->id,
               current->title,
               current->autname,
               current->year,
               current->category,
               current->where);

}

void credits(){

printf("    _________________     _________________\n");
printf("  /|                  \\ /                  |\\\n");
printf(" /||                   |                   ||\\\n");
printf("||||                   |                   ||||\n");
printf("||||   Thank you for   |    Created By:    ||||\n");
printf("||||                   |                   ||||\n");
printf("||||      using my     |    Fodor Attila   ||||\n");
printf("||||                   |                   ||||\n");
printf("||||    library app    |     BME 2022      ||||\n");
printf("||||                   |                   ||||\n");
printf("||||                   |                   ||||\n");
printf("||||                   |                   ||||\n");
printf("||||__________________ | __________________||||\n");
printf("||/===================\\|/===================\\||\n");
printf("''-------------------~___~-------------------''\n");

}

void stLoadindScreen(){

printf("      ////^\\\\\\\\\n");
printf("      | ~   ~ |     ___________________\n");
printf("     ( (o) (o) )   /                   |\n");
printf("      |   <   |   /  Loading student   |\n");
printf("      |  __,  |  <   management page   |\n");
printf("       \\_____/     \\___________________|\n");
printf("      ___| |___\n");
printf("     /  \\_:_/  \\\n");
printf("    /           \\\n");
printf("   /\\/|       |\\/\\\n");
printf("  / / |       | \\ \\\n");
printf(" ( <  |       |  > ) \n");
printf("  \\\\  |       |  //\n");
printf("   \\\\ |_______| //\n");
printf("    \\\\|===E===|\n");

    printf("\n      ");
        for (int i=0;i<10;i++)
    {
        printf(":");
        Sleep(300);
    }
}

void mainScreen(){

printf("           _____________________________________________________ \n");
printf("  ________|                    _          _                     |________  \n");
printf("  \\       |                   |_)  |\\/|  |_                     |       /  \n");
printf("   \\      |                   |_)  |  |  |_                     |      /   \n");
printf("   /      |_____________________________________________________|      \\   \n");
printf("  /__________)|.'',         Welcome to my library       ,''.|(__________\\\n");
printf("              |.'.'',                                 ,''.'.|\n");
printf("              |.'.'.'',         Press a key         ,''.'.'.|\n");
printf("              |.'.'.'.'',     to get started      ,''.'.'.'.|\n");
printf("              |.'.'.'.'.|                         |.'.'.'.'.|\n");
printf("              |.'.'.'.'.|===:                 :===|.'.'.'.'.|\n");
printf("              |.'.'.'.'.|:::|',             ,'|:::|.'.'.'.'.|\n");
printf("              |.'.'.'.'.|---|'.|   _____   |.'|---|.'.'.'.'.|\n");
printf("              |.'.'.'.'.|:::|'.|  |!!!!!|  |.'|:::|.'.'.'.'.|\n");
printf("              |,',',',',|---|',|  |=====|  |,'|---|,',',',',|\n");
printf("              |.'.'.'.'.|:::|'.|  |+++++|  |.'|:::|.'.'.'.'.|\n");
printf("              |.'.'.'.'.|---|','   /000\\   ','|---|.'.'.'.'.|\n");
printf("              |.'.'.'.'.|===:'    /00000\\    ':===|.'.'.'.'.|\n");
printf("              |.'.'.'.'.|0000000000000000000000000|.'.'.'.'.|\n");
printf("              |.'.'.'.','       /000000000\\       ','.'.'.'.|\n");
printf("              |.'.'.','        /00000000000\\        ','.'.'.|\n");
printf("              |.'.','         /0000000000000\\         ','.'.|\n");
printf("              |.','          /000000000000000\\          ','.|\n");
printf("              |;____________/00000000000000000\\____________;|\n");


}

void bookLoadindScreen(){

printf("      ////^\\\\\\\\\n");
printf("      | ~   ~ |     ___________________\n");
printf("     ( (o) (o) )   /                   |\n");
printf("      |   <   |   /  Loading book      |\n");
printf("      |  __,  |  <   management page   |\n");
printf("       \\_____/     \\___________________|\n");
printf("      ___| |___\n");
printf("     /  \\_:_/  \\\n");
printf("    /           \\\n");
printf("   /\\/|       |\\/\\\n");
printf("  / / |       | \\ \\\n");
printf(" ( <  |       |  > ) \n");
printf("  \\\\  |       |  //\n");
printf("   \\\\ |_______| //\n");
printf("    \\\\|===E===|\n");

        printf("\n     ");
        for (int i=0;i<10;i++)
    {
        printf(":");
        Sleep(300);
    }
}

void searchLoadingScreen(){
printf("            ______ \n");
printf("         .-'      `-.   \n");
printf("       .'            `.      \n");
printf("      /    Loading     \\        \n");
printf("     ;    Search for   ;`       \n");
printf("     |     Book page   |;       \n");
printf("     ;                 ;|\n");
printf("     '\\               / ;     \n");
printf("      \\`.           .' /        \n");
printf("       `.`-._____.-' .'         \n");
printf("         / /`_____.-'           \n");
printf("        / / /                   \n");
printf("       / / /\n");
printf("      / / /\n");
printf("     / / /\n");
printf("    / / /\n");
printf("   / / /\n");
printf("   \\/_/\n");

    printf("\n      ");
        for (int i=0;i<10;i++)
    {
        printf(":");
        Sleep(300);
    }

}
