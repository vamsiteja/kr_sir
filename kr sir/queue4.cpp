#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;
string stringconvert(int x)
{
    if(x/10==0)
    {

        switch(x)
        {
            case 0:return "0";
            case 1:return "1";
            case 2:return "2";
            case 3:return "3";
            case 4:return "4";
            case 5:return "5";
            case 6:return "6";
            case 7:return "7";
            case 8:return "8";
            case 9:return "9";
        }
    }
    else
    {
        return stringconvert(x/10)+stringconvert(x%10);
    }
}
int numberconvert(string x)
{
    int ans=0;
    int len=x.length();
    for(int i=0;i<x.length();i++)
        ans+=pow(10,len-i-1)*((int)x[i]-48);
    return ans;
}
struct queue
{
    int size;
    int front;
    int rear;
    string elements[10001];
};

void enqueue(queue& q,string  x)
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
string dequeue(queue& q)
{
    if(q.front==-1 && q.rear==-1)
        cout <<"Empty\n";
    else
    {
        string t=q.elements[q.front];
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
    Q.size=1000;
    Q.front=-1;
    Q.rear=-1;
    cout<<"enter the infix string"<<endl;
    string a;
    cin >>a;
    int len=a.length(),i;

    for(i=0;i<len;i++)
    {
        string x( 1, a[i]);
        enqueue(Q,x);
    }

    for(int k=0;k<2;k++)
    {
        int size1=(Q.rear-Q.front+Q.size)%Q.size+1;
        int x1=-1,x2=-1;
        string x1s="-1",x2s="-1";
        string  op="-1";

        size1=size1/2;
        while(size1--)
        {
           string q1=dequeue(Q);
           string q2=dequeue(Q);
           if(x1==-1 && op=="-1")
           {
               int num=numberconvert(q1);
               x1=num;
               x1s=q1;
               op=q2;
           }
           else
           {
               int num=numberconvert(q1);
               x2=num;
               x2s=q1;

               if(q2=="/")
               {
                   enqueue(Q,x1s);
                   enqueue(Q,op);
                   x1s=x2s;
                   x1=x2;

                   x2s="-1";
                   x2=-1;
                   op=q2;
               }
               else if(q2=="*")
               {

                   if(op=="/")
                   {
                       x1=x1/x2;
                       x1s=stringconvert(x1);
                       x2=-1;
                       x2s="-1";
                       op=q2;
                   }
                   else
                   {

                   enqueue(Q,x1s);
                   enqueue(Q,op);
                   x1s=x2s;
                   x1=x2;
                   x2s="-1";
                   x2=-1;
                   op=q2;

                   }

               }
               else
               {
                   if(op=="+" || op=="-")
                   {enqueue(Q,x1s);
                   enqueue(Q,op);
                   x1s=x2s;
                   x1=x2;
                   x2s="-1";
                   x2=-1;
                   op=q2;
                   }
                   else
                   {
                       if(op=="/")
                       x1=x1/x2;
                       else
                       x1=x1*x2;

                       x1s=stringconvert(x1);
                       x2s="-1";
                       x2=-1;
                       op=q2;
                   }
               }
           }

        }

        string q=dequeue(Q);
        x2s=q;
        x2=numberconvert(x2s);
        int ans;
        char op1=op[0];
        
        {
            case '*':ans=x1*x2;
            break;
            case '/':ans=x1/x2;
            break;
        }
        if(op1=='+' || op1=='-')
        {enqueue(Q,x1s);
        enqueue(Q,op);
        enqueue(Q,x2s);}
        else
        enqueue(Q,stringconvert(ans));

        x1s="-1";x1=-1;x2s="-1";x2=-1;
        op="-1";
    }

    string x1=dequeue(Q);
    int ans=numberconvert(x1);
    while(Q.front!=-1)
    {
        string x2=dequeue(Q);
        string x3=dequeue(Q);
        if(x2=="+")
            ans=ans+numberconvert(x3);
        else
            ans=ans-numberconvert(x3);
    }


    cout <<ans<<endl;

    return 0;

}
