#include <iostream>

using namespace std;

struct node{
    int data;
    node* next;
};
void insert(node** head,int value)
{
    node* temp = new node();
    temp->data=value;
    temp->next= *head;
    *head=temp;
    
    
}
void search(node* head,int x)
{
    node* temp = head;
   
    while(temp->next!=NULL)
    {
      if(temp->data==x)
    {
        cout<<"found"<<endl;
        return;
    }
     temp=temp->next;  
    }
}
void print(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<endl;
        head=head->next;
    }
}

int main()
{
    node* head=NULL;
    insert(&head,1);
    insert(&head,2);
    insert(&head,3);
    search(head,2);
    print(head);

    return 0;
}
