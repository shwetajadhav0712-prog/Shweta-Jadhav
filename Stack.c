#include <stdio.h>
#include <string.h>
#define MAX 5

char stack[MAX][50];
int top = -1;

void push(char book[]) {
    if (top == MAX - 1)
        printf("Stack Overflow! Cannot add more books.\n");
    else {
        ++top;
        strcpy(stack[top], book);
        printf("Book '%s' added to the library.\n", book);
    }
}

void pop() {
    if (top == -1)
        printf("Stack Underflow! No book to remove.\n");
    else {
        printf("Book '%s' removed from library.\n", stack[top]);
        --top;
    }
}

void peek() {
    if (top == -1)
        printf("No books in the library.\n");
    else
        printf("Top book: %s\n", stack[top]);
}

void display() {
    if (top == -1)
        printf("No books in the library.\n");
    else {
        printf("\nBooks in library:\n");
        for (int i = top; i >= 0; i--)
            printf("%d. %s\n", i + 1, stack[i]);
    }
}

int main() {
    int choice;
    char book[50];

    while (1) {
        printf("\n1.Add Book  2.Remove Book  3.View Top Book  4.Display All  5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // clear buffer

        switch (choice) {
            case 1:
                printf("Enter book name: ");
                gets(book);
                push(book);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
