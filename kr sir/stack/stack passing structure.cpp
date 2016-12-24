#include <iostream>
#include <string>
using namespace std;
struct node
{
    string name;
    int roll_num;
};
struct nodestack
{
    int size;
    int max_size;
    node top;
    node elements[100001];
};
void push(nodestack& s,node x)
{
    if(s.size==s.max_size)
        cout <<"Stack is Empty\n";
    else
    {
        s.size++;
        s.elements[s.size-1]=x;
    }
}
node pop(nodestack& s)
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
{
    nodestack S;
    S.size=0;
    S.max_size=100000;int a;cout<<"enter the number of students records u want to eneter"<<endl;
    cin>>a;node x;

    cout <<"Enter data\n";

    
    for(int i=0;i<a;i++)
    {
        cin >>x.roll_num;
        if(x.roll_num!=0)
            {cin >>x.name;
             push(S,x);
            }
    }


    while(S.size!=0)
    {
        node y=pop(S);
        cout <<y.roll_num<<" "<<y.name<<endl;
    }

    return 0;

}
