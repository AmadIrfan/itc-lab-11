#include <iostream>
#include <fstream>
#include <string.h>
#include <windows.h>
using namespace std;
int totalusers;

void login();
void registration();
void valid(string str);

int main()
{
    while (true)
    {
        int c;
        cout << "-------------------------------------------------------------------------------------------------------------------------\n";
        cout << "----------------------------------------------Welcome to our system!------------------------------------------------------\n";
        cout << "----------------------------------------------     Main Menu        ------------------------------------------------------\n";
        cout << "                                                                                                                           \n\n";
        cout << "\t | Press 1 To Login.                      |" << endl;
        cout << "\t | Press 2 To Register.                   |" << endl;
        cout << "\t | Press 3 To Exit.                       |" << endl;
        cout << "\n\t\t\t Please Enter Your Choice: ";
        cin >> c;
        cout << endl;
        if (c == 1)
        {
            login();
        }
        if (c == 2)
        {
            registration();
        }
        if (c == 3)
        {
            exit(0);
        }
    }
}
void login()
{
    ifstream filei;
    int check = 0, count = 0;
    string username, password, id, pass, fname;
    float age, gpa;
    system("cls");
    cout << "\t\t\t Please Enter The UserName And Password: " << endl;
    cout << "\t\t\t USERNAME :  ";
    cin >> username;
    cout << "\t\t\t PASSWORD :  ";
    cin >> password;

    fname = username + ".txt";
    filei.open(fname.c_str());
    if (!filei.is_open() && filei.fail())
    {
        cout << "\nYou are not registered, please register before logging in.\n";
        filei.close();
        check = 1;
    }
    if (check == 0)
    {
        while (filei >> id >> pass >> age >> gpa)
        {
            if (id == username && pass == password)
            {
                count = 1;
                system("cls");
            }
            filei.close();
            if (count == 1)
            {
                system("cls");
                cout << username << "\n Your Login Is Successful \n Thnx For Logging In \n";
                if (gpa > 3.5)
                {
                    cout << "\nGood work\n";
                    system("color 0A");
                }
                else
                    system("color 04");

                main();
            }
            else
            {
                system("cls");
                cout << "\n Logging Error \n Please Check Your Username And Password \n";
                main();
            }
        }
    }
}
void registration()
{
    int check = 0;
    ofstream fileo;
    string RuserId, Rpassword, Rid, Rpass, fname;
    float age, gpa;
    system("cls");
    cout << "\t\t\t Please Enter The UserName And Password: " << endl;
    cout << "\t\t\t USERNAME :  ";
    cin >> RuserId;
    totalusers = 0;
    valid(RuserId);
    if (totalusers >= 3)
    {
        check = 1;
    }
    if (check == 0)
    {
        cout << "\t\t\t PASSWORD :  ";
        cin >> Rpassword;
        cout << "\t\t\t AGE :  ";
        cin >> age;
        cout << "\t\t\t GPA :  ";
        cin >> gpa;
        fname = RuserId + ".txt";
        fileo.open(fname.c_str());
        fileo << RuserId << endl
              << Rpassword << endl
              << age << endl
              << gpa << endl;
        cout << "\nYou are successfully registered:)";
        fileo.close();
        main();
    }
}
void valid(string str)
{
    string dir, user;
    ifstream file;
    dir = str + ".txt";
    file.open(dir.c_str());
    if (!file.is_open() && file.fail())
    {
        // file.close();
        return;
    }
    else
    {
        totalusers++;
        if (totalusers == 3)
        {
            cout << "\nThis username already exists\nPlease try Again.";
            return;
        }
        cout << "\nThis username already exists!\nCreate a username:";
        cin >> user;
        valid(user);
    }
}