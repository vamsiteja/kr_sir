#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
int main()
{
	int d,num;
	node *P,*T,*S,*D,*R;
	P=new node;
	S=P;
	cout<<"Enter the data , when done type -1;"<<endl;
	cin>>d;
	P->data=d;
	P->next=NULL;
	cin>>d;
	while(d!=-1)
	{
		T=new node;
		T->data=d;
		T->next=NULL;
		P->next=T;
		P=T;
		cin>>d;
	}
	P=S;
	cout<<"Enter the element you want to delete";
	cin>>num;
	while(P->next->data!=num)
	{
		P=P->next;
	}
	D=P->next->next;
	R=P->next;
	P->next=D;
	delete R;
	P=S;
	while(P!=NULL)
	{
		cout<<P->data;
		P=P->next;
	}
	return 0;
	
}
