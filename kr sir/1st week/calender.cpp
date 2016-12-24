#include <iostream>
using namespace std;
void printMonth(int month)
{
    switch(month)
    {
        case 1:cout <<"January\n";
        break;
        case 2:cout <<"February\n";
        break;
        case 3:cout <<"March\n";
        break;
        case 4:cout <<"April\n";
        break;
        case 5:cout <<"May\n";
        break;
        case 6:cout <<"June\n";
        break;
        case 7:cout <<"July\n";
        break;
        case 8:cout <<"August\n";
        break;
        case 9:cout <<"September\n";
        break;
        case 10:cout <<"October\n";
        break;
        case 11:cout <<"November\n";
        break;
        case 12:cout <<"December\n";

    }


}
void printDay(int day)
{

         switch(day)
        {

        case 1:cout <<"Mon\t";
        break;
        case 2:cout <<"Tue\t";
        break;
        case 3:cout <<"Wed\t";
        break;
        case 4:cout <<"Thurs\t";
        break;
        case 5:cout <<"Fri\t";
        break;
        case 6:cout <<"Sat\t";
        break;
        case 7:cout <<"Sun\t";
        break;

        }
}
void printNum(int month,int day1)
{

    int days,i,j;
    if(month==4 || month==6 || month==9 || month==11)
    days=30;
    else if(month==2)
    days=29;
    else
    days=31;

    if(day1==0)
        day1=7;

        printMonth(month);
        for(i=1;i<=7;i++)
        {
            printDay(i);
            if(i<day1)
            {
                cout <<"  ";
                for(j=7-day1+1+i;j<=days;j=j+7)
                    cout <<j<<"  ";
                cout <<endl;
            }
            else
            {
                for(j=i-day1+1;j<=days;j=j+7)
                    cout <<j<<"  ";
                cout <<endl;
            }

        }
        cout <<endl;
        cout <<endl;
        if(month<12)
        printNum(month+1,(days+day1)%7);

}
int main()
{
    printNum(1,1);
    return 0;
}

