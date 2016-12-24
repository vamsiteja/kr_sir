#include <iostream>
using namespace std;
struct poly
{
    int c;
    int e;
};
struct node
{
    poly data;
    struct node* next;
};
typedef struct node* lptr;
void addEnd(lptr* L,poly d)
{
    lptr t=*L;
    while(t->next!=NULL)
    {
        t=t->next;
    }
    t->next=new node;
    t=t->next;
    t->data=d;
    t->next=NULL;
}
lptr addPoly(lptr L1,lptr L2)
{
    lptr T1=L1,T2=L2;
    lptr L=new node;
    int flag=1;
    while(T1!=NULL && T2!=NULL)
    {
        if(T1->data.e>T2->data.e)
        {
            if(flag==1)
            {
                L->data=T1->data;
                L->next=NULL;
                flag=0;
            }
            else
            addEnd(&L,T1->data);
            T1=T1->next;
        }
        else if(T2->data.e > T1->data.e)
        {
            if(flag==1)
            {
                L->data=T2->data;
                L->next=NULL;
                flag=0;
            }
            else
            addEnd(&L,T2->data);
            T2=T2->next;
        }
        else
        {
            poly temp;
            temp.c=T1->data.c+T2->data.c;
            temp.e=T1->data.e;
            if(flag==1)
            {
                L->data=temp;
                L->next=NULL;
                flag=0;
            }
            else
            addEnd(&L,temp);
                T2=T2->next;
                T1=T1->next;
        }
    }


    while(T1!=NULL)
    {
        if(flag==1)
            {
                L->data=T1->data;
                L->next=NULL;
                flag=0;
            }
            else
            addEnd(&L,T1->data);
        T1=T1->next;

    }

    while(T2!=NULL)
    {

        if(flag==1)
            {
                L->data=T2->data;
                L->next=NULL;
                flag=0;
            }
            else
            addEnd(&L,T2->data);
        T2=T2->next;
    }


    return L;

}
int main()
{
    int N1,N2;
    int c,e;
    lptr L1,L2;
cout<<"enter the number of terms of the polynomial"<<endl;
    cin >>N1;
    cout <<"Enter coff and exp of poly1\n";
    L1=new node;
    cin >>c>>e;
    L1->data.c=c;
    L1->data.e=e;
    L1->next=NULL;
    N1--;

    while(N1--)
    {
        poly d;
        cin >>d.c>>d.e;
        addEnd(&L1,d);
    }
cout<<"enter the number of elements of second polynomial"<<endl;
    cin >>N2;
    cout <<"Enter coff and exp of poly2\n";
    L2=new node;
    cin >>c>>e;
    L2->data.c=c;
    L2->data.e=e;
    L2->next=NULL;
    N2--;

    while(N2--)
    {
        poly d;
        cin >>d.c>>d.e;
        addEnd(&L2,d);
    }
    lptr L=addPoly(L1,L2);

    while(L!=NULL)
    {
        cout <<L->data.c<<"x"<<L->data.e<<endl;
        L=L->next;
    }

    return 0;
}
