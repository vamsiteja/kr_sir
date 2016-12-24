#include <iostream>
#include <cstring>
using namespace std;
char a1[1001];
char a2[1001];
bool vis[1001];
int pos[10001];
struct btnode
{
    int x;
    int y;
    char data;
    struct btnode* lc;
    struct btnode* rc;
};
typedef struct btnode* btptr;
void PrintDLR(btptr t)
{
    if(t==NULL)
        return;
    else
    {
        cout <<t->data<<" ";
        PrintDLR(t->lc);
        PrintDLR(t->rc);
    }
}
void PrintLRD(btptr t)
{
    if(t==NULL)
        return;
    else
    {
        PrintLRD(t->lc);
        PrintLRD(t->rc);
        cout <<t->data<<" ";
    }
}
void PrintLDR(btptr t)
{
    if(t==NULL)
        return;
    else
    {
        PrintLDR(t->lc);
        cout <<t->data<<" ";
        PrintLDR(t->rc);
    }
}
void FindTree(int low,int high,btptr& t,int i,int len)
{

    if(low==high)
    {
        t=new btnode;
        t->data=a2[i];
        t->lc=NULL;
        t->rc=NULL;
        vis[i]=true;
        return;
    }

    if(i<0)
        return;

    t=new btnode;
    t->data=a2[i];
    vis[i]=true;

    int mid;
    for(int j=0;j<=len;j++)
    {
        if(a1[j]==a2[i])
        {
            mid=j;
            break;
        }
    }

    if(mid+1>high)
    t->rc=NULL;
    else
    FindTree(mid+1,high,t->rc,i-1,len);

    if(low>mid-1)
    t->lc=NULL;
    else
    {
        int j;
        for(j=i;j>=0;j--)
        {
            if(vis[j]==false)
                break;
        }
        FindTree(low,mid-1,t->lc,j,len);
    }
}
int main()
{
    cout <<"Enter LDR and LRD\n";
    cin.getline(a1,1001);
    cin.getline(a2,1001);

    for(int i=0;i<=10001;i++)
        vis[i]=false;

    btptr t=NULL;
    int len=strlen(a1);

    FindTree(0,len-1,t,len-1,len-1);

    PrintLDR(t);
    cout <<endl;
    PrintDLR(t);
    cout <<endl;
    PrintLRD(t);
    cout <<endl;

    return 0;
}
