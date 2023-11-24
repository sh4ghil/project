#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[100];
    char author[100];
    int quantity;
};

void addBook(struct Book *books, int *n) {
    int newID;
    printf("Enter the ID of the new book: ");
    scanf("%d", &newID);

    for (int i = 0; i < *n; i++) {
        if (books[i].id == newID) {
            printf("Book with ID %d already exists.\n", newID);
            return;
        }
    }

    books[*n].id = newID;
    printf("Enter the title of the book: ");
    fgets(books[*n].title, sizeof(books[*n].title), stdin);
    books[*n].title[strcspn(books[*n].title, "\n")] = '\0';

    printf("Enter the author of the book: ");
    fgets(books[*n].author, sizeof(books[*n].author), stdin);
    books[*n].author[strcspn(books[*n].author, "\n")] = '\0';

    printf("Enter the quantity of the book: ");
    scanf("%d", &books[*n].quantity);

    (*n)++;
    printf("Book added successfully.\n");
}

void printBooks(struct Book *books, int n) {
    printf("ID | Title | Author | Quantity\n");
    for (int i = 0; i < n; i++) {
        printf("%d | %s | %s | %d\n", books[i].id, books[i].title, books[i].author, books[i].quantity);
    }
}

int main() {
    struct Book books[100];
    int n = 0;

    while (1) {
        int choice;
        printf("\n1. Add Book\n2. Print Books\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(books, &n);
                break;
            case 2:
                printBooks(books, n);
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}