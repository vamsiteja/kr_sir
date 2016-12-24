
#include <iostream>
using namespace std;
const int max_size=100000;
class stackv
{
public:
    int sizef();
    bool isEmpty();
    int topelement();
    void push(int data);
    void pop();
    stackv();
private:
    int a[max_size];
    int size;
};

int stackv::sizef()
{
    return size;
}
bool stackv::isEmpty()
{
    if(size!=0)
        return false;
    else
        return true;
}

int stackv::topelement()
{
    if(size==0)
    {
        cout <<"No element NULL ";
        return NULL;

    }
    else
        return a[size];
}

void stackv::push(int data)
{
    if(size==max_size)
        cout <<"Stack is full\n";
    else
    {
        a[size+1]=data;
        size++;
    }
}

void stackv::pop()
{

    if(size==0)
        cout <<"Stack is Empty\n";
    else
    {
        a[size]=NULL;
        size--;
    }
}
stackv::stackv()
{
    size=0;
}
int main()
{
    stackv a;
    cout <<a.sizef()<<endl;
    a.push(5);
    cout <<a.sizef()<<endl;
    a.push(4);
    cout <<a.topelement()<<endl;
    a.pop();
    cout <<a.topelement()<<endl;
    a.pop();
    a.pop();
    int x=a.topelement();
    cout <<x<<endl;
    return 0;
}

