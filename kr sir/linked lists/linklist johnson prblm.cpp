#include <iostream>
#include <cstdlib>
using namespace std;
struct node1
{
    int data;
    struct node* front;
    struct node* rear;
};
typedef struct node* lptr;
void addEnd(lptr* t,int d)
{
    lptr temp=*t;
    temp->front=new node;
    temp=temp->front;
    temp->data=d;
    temp->front=NULL;
    temp->rear=*t;
    *t=temp;
}
void deleteAfter(lptr* t)
{
    (*t)->front=((*t)->front)->front;
    (*t)->front->rear=*t;
}
lptr movelist  (lptr l,int count)
{
    lptr last=l;
    while(count--)
    {
        last=last->front;
    }

    return last;
}
int main()
{
    int N,d;
    lptr head=new node,tail;cout<<"enter the number of numbers u want to enter"<<endl;
    cin >>N;

    for(int i=0;i<N;i++)
    {
        cin >>d;
        if(i==0)
        {
            head->data=d;
            head->front=NULL;
            tail=head;
        }
        else if(i<N-1)
        {
            addEnd(&tail,d);
        }
        else if(i==N-1)
        {
            lptr temp=tail;
            tail->front=new node;
            tail=tail->front;
            tail->data=d;
            tail->front=head;
            tail->rear=temp;
            head->rear=tail;
        }
    }
       lptr temp=head;
     while(temp->front!=temp)
     {
        int random=rand()%10+1;
        cout <<"random value= "<<random<<" "<<endl;
        lptr T=movelist(temp,random);
        temp=T->front;
        deleteAfter(&(T->rear));
     }

    cout <<endl;
    cout <<temp->data<<endl;

    return 0;
}
