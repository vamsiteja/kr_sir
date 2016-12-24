#include<iostream>
using namespace std;

struct node
{
int data;
node *next;
};
int arr_size;
int div=1;
int max_size;

int getmod(int n)
{
int x;
x=((n/div)%10);
return x;
}

void enqueue(node** header,int key)
{

node *newnode;
newnode=new node;
newnode->next=NULL;
newnode->data=key;
if((*header)==NULL)
{
*header=newnode;}
else
{
node* ptr=(*header);
while(ptr->next!=NULL)
ptr=ptr->next;
ptr->next=newnode;

}
}

int dequeue(node** header)
{int k;

if((*header)->next==NULL)
{k=(*header)->data;
  (*header)=NULL;
}
else{

    k=(*header)->data;*header=(*header)->next;
   }

return(k);

}

void radixsort(int a[],int size)
{
int t;
int j=-1;
node* r[10];


for(int k=0;k<max_size;k++)
{j=-1;
     	for(int s=0;s<10;s++)
          {
		    r[s]=NULL;
		  }
     for(int i=0;i<size;i++)
     {
         t=getmod(a[i]);
          enqueue(&r[t],a[i]);
     }   

          for(int i=0;i<10;i++)
           {

               while(r[i]!=NULL)
               {
                    j++;
                    a[j]=dequeue(&r[i]);
                }
            }   
              div=div*10;
}
cout<<endl;
for(int l=0;l<arr_size;l++)
  {cout<<a[l]<<" ";
  }
}

int main()
{
int a[100];
cout<<"enter the maximum digit size\n";
cin>>max_size;
cout<<"enter the max input array  size\n";
cin>>arr_size;
cout<<"enter the numbers you wish to sort\n";
for(int i=0;i<arr_size;i++)
cin>>a[i];
radixsort(a,arr_size);
return 0;
}
