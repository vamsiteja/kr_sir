#include <iostream>
using namespace std;
struct stack
{
    int size;
    int top;
    int elements[100001];

};
void push(stack& s,int x)
{
    if(s.top+1==s.size)
        cout <<"Full\n";
    else
    {
        s.elements[s.top+1]=x;
        s.top=s.top+1;
    }
}
int pop(stack& s)
{
    if(s.top==-1)
        cout <<"Empty\n";
    else
    {
         int x=s.elements[s.top];
         s.top--;
         return x;
    }
}
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
int main()
{
    queue Q;
    Q.size=10000;
    Q.front=-1;
    Q.rear=-1;
cout<<"enter the number of elements in queue"<<endl;
    int N;
    cin >>N;
    while(N--)
    {
        int temp;
        cin >>temp;
        enqueue(Q,temp);
    }

    stack S;
    S.size=100000;
    S.top=-1;


    while(Q.front!=-1)
    {
        int x=dequeue(Q);
        push(S,x);

    }


    while(S.top!=-1)
    {
        enqueue(Q,pop(S));
    }

    while(Q.front!=-1)
    {
        cout <<dequeue(Q)<<" ";
    }
    cout <<endl;

    return 0;

}
