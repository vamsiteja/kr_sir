#include <iostream>
#include <string>
using namespace std;
struct intstack
{
    int size;
    int max_size;
    int elements[100001];
};
void push(intstack& s,int x)
{
    if(s.size==s.max_size)
        return;
    else
    {
        s.size++;
        s.elements[s.size-1]=x;
    }

}
int  pop(intstack& s)
{
    if(s.size==0)
        cout <<"Stack is Empty\n";
    else
    {
       s.size--;
       return s.elements[s.size];
    }
}
int main()
{   cout<<"enter the string of postfix"<<endl;
     string a;
     cin >>a;
     int i,len=a.length();


     intstack s1;
     s1.size=0;
     s1.max_size=10000;

     for(i=0;i<len;i++)
     {
         if(a[i]>='0' && a[i]<='9')
            {   int y=(int)a[i]-48;
                push(s1,y);
            }
        else
        {
          switch(a[i])
          {
           case '+':
               {int x1=pop(s1);
               int x2=pop(s1);
               push(s1,x1+x2);
               break;
               }
           case '-':
               {int x1=pop(s1);
               int x2=pop(s1);
               push(s1,x2-x1);
               break;
               }
           case '*':
               {int x1=pop(s1);
               int x2=pop(s1);
               push(s1,x1*x2);
               break;
               }
            case '/':
               {int x1=pop(s1);
               int x2=pop(s1);
               push(s1,x2/x1);
               break;
               }
          }

        }

     }

     while(s1.size!=0)
        cout <<pop(s1)<<" ";


     return 0;


}
