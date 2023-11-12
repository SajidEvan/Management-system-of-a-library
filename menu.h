#ifndef MENU_H
#define MENU_H

struct Book
{
    char title[50];
    char author[50];
    int year;
};

void addBook();
void displayBooks();
void searchBook();
void deleteBook();

#endif // MENU_H
