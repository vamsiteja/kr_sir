#include<iostream>
using namespace std;

 
struct node
{
    int data;
    struct node* next;
};
 

void sortedInsert(struct node**, struct node*);
void insertionSort(struct node **head_ref)
{
    struct node *sorted = NULL;
 
    
    struct node *current = *head_ref;
    while (current != NULL)
    {
	  struct node *next = current->next;
      sortedInsert(&sorted, current);
      current = next;
    }
       *head_ref = sorted;
}
void sortedInsert(struct node** head_ref, struct node* new_node)
{  struct node* current;
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else
    {
       current = *head_ref;
        while (current->next!=NULL &&
               current->next->data < new_node->data)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}
void printList(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        cout<< temp->data<<" ";
        temp = temp->next;
    }
}
 
void push(struct node** head_ref, int new_data)
{
   struct node* new_node = new node;
     new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
 
 

int main()
{int n,k;
    struct node *a = NULL;
    cout<<"enter the number of elements in linked list"<<endl;
    cin>>n;cout<<"enter the elements"<<endl;
    for(int i=0;i<n;i++)
      {cin>>k;push(&a,k);
	
      } 
    cout<<"linked list before sorting"<<endl;
    printList(a);
 
    insertionSort(&a);
 
    cout<<"linked list after sorting\n";
    printList(a);
 
    return 0;
}
