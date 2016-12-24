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
    stack s1;
    stack s2;
    int size;
};
void enqueue(queue& q,int x)
{
    if(q.s1.top+1==q.s1.size)
        cout <<"Full\n";
    else
    {
       q.s1.elements[q.s1.top+1]=x;
       q.s1.top++;
       q.size++;
    }
}
int  dequeue(queue& q)
{

    if(q.s1.top==-1)
        cout <<"Empty\n";
    else
    {
        q.s2.size=10000;
        q.s2.top=-1;
        while(q.s1.top!=0)
        {
            push(q.s2,pop(q.s1));
        }
        int garbage=pop(q.s1);
        while(q.s2.top!=-1)
        {
            push(q.s1,pop(q.s2));
        }
        q.size--;
        return garbage;
    }
}
int main()
{
    queue Q;
    Q.s1.top=-1;
    Q.s1.size=10000;
    Q.size=0;

    int N;
    cin >>N;

    while(N--)
    {
        int temp;
        cin >> temp;
        enqueue(Q,temp);
    }
    dequeue(Q);
    dequeue(Q);
    enqueue(Q,5);

    while(Q.size!=0)
        cout <<dequeue(Q)<<" ";


    return 0;

}
