#include "Header.h"

void displayLogin(Staff *staff, Student* student, SchoolYear *schoolYear) {
    int choice;
    cout << "\n\t\t\t\t=======================================================\n";
    cout << "\n\t\t\t\t\tCOURSE REGISTRATION SYSTEM\n";
    cout << "\n\t\t\t\t1. Academic staff login";
    cout << "\n\t\t\t\t2. Student login";
    cout << "\n\t\t\t\t3. Exit";
    cout << "\n\t\t\t\tEnter your choice: "; cin >> choice;
    string account;


    switch (choice) {
    case 1:
        system("cls");
        cin.ignore();
        if (loginStaff(staff, account)) {
            loadingSuccess();
            system("cls");
            displayLoginStaff(staff, student, schoolYear, account);
            switch (choice) {
            case 1:
                system("cls");
                displayYear(schoolYear);
                displaySchoolYear(staff, student,  schoolYear, account);
                cin >> choice;
                switch (choice) {
                case 1:
                    createNewYear(schoolYear);
                    Sleep(2000);
                    cout << "\n\t\t\t\t Added.";
                    cout << "\n\t\t\t\tPress any key to return to previous page...";
                    _getch();
                    system("cls");
                    displaySchoolYear(staff,student, schoolYear, account);
                    cin >> choice;
                case 2:
                    system("cls");
                    displayLoginStaff(staff, student, schoolYear, account);
                }
            case 2:
                system("cls");
                displayStaffProfile(staff, account);
                cout << "\n\t\t\t\tPress any key to return to previous page...";
                _getch();
                system("cls");
                displayLoginStaff(staff, student, schoolYear, account);
            case 3:
                system("cls");
                changePassStaff(staff, student, schoolYear, "Staff.csv", account);
            default:
                displayLogin(staff, student, schoolYear);
            }
        }
        else {
            cout << "Your account or password is incorrect. Try again?";
        }
    case 2:
        system("cls");
    case 3:
        cout << "\t\t\t\t    SEE YOU LATER\n";
    }
}

void displayLoginStudent(Staff* staff, Student* student, SchoolYear* schoolyear, string account) {
    cout << "\n\t\t\t\t=======================================================\n";
    cout << "\n\t\t\t\t\tCOURSE REGISTRATION SYSTEM FOR STUDENTS\n";
    cout << "\n\t\t\t\t1. School year\n";
    cout << "\n\t\t\t\t2. View and edit profile\n";
    cout << "\n\t\t\t\t3. Change password\n";
    cout << "\n\t\t\t\t4. Log out\n";
    cout << "\n\t\t\t\tEnter your choice: ";
    int choice; cin >> choice; cin.ignore();
    switch (choice) {
    case 1:
        system("cls");
        displayYear(schoolyear);
        displaySchoolYear(staff, student, schoolyear,account);
        cin >> choice;
        switch (choice) {
        case 1:
            createNewYear(schoolyear);
            Sleep(2000);
            cout << "\n\t\t\t\t Added.";
            cout << "\n\t\t\t\tPress any key to return to previous page...";
            _getch();
            system("cls");
            displaySchoolYear(staff, student, schoolyear, account);
            cin >> choice;
        case 2:
            system("cls");
            displayLoginStudent(staff, student, schoolyear, account);
        }
    case 2:
        system("cls");
        //displayStudentProfile(student);
        cout << "\n\t\t\t\tPress any key to return to previous page...";
        _getch();
        system("cls");
        displayLoginStudent(staff, student, schoolyear, account);
    case 3:
        system("cls");
        changePassStudent(staff, student, schoolyear, "Student.csv", account);
    default:
        cout << "\n\t\t\t\tError.";
    }
}
void loadingSuccess() {
    system("cls");
    cout << "\n\n\t\t\t\t\t  Login successfully!!\n\n";
    cout << "\t\t\t\t\tLoading...";
    Sleep(3000);
}

