#include <iostream>
using namespace std;
const int max_size=5;
class queuev
{
public:
    void enqueue(int data);
    void dequeue();
    int frontelement();
    int sizef();
    bool isEmpty();
    queuev();

private:
    int a[max_size];
    int start;
    int end;
    int size;
} ;

int queuev::sizef()
{
  return size;
}

bool queuev::isEmpty()
{
    int temp_size=(max_size+end-start)%max_size;
    if(temp_size==0)
        return true;
    else
        return false;
}

int queuev::frontelement()
{
    return a[start];
}

void queuev::enqueue(int data)
{

    if(size==max_size)
        cout <<"Queue is full\n";
    else
    {

    a[end%max_size]=data;
    end++;
    end=end%max_size;
    }
    size=(max_size+end-start)%max_size;
    if(start==end && a[start]!=NULL)
        size=max_size;
}

void queuev::dequeue()
{
    if(size==0)
    {
        cout <<"Queue is Empty\n";
    }
    else
    {
    a[start%max_size]=NULL;
    start++;
    start=start%max_size;
    }
    size=(max_size+end-start)%max_size;
    if(start==end && a[start]!=NULL)
        size=max_size;
}

queuev::queuev()
{
    start=0;
    end=0;
    size=(max_size+end-start)%max_size;
}

int main()
{
     queuev a;
     cout <<a.sizef()<<endl;
     a.enqueue(5);
     cout <<a.sizef()<<endl;
     a.enqueue(4);
     cout<<a.frontelement()<<endl;
     a.dequeue();
     cout <<a.frontelement()<<endl;
     cout <<a.sizef()<<endl;

     a.enqueue(3);
     a.enqueue(2);
     a.enqueue(1000);
     a.enqueue(1);

     cout <<a.frontelement()<<" ";
     cout <<a.sizef();


     return 0;
}

