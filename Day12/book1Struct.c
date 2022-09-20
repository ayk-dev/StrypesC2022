#include <stdio.h>
#include <string.h>

struct Book {
    char title[100];
    char author[100];
    int pages;
    double price;
};

void printInfo(struct Book b);
void getData(struct Book * b);

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

    struct Book b3;
    struct Book * p = &b3;
    getData(p);
    printf("===========================\n");
    printInfo(b3);
    
    return 0;
}

void printInfo(struct Book b) {
    printf("Title: %s\n", b.title);
    printf("Author: %s\n", b.author);
    printf("Pages: %d\n", b.pages);
    printf("Price: %.2flv.\n", b.price);
}

void getData(struct Book * b) {
    printf("Enter title: \n");
    fgets((*b).title, 100, stdin);
    (*b).title[strlen((*b).title) - 1] = '\0';
    printf("Enter author: \n");
    fgets((*b).author, 100, stdin);
    (*b).author[strlen((*b).author) - 1] = '\0';
    printf("Enter pages: \n");
    scanf("%d", &((*b).pages));
    printf("Enter price: \n");
    scanf("%lf", &((*b).price));
}