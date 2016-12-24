#include <iostream>
#include <string>
using namespace std;
struct charstack
{
    char top;
    int size;
    int max_size;
    int  elements[10001];
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
int pop(charstack& s)
{
    if(s.size==0)
        return '-1';
    else
    {
        s.size--;
        return s.elements[s.size];
    }
}
int main()
{
    charstack S;
    S.size=0;
    S.max_size=1000;

    string p;
    cin >>p;

    int i,len=p.length();

    int flag=1;
    for(i=0;i<len;i++)
    {

        if(p[i]=='(' || p[i]=='{' || p[i]=='[')
            push(S,p[i]);
        else
        {
            if(p[i]==')')
            {
                char x=pop(S);
                if(x!='(')
                flag=0;
            }
            else if(p[i]=='}')
            {
                char x=pop(S);
                if(x!='{')
                flag=0;
            }
            else if(p[i]==']')
            {
                char x=pop(S);
                if(x!='[')
                flag=0;
            }
        }

    }

    if(S.size==0 && flag!=0)
        cout <<"Yes\n";
    else
        cout <<"No\n";


    return 0;
}
