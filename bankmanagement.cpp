#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;

class bank 
{
    char name[100],add[100],y;
    int balance;
    public:
    void open_account();
    void deposite_money();
    void withdraw_money();
    void display_account();
};

void bank :: open_account()
{
    cout<<"entre your full name:";
    cin.ignore();
    cin.getline(name,100);
    cout<<"entre your address:";
    cin.ignore(); 
    cin.getline(add,100);
    cout<<"what type of account you want to open saving(s) or current(c) :";
    cin>>y;
    cout<<"entre amount for deposite:";
    cin>>balance;
    cout<<"your account is created!! THANK YOU FOR JOINING US!!"<<endl;
}

void bank :: withdraw_money()
{
    float amount;
    cout<<"withdraw:";
    cout<<"entre amount you want to withdraw:";
    cin>>amount;
    balance= balance - amount;
    cout<<"your balance is:"<<balance<<endl;
}

void bank :: deposite_money()
{
    int a;
    cout<<"entre how much you deposite:";
    cin>>a;
    balance += a;
    cout<<"total amount you deposite: \t"<<balance<<endl;
}

void bank :: display_account()
{
    cout<<"your full name :"<<name<<endl;
    cout<<"your address:"<<add<<endl;
    cout<<"type of account that you open:"<<y<<endl;
    cout<<"amount you deposite:"<<balance<<endl;
}
int main()
{
    int take,x,ch;
    bank obj;
    
do
    {
    cout<<"1.open bank account"<<endl;
    cout<<"2.deposit money"<<endl;
    cout<<"3.withdraw money"<<endl;
    cout<<"4.display account"<<endl;
    cout<<"5.exit"<<endl;
    cout<<"select a number from above:";
    cin>>take;

    switch(take)
    {
        case 1:
        cout<<"1.open account:"<<endl;
        obj.open_account();
        break;

        case 2:
        cout<<"2.deposite money:"<<endl;
        obj.deposite_money();
        break;

        case 3:
        cout<<"3.withdraw money:"<<endl;
        obj.withdraw_money();
        break;

        case 4:
        cout<<"4.display account:"<<endl;
        obj.display_account();
        break;

        case 5:
        cout<<"exit"<<endl;
        if(ch==5)
        {
            exit(1);
        }
        break;

        default:
        cout<<"entre valid number, try again!!!";
    }
        cout<<"if want to try again then press 'y' , if not then press 'n':"<<endl;
        x=getch();
        if(x=='n'|| x=='N')
        exit(0);
    }
while(x=='y' || x=='Y');


    getch();
    return 0;
}