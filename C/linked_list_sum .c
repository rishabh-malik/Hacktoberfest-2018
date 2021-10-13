#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node * next;
}NODE;
void printList(NODE* head){
    NODE* ptr=head;
    if(head==NULL)
        return;
    while(ptr!=NULL){
        if(ptr!=head)
            printf("->");
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}//Fuction used to print the linked list
NODE* createNode(int dt){
    NODE* n=(NODE*)malloc(sizeof(NODE));
    n->data=dt;
    n->next=NULL;
    return n;
}//Function that creates and returns a pointer to a NODE
NODE* input(int n){
    NODE* head=NULL,*tail=NULL,*pt;
    int num;
    for(int i=0;i<n;i++){
        scanf("%d",&num);
        pt=createNode(num);
        if(head==NULL)
            head=tail=pt;
        else{
            tail->next=pt;
            tail=pt;
        }
    }
    return head;
}//function that takes in the input in the form of a linked list and returns the head
NODE* solve(NODE*);
NODE* reverse(NODE *);
NODE* add(NODE*,NODE*);
NODE* trim(NODE *);
int main(){
    int n;
    scanf("%d",&n);
    NODE* head=input(n);
    printList(solve(head));
    return 0;
}
NODE* solve(NODE* A){
    NODE* t=createNode(-1),*p=t,*q=t,*t1,*t2;
    t->next=A;
    while(p&&p->next){
        p=p->next->next;
        if(p==NULL)
            break;
        q=q->next;
    }
    t2=q->next;
    q->next=NULL;
    t1=t->next;
    free(t);
    return add(reverse(t1),reverse(t2));
}
NODE* reverse(NODE *A){
    if(A==NULL)
        return A;
    NODE* prev=NULL,*pt=A,*npt=A->next;
    while(npt!=NULL){
        pt->next=prev;
        prev=pt;
        pt=npt;
        npt=npt->next;
    }
    pt->next=prev;
    return pt;
}
NODE* add(NODE* A,NODE* B){
    if(A==NULL&&B==NULL)
        return NULL;
    if(A==NULL){
       return trim(B); 
    }
    if(B==NULL){
       return trim(A); 
    }
    int x,y=0;
    NODE* ptr1=A,*ptr2=B,*head=NULL,*hPt;
    while(ptr1!=NULL&&ptr2!=NULL){
        x=ptr1->data+ptr2->data+y;
        y=x/10;
        if(head==NULL)
            head=hPt=createNode(x%10);
        else{
            hPt->next=createNode(x%10);
            hPt=hPt->next;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;  
    }
    if(ptr1==NULL){
        while(ptr2!=NULL){
            x=ptr2->data+y;
            y=x/10;
            hPt->next=createNode(x%10);
            hPt=hPt->next;
            ptr2=ptr2->next;
        }
    }
    if(y!=0)
        hPt->next=createNode(y);
    free(A);
    free(B);
    return reverse(trim(head));
}
NODE* trim(NODE * A){
    if(A==NULL)
        return A;
    NODE* ptr=A,* end=A;
    while(ptr!=NULL){
        if(ptr->data!=0)
            end=ptr;
        ptr=ptr->next;
    }
    end->next=NULL;
    return A;
}
