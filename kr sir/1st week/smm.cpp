#include <iostream>
using namespace std;
void smm(int& sum,int& max1,int& min1,int i,int a[])
{
    if(i==1)
    {
        sum+=a[i];
        if(a[i]>max1)
            max1=a[i];
        if(a[i]<min1)
            min1=a[i];
    }
    else
    {
        sum+=a[i];
        if(a[i]>max1)
            max1=a[i];
        if(a[i]<min1)
            min1=a[i];
        smm(sum,max1,min1,i-1,a);
    }
}
int main()
{
    int sum=0,i,max1,min1,N;
    int a[100001];

    cin >>N;
    for(i=1;i<=N;i++)
        cin >>a[i];

    max1=a[N];min1=a[N];
    smm(sum,max1,min1,N,a);
    cout <<sum<<" "<<max1<<" "<<min1<<endl;
    return 0;
}

