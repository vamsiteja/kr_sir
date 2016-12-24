#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node* front;
    struct node* rear;
};
typedef struct node* lptr;
void printList(lptr L)
{
    lptr T=L;
    if(T==NULL)
    cout<<"no intersection\n";
    while(T!=NULL)
    {
        cout <<T->data<<" ";
        T=T->front;
    }
    cout <<endl;
}
void addEnd(lptr* L,int d)
{
    lptr T=*L;
    while(T->front!=NULL)
        T=T->front;

      T->front=new node;
     (T->front)->rear=T;
     (T->front)->front=NULL;
     (T->front)->data=d;
}
void addBegin(lptr* L,int d)
{

    lptr temp=*L;
    (*L)=new node;
    (*L)->data=d;
    (*L)->rear=NULL;
    (*L)->front=temp;
    temp->rear=*L;
}
void addAfter(lptr* T,int d )
{
    lptr temp1=(*T)->front;
    lptr temp2=new node;

    temp2->data=d;
    (*T)->front=temp2;
    temp2->front=temp1;
    temp2->rear=(*T);
    temp1->rear=temp2;
}
void deleteAfter(lptr* T)
{

    lptr temp=*T;
    (*T)->front=(temp->front)->front;
    if((*T)->front!=NULL)
    {
        lptr temp2=(*T)->front;
        temp2->rear=(*T);
    }

}
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

void  IntersectionList(lptr L1,lptr L2)
{

    lptr T1,T2,L;
    T1=L1;T2=L2;
   L=NULL;
    int flag=1;
    while(T1!=NULL && T2!=NULL)
    {

      if(T1->data > T2->data)
            T2=T2->front;
      else if(T2->data > T1->data)
            T1=T1->front;
           else
            {
               if(flag==1)
             { L=new node;
              L->data=T1->data;
              L->front=NULL;
              L->rear=NULL;
              flag=0;
             }
               else
               addEnd(&L,T1->data);
               T1=T1->front;
                T2=T2->front;
            }

    }

    cout <<"Intersection\n";
    printList(L);

}

void UnionList(lptr L1,lptr L2)
{

       lptr T1=L1,T2=L2;
    lptr L=new node;
    int flag=1;
    while(T1!=NULL && T2!=NULL)
    {
        if(T1->data < T2->data)
        {
            if(flag==1)
            {
                L->data=T1->data;
                L->front=NULL;
                flag=0;
            }
            else
            addEnd(&L,T1->data);
            T1=T1->front;
        }
        else if(T2->data < T1->data)
        {
            if(flag==1)
            {
                L->data=T2->data;
                L->front=NULL;
                flag=0;
            }
            else
            addEnd(&L,T2->data);
            T2=T2->front;
        }
        else
        {
            if(flag==1)
            {
                L->data=T1->data;
                L->front=NULL;
                flag=0;
            }
            else
            addEnd(&L,T1->data);
                T2=T2->front;
                T1=T1->front;
        }
    }


    while(T1!=NULL)
    {
        if(flag==1)
            {
                L->data=T1->data;
                L->front=NULL;
                flag=0;
            }
            else
            addEnd(&L,T1->data);
        T1=T1->front;

    }

    while(T2!=NULL)
    {

        if(flag==1)
            {
                L->data=T2->data;
                L->front=NULL;
                flag=0;
            }
            else
            addEnd(&L,T2->data);
        T2=T2->front;
    }

    cout <<"Union\n";
    printList(L);

}
int main()
{
    int N1,d,N2;
    cout <<"List 1\n";
    cout<<"enter the number of elements in list1\n";
    cin >>N1;cout<<"enter the elements\n";
    cin >>d;
    lptr L1=new node;
    lptr L2=new node;

    L1->data=d;
    L1->front=NULL;
    L1->rear=NULL;
    N1--;

    while(N1--)
    {
        cin >>d;
        addEnd(&L1,d);
    }
    listsorting(&L1);


    cout <<"List 2\n";cout<<"enter the number of elements in list2\n";
    cin >>N2;cout<<"enter the elements\n";
    cin >>d;

    L2->data=d;
    L2->front=NULL;
    L2->rear=NULL;
    N2--;

    while(N2--)
    {
        cin >>d;
        addEnd(&L2,d);
    }
    listsorting(&L2);

    IntersectionList(L1,L2);
   UnionList(L1,L2);

    return 0;

}
