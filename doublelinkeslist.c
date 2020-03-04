/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>
struct node
{
    int x;
    struct node* next;
    struct node* prev;
};
struct node* head;
struct node* getnode(int x)
{
    struct node* new = (struct node*) malloc(sizeof(struct node));
    new->x=x;
    new->next=NULL;
    new->prev=NULL;
    return new;
}
void insertathead(int x)
{
    struct node* new=getnode(x);
    if(head==NULL)
    {
        head=new;
        return;
    }
    head->prev=new;
    new->next=head;
    head=new;
}
void inserttail(int x)
{
    struct node* new=getnode(x);
    if(head==NULL){
         head=new;
        return;
    }
    struct node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new;
    new->prev=temp;
}
void print()
{
    struct node*temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->x);
        temp=temp->next;
    }
    printf("\n");
}
void rprint()
{
    struct node*temp=head;
    if(temp==NULL) return;
    while(temp->next !=NULL)
    {
        temp=temp->next;
    }
    while(temp != NULL)
    {
       printf("%d ",temp->x);
      temp=temp->prev;
     
    }
    printf("\n");
}
int main()
{
    head=NULL;
   insertathead(5);
   insertathead(8);
   insertathead(7);
   inserttail(10);
   print();
   rprint();

    return 0;
}
