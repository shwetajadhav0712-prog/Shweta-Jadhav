#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
    struct Student* next;
};

struct Student* create(int r, char n[], float m) {
    struct Student* s = (struct Student*)malloc(sizeof(struct Student));
    s->roll = r;
    strcpy(s->name, n);
    s->marks = m;
    s->next = NULL;
    return s;
}

void insert(struct Student** head, int r, char n[], float m) {
    struct Student* s = create(r, n, m);
    if (*head == NULL) *head = s;
    else {
        struct Student* t = *head;
        while (t->next) t = t->next;
        t->next = s;
    }
}

void display(struct Student* head) {
    printf("\n--- Student Records ---\n");
    while (head) {
        printf("Roll: %d | Name: %s | Marks: %.2f\n", head->roll, head->name, head->marks);
        head = head->next;
    }
}

int main() {
    struct Student* head = NULL;
    int ch, r; char n[50]; float m;

    while (1) {
        printf("\n1.Insert  2.Display  3.Exit\nEnter choice: ");
        scanf("%d", &ch);
        if (ch == 1) {
            printf("Enter Roll, Name, Marks: ");
            scanf("%d %s %f", &r, n, &m);
            insert(&head, r, n, m);
        } 
        else if (ch == 2) display(head);
        else if (ch == 3) break;
        else printf("Invalid choice!\n");
    }
    return 0;
}
