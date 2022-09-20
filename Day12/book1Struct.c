#include <stdio.h>
#include <string.h>

struct Book {
    char title[100];
    char author[100];
    int pages;
    double price;
};

void printInfo(struct Book b);

int main(){
    struct Book b1;
    strcpy(b1.title, "Code Complete 2nd Edition");
    strcpy(b1.author, "Steve McConnel");
    b1.pages = 914;
    b1.price = 106.6806;
    printInfo(b1);

    struct Book b2 = {
        .title = "Clean Code",
        .author = "Robert C. Martin",
        .pages = 431,
        .price = 96.9806
    };
    printf("===========================\n");
    printInfo(b2);

    return 0;
}

void printInfo(struct Book b) {
    printf("Title: %s\n", b.title);
    printf("Author: %s\n", b.author);
    printf("Pages: %d\n", b.pages);
    printf("Price: %.2flv.\n", b.price);
}