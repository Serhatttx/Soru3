#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    struct Node temp;
    struct Node* dummy = &temp;
    dummy->next = NULL;
    while (head1 && head2) {
        if (head1->data < head2->data) {
            dummy->next = head1;
            head1 = head1->next;
        }
        else {
            dummy->next = head2;
            head2 = head2->next;
        }
        dummy = dummy->next;
    }
    dummy->next = head1 ? head1 : head2;
    return temp.next;
}

int main() {
    struct Node s1 = { 1, NULL };
    struct Node s2 = { 3, NULL };
    struct Node s3 = { 5, NULL };
    s1.next = &s2;
    s2.next = &s3;

    struct Node d1 = { 2, NULL };
    struct Node d2 = { 4, NULL };
    struct Node d3 = { 6, NULL };
    d1.next = &d2;
    d2.next = &d3;

    struct Node* mergedList = mergeLists(&s1, &d1);
    while (mergedList) {
        printf("%d ", mergedList->data);
        mergedList = mergedList->next;
    }
    return 0;
}