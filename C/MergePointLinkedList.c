#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
int findMergeNode(struct Node* head1, struct Node* head2) {
    struct Node* p = head1;
    struct Node* q = head2;
    int i;
    int c1=0, c2=0;
    while(p!=NULL) {
        c1++;
        p=p->next;
    }
    while(q!=NULL) {
        c2++;
        q=q->next;
    }
    p = head1;
    q = head2;
    if(c1 > c2) {
        for(i =0 ;i < c1 - c2 ;i++) {
            p = p->next;
        }
    }
    else {
        for(i=0 ; i < c2 - c1 ; i++) {
            q = q->next;
        }
    }
    while(p!=NULL && q!=NULL) {
        if(p == q) {
            return p->data;
        }
        else {
            p = p->next;
            q = q->next;
        }
    }
    return 0;
}
  int main()  {
    /*
    Create two linked lists

    1st 3->6->9->15->30
    2nd 10->15->30

    15 is the intersection point
  */

    struct Node* newNode;
    struct Node* head1 = (struct Node*)malloc(sizeof(struct Node));
    head1->data = 10;

    struct Node* head2 = (struct Node*)malloc(sizeof(struct Node));
    head2->data = 3;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = 6;
    head2->next = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = 9;
    head2->next->next = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = 15;
    head1->next = newNode;
    head2->next->next->next = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = 30;
    head1->next->next = newNode;
    int mergepoint = findMergeNode(head1, head2);
    printf("%d",mergepoint);
    getchar();
}
