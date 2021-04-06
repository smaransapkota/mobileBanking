//Mobile Banking

// #include <iostream>
// #include <istream>
// #include <fstream>
// #include <stdlib.h>
// #include <strings.h>
//comment

#include <bits/stdc++.h>

using namespace std;

class User
{
protected:
    string user;
    // int age;
    // unsigned int phNo;
    // string address;
};

class BankDetails : public User
{
protected:
    long long int acNumber;
    unsigned int balance;
public:
    void sendMoney(unsigned int);
    unsigned int loadEsewa(unsigned int);

};
class Login : public User
{

    string pass, u, p;
    int exist;
    bool islogin;

public :
    void showMenu(BankDetails &bnk1);


public:
    void login();
};

class Register : public BankDetails
{
    string tokenId;

    string regpass;


public:
    void registeer();
};
class ForgetPassword : public User
{
    string tokenId;


public:
    void forgetPassword();
};

class Mbanking{
    public :
        BankDetails b1;
        Login l1;
        Register r1;
        ForgetPassword f1;
        void clear()
        {
            system("cls");
        }
};


int main()
{
    Mbanking m1;
    char choice;
    do
    {
    cout << " *********************** ***********************\n";
    cout << " ******************** LOGIN ********************\n";
    cout << " *********************** ***********************\n\n";
    cout << " Press : \n";
    cout << "1.For Login";
    cout << "\n2.To Register Account";
    cout << "\n3.To Recover Password";
    cout << "\n4.To Exit From MBanking";
    cout << "\n\nEnter Your Selection : ";

    cin>>choice;
    // cout << typeid(choice).name() <<"aaaaaaaaaaa"<< endl;

    switch (choice)
    {
    case '1':
    {
        // login();
        m1.l1.login();
        //cout<<Account Number : BankDetails::acNumber
        m1.l1.showMenu(m1.b1);
        m1.clear();
    }
        break;

    case '2':
    {
        m1.r1.registeer();
        m1.clear();
    }
        break;

    case '3':
    {
        m1.f1.forgetPassword();
        m1.clear();
    }
        break;

    case '4':
    {
       exit(0);
    }
        break;

    default:
        m1.clear();
        cout << "\nInvalid Choice Selected.\n--> Press Enter key to return mainmenu.\n";

        cin.get();
        cin.get();
        m1.clear();
        break;
    }
}while(true);

}
void Register::registeer()
{

    cout << "Enter new username : ";
    cin >> user;
    cout << "Enter new password : ";
    cin >> regpass;
    cout << "Enter initial balance : ";
    cin >> balance;
    if(balance < 0)
    {

        balance = 0;
    }
    cout << "Enter Your A/C Number : ";
    cin >> acNumber;
    ofstream reg("database.txt", ios::app);
    reg << user << ' ' << regpass<<' '<<balance <<' ' <<acNumber << endl;

    cout << "\nDear "<<user<<", Your Account ( "<<acNumber <<" ) has been created successfully with Initial balance Rs."<<balance<<endl;
    cout<<"Press any key to continue..."<<endl;
    cin.get();
    cin.get();
    system("cls");
    main();
}
void Login::login()
{
    cout << "Enter your UserName : ";
    cin >> user;
    cout << "Enter your Password :";
    cin >> pass;

    ifstream input("database.txt");

    while (input >> u >> p)
    {
        if (u == user && p == pass)
        {
            exist = 1;
            islogin = true;
        }
    }
    input.close();
    if (exist == 1)
    {
        system("cls");
        cout << "\nHello " << user <<", Welcome to SUB Bank Limited."<<endl<<endl;

    }
    else
    {
        cout << "Login Error\n";
        cin.get();
        cin.get();
        main();
    }
}

void ForgetPassword::forgetPassword()
{
    char ch;
    cout << "1.Search Your Account By Username";
    cout << "\n2.Search Your Account By Password";
    cout <<"\n3.Return to main menu";
    cout <<"\n4.Exit Mobile Banking";
    cout << "\nEnter Your Choice :";
    cin >> ch;

    switch (ch)
    {
    case '1':
    {
        int ex = 0;
        string searchuser, su, sp;
        cout << "Enter Your Remembered username : ";
        cin >> searchuser;

        ifstream searchu("database.txt");
        while (searchu >> su >> sp)
        {
            if (su == searchuser)
            {
                ex = 1;
                break;
            }
        }
        searchu.close();
        if (ex == 1)
        {
            cout << "\nAccount Found !\n";
            cout << "Your password is : " << sp;
            cin.get();
            cin.get();
            main();
        }
        else
        {
            cout << "Couldn't find account details with that username. Kindly contact your nearest branch.\n";
            cin.get();
            cin.get();
            forgetPassword();
        }
        break;
    }

    case '2':
    {
        int exi = 0;
        string searchpass, su2, sp2;
        cout << "Enter the Remembered Password : ";
        cin >> searchpass;

        ifstream searchp("database.txt");
        while (searchp >> su2 >> sp2)
        {
            if (sp2 == searchpass)
            {
                exi = 1;
            }
            searchp.close();
            if (exi == 1)
            {
                cout << "Your account found\n";
                cout << "Your Username is : " << su2;
                cout << "Your Password is : " << sp2;
                cin.get();
                cin.get();
                main();
            }
        }
    }
    case '3':
    {
        main();
        break;
    }

    case '4':
        {

            exit(0);
        }

    default:
    {
        cout << "Wrong choice given. Enter any key to continue.";
        cin.get();
        cin.get();
        forgetPassword();
    }
    }

}

void BankDetails::sendMoney(unsigned int money){
    if(balance < money){
        cout<<"Dai Paisa Xaina";
    }
    else{
            balance -= money;
            cout<<"Dai Rs."<<money<<" Chuna Lagyo"<<endl;
    }


}
unsigned int BankDetails::loadEsewa(unsigned int money){
    if(balance < money){
        cout<<"No money Left";
    }
    else{
            balance -= money;
            cout<<"Dai Rs."<<money<<" Esewa Load Vayo"<<endl;
    }

}
void Login::showMenu(BankDetails &bnk1)
  {
      //ofstream

do{
        char choice;
        cout<<"1. To SendMoney"<<endl;
        cout<<"2. To Recieve Money"<<endl;
        cout<<"3. Go To Main Menu"<<endl;
        cout<<"4. To Exit"<<endl;

        cin>>choice;

        switch(choice)
       {

        case '1':
            {

            unsigned int money;
            cin>>money;
            bnk1.sendMoney(money);
            }
            break;

        case '2':
            {

            unsigned int money;
            cin>>money;
            bnk1.loadEsewa(money);

            }
            break;
        case '3':
            {
                main();
            }
            break;
        case '4':
            {

                exit(0);
            }
            break;
        default:
            {

                cout<<"Invalid Choice. Use Chasma to see clearly."<<endl;

            }
       }
}while(true);

    }
