#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* addTwoLists(struct Node* first, struct Node* second) {
    struct Node* res = NULL;
    struct Node* temp, * prev = NULL;
    int carry = 0, sum;

    while (first != NULL || second != NULL) {
        sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = sum;
        temp->next = NULL;
        if (res == NULL)
            res = temp;
        else
            prev->next = temp;
        prev = temp;
        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }
    if (carry > 0) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = carry;
        temp->next = NULL;
        prev->next = temp;
    }
    return res;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct Node* first = NULL;
    struct Node* second = NULL;

    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = 4;
    first->next = (struct Node*)malloc(sizeof(struct Node));
    first->next->data = 6;
    first->next->next = (struct Node*)malloc(sizeof(struct Node));
    first->next->next->data = 6;
    first->next->next->next = NULL;

    second = (struct Node*)malloc(sizeof(struct Node));
    second->data = 3;
    second->next = (struct Node*)malloc(sizeof(struct Node));
    second->next->data = 4;
    second->next->next = (struct Node*)malloc(sizeof(struct Node));
    second->next->next->data = 2;
    second->next->next->next = NULL;

    printf("Birinci baðlantýlý liste: ");
    printList(first);
    printf("\nÝkinci baðlantýlý liste: ");
    printList(second);

    struct Node* res = addTwoLists(first, second);
    printf("\nSonuç Listesi: ");
    printList(res);

    return 0;
}

