#include<iostream>
using namespace std;
struct multill
{
    int tag;
    multill *next;
    union u
    {
        multill *down;
        char ch;
    }data;
};
typedef multill * mulptr;
void print(mulptr& l)
{
    cout<<"(";
    mulptr t=l;
    while(t!=NULL)
    {
        if(t->tag==0)
            {cout<<(t->data).ch;
		      if(t->next!=NULL)
			  cout<<",";
			}
        else
            print((t->data).down);
        t=t->next;
    }
    cout<<")";
    
}
void create(mulptr& l)
{
    cout<<"enter no elements of set:"<<endl;
    int d;
    cin>>d;
    while(d--)
    if(l==NULL)
    {   cout<<"enter the tag for data"<<endl;
        l=new multill;
        cin>>l->tag;
        l->next=NULL;
        if(l->tag==0)
            {cin>>(l->data).ch;}
        else
            {
			(l->data).down=NULL;
			create((l->data).down);
			cout<<"new set writing completed";
			}
    }
    else
    {
        mulptr t=l;
        while(t->next!=NULL)
            t=t->next;
        t->next=new multill;
        t=t->next;
		cout<<"entr the tag for data"<<endl;
        cin>>t->tag;
        t->next=NULL;
        if(t->tag==0)
            {cin>>(t->data).ch;}
        else
            {(t->data).down=NULL;
			create((t->data).down);
			cout<<"new set writing completed";}
    }
}
int main()
{
    mulptr l=NULL;
    create(l);
    print(l);
    return 0;
}
