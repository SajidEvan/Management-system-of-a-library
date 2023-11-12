#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "splash.h"
#include "login.h"
#include "menu.h"


void displaySplashScreen() {
    FILE* file = fopen("splash.txt", "r");

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
        Sleep(1);
    }
    fclose(file);
    system("cls");
}


void login() {
    char password[10], username[10];
    int i = 0;
    char username1[10] = "Sajid";
    char password1[10] = "87654321";
    char ch;
    char pwd[30];

    printf("\nEnter user name : ");
    gets(username);
    printf("\nEnter 8 digit password:");

    while ((ch = _getch()) != 13)
    {
        pwd[i++] = ch;
        printf("*");
    }
    pwd[i] = '\0';

    if (strcmp(username, username1) == 0 && strcmp(pwd, password1) == 0)
    {
        printf("\nLogin successful\n");
    }
    else
    {
        printf("\nPassword incorrect. Try again\nGood bye");
        exit(0);
    }
}

void addBook()
{
    struct Book book;
    FILE* fp;

    fp = fopen("library.txt", "a");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return;
    }
    fflush(stdin);
    printf("\nEnter Book Title: ");
    gets(book.title);
    fflush(stdin);
    printf("Enter Author Name: ");
    gets(book.author);

    printf("Enter Publication Year: ");
    scanf("%d", &book.year);

    fprintf(fp, "%s\t%s\t%d\n", book.title, book.author, book.year);

    fclose(fp);

    printf("\nBook added successfully!\n");
}

void displayBooks()
{
    struct Book book;
    FILE* fp;

    fp = fopen("library.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    printf("\nList of Books:\n");
    printf("Title\tAuthor\tPublication Year\n");

    while (fscanf(fp, "%s", book.title) != EOF)
    {
        fscanf(fp, "\t%s\t%d\n", book.author, &book.year);
        printf("%s\t%s\t%d\n", book.title, book.author, book.year);
    }

    fclose(fp);
}

void searchBook()
{
    char searchTitle[50];
    struct Book book;
    FILE* fp;

    fp = fopen("library.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    printf("\nEnter Book Title to search: ");
    scanf(" %s", searchTitle);

    while (fscanf(fp, " %s", book.title) != EOF)
    {
        fscanf(fp, "\t%s\t%d\n", book.author, &book.year);

        if (strcmp(book.title, searchTitle) == 0)
        {
            printf("\nBook Found!\n");
            printf("Title: %s\n", book.title);
            printf("Author: %s\n", book.author);
            printf("Publication Year: %d\n", book.year);
            fclose(fp);
            return;
        }
    }

    fclose(fp);
    printf("\nBook not found.\n");
}

void deleteBook()
{
    char title[100];
    struct Book book;
    FILE* file, * tempFile;
    int deleted = 0;

    printf("\nEnter the Title of the Book to delete: ");
    scanf(" %s", title);

    file = fopen("library.txt", "r");
    tempFile = fopen("temp.txt", "w");

    if (file == NULL || tempFile == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    while (fscanf(file, "%s\t%s\t%d\n", book.title, book.author, &book.year) != EOF)
    {
        if (strcmp(book.title, title) == 0)
        {
            deleted = 1;
            continue;
        }

        fprintf(tempFile, "%s\t%s\t%d\n", book.title, book.author, book.year);
    }

    fclose(file);
    fclose(tempFile);

    if (deleted)
    {
        remove("library.txt");
        rename("temp.txt", "library.txt");
        printf("Book deleted successfully.\n");
    }
    else
    {
        remove("temp.txt");
        printf("Book not found.\n");
    }
}


int main()
{
    displaySplashScreen();

    char password[10], username[10];
    int i=0;
    int flag=0;
    char username1[10]="Sajid";
    char password1[10]="87654321";
    char ch;
    char pwd[30];

    printf("\nEnter user name : ");
    gets(username);
    printf("\nEnter 8 digit password:");
    while((ch= _getch())!=13)
    {
        pwd[i] = ch;
        i++;
        printf("*");
    }
    pwd[i]='\0';

    if (strcmp(username,username1)==0 && strcmp(pwd,password1)==0)
    {
        printf("\nLogin successful\n");
    }
    else
    {
        printf("\nPassword incorrect.Try again\nGood bye");
        return 0;
    }

    int choice;

    while (1)
    {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Delete book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            addBook();
            break;
        case 2:
            displayBooks();
            break;
        case 3:
            searchBook();
            break;
        case 4:
            deleteBook();
            break;
        case 5:
            printf("Exiting the program...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
