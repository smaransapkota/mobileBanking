#include <iostream>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <strings.h>

using namespace std;

void login();
void registeer();
void forgetPassword();

int main()
{
    int choice;
    cout<<" *********************** LOGIN ***********************\n";
    cout<<"1.Login";
    cout<<"\n2.Register Account";
    cout<<"\n3.Forget Password";
    cout<<"\n\nEnter Your Choice : ";
    cin>>choice;
    switch(choice)
    {
        case 1:
            login();
            break;

        case 2:
            registeer();
            break;

        case 3:
            forgetPassword();
            break;

        default:
            cout<<"Wrong Choice Selected. Press Any Key To Redirect in MainMenu \n";
            main();

    }
}

void registeer()
{
    string reguser, regpass;
    system("cls");
    cout<<"Enter the Username : " ;
    cin>>reguser;
    cout<<"Enter the Password : ";
    cin >> regpass;

    ofstream reg("database.txt", ios::app);
    reg<<reguser<<' '<<regpass<<endl;
    system("cls");
    cout<<"Registration is Succesful\n";
    main();
}
void login()
{
    int exist;
    string user, pass, u, p;
    system("cls");
    cout<<"Enter the UserName : ";
    cin>>user;
    cout<<"Enter the Password :";
    cin>>pass;

    ifstream input("database.txt");

    while(input>>u>>p)
    {
        if(u == user && p == pass)
        {
            exist =1;
        }
    }
    input.close();
    if(exist == 1)
    {
        cout<<"Hello"<<user<<"\nThank You For Using Our Banking Service";
        cin.get();
        cin.get();
        main();
    }
    else
    {
        cout<<"Login Error\n";
        cin.get();
        cin.get();
        main();

    }
}

void forgetPassword()
{
    int ch;
    system("cls");
    cout<<"1.Search Your Account By Username";
    cout<<"\n2.Mainmenu";
    cout<<"\nEnter Your Choice :";
    cin>>ch;

    switch(ch)
    {
        case 1:
        {
            int ex = 0;
            string searchuser,su,sp;
            cout<<"Enter Your Remembered username : ";
            cin>>searchuser;

            ifstream searchu("database.txt");
            while(searchu>>su>>sp)
            {
                 if (su == searchuser)
                 {
                     ex=1;
                     break;
                 }

            }
            searchu.close();
            if (ex ==1 )
            {
                cout<<"Account Found !\n";
                cout<<"Your password is "<<sp;
                cin.get();
                cin.get();
                main();

            }
            else{
                cout<<"Sorry Invalid user name\n";
                cin.get();
                cin.get();
                main();

            }
            break;
        }

        case 2:
        {
            int exi = 0;
            string searchpass, su2, sp2;
            cout<<"Enter the Remembered Password : ";
            cin>>searchpass;

            ifstream searchp("database.txt");
            while(searchp>>su2>>sp2)
            {
                if(sp2 == searchpass)
                {
                    exi = 1;

                }
                searchp.close();
                if(exi == 1)
                {
                    cout<<"Your account found\n";
                    cout<<"Your Username is : "<<su2;
                    cout<<"Your Password is : "<<sp2;
                    cin.get();
                    cin.get();
                    main();
                }
            }
        }
        case 3:
        {
            main();
            break;
        }

        default :
        {
            cout<<"Wrong choice given. Enter any key to continue.";
            cin.get();
            cin.get();
            forgetPassword();
        }
    }
}
