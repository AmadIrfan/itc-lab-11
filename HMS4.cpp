#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;
//    _____________________________________________________________________________
//    _____________________________ Variables______________________________________
//    _____________________________________________________________________________

// ------------- Global Doctor Variables-----------------
string doctorname, profession, DoctorAge, Doctorpwd, doctorname2, doctorpwd2;
// ------------- Global Admin Variables-----------------
string username, password;
// ------------- Global Patient Variables-----------------
string date;

//    ____________________________________________________________________________
//    _____________________________Inputs_________________________________________
//    ____________________________________________________________________________
// ------------- Inputs-----------------
int a, b = 0, c = 0, d;

//    ____________________________________________________________________________
//    _____________________________PROTOTYPES_____________________________________
//    ____________________________________________________________________________
// Main Function Prototypes.........
void header();

// --------   Comma Seperation Function Prototype -------------
string comma(string row, int column);

// Wrong Password Prototypes.....
void WrongPwd();

// ------------- Admin Login Functions Prototypes--------------------
bool PasswordChecking();
bool AdminLogin();
void AdminModule();
void AddDoctor();
void Dashboard();
void PatientDetails();
void AppointmentDetails();
void DoctorSessonLog();

// Admin And User Query Prototypes.....
void Queries();
void MainMenu();

// Doctor Login functions Prototypes..
bool PWDChecking();
bool DoctorLogin();
void DoctorModule();
void DocDashboard();
void AddPatient();
void AppointmentHistory();
void SearchPatient();

// User Login functions Prototypes..
void UserLogin();
void UserModule();
void BookAppointment();

//   _____________________________________________________________________________
//   ___________________________Main Function_____________________________________
//   _____________________________________________________________________________

int main()
{

    a = 0;
    while (a < 4)
    {
        system("cls");
        header();
        MainMenu();
        if (a == 1)
        {
            while (true)
            {
                system("cls");
                header();
                bool k = AdminLogin();
                if (k)
                {
                    c = 0;
                    while (c != 7)
                    {
                        system("cls");
                        header();
                        AdminModule();
                        if (c == 1)
                        {
                            system("cls");
                            header();
                            Dashboard();
                        }

                        if (c == 2)
                        {
                            system("cls");
                            header();
                            AddDoctor();
                            if (d == 0)
                            {
                                break;
                            }
                        }
                        if (c == 3)
                        {
                            system("cls");
                            header();
                            PatientDetails();
                        }
                        if (c == 4)
                        {
                            system("cls");
                            header();
                            AppointmentDetails();
                        }
                        if (c == 5)
                        {
                            system("cls");
                            header();
                            DoctorSessonLog();
                        }
                        if (c == 6)
                        {
                            system("cls");
                            header();
                            Queries();
                        }
                    }
                    if (c == 7)
                    {
                        c = 0;
                        break;
                    }
                }
            }
        }

        if (a == 2)
        {
            while (true)
            {
                system("cls");
                bool k = DoctorLogin();
                if (k)
                {
                    while (c != 5)
                    {
                        system("cls");
                        header();
                        DoctorModule();
                        if (c == 1)
                        {
                            system("cls");
                            header();
                            DocDashboard();
                        }
                        if (c == 2)
                        {
                            system("cls");
                            header();
                            AppointmentHistory();
                        }
                        if (c == 3)
                        {
                            system("cls");
                            header();
                            AddPatient();
                        }
                        if (c == 4)
                        {
                            system("cls");
                            header();
                            SearchPatient();
                        }
                    }
                    if (c == 5)
                    {
                        c = 0;
                        break;
                    }
                }
            }
        }
        if (a == 3)
        {
            int m = 0;
            while (true)
            {
                system("cls");
                header();
                UserLogin();
                if (b == 1)
                {
                    while (c != 3)
                    {
                        m = 1;
                        system("cls");
                        header();
                        UserModule();
                        if (c == 1)
                        {
                            system("cls");
                            header();
                            BookAppointment();
                        }
                        if (c == 2)
                        {
                            system("cls");
                            header();
                            Queries();
                        }
                    }
                }
                if (m == 1)
                {
                    break;
                }
            }
        }
    }
    if (a == 4)
    {
        system("cls");
        header();
        cout << endl
             << endl
             << endl;
        cout << "                          Exiting..........";
        exit(0);
    }
}

//    ____________________________________________________________________________
//    _____________________________Functions______________________________________
//    ____________________________________________________________________________
bool PasswordChecking()
{
    int count = 0;
    int m = 0;
    int l = 0;
    string line;
    fstream file;
    file.open("admin.txt", ios::in);
    while (true)
    {
        if (m == 1)
        {
            // To again get the correct username & password from user..
            system("cls");
            header();
            cout << "                                           Main Menu> Admin Login" << endl;
            cout << "                        --------------------------------------------------------------------" << endl;
            cout << "                                                User Name:  ";
            cin >> username;
            cout << "                      " << endl;
            cout << "                                                Password :   ";
            cin >> password;
            cout << "                      " << endl;
        }
        while (!file.eof())
        {
            // taking a whole line and extracting username & password...
            getline(file, line);
            string name = comma(line, 1);
            string pwd = comma(line, 2);
            if (username == name && password == pwd)
            {
                return 1;
            }
        }
        file.close();
        if (l == 0)
        {
            m = 1;
            WrongPwd();
            count++;
        }
        if (count == 4)
        {
            cout << "\n\n You Have Entered Incorrect Command Many Times......\n";
            cout << "         TRY AGAIN Later...\n\n";
            getch();
            exit(0);
        }
    }
}
bool AdminLogin()
{
    bool i;
    cout << "                                           Main Menu> Admin Login" << endl;
    cout << "                        --------------------------------------------------------------------" << endl;
    cout << "                                                User Name:  ";
    cin >> username;
    cout << "                      " << endl;
    cout << "                                                Password :   ";
    cin >> password;
    cout << "                      " << endl;
    cout << "                        To Save Press 1 & Press 2 To Exit........";
    cin >> b;
    if (b == 1)
    {
        i = PasswordChecking();
    }
    if (i)
    {
        return 1;
    }
    else
        return 0;
}
void AdminModule()
{
    cout << "                                        Main Menu> Admin Module" << endl;
    cout << "                         ------------------------------------------------------------------" << endl
         << endl;
    cout << "                                        1:- View Dashboard." << endl;
    cout << "                                        2:- Add/Update Doctors." << endl;
    cout << "                                        3:- View Patient Detail." << endl;
    cout << "                                        4:- Appointment Detail." << endl;
    cout << "                                        5:- Doctor Session Logs." << endl;
    cout << "                                        6:- Contact Us Queries." << endl;
    cout << "                                        7:- Exit" << endl;
    cout << "                      " << endl;
    cout << "                      " << endl;
    cout << "                         Your Option.........";
    cin >> c;
}
void AddDoctor()
{
    string time1, time2;
    cout << "                                           Main Menu> Admin Module> Add Doctor:" << endl;
    cout << "                        --------------------------------------------------------------------" << endl;
    cout << "                                                Doctor Name:  ";
    cin >> doctorname;
    cout << "                      " << endl;
    cout << "                                                Profession:  ";
    cin >> profession;
    cout << "                      " << endl;
    cout << "                                                Age: ";
    cin >> DoctorAge;
    cout << "                      " << endl;
    cout << "                                                Create Password :   ";
    cin >> Doctorpwd;
    cout << "                      " << endl;
    cout << "                                                Starting Time :   ";
    cin >> time1;
    cout << "                                                Closing Time :   ";
    cin >> time2;
    cout << "                        To Save Press 1 & Press 2 To Exit........";
    cin >> d;
    fstream newfile;
    newfile.open("doctor.txt", ios::app);
    if (d == 1)
    {
        newfile << endl
                << doctorname << "," << Doctorpwd << "," << profession << "," << DoctorAge << "," << time1 << "," << time2;
    }
    newfile.close();
}
void Dashboard()
{
    string line, name7, prof, age;
    int i = 1;
    cout << "                                           Main Menu> Admin Module> Dashboard :" << endl;
    cout << "                        --------------------------------------------------------------------" << endl;
    fstream newfile;
    newfile.open("doctor.txt", ios::in);
    while (!newfile.eof())
    {
        getline(newfile, line);

        cout << "                         " << i << " Doctor : -" << endl;
        cout << "                                                Doctor Name:  " << comma(line, 1) << endl;
        cout << "                                                " << endl;
        cout << "                                                Professon:    " << comma(line, 3) << endl;
        cout << "                                                " << endl;
        cout << "                                                Age:          " << comma(line, 4) << endl
             << endl;
        i++;
    }
    newfile.close();
    getch();
}
void PatientDetails()
{
    string line;
    int i = 1;
    cout << "                                           Main Menu> Admin Module> View Patient Detail:" << endl;
    cout << "                        --------------------------------------------------------------------" << endl;
    fstream file;
    file.open("patient.txt", ios::in);
    while (!file.eof())
    {
        getline(file, line);
        cout << "                    Patient " << i << ":- " << endl;
        cout << "                         Name: " << comma(line, 1) << endl;
        cout << "                         Phone No: " << comma(line, 3) << endl;
        cout << "                         CNIC: " << comma(line, 4) << endl;
        cout << "                         Age: " << comma(line, 2) << endl;
        cout << "                         Disease: " << comma(line, 5) << endl;
        cout << endl
             << endl;
        i++;
    }
    file.close();
    cout << "                       press 1 to Go Back. ";
    cin >> b;
}
void AppointmentDetails()
{
    string line;
    cout << "                                        Main Menu> Admin Module< Appointment Detail." << endl;
    cout << "                         ------------------------------------------------------------------" << endl
         << endl;
    cout << "                         Patients        Days           Timings" << endl;
    cout << "                        " << endl;
    fstream file;
    file.open("appointments.txt", ios::in);
    while (!file.eof())
    {
        getline(file, line);
        cout
            << "                        " << comma(line, 1) << "      " << comma(line, 2) << "          " << comma(line, 3) << endl;
    }
    file.close();
    cout << "                         Press 1 to Go Back.";
    cin >> d;
}
void DoctorSessonLog()
{
    fstream file;
    string line;
    file.open("doctor.txt", ios::in);
    cout << "                                        Main Menu> Admin Module< Doctor Sesson Logs." << endl;
    cout << "                         ------------------------------------------------------------------" << endl
         << endl;
    cout << "                         Name                       Time Start                  Time Ends" << endl;
    while (!file.eof())
    {
        getline(file, line);
        cout << "                         " << comma(line, 1) << "                  " << comma(line, 5) << "                     " << comma(line, 6) << endl;
    }
    file.close();
    // press 1 to go back.....
    cout << "                      Press 1 to Go Back: ";
    cin >> d;
}

// Admin and User Queries..
void Queries()
{
    cout << "                                        Main Menu> Admin Module< Contact Us Queries." << endl;
    cout << "                         ------------------------------------------------------------------" << endl
         << endl;
    cout << "                         Phone Number:- 03240859565" << endl
         << endl;
    cout << "                         Email:-        yasir.hsn890@gmail.com" << endl
         << endl;
    cout << "                      Press 1 to Go Back: ";
    cin >> d;
}

// Wrong Password Function..
void WrongPwd()
{
    cout << "                           " << endl
         << endl
         << endl;
    cout << "                          Incorrect Password. " << endl
         << endl
         << endl;
    cout << "                          Press any Key To Continue: ";
    getch();
}

// -------------MAIN FUNCTIONS-----------------
void header()
{
    cout << "                         ******************************************************************" << endl;
    cout << "                         ***********   Jinnah Hospital Management System   ****************" << endl;
    cout << "                         ******************************************************************" << endl;
    cout << "                      " << endl;
    cout << "                      " << endl;
}
void MainMenu()
{
    cout << "                         Main Menu" << endl;
    cout << "                         ------------------------------------------------------------------" << endl;
    cout << "                                             1:- Admin Module" << endl;
    cout << "                                             2:- Doctor Module." << endl;
    cout << "                                             3:- User Module." << endl;
    cout << "                                             4:- Exit.";
    cout << "                      " << endl;
    cout << "                      " << endl;
    cout << "                         Your Option.........";
    cin >> a;
}

// --------   Comma Seperation Function -------------
string comma(string row, int column)
{

    int commansCount = 1;
    string item;
    int index = 0;
    while (true)
    {

        char ch = row[index];
        if (ch == '\0')
            return item;
        if (ch == ',')
        {
            commansCount++;
        }
        else if (commansCount == column)
        {
            item = item + ch;
        }
        index++;
    }

    return item;
}

// Doctor Login functions..
bool PWDChecking()
{
    int count = 0;
    int m = 0;
    int l = 0;
    string line;
    fstream newfile;
    newfile.open("doctor.txt", ios::in);
    while (true)
    {
        if (m == 1)
        {
            // To again get the correct username & password from user..
            system("cls");
            cout << "                                           Main Menu> Doctor Login" << endl;
            cout << "                        --------------------------------------------------------------------" << endl;
            cout << "                                                User Name:  ";
            cin >> doctorname2;
            cout << "                      " << endl;
            cout << "                                                Password :   ";
            cin >> doctorpwd2;
            cout << "                      " << endl;
        }
        while (!newfile.eof())
        {
            // taking a whole line and extracting username & password...
            getline(newfile, line);
            string name = comma(line, 1);
            string pwd = comma(line, 2);
            if (doctorname2 == name && doctorpwd2 == pwd)
            {
                return 1;
            }
        }
        newfile.close();
        if (l == 0)
        {
            m = 1;
            WrongPwd();
            count++;
        }
        if (count == 4)
        {
            cout << "\n\n You Have Entered Incorrect Command Many Times......\n";
            cout << "         TRY AGAIN Later...\n\n";
            getch();
            exit(0);
        }
    }
}
bool DoctorLogin()
{
    bool i;
    cout << "                                          Main Menu> Doctor Login" << endl;
    cout << "                         ------------------------------------------------------------------" << endl;
    cout << "                                               User Name.......  " << endl;
    cin >> doctorname2;
    cout << "                                               Password........  " << endl;
    cin >> doctorpwd2;
    cout << "                      " << endl;
    cout << "                      " << endl;
    cout << "                         To Save Press 1.........";
    cin >> b;
    if (b == 1)
    {
        i = PWDChecking();
    }
    if (i)
    {
        return 1;
    }
    else
        return 0;
}
void DoctorModule()
{
    cout << "                                           Main Menu> Doctor Module" << endl;
    cout << "                         ------------------------------------------------------------------" << endl;
    cout << "                                           1:- View Dashboard." << endl;
    cout << "                                           2:- Appointment History.." << endl;
    cout << "                                           3:- Add/Update Patients." << endl;
    cout << "                                           4:- Search Patient By Name." << endl;
    cout << "                                           5:- Exit" << endl;
    cout << "                      " << endl;
    cout << "                      " << endl;
    cout << "                         Your Option.........";
    cin >> c;
}
void DocDashboard()
{
    string line;
    int i = 1;
    cout << "                                           Main Menu> Doctor Module> DashBoard" << endl;
    cout << "                         ------------------------------------------------------------------" << endl;
    fstream file;
    file.open("patient.txt", ios::in);
    while (!file.eof())
    {
        getline(file, line);
        cout << "                         Patient " << i << " :- " << endl;
        cout << "                                                Patient Name: " << comma(line, 1);
        cout << "                                                " << endl;
        cout << "                                                Disease:       " << comma(line, 5);
        cout << "                                                " << endl;
        cout << "                                                Age:           " << comma(line, 2) << endl
             << endl;
        i++;
    }
    getch();
}
void AddPatient()
{
    string patientname, Patientage, phoneNo, idcard, disease;
    cout << "                                     Main Menu> Doctor Module> Add/Update Patients." << endl;
    cout << "                         ------------------------------------------------------------------" << endl;
    fstream file;
    file.open("patient.txt", ios::app);
    cout << "                                                Patient Name:  ";
    cin >> patientname;
    cout << "                      " << endl;
    cout << "                                                Age:  ";
    cin >> Patientage;
    cout << "                      " << endl;
    cout << "                                                Phone No:   ";
    cin >> phoneNo;
    cout << "                      " << endl;
    cout << "                                                CNIC:   ";
    cin >> idcard;
    cout << "                                                Disease:   ";
    cin >> disease;
    cout << "                      " << endl;
    cout << "                                                Date:   ";
    cin >> date;
    cout << "                      To Save Press 1 & Press 2 To Exit........";
    cin >> d;
    if (d == 1)
    {
        file << endl
             << patientname << "," << Patientage << "," << phoneNo << "," << idcard << "," << disease << "," << date;
    }
    file.close();
}
void AppointmentHistory()
{
    int i = 1;
    string line;
    cout << "                                     Main Menu> Doctor Module> Appointment History." << endl;
    cout << "                         ------------------------------------------------------------------" << endl;
    cout << "                                           Name:           Date              Type " << endl
         << endl;
    fstream file;
    file.open("patient.txt", ios::in);
    while (!file.eof())
    {
        getline(file, line);
        cout << "                          Patient" << i << " : " << endl;
        cout << "                                         " << comma(line, 1) << "       " << comma(line, 6) << "        " << comma(line, 5) << endl;
        i++;
    }
    file.close();
    cout << endl
         << "                  Press Any Key To Continue: ";
    getch();
}
void SearchPatient()
{
    int z = 0;
    string patient, line;
    cout << "                                     Main Menu> Doctor Module> Search Patient." << endl;
    cout << "                         ------------------------------------------------------------------" << endl;
    cout << "                          Search Patient Name: " << endl;
    cin >> patient;
    fstream file;
    file.open("patient.txt", ios::in);
    while (!file.eof())
    {
        getline(file, line);
        if (patient == comma(line, 1))
        {
            z = 1;
            cout << "                         Name: " << comma(line, 1) << endl;
            cout << "                         Age: " << comma(line, 2) << endl;
            cout << "                         Phone No: " << comma(line, 3) << endl;
            cout << "                         CNIC: " << comma(line, 4) << endl
                 << endl;
        }
    }
    if (z = 0)
    {
        cout << "                         No Patient Found " << endl
             << endl;
    }
    cout << "                          Press any Key To Continue: ";
    getch();
}

// User Login functions..
void UserLogin()
{
    string user, idcard, phoneNo, Patientage;
    while (true)
    {
        system("cls");
        header();
        cout << "                         Main Menu> User Login" << endl;
        cout << "                         ------------------------------------------------------------------" << endl;
        cout << "                         " << endl
             << endl;
        cout << "                         User Name: ";
        cin >> user;
        cout << "                         ID Card Number: ";
        cin >> idcard;
        cout << "                         Phone Number: ";
        cin >> phoneNo;
        cout << "                         Age: ";
        cin >> Patientage;
        if (end(idcard)-begin(idcard) > 13 && end(idcard)-begin(idcard) < 13)
        {
            cout<<"Incorrect idcard \n";
            cout<<"Try Again";
            getch();
            continue;
        }
        else
        break;
    }
    cout << "                         To Save Press 1.........";
    cin >> b;
    fstream file;
    file.open("user-data.txt", ios::app);
    if (b == 1)
    {
        file << endl
             << user << "," << phoneNo << "," << idcard << "," << Patientage;
    }
    file.close();
}
void UserModule()
{
    header();
    cout << "                         Main Menu> User Module" << endl;
    cout << "                         ------------------------------------------------------------------" << endl;
    cout << "                         1:- Book Appointment." << endl;
    cout << "                         2:- Contact Us Queries." << endl;
    cout << "                         3:- Exit" << endl;
    cout << "                      " << endl;
    cout << "                      " << endl;
    cout << "                         Your Option.........";
    cin >> c;
}
void BookAppointment()
{
    string name, day, date2;
    int k = 1;
    header();
    cout << "                         Main Menu> User Module> Book Appointments." << endl;
    cout << "                         ------------------------------------------------------------------" << endl;
    fstream file;
    file.open("appointments.txt", ios::app);
    cout << "                         1: Name :- ";
    cin >> name;
    cout << "                         2: Day :- ";
    cin >> day;
    cout << "                         3: Date :- ";
    cin >> date2;
    cout << "                         Press 1 To Save Data Or 2 To Exit.....";
    cin >> d;
    if (d == 1)
    {
        file << endl
             << name << "," << day << "," << date2;
    }
}