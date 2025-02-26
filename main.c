#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "StudentLinkedList.h"
#include "CoreFunctions.h"
#include "debugmalloc.h"
#include "BookManagementFunctions.h"
#include "StudentManagementFunctions.h"
#include "SearchFunctions.h"



int mainmenu(){
    system("cls");
    printf("Library management\n\n");
    printf("Please select an option: \n");
    printf("-------------------------\n");
    printf("1. Student management\n");
    printf("2. Book management\n");
    printf("0. Exit application\n\n");

    printf("Please enter a number and hit ENTER: ");

    int ret;

     switch(getc(stdin))
    {
        case '1':
            system("cls");
            stLoadindScreen();
            while((ret=studentmanagement())==3)
            {
            }
            break;
        case '2':
            system("cls");
            bookLoadindScreen();
           while((ret=bookmanagement())==2)
            {
            }
            break;
        case '0':
            system("cls");
            credits();
            ret=0;
            break;
        default:
            printf("Error!: Invalid input, try again in a few seconds");
            Sleep(2000);
            ret=1;
    }
    fflush(stdin);
    return ret;
}

int studentmanagement(){
    system("cls");
    fflush(stdin);
    printf("Student management page\n\n");
    printf("Please select an option: \n");
    printf("-------------------------\n");
    printf(" 1. Add Student \n");
    printf(" 2. Modify Student \n");
    printf(" 3. Rented books \n");
    printf(" 4. Back to Main Menu \n");
    printf(" 0. Exit application \n\n");
    printf("Please enter a number and hit ENTER: ");

    int ret;
     switch(getc(stdin))
    {
    case '1':
        ret=addStudent();
        break;
    case '2':
        ret=modifyStudent();
        break;
    case '3':
        ret=rentedbyStudent();
        break;
    case '4':
        //goes back to main menu
        ret=1;
        break;
    case '0':
        //returns 0 = exit the main loop
        system("cls");
        credits();
        ret=0;
        break;
    default:
        printf("Error!: Invalid input, try again in a few seconds");
        Sleep(2000);
        ret=3;

    }
    return ret;
}

int bookmanagement(){
    system("cls");
    fflush(stdin);
    printf("Book management page\n\n");
    printf("Please select an option: \n");
    printf("-------------------------\n");
    printf(" 1. Add Book \n");
    printf(" 2. Modify Book Record \n");
    printf(" 3. List Books \n");
    printf(" 4. Rent Book \n");
    printf(" 5. List Rentals \n");
    printf(" 6. Book availability \n");
    printf(" 7. Search for book \n");
    printf(" 8. Delete book \n");
    printf(" 9. Back to main menu \n");
    printf(" 0. Exit application \n\n");
    printf("Please enter a number and hit ENTER: ");

    int ret;

     switch(getc(stdin))
    {
    case '1':
        ret =addBook();
        break;
    case '2':
        ret=modifyBook();
        break;
    case '3':
        ret=listBook();
        break;
    case '4':
        ret=rentBook();
        break;
    case '5':
        ret=listRentals();
        break;
    case '6':
        ret=bookAvailability();
        break;
    case '7':
        system("cls");
        searchLoadingScreen();
        while((ret=searchBook())==4)
        {
        }
        break;
    case '8':
        ret=deleteBook();
        break;
    case '9':
        //returns to main menu
        ret=1;
        break;
    case '0':
        //exits the program
        system("cls");
        credits();
        ret=0;
        break;
    default:
        printf("Error!: Invalid input, try again in a few seconds");
        Sleep(2000);
        ret=2;

    }
    return ret;
}

int searchBook(){
    system("cls");
    fflush(stdin);
    printf("Search for specific book\n\n");
    printf("Please select an option: \n");
    printf("-------------------------\n");
    printf(" 1. Search by ID \n");
    printf(" 2. Search by Author \n");
    printf(" 3. Search by Title \n");
    printf(" 4. Search by Year \n");
    printf(" 5. Search by Category \n");
    printf(" 6. Back to book management page \n");
    printf(" 0. Exit application \n\n");
    printf("Please enter a number and hit ENTER: ");

    int ret;

     switch(getc(stdin))
    {
    case '1':
        ret=searchbyID();
        break;
    case '2':
        ret=searchbyAuthor();
        break;
    case '3':
        ret=searchbyTitle();
        break;
    case '4':
        ret=searchbyYear();
        break;
    case '5':
        ret=searchbyCategory();
        break;
    case '6':
        system("cls");
        bookLoadindScreen();
        ret=2;
        break;
    case '0':
        system("cls");
        credits();
        ret=0;
        break;
    default:
        printf("Error!: Invalid input, try again in a few seconds");
        Sleep(2000);
       ret=4;
    }
    return ret;
}

int main(){

    mainScreen();
    getch();
     //return: 1: main menu
        //0 ends program
        //-1 error->exit
        //2 bookmanagement
        //3 studentmanagement
        //4 searchBook

    while(mainmenu()==1)
    {
    }

    return 0;
}
