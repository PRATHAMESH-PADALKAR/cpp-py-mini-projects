#include<iostream>
#include<windows.h>
using namespace std;

int main()
{
    int h,m,s,a,err;
    err=a=0;
    while(err==0)
    {
        //cout<<"entre hour:"<<endl;
        //cin>>h;
        cout<<"entre minutes:"<<endl;
        cin>>m;
        cout<<"entre seconds:"<<endl;
        cin>>s;
        if(h<24 && m<60 && s<60)
        err++;
        else
        system("cls");

    }
    while(a==0)
    {
        system("cls");
        cout<<h<<":"<<m<<":"<<s<<endl;
        Sleep(1000);
        s--;
        if(s<1)
        {
            s=60;
            m--;
            if (m<=0)
            break;
        }
        /*if(m==0)
        {
            //m=0;
            exit;

            //h++;
        }
        if(h>24)
        {
            h=0;

        }*/
    }
    return 0;
}