#include <iostream>
#include <fstream>
#include<istream>
#include <cstdlib>
using namespace std;


bool IsLoggedIn()
{
    string login_username, stored_username, login_password, stored_password;
    cout << "\nEnter your username: ";
    cin >> login_username;
    cout << "Enter your password: ";
    cin >> login_password;

    ifstream read("database.txt");
    (read>>stored_username>>stored_password);


    if (stored_username == login_username && stored_password == login_password)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
int choice;
choice = 1;
choice = 2;

cout << "\n*************MENU**********:"<<endl;
cout << "\n1: Login\n2: Register\n\nEnter your choice: ";
cin >> choice;

if(choice == 2)
{
    string login_username, login_password;

    cout << "\nSelect a username: ";
    cin >> login_username;
    cout << "Select a password: ";
    cin >> login_password;
    cout <<endl;

    ofstream read("database.txt",ios::app);
    read << login_username <<' '<< login_password <<endl;
    system("cls");
    cout<<"\nRegistration Sucessful\n";
    main();
    read.close();
}

else if(choice == 1)
{
bool status = IsLoggedIn();

if(!status)
{
    cout << "Incorrect username or password" <<endl;
    system("PAUSE");
    return 0;
}
else
{
 cout << "\nLogin successful!\n" <<endl;
 system("PAUSE");
 return 1;
}

}

}