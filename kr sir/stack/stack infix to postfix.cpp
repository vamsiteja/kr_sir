#include <iostream>
#include <string>
using namespace std;
struct charstack
{
    char top;
    int size;
    int max_size;
    char elements[100001];
};
void push(charstack& s,char x)
{
    if(s.size==s.max_size)
        return;
    else
    {
        s.size++;
        s.elements[s.size-1]=x;
    }

}
char pop(charstack& s)
{
    if(s.size==0)
        return '-1';
    else
    {
        s.size--;
        return s.elements[s.size];
    }
}
char top(charstack& s)
{
    if(s.size==0)
        return '-1';
    else
    {
        return s.elements[s.size-1];
    }
}
int return_num(char x)
{
    switch(x)
    {
        case '+':return 1;
        break;
        case '-':return 2;
        break;
        case '*':return 3;
        break;
        case '/':return 4;
        break;
        return 0;
    }
}
int main()
{
    charstack S;
    S.size=0;
    S.max_size=100000;
    char arrayop[4]={'+','-','*','/'};
    cout<<"enter the string"<<endl;
    string p;
    cin >>p;

    int i,len=p.length();

    int flag=1;
    for(i=0;i<len;i++)
    {

         if(p[i]>='0' && p[i]<='9')
            cout <<p[i];
         else if( return_num(p[i]) )
         {
             char x=top(S);
             if(x=='-1')
             {
              push(S,p[i]);
             }
             else
             {
                 if(p[i]=='+' ||  p[i]=='-')
                 {
                     while(S.size!=0)
                     {
                         cout <<pop(S);
                     }
                     push(S,p[i]);
                 }
                 else if(p[i]=='*' ||  p[i]=='/')
                 {

                     while(top(S)=='*' || top(S)=='/')
                     {
                         cout <<pop(S);
                     }
                     push(S,p[i]);
                 }
             }

         }
    }

    while(S.size!=0)
        cout <<pop(S);



    return 0;
}
