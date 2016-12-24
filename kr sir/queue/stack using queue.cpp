#include <iostream>
using namespace std;
struct queue
{
    int size;
    int front;
    int rear;
    int elements[100001];
};
void enqueue(queue& q,int x)
{
    if( (q.rear+1)%q.size==q.front%q.size)
        cout <<"Full\n";
    else
    {
        q.elements[ (q.rear+1)%q.size]=x;
        q.rear=(q.rear+1)%q.size;
        if(q.front==-1)
            q.front=0;
    }
}
int  dequeue(queue& q)
{
    if(q.front==-1 && q.rear==-1)
        cout <<"Empty\n";
    else
    {
        int t=q.elements[q.front];
        if(q.front==q.rear)
        {
                   q.front=-1;
                   q.rear=-1;
        }
        else
            q.front=(q.front+1)%q.size;
        return t;
    }
}
struct stack
{
    int size;
    queue q;
};
void push(stack& s,int x)
{
    if(s.size==s.q.size)
        cout <<"Full\n";
    else
    {
        s.q.elements[(s.q.rear+1)%s.q.size]=x;
        s.q.rear=(s.q.rear+1)%s.q.size;
        if(s.q.front==-1)
            s.q.front=0;
        s.size++;
    }
}
int pop(stack& s)
{
    if(s.size==0)
        cout <<"Empty\n";
    else
    {
         int x=s.q.elements[s.q.rear];
         s.q.rear=(s.q.rear-1);
         if(s.q.rear==-1)
            s.q.front=-1;
        s.size--;
         return x;
    }
}

int main()
{
    stack S;
    S.size=0;
    S.q.front=-1;
    S.q.rear=-1;
    S.q.size=10;

cout<<"enter the number of elements in queue"<<endl;
    int N;
    cin >>N;
    while(N--)
    {
        int temp;
        cin >>temp;
        push(S,temp);
    }

    
    

    while(S.size!=0)
        cout <<pop(S)<<" ";

    cout <<endl;

    return 0;

}
