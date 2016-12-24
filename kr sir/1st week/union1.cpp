
#include <iostream>
#include <string>
using namespace std;
union adr
{
    long int sec_num;
    long long int  mobile;
};
struct std1
{
    int roll_num;
    string name;
    union adr address;
    float gpa;
    int tag;
};
int main()
{
    struct std1 s[10];
    int i;

    for(i=1;i<=2;i++)
    {
        cin >>s[i].roll_num;
        cin >>s[i].name;
        cin >>s[i].tag;
        if(s[i].tag==1)
            cin >>s[i].address.sec_num;
        else
            cin >>s[i].address.mobile;
    }

    for(i=1;i<=2;i++)
    {
        cout <<s[i].roll_num<<endl;
         cout <<s[i].name<<endl;
         /*cout <<s[i].address.tag<<endl;*/
        if(s[i].tag==1)
             cout <<s[i].address.sec_num<<endl;
        else
             cout <<s[i].address.mobile<<endl;
    }

    return 0;

}
