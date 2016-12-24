#include<iostream>
#include<conio.h>
using namespace std;
class queue
{public:
      int size;
      int element[50];
      int front;
      int rear;
      
      queue()
      {size=50;
             front=-1;
             rear=-1;
      }
      queue(int s)
      {
                size=s;
                front=-1;
                rear=-1;
}
         int full()
         {if((rear+1)%size==front)
                              { cout<<"queue is full";
                               return 1;}
                               else return 0;
                               }
           int empty()
           {
               if(front==-1)
               {
                            cout<<"\nqueue is empty";
                            return 1;}
                            else return 0;
                            }
                  void enque(int p)
                  {
                       if(full())
                       cout<<"full";
                       else
                       {rear=(rear+1)%size;
                       element[rear]=p;
                           if(front==-1)  
                          front=front+1;
                          }
                          }
                      int deque()
                          {int c=front;
                          if(rear!=front)
                          {front=(front+1)%size;
                          return element[c];}
                          else if(!empty()&&front==rear)
                          {front=-1;
                          rear=-1;
                          return element[c];
                          }
                          }
                          };
 int main()
 {
 	queue q;char b[100],o[100];int i,k,s,l,a,m;
 	cout<<"enter the postfix expression";
 	cin>>b;
 	for(i=0;b[i]!='\0';i++)
 	{
 		if(b[i]>='0'&&b[i]<='9')
 		q.enque(b[i]-48);
 		else
 		{    k=0;
 			while(k!=((q.front+q.rear+1)-2))
 			{
 				a=q.deque();
 				q.enque(a);
 			}
 				l=q.deque();m=q.deque();
 			switch(b[i])
 			{
 			    case '*':q.enque(l*m);break;
 			    case '+':q.enque(l+m);break;
 			    case '-':q.enque(l-m);break;
 			    case '/':q.enque(l/m);break;
 			    
 			}
 		}
 	}
   cout<<q.deque();
   return 0;
 }                         