void displayLoginStaff(Staff* staff, Student* student, SchoolYear* schoolyear, string account) {
    cout << "\n\t\t\t\t=======================================================\n";
    cout << "\n\t\t\t\t\tCOURSE REGISTRATION SYSTEM\n";
    cout << "\n\t\t\t\t1. School year\n";
    cout << "\n\t\t\t\t2. View and edit profile\n";
    cout << "\n\t\t\t\t3. Change password\n";
    cout << "\n\t\t\t\t4. Log out\n";
    cout << "\n\t\t\t\tEnter your choice: ";
    int choice; cin >> choice; cin.ignore();
    switch (choice) {
    case 1:
        system("cls");
        displayYear(schoolyear);
        displaySchoolYear(staff, student, schoolyear, account);
        cin >> choice; cin.ignore();
        switch (choice) {
        case 1:
            createNewYear(schoolyear);
            Sleep(2000);
            cout << "\n\t\t\t\tAdded.\n";
            cout << "\n\t\t\t\tPress any key to return to previous page...";
            _getch();
            system("cls");
            displaySchoolYear(staff, student, schoolyear, account);
            cin >> choice;
        case 2:
            system("cls");
            displayLoginStaff(staff, student, schoolyear, account);
        }
    case 2:
        system("cls");
        displayStaffProfile(staff, account);
        cout << "\n\t\t\t\tPress any key to return to previous page...";
        _getch();
        system("cls");
        displayLoginStaff(staff, student, schoolyear, account);
    case 3:
        system("cls");
        changePassStaff(staff, student, schoolyear, "Staff.csv",  account);
    case 4:
        system("cls");
        displayLogin(staff, student, schoolyear);
    default:
        cout << "\n\t\t\t\tError.";
        Sleep(2000);
        system("cls");
        displayLoginStaff(staff, student, schoolyear, account);
    }
}

void displaySchoolYear(Staff *staff, Student* student, SchoolYear *schoolyear, string account) {
    cout << "\n\t\t\t\t1. Create new year\n";
    cout << "\n\t\t\t\t2. Exit\n";
    cout << "\n\t\t\t\tEnter your choice: ";
    int choice; cin >> choice; cin.ignore();
    switch (choice) {
    case 1:
        createNewYear(schoolyear);
        cout << "\n\n\t\t\t\tLoading...\n";
        Sleep(2000);
        cout << "\n\t\t\t\tAdded.\n";
        cout << "\n\t\t\t\tPress any key to return to previous page...";
        _getch();
        system("cls");
        displayYear(schoolyear);
        displaySchoolYear(staff, student, schoolyear, account);
    case 2:
        system("cls");
        displayLoginStaff(staff, student, schoolyear, account);
    default:
        cout << "\n\t\t\t\tInvalid input, please try again...";
        _getch();
        system("cls");
        displayYear(schoolyear);
        displaySchoolYear(staff, student, schoolyear, account);
    }
}

void displayStaffProfile(Staff* staff, string account) {
    cout << "\n\t\t\t\t\tPROFILE\n";

    while (staff && staff->staffAccount != account)
        staff = staff->pNext;
           
    cout << "\n\t\t\t\tName: " << staff->nameStaff;
    cout << "\n\t\t\t\tAccount: " << staff->staffAccount;
    cout << "\n\t\t\t\tPassword: " << staff->staffPassword;

    if (staff->teacherCourse == "N/A") {
        cout << "\n\t\t\t\tWhat courses are you incharge of? ";
        getline(cin, staff->teacherCourse, '\n');
    }
    else if (staff->teacherCourse != "N/A")
        cout << "\n\t\t\t\tCourse incharge: " << staff->teacherCourse;

    if (staff->teacherClass == "N/A") {
        cout << "\n\t\t\t\tWhat classes are you incharge of? ";
        getline(cin, staff->teacherClass, '\n');
    }
    else if (staff->teacherClass != "N/A")
        cout << "\n\t\t\t\tClass incharge: " << staff->teacherClass;

}

