#include <iostream>
using namespace std;
struct glnode
{
    int data;
    int count;
    struct glnode** next;
};
struct queue
{
    int front;
    int rear;
    int size;
    int elements[100001];
};
typedef struct glnode* glptr;
void enqueue(queue& Q,int x)
{
    if((Q.rear+1)%Q.size==Q.front%Q.size)
        cout <<"Full\n";
    else
    {
        Q.elements[Q.rear+1]=x;
        Q.rear++;
        if(Q.front==-1)
            Q.front=0;
    }
}
int dequeue(queue& Q)
{
    if(Q.front==-1)
        cout <<"Empty\n";
    else
    {
       int x=Q.elements[Q.front];
       if(Q.front==Q.rear)
       {
           Q.front=-1;
           Q.rear=-1;
       }
       else
        Q.front++;
        return x;
    }
}
void create(glptr* s,int q)
{
    cout <<"Enter data and number of edges\n";
    int x,y;
    cin >>x>>y;
    glptr t=*s;
    t->next[q]=new glnode;
    t=t->next[q];
    t->next=new glptr[y+1];
    t->data=x;
    t->count=y;

    if(y!=0)
    {
        for(int i=0;i<y;i++)
        create(&t,i);
    }
    else
        {t->next[0]=NULL;
         return;
        }
}

void searcht(glptr start,int val,bool& ans)
{
    if(start->data==val)
        {
            ans=true;
            return;
        }
    else
    {
       for(int i=0;i<start->count;i++)
       {
           searcht(start->next[i],val,ans);
       }
    }
}
void PrintPathtoGoal(glptr start,int val)
{

    bool ans=false;
    searcht(start,val,ans);
    if(ans==false)
        return;
    else
    {
        cout <<start->data<<" ";
        for(int y=0;y<start->count;y++)
            PrintPathtoGoal(start->next[y],val);
    }
}
int main()
{
    struct glnode* s;
    s=new glnode;
    s->data=-1;
    s->count=0;
    s->next=new glptr[1];

    create(&s,0);

    glptr start=s->next[0];
    cout <<"Enter Goal\n";
    int val;
	cin >>val;

    PrintPathtoGoal(start,val);

    return 0;
}
