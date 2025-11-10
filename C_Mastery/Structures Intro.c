// A Structure Example using Books
#include <stdio.h>
#include <string.h>

//Defining the structure.
struct Book{
    char title[50];
    char author[50];
    int pages;
    float price;
    int year;
};

int main(){

    struct Book book1;// Declare a Structure Variable

    strcpy(book1.title, "Heads Up C");
    strcpy(book1.author, "Asif Ahamed S");
    book1.pages = 300;
    book1.price = 299.99;
    book1.year = 2028;


    //basic print members and data.

    printf("Book Information: \n");
    printf("Book Title: %s\n",book1.title);
    printf("Book Author: %s\n", book1.author);
    printf("Total Pages: %d\n",book1.pages);
    printf("Cost price: %.2f\n",book1.price);
    printf("Published Year: %d\n",book1.year);

    return 0;
}
