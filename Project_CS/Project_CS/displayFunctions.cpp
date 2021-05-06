#include "Header.h"

extern string g_account;
extern int g_ID;
extern string g_selectyear;
extern string g_selectClass;
extern string g_selectCourse;
extern int g_selectSemester;
extern string g_Time;


void displayLogin(Staff *staff, Student* student, SchoolYear *schoolYear) {
    if (g_Time != "") {
        gotoXY(26, 4); cout << "Date: " << g_Time;
    }
    gotoXY(26, 5); cout << "=======================================================";
    Textcolor(rand() % 16);
    gotoXY(39, 9); cout << "COURSE REGISTRATION SYSTEM";
    Textcolor(7);
    gotoXY(31, 12); cout << "1. Academic staff login";
    gotoXY(31, 14); cout << "2. Student login";
    gotoXY(31, 16); cout << "3. Set date";
    gotoXY(31, 18); cout << "4. Exit";
    if (g_Time == "") {
        gotoXY(31, 25); cout << "You should set date first!";
    }
    gotoXY(31, 20); cout << "Enter your choice: "; 
    string date;
    char choice = getchar();
    cin.ignore(100, '\n');
    switch (choice) {
    case '1':
        system("cls");
        if (loginStaff(staff)) {
            loadingSuccess();
            system("cls");
            displayLoginStaff(staff, student, schoolYear);
        }
        else {
            gotoXY(31, 16); cout << "Your account or password is incorrect.";
            gotoXY(31, 18); cout << "Try again in 3...";
            Sleep(1000);
            gotoXY(31, 18); cout << "Try again in 2...";
            Sleep(1000);
            gotoXY(31, 18); cout << "Try again in 1...";
            Sleep(1000);
            system("cls");
            displayLogin(staff, student, schoolYear);
        }
        break;
    case '2':
        system("cls");
        getDataStudent(student, "student.csv");
        if (loginStudent(student)) {
            loadingSuccess();
            system("cls");
            displayLoginStudent(staff, student, schoolYear);
        }
        else {
            gotoXY(31, 16); cout << "Your account or password is incorrect.";
            gotoXY(31, 18); cout << "Try again in 3...";
            Sleep(1000);
            gotoXY(31, 18); cout << "Try again in 2...";
            Sleep(1000);
            gotoXY(31, 18); cout << "Try again in 1...";
            Sleep(1000);
            system("cls");
            displayLogin(staff, student, schoolYear);
        }
        break;
    case '3':
        system("cls");
        gotoXY(26, 5); cout << "=======================================================";
        Textcolor(rand() % 15 + 1);
        gotoXY(48, 9); cout << "SET DATE";
        Textcolor(7);
        gotoXY(29, 13); cout << "This date will be consider as the time at present.";
        gotoXY(7, 15); cout << "Which will determine whether the student can be able to get access into a semester or not.";
        gotoXY(29, 19); cout << "Enter date (dd/mm/yyyy): ";
        getline(cin, date, '\n');
        g_Time = add0(date);
        gotoXY(29, 21); cout << "Set date successfully!";
        gotoXY(35, 24); cout << "Press any key to return...";
        _getch();
        system("cls");
        displayLogin(staff, student, schoolYear);
        break;
    case '4':
        system("cls");
        gotoXY(31, 15); cout << "THANK YOU FOR USING OUR SYSTEM!\n\t\t\t\t";
        exit(0);
        break;
    default:
        gotoXY(31, 23); cout << "Try again in 2...";
        Sleep(1000);
        gotoXY(31, 23); cout << "Try again in 1...";
        Sleep(1000);
        system("cls");
        displayLogin(staff, student, schoolYear);
        break;
    }
}

void displayLoginStudent(Staff* staff, Student* student, SchoolYear* schoolyear) {
    if (g_Time != "") {
        gotoXY(26, 4); cout << "Date: " << g_Time;
    }
    gotoXY(26, 5); cout << "=======================================================";
    Textcolor(rand() % 15 + 1);
    gotoXY(39, 9); cout << "COURSE REGISTRATION SYSTEM";
    Textcolor(7);
    gotoXY(31, 12); cout << "1. School year";
    gotoXY(31, 14); cout << "2. View and edit profile";
    gotoXY(31, 16); cout << "3. Change password";
    gotoXY(31, 18); cout << "4. Log out";
    gotoXY(31, 20); cout << "Enter your choice: ";
    char choice = getchar();
    cin.ignore(100, '\n');
    switch (choice) {
    case '1':
        system("cls");
        displaySchoolYearForStudent(staff, student, schoolyear);
        choice = getchar();
        cin.ignore(100, '\n');
        switch (choice) {
        case '1':
            createNewYear(schoolyear);
            Sleep(2000);
            system("cls");
            displaySchoolYearForStudent(staff, student, schoolyear);
            cin >> choice;
            break;
        case '2':
            system("cls");
            displayLoginStudent(staff, student, schoolyear);
            break;
        }
    case '2':
        system("cls");
        displayStudentProfile(student, "Student.csv");
        system("cls");
        displayLoginStudent(staff, student, schoolyear);
        break;
    case '3':
        system("cls");
        changePassStudent(staff, student, schoolyear, "Student.csv");
        break;
    case '4':
        gotoXY(31, 23); cout << "Logging out...";
        Sleep(3000);
        system("cls");
        displayLogin(staff, student, schoolyear);
        break;
    default:
        gotoXY(31, 22); cout << "Invalid input.";
        gotoXY(31, 23); cout << "Try again in 3...";
        Sleep(1000);
        gotoXY(31, 23); cout << "Try again in 2...";
        Sleep(1000);
        gotoXY(31, 23); cout << "Try again in 1...";
        Sleep(1000);
        system("cls");
        displayLoginStudent(staff, student, schoolyear);
        break;
    }
}
void loadingSuccess() {
    system("cls");
    gotoXY(40, 15);cout << "Login successfully!!";
    gotoXY(44, 18);cout << "Loading...";
    Sleep(3000);
}

void displayLoginStaff(Staff* staff, Student* student, SchoolYear* schoolyear) {
    if (g_Time != "") {
        gotoXY(26, 4); cout << "Date: " << g_Time;
    }
    gotoXY(26, 5); cout << "=======================================================";
    Textcolor(Blue);
    gotoXY(39, 9); cout << "COURSE REGISTRATION SYSTEM";
    Textcolor(7);
    gotoXY(31, 12); cout << "1. School year";
    gotoXY(31, 14); cout << "2. View and edit profile";
    gotoXY(31, 16); cout << "3. Change password";
    gotoXY(31, 18); cout << "4. Log out";
    gotoXY(31, 20); cout << "Enter your choice: ";
    char choice = getchar();
    cin.ignore(100, '\n');
    switch (choice) {
    case '1':
        system("cls");
        displayYear(schoolyear);
        displaySchoolYearForStaff(staff, student, schoolyear);
    case '2':
        system("cls");
        displayStaffProfile(staff);
        _getch();
        system("cls");
        displayLoginStaff(staff, student, schoolyear);
        break;
    case '3':
        system("cls");
        changePassStaff(staff, student, schoolyear, "Staff.csv");
        break;
    case '4':
        gotoXY(31, 23); cout << "Logging out...";
        Sleep(3000);
        system("cls");
        displayLogin(staff, student, schoolyear);
        break;
    default:
        gotoXY(31, 22); cout << "Invalid input.";
        gotoXY(31, 23); cout << "Try again in 3...";
        Sleep(1000);
        gotoXY(31, 23); cout << "Try again in 2...";
        Sleep(1000);
        gotoXY(31, 23); cout << "Try again in 1...";
        Sleep(1000);
        system("cls");
        displayLoginStaff(staff, student, schoolyear);
        break;
    }
}

void displaySchoolYearForStaff(Staff* staff, Student* student, SchoolYear*& schoolyear) {
    displayYear(schoolyear);
    cout << "\n\n\n\n\n\t\t\t\t1. Create new school year\n";
    cout << "\n\t\t\t\t2. Access into a school year\n";
    cout << "\n\t\t\t\t3. Exit\n";
    cout << "\n\n\t\t\t\tEnter your choice: ";
    string year;
    char choice = getchar();
    cin.ignore(100, '\n');
    SchoolYear* pCur = schoolyear;
    switch (choice) {
    case '1':
        createNewYear(schoolyear);
        system("cls");
        displayYear(schoolyear);
        displaySchoolYearForStaff(staff, student, schoolyear);
        break;
    case '2':
        cout << "\n\t\t\t\tEnter the schoolyear (ex: 2020_2021): ";
        getline(cin, year, '\n');
        while (pCur && pCur->year != year) {
            pCur = pCur->pNext;
        }
        if (pCur != nullptr) {
            g_selectyear = year;
            system("cls");
            displaySelectedYearForStaff(staff, student, schoolyear);
        }
        else {
            cout << "\n\t\t\t\tSchool year " << year << " doesn't exist";
            system("cls");
            displaySchoolYearForStaff(staff, student, schoolyear);
        }
        break;
    case '3':
        system("cls");
        displayLoginStaff(staff, student, schoolyear);
        break;
    default:
        cout << "\n\t\t\t\tInvalid input, try again...";
        Sleep(1500);
        system("cls");
        displaySchoolYearForStaff(staff, student, schoolyear);
        break;
    }
}

void displaySchoolYearForStudent(Staff* staff, Student* student, SchoolYear*& schoolyear) {
    displayYear(schoolyear);
    cout << "\n\t\t\t\t1. Exit\n";
    cout << "\n\n\t\t\t\tEnter your choice\n\t\t\t\tOr year (2xxx_2xxx): ";
    string choice;
    getline(cin, choice);
    g_selectyear = choice;
    SchoolYear* pCur = schoolyear;

    if (choice == "1") {
        system("cls");
        displayLoginStudent(staff, student, schoolyear);
    }
    else {
        while (pCur && pCur->year != g_selectyear) {
            pCur = pCur->pNext;
        }
        if (pCur != nullptr) {
            system("cls");
            displaySelectedYearForStudent(staff, student, schoolyear);
        }
        else {
            gotoXY(31, 22); cout << "Invalid input.";
            gotoXY(31, 23); cout << "Try again in 3...";
            Sleep(1000);
            gotoXY(31, 23); cout << "Try again in 2...";
            Sleep(1000);
            gotoXY(31, 23); cout << "Try again in 1...";
            Sleep(1000);
            system("cls");
            displaySchoolYearForStudent(staff, student, schoolyear);
        }
    }
}

void displayStaffProfile(Staff* staff) {
    if (g_Time != "") {
        gotoXY(26, 4); cout << "Date: " << g_Time;
    }
    gotoXY(26, 5); cout << "=======================================================";
    Textcolor(rand() % 15 + 1);
    gotoXY(47, 9); cout << "PROFILE";
    Textcolor(7);

    while (staff && staff->staffAccount != g_account)
        staff = staff->pNext;
    if (staff) {
        gotoXY(31, 12); cout << "Name: " << staff->nameStaff;
        gotoXY(31, 14); cout << "Account: " << staff->staffAccount;
        gotoXY(31, 16); cout << "Password: " << staff->staffPassword;
        gotoXY(31, 20); cout << "Press any key to return...";
    }
    else {
        gotoXY(31, 12); cout << "Staff not found!";
    }

    /*if (staff->teacherCourse == "N/A") {
        cout << "\nWhat courses are you incharge of? ";
        getline(cin, staff->teacherCourse, '\n');
    }
    else if (staff->teacherCourse != "N/A")
        cout << "\nCourse incharge: " << staff->teacherCourse;

    if (staff->teacherClass == "N/A") {
        cout << "\nWhat classes are you incharge of? ";
        getline(cin, staff->teacherClass, '\n');
    }
    else if (staff->teacherClass != "N/A")
        cout << "\nClass incharge: " << staff->teacherClass;*/

}

void displayStudentProfile(Student*& student, string path) {
    if (g_Time != "") {
        gotoXY(26, 4); cout << "Date: " << g_Time;
    }
    gotoXY(26, 5); cout << "=======================================================";
    Textcolor(rand() % 15 + 1);
    gotoXY(47, 9); cout << "PROFILE";
    Textcolor(7);

    Student* pCur = student;

    while (pCur && pCur->StudentID != g_ID)
        pCur = pCur->pNext;
    if (pCur) {
        gotoXY(31, 12); cout << "First name: " << pCur->Firstname;
        gotoXY(31, 14); cout << "Last name: " << pCur->Lastname;
        gotoXY(31, 16); cout << "Gender: " << pCur->Gender;
        gotoXY(31, 18); cout << "Student ID: " << pCur->StudentID;
        gotoXY(31, 20); cout << "Password: " << pCur->studentPassword;
        gotoXY(31, 22); cout << "Date of birth: " << pCur->DoB;
        gotoXY(31, 24); cout << "Social ID: " << pCur->SocialID;

        gotoXY(31, 26); cout << "U: Update Date of birth";
        gotoXY(31, 27); cout << "ESC: Exit";
    }
    else {
        gotoXY(31, 12); cout << "Student not found";
    }
    string title;
    string Firstname, Lastname, Gender, studentPassword, DoB, studentClass, tempDoB;
    //long SocialID;
    int ID, SocialID, check = 1;
    ifstream in;
    ofstream out;

    AnTroChuot();

    while (check) {
        if (_kbhit())
        {
            switch (_getch())
            {
            case 'u':

                gotoXY(55, 25); cout << ": ";
                gotoXY(57, 25); getline(cin, tempDoB, '\n');

                in.open(path);
                if (in) {
                    out.open("tempStudent.csv");
                    getline(in, title, '\n');
                    out << title << endl;
                    for (int i = 1; i <= numberOfLine(path) - 1; i++) {
                        in >> ID;
                        out << ID << ",";
                        char z;
                        in >> z;
                        getline(in, Firstname, ',');
                        out << Firstname << ",";
                        getline(in, Lastname, ',');
                        out << Lastname << ",";
                        getline(in, Gender, ',');
                        out << Gender << ",";
                        getline(in, DoB, ',');
                        if (pCur && ID == pCur->StudentID) {
                            out << tempDoB << ",";
                            pCur->DoB = tempDoB;
                        }
                        else {
                            out << DoB << ",";
                        }
                        getline(in, studentClass, ',');
                        out << studentClass << ",";
                        in >> SocialID;
                        out << SocialID << "\n";
                        getline(in, studentPassword, ',');
                        out << studentPassword << "," << endl;
                    }
                    out.close();
                    in.close();
                    remove("Student.csv");
                    rename("tempStudent.csv", "Student.csv");
                    system("cls");
                    gotoXY(31, 16); cout << "Date of birth updated successfully!";
                    gotoXY(31, 18); cout << "Return in 2 ...";
                    Sleep(1000);
                    gotoXY(31, 18); cout << "Return in 1 ...";
                    Sleep(1000);
                    system("cls");
                    displayStudentProfile(student, path);
                }
                else {
                    cout << "\n\n\t\t\t\tCan't not open " << path << ", return after 3 seconds..";
                    Sleep(3000);
                    displayStudentProfile(pCur, path);
                }
                break;
            case 27:
                check = 0;
                break;
            }
        }
    }

}

string displaySelectedYearForStaff(Staff* staff, Student* student, SchoolYear* schoolyear) {
    string choice1;
    if (g_Time != "") {
        gotoXY(26, 4); cout << "Date: " << g_Time;
    }
    gotoXY(26, 5); cout << "=======================================================";
    Textcolor(Blue);
    gotoXY(38, 8); cout << "SCHOOL YEAR: " << g_selectyear;
    Textcolor(7);
    gotoXY(31, 14); cout << "1. Semester";
    gotoXY(31, 16); cout << "2. Class";
    gotoXY(31, 18); cout << "3. Exit";
    gotoXY(31, 20); cout << "Enter your choice: ";

    while (schoolyear && schoolyear->year != g_selectyear)
        schoolyear = schoolyear->pNext;

    cin >> choice1; cin.ignore();
    if (choice1 == "1") {
        system("cls");
        if (schoolyear)
            displaySemester(schoolyear->staff, student, schoolyear);
    }
    else if (choice1 == "2") {
        system("cls");
        if (schoolyear)
            displayMenuClass(schoolyear->staff, student, schoolyear);
    }
    else if (choice1 == "3") {
        gotoXY(40, 22); cout << "Loading...";
        Sleep(2000);
        system("cls");
        displayYear(schoolyear);
        displaySchoolYearForStaff(staff, student, schoolyear);
    }
    else {
        gotoXY(31, 22); cout << "Invalid input.";
        gotoXY(31, 23); cout << "Try again in 2...";
        Sleep(1000);
        gotoXY(31, 23); cout << "Try again in 1...";
        Sleep(1000);
        system("cls");
        displaySelectedYearForStaff(staff, student, schoolyear);
    }
    return choice1;
}

string displaySelectedYearForStudent(Staff* staff, Student* student, SchoolYear* schoolyear) {
    string choice1;
    if (g_Time != "") {
        gotoXY(26, 4); cout << "Date: " << g_Time;
    }
    gotoXY(26, 5); cout << "=======================================================";
    Textcolor(Blue);
    gotoXY(38, 8); cout << "SCHOOL YEAR: " << g_selectyear;
    Textcolor(7);
    gotoXY(31, 16); cout << "1. Semester";
    gotoXY(31, 18); cout << "2. Exit";
    gotoXY(31, 20); cout << "Enter your choice: ";

    while (schoolyear && schoolyear->year != g_selectyear)
        schoolyear = schoolyear->pNext;

    cin >> choice1; cin.ignore();
    if (choice1 == "1") {
        system("cls");
        displaySemesterForStudent(staff, student, schoolyear);
    }
    else if (choice1 == "2") {
        gotoXY(40, 22); cout << "Loading...";
        Sleep(2000);
        system("cls");
        displayYear(schoolyear);
        displaySchoolYearForStudent(staff, student, schoolyear);
    }
    else {
        gotoXY(31, 22); cout << "Invalid input.";
        gotoXY(31, 23); cout << "Try again in 2...";
        Sleep(1000);
        gotoXY(31, 23); cout << "Try again in 1...";
        Sleep(1000);
        system("cls");
        displaySelectedYearForStudent(staff, student, schoolyear);
    }
    return choice1;
}

void displayStudentInClass(SchoolYear*& schoolyear, Student* student) {
    ofstream out;
    ifstream in;
    int y = 16, No = 0, check = 1;
    in.open("student.csv");
    string str;
    getline(in, str);
    in.close();
    out.open(g_selectyear + "_" + g_selectClass + ".csv", ios::app);
    if (numberOfLine(g_selectyear + "_" + g_selectClass + ".csv") == 0) {
        out << str << endl;
    }
    out.close();
    getDataStudentinClass(schoolyear);
    Class* tempClass = schoolyear->classes;
    while (tempClass && tempClass->className != g_selectClass)
        tempClass = tempClass->pNext;


    if (g_Time != "") {
        gotoXY(26, 4); cout << "Date: " << g_Time;
    }
    gotoXY(26, 5); cout << "=======================================================";
    Textcolor(Blue);
    gotoXY(38, 8); cout << "CLASS: " << g_selectClass;
    Textcolor(7);
    gotoXY(31, 14); cout << "1. View lecturer";
    gotoXY(31, 16); cout << "2. View student";
    gotoXY(31, 18); cout << "3. Exit";
    gotoXY(31, 20); cout << "Enter your choice: ";
    char choice = getchar();
    cin.ignore(100, '\n');
    switch (choice) {
    case '1':
        /*system("cls");
        gotoXY(26, 5); cout << "=======================================================";
        Textcolor(Blue);
        gotoXY(38, 8); cout << "CLASS: " << g_selectClass;
        Textcolor(7);
        gotoXY(31, 14); cout << "Lecturer's name";
        gotoXY(61, 14); cout << "Course incharge";
        int y = 16;
        if (!tempClass->staff) {
            gotoXY(31, 16); cout << "Not available.";
            gotoXY(61, 16); cout << "Not available.";
        }
        while (tempClass->staff && tempClass->staff->nameStaff == g_selectClass) {
            gotoXY(31, y); cout << tempClass->staff->nameStaff;
            gotoXY(61, y); cout << tempClass->staff->staffCourse->courseName;
            y += 2;
            tempClass->staff = tempClass->staff->pNext;
        }
        gotoXY(31, y); cout << "Press any key to return...";
        _getch();
        gotoXY(31, y += 2); cout << "Loading..";
        system("cls");
        displayStudentInClass(schoolyear, student);*/
        break;
    case '2':
        system("cls");
        if (g_Time != "") {
            gotoXY(26, 4); cout << "Date: " << g_Time;
        }
        gotoXY(26, 5); cout << "=======================================================";
        Textcolor(Blue);
        gotoXY(46, 8); cout << "CLASS: " << g_selectClass;
        Textcolor(7);

        gotoXY(05, 14); cout << "No";
        gotoXY(10, 14); cout << "Student ID";
        gotoXY(24, 14); cout << "First name";
        gotoXY(38, 14); cout << "Last name";
        gotoXY(51, 14); cout << "Gender";
        gotoXY(61, 14); cout << "Date of birth";
        gotoXY(78, 14); cout << "Social ID";

        
        if (numberOfLine(g_selectyear + "_" + g_selectClass + ".csv") == 1) {
            gotoXY(05, 16); cout << "N/A";
            gotoXY(10, 16); cout << "N/A";
            gotoXY(24, 16); cout << "N/A";
            gotoXY(38, 16); cout << "N/A";
            gotoXY(51, 16); cout << "N/A";
            gotoXY(61, 16); cout << "N/A";
            gotoXY(78, 16); cout << "N/A";

        }
        else {
            while (tempClass && tempClass->student && tempClass->student->studentClass == g_selectClass) {
                gotoXY(05, y); cout << No;
                gotoXY(10, y); cout << tempClass->student->StudentID;
                gotoXY(24, y); cout << tempClass->student->Firstname;
                gotoXY(38, y); cout << tempClass->student->Lastname;
                gotoXY(51, y); cout << tempClass->student->Gender;
                gotoXY(61, y); cout << tempClass->student->DoB;
                gotoXY(78, y); cout << tempClass->student->SocialID;
                y++; No++;
                tempClass->student = tempClass->student->pNext;
            }
        }

        gotoXY(31, y += 2); cout << "T: Add student by typing";
        gotoXY(31, ++y); cout << "F: Add student using csv file";
        gotoXY(31, ++y); cout << "ESC: Exit";

        AnTroChuot();

        while (check) {
            if (_kbhit())
            {
                switch (_getch()) {
                case 't':
                    system("cls");
                    AddStudentIntoClass(schoolyear, student, g_selectyear + "_" + g_selectClass + ".csv");
                    break;
                case 'f':
                    inputStudent();
                    system("cls");
                    displayStudentInClass(schoolyear, student);
                    break;
                case 27:
                    check = 0;
                    system("cls");
                    displayStudentInClass(schoolyear, student);
                    break;
                }
            }
        }
        break;
    case '3':
        system("cls");
        gotoXY(40, 16); cout << "Loading...";
        Sleep(2000);
        system("cls");
        displayMenuClass(schoolyear->staff, student, schoolyear);
    }
}


void AddStudentIntoClass(SchoolYear*& schoolyear, Student*& student, string path) { // path o day la chi toi lop, vd: 2020_2021_20CTT2.csv/txt
   // Add course;
   
}

void displaySemester(Staff* staff, Student* student, SchoolYear* schoolyear) {
    getDataSemester(schoolyear);
    Semester* temp = schoolyear->semester;
    bool check1 = false, check2 = false, check3 = false;
    int sem = 1;
    while (temp) {
        if (temp->no == 1) check1 = true;
        else if (temp->no == 2) check2 = true;
        else if (temp->no == 3) check3 = true;
        temp = temp->pNext;
    }
    if (g_Time != "") {
        gotoXY(26, 4); cout << "Date: " << g_Time;
    }
    gotoXY(26, 5); cout << "=======================================================";
    Textcolor(Blue);
    gotoXY(38, 8); cout << "SCHOOL YEAR: " << g_selectyear;
    Textcolor(7);
    cout << "\n\n\t\t\t\tList of semester: Semester 1";
    if (!check1) cout << " (Not created)";
    cout << "\n\t\t\t\t\t\t  Semester 2";
    if (!check2) cout << " (Not created)";
    cout << "\n\t\t\t\t\t\t  Semester 3";
    if (!check3) cout << " (Not created)";
    
    int no;
    Semester* pCur;
    cout << "\n\n\n\t\t\t\t1. Create semester (maximum 3) \n";
    cout << "\n\n\t\t\t\t2. Get access in semester \n";
    cout << "\n\n\t\t\t\t3. Exit \n";
    cout << "\n\n\t\t\t\tEnter your choice: ";
    char choice = getchar();
    cin.ignore(100, '\n');
    switch (choice) {
    case '1':
        createSemester(schoolyear);
        system("cls");
        displaySemester(staff, student, schoolyear);
        break;
    case '2':
        cout << "\n\n\t\t\t\tEnter the semester you want to get access into (number): ";
        cin >> no; cin.ignore();
        getDataSemester(schoolyear);
        pCur = schoolyear->semester;
        while (pCur && pCur->no != no) {
            pCur = pCur->pNext;
        }
        if (pCur) {
            g_selectSemester = no;
            cout << "\n\n\t\t\t\tEntering semester " << no << "...";
            Sleep(2000);
            system("cls");
            /*if (date_cmp(add0(pCur->start_date).c_str(), g_Time.c_str()) < 0
                && date_cmp(add0(pCur->end_date).c_str(), g_Time.c_str()) > 0)
                displayCourseInSemester(schoolyear);
            else {
                system("cls");
                displayCourseWhenDayExceed(schoolyear);
            }*/
            // Trong khoang thoi gian dau hoc ky toi 5 ngay truoc khi ket thuc ky thi 
            // staff co the them course, delete cource, update course, ...

            if (date_cmp(add0(pCur->start_date).c_str(), g_Time.c_str()) < 0
                && (add0(pCur->end_date)[0]*10 + add0(pCur->end_date)[1]
                    - g_Time[0]*10 - g_Time[1] > 5))
                displayCourseInSemester(schoolyear);
            // Trong 5 ngay truoc khi ket thuc ky tro di, staff co the export hoc sinh, them diem, ...

            else {
                system("cls");
                displayCourseWhenDayExceed(schoolyear);
            }
        }
        else {
            cout << "\n\n\t\t\t\tSemester " << no << " doesn't exist.";
            Sleep(2000);
            system("cls");
            displaySemester(staff, student, schoolyear);
        }
        break;
    case '3':
        cout << "\n\n\t\t\t\tLoading...";
        Sleep(2000);
        system("cls");
        displaySchoolYearForStaff(staff, student, schoolyear);
        break;
    default:
        cout << "\n\n\t\t\t\tInvalid input. Try again..";
        Sleep(1800);
        system("cls");
        displayMenuClass(staff, student, schoolyear);
        break;
    }
}

void displayCourseInSemester(SchoolYear*& schoolyear) {
    setConsoleWindow(1000, 600);
    ofstream out;
    ifstream in;
    int y = 16, No = 0, check = 1;
  
    string title = { "Course name,Course ID,credits,teacher name,"
    "number of students,day,time" };

    string path = g_selectyear + "_Semester" + to_string(g_selectSemester) + ".csv";

    out.open(path, ios::app);
    if (numberOfLine(path) == 0) {
        out << title << endl;
    }
    out.close();

    getDataCoursesInSemester(schoolyear);
    Semester* tempSemester = schoolyear->semester;
    while (tempSemester && tempSemester->no != g_selectSemester)
        tempSemester = tempSemester->pNext;

    Course* pCurCase2 = schoolyear->semester->course;
    Course* pCurCase3 = schoolyear->semester->course;
    Course* tempCourse = tempSemester->course; // Will be used to add course later;

    if (g_Time != "") {
        gotoXY(26, 4); cout << "Date: " << g_Time;
    }
    gotoXY(26, 5); cout << "==========================================================================================";
    Textcolor(Blue);
    gotoXY(63, 8); cout << "SEMESTER " << g_selectSemester;
    Textcolor(7);

    gotoXY(05, 12); cout << "Course name";
    gotoXY(45, 12); cout << "Course ID"; //25
    gotoXY(57, 12); cout << "Credits";  // 12
    gotoXY(67, 12); cout << "Teacher"; // 10
    gotoXY(85, 12); cout << "NoS"; // 18
    gotoXY(91, 12); cout << "Day"; // 6
    gotoXY(103, 12); cout << "Session"; // 12

    gotoXY(02, 14); cout << "===================================================="
        "=========================================================================";

    if (numberOfLine(path) == 1) {
        gotoXY(05, 16); cout << "N/A";
        gotoXY(45, 16); cout << "N/A";
        gotoXY(57, 16); cout << "N/A";
        gotoXY(67, 16); cout << "N/A";
        gotoXY(85, 16); cout << "N/A";
        gotoXY(91, 16); cout << "N/A";
        gotoXY(103, 16); cout << "N/A";
    }
    else {
        while (tempSemester->course) {
            gotoXY(05, y); cout << tempSemester->course->courseName;
            gotoXY(45, y); cout << tempSemester->course->courseID;
            gotoXY(57, y); cout << tempSemester->course->creditNum;
            gotoXY(67, y); cout << tempSemester->course->teacherName;
            gotoXY(85, y); cout << tempSemester->course->numOfStudents;
            gotoXY(91, y); cout << tempSemester->course->courseDate;
            gotoXY(103, y); cout << tempSemester->course->courseSession;
            y++; No++; 
            tempSemester->course = tempSemester->course->pNext;
        }
    }

    string courseName, courseID, teacherName, DoW, session1, session2;
    int credit, NoS;
    
  
    gotoXY(45, y + 4); cout << "1. Add course";
    gotoXY(45, y + 5); cout << "2. Update course information";
    gotoXY(45, y + 6); cout << "3. Delete course";
    gotoXY(45, y + 7); cout << "4. Import scoreboard";
    gotoXY(45, y + 8); cout << "5. Exit";
    gotoXY(45, y + 9); cout << "Enter your choice: ";
    char choice = getchar();
    cin.ignore(100, '\n');
    switch (choice) {
    case '1':
        // Add course;
        system("cls");
        setConsoleWindow(800, 600);
        if (g_Time != "") {
            gotoXY(26, 4); cout << "Date: " << g_Time;
        }
        gotoXY(26, 5); cout << "=======================================================";
        Textcolor(Blue);
        gotoXY(48, 8); cout << "SEMESTER " << g_selectSemester;
        gotoXY(46, 10); cout << "ADDING  COURSE";
        Textcolor(7);

        tempSemester->course = new Course;

        gotoXY(30, 12); cout << "Course name: ";
        getline(cin, courseName, '\n');
        gotoXY(30, 14); cout << "Course ID: ";
        getline(cin, courseID, '\n');

        while (tempCourse && (tempCourse->courseName != courseName 
            && tempCourse->courseID != courseID))
            tempCourse = tempCourse->pNext;

        if (tempCourse) {
            gotoXY(30, 16); cout << "This course already exists!";
            Sleep(2000);
            system("cls");
            displayCourseInSemester(schoolyear);
            return;
        }

        gotoXY(30, 16); cout << "Number of credit: ";
        cin >> credit; cin.ignore();
        gotoXY(30, 18); cout << "Teacher in charge: ";
        getline(cin, teacherName, '\n');
        gotoXY(30, 20); cout << "Number of student: ";
        cin >> NoS; cin.ignore();
        gotoXY(30, 23); cout << "(If there is more than one day, separate with &, ex: TUE & WED)";
        gotoXY(30, 22); cout << "Day of the week: ";
        getline(cin, DoW, '\n');
        gotoXY(70, 25); cout << "There are 4 sessions available";
        gotoXY(80, 26); cout << "07:30"; gotoXY(89, 26); cout << "09:30";
        gotoXY(80, 27); cout << "13:30"; gotoXY(89, 27); cout << "15:30";
        gotoXY(30, 25); cout << "First session: ";
        getline(cin, session1, '\n');
        cout << endl;
        while (session1 != "7:30" && session1 != "07:30" &&
            session1 != "9:30" && session1 != "09:30" &&
            session1 != "13:30" && session1 != "15:30") {
            cout << "\t\t\t      Invalid input, try again: ";
            getline(cin, session1, '\n');
        }
        cout << "\n\t\t\t      Second session: ";
        getline(cin, session2, '\n');
        cout << endl;
        while (session2 != "7:30" && session2 != "07:30" &&
            session2 != "9:30" && session2 != "09:30" &&
            session2 != "13:30" && session2 != "15:30") {
            cout << "\t\t\t      Invalid input, try again: ";
            getline(cin, session2, '\n');
        }

        out.open(path, ios::app);
        if (out) {
            out << courseName << ",";
            out << courseID << ",";
            out << credit << ",";
            out << teacherName << ",";
            out << NoS << ",";
            out << DoW << ",";
            out << session1 + " & " + session2 << "\n";
            out.close();
            cout << "\n\t\t\t      Course has been add successfully!";
        }
        else cout << "\n\t\t\t      Unable to open file " << path;
        Sleep(2500);
        system("cls");
        displayCourseInSemester(schoolyear);
        break;
    case '2':
        // Update course info;
        
        gotoXY(45, y + 11); cout << "Enter course ID: ";
        getline(cin, courseID, '\n');
        while (pCurCase2 && pCurCase2->courseID != courseID) {
            pCurCase2 = pCurCase2->pNext;
        }
        if (!pCurCase2) {
            gotoXY(45, y + 12); cout << "Course ID " << courseID
                << " doesn't exist.";
            Sleep(2000);
            system("cls");
            displayCourseInSemester(schoolyear);
        }
        else {
            g_selectCourse = courseID;
            system("cls");
            setConsoleWindow(800, 600);
            updateCourseInfo(schoolyear);
        }
        break;
    case '3':
        // Delete course;
        gotoXY(45, y + 11); cout << "Enter course ID: ";
        getline(cin, courseID, '\n');
        while (pCurCase2 && pCurCase2->courseID != courseID) {
            pCurCase2 = pCurCase2->pNext;
        }
        if (!pCurCase2) {
            gotoXY(45, y + 12); cout << "Course ID " << courseID
                << " doesn't exist.";
            
        }
        else {
            g_selectCourse = courseID;
            deleteCourse(schoolyear);
            gotoXY(45, y + 13); cout << "Delete course " << courseID << " successfully!";
        }
        Sleep(2000);
        system("cls");
        displayCourseInSemester(schoolyear);
        break;
    case '4':
        importScoreboard(schoolyear);
        break;
    case '5':
        system("cls");
        setConsoleWindow(800, 600);
        displaySemester(schoolyear->staff, schoolyear->student, schoolyear);
        break;
    default:
        system("cls");
        displayCourseInSemester(schoolyear);
        break;
    }
}

void displayCourseWhenDayExceed(SchoolYear*& schoolyear) {
    setConsoleWindow(1000, 600);
    ofstream out;
    ifstream in;
    int y = 16, No = 0, check = 1;

    string title = { "Course name,Course ID,credits,teacher name,"
    "number of students,day,time" };

    string path = g_selectyear + "_Semester" + to_string(g_selectSemester) + ".csv";

    out.open(path, ios::app);
    if (numberOfLine(path) == 0) {
        out << title << endl;
    }
    out.close();
    getDataCoursesInSemester(schoolyear);
    Semester* tempSemester = schoolyear->semester;
    while (tempSemester && tempSemester->no != g_selectSemester)
        tempSemester = tempSemester->pNext;
    
    Course* pCur4 = tempSemester->course;
    Course* tempCourse = tempSemester->course; // Will be used to add course later;

    if (g_Time != "") {
        gotoXY(26, 4); cout << "Date: " << g_Time;
    }
    gotoXY(26, 5); cout << "==========================================================================================";
    Textcolor(Blue);
    gotoXY(63, 8); cout << "SEMESTER " << g_selectSemester;
    Textcolor(7);

    gotoXY(05, 12); cout << "Course name";
    gotoXY(45, 12); cout << "Course ID"; //25
    gotoXY(57, 12); cout << "Credits";  // 12
    gotoXY(67, 12); cout << "Teacher"; // 10
    gotoXY(85, 12); cout << "NoS"; // 18
    gotoXY(91, 12); cout << "Day"; // 6
    gotoXY(103, 12); cout << "Session"; // 12

    gotoXY(02, 14); cout << "===================================================="
        "=========================================================================";

    if (numberOfLine(path) == 1) {
        gotoXY(05, 16); cout << "N/A";
        gotoXY(45, 16); cout << "N/A";
        gotoXY(57, 16); cout << "N/A";
        gotoXY(67, 16); cout << "N/A";
        gotoXY(85, 16); cout << "N/A";
        gotoXY(91, 16); cout << "N/A";
        gotoXY(103, 16); cout << "N/A";
    }
    else {
        while (tempSemester->course) {
            gotoXY(05, y); cout << tempSemester->course->courseName;
            gotoXY(45, y); cout << tempSemester->course->courseID;
            gotoXY(57, y); cout << tempSemester->course->creditNum;
            gotoXY(67, y); cout << tempSemester->course->teacherName;
            gotoXY(85, y); cout << tempSemester->course->numOfStudents;
            gotoXY(91, y); cout << tempSemester->course->courseDate;
            gotoXY(103, y); cout << tempSemester->course->courseSession;
            y++; No++;
            tempSemester->course = tempSemester->course->pNext;
        }
    }

    gotoXY(45, y + 4); cout << "1. Export list of student into a csv file";
    gotoXY(45, y + 5); cout << "2. Import score board";
    gotoXY(45, y + 6); cout << "3. View scoreboard";
    gotoXY(45, y + 7); cout << "4. Update a student result";
    gotoXY(45, y + 8); cout << "5. Exit";
    gotoXY(45, y + 9); cout << "Enter your choice: ";
    char choice = getchar();
    string courseID;
    int studentID;
    cin.ignore(100, '\n'); 
    switch (choice) {
    case '1': // Sonw
        gotoXY(73, y + 4); cout << ": Enter course ID: ";
        getline(cin, courseID, '\n');
        g_selectCourse = courseID;
        exportListStudentInCourse(schoolyear);
        cout << "bam nut bat ky de thoat \n";
        _getch();
        system("cls");
        displayCourseWhenDayExceed(schoolyear);
        break;
    case '2': // Mountain
        gotoXY(53, y + 5); cout << ": Enter course ID: ";
        getline(cin, courseID, '\n'); 
        g_selectCourse = courseID;
        importScoreboard(schoolyear);
        system("cls");
        displayCourseWhenDayExceed(schoolyear);
        break;
    case '3': // Som
        gotoXY(50, y + 6); cout << ": Enter course ID: ";
        getline(cin, courseID, '\n');
        g_selectCourse = courseID;
        viewScore(schoolyear);
        cout << "press any ket to exit \n";
        _getch();
        system("cls");
        displayCourseWhenDayExceed(schoolyear);
        break;
    case '4': // Khang
        gotoXY(73, y + 4); cout << ": Enter course ID: ";
        getline(cin, courseID);
        g_selectCourse = courseID;
        updateStudentResult(schoolyear);
        cout << "press any ket to exit \n";
        _getch();
        system("cls");
        displayCourseWhenDayExceed(schoolyear);
        break;
    case '5':
        system("cls");
        displaySemester(schoolyear->staff, schoolyear->student, schoolyear);
        break;
    default:
        gotoXY(31, y + 11); cout << "Try again in 2...";
        Sleep(1000);
        gotoXY(31, y + 11); cout << "Try again in 1...";
        Sleep(1000);
        system("cls");
        displaySemester(schoolyear->staff, schoolyear->student, schoolyear);
        break;
    }
    
}

void displayCourseForStudent(SchoolYear*& schoolyear) {
    setConsoleWindow(1000, 600);
    ofstream out;
    ifstream in;
    int y = 16, No = 0, check = 1;

    string title = { "Course name,Course ID,credits,teacher name,credits,"
    "number of students,day,time" };

    string path = g_selectyear + "_Semester" + to_string(g_selectSemester) + ".csv";

    out.open(path, ios::app);
    if (numberOfLine(path) == 0) {
        out << title << endl;
    }
    out.close();
    getDataCoursesInSemester(schoolyear);
    Semester* tempSemester = schoolyear->semester;
    while (tempSemester && tempSemester->no != g_selectSemester)
        tempSemester = tempSemester->pNext;

    Course* tempCourse = tempSemester->course; // Will be used to add course later;

    if (g_Time != "") {
        gotoXY(26, 4); cout << "Date: " << g_Time;
    }
    gotoXY(26, 5); cout << "==========================================================================================";
    Textcolor(Blue);
    gotoXY(63, 8); cout << "SEMESTER " << g_selectSemester;
    Textcolor(7);

    gotoXY(05, 12); cout << "Course name";
    gotoXY(45, 12); cout << "Course ID"; //25
    gotoXY(57, 12); cout << "Credits";  // 12
    gotoXY(67, 12); cout << "Teacher"; // 10
    gotoXY(85, 12); cout << "NoS"; // 18
    gotoXY(91, 12); cout << "Day"; // 6
    gotoXY(103, 12); cout << "Session"; // 12

    gotoXY(02, 14); cout << "===================================================="
        "=========================================================================";

    if (numberOfLine(path) == 1) {
        gotoXY(05, 16); cout << "N/A";
        gotoXY(45, 16); cout << "N/A";
        gotoXY(57, 16); cout << "N/A";
        gotoXY(67, 16); cout << "N/A";
        gotoXY(85, 16); cout << "N/A";
        gotoXY(91, 16); cout << "N/A";
        gotoXY(103, 16); cout << "N/A";
    }
    else {
        while (tempSemester->course) {
            gotoXY(05, y); cout << tempSemester->course->courseName;
            gotoXY(45, y); cout << tempSemester->course->courseID;
            gotoXY(57, y); cout << tempSemester->course->creditNum;
            gotoXY(67, y); cout << tempSemester->course->teacherName;
            gotoXY(85, y); cout << tempSemester->course->numOfStudents;
            gotoXY(91, y); cout << tempSemester->course->courseDate;
            gotoXY(103, y); cout << tempSemester->course->courseSession;
            y++; No++;
            tempSemester->course = tempSemester->course->pNext;
        }
    }

    gotoXY(45, y + 4); cout << "1. Enroll the course";
    gotoXY(45, y + 5); cout << "2. View List Course";
    gotoXY(45, y + 6); cout << "3. Remove a Course";
    gotoXY(45, y + 7); cout << "4. Exit";
    gotoXY(45, y + 8); cout << "Enter your choice: ";
    char choice = getchar();
    string courseID;
    int studentID;
    cin.ignore(100, '\n');
    switch (choice) {
    case '1': // Sonw
        gotoXY(73, y + 4); cout << ": Enter course ID: ";
        getline(cin, courseID, '\n');
        g_selectCourse = courseID;
        enroll();
        cout << "bam nut bat ky de thoat \n";
        _getch();
        system("cls");
        displayCourseForStudent(schoolyear);
        break;
    case '2': // Mountain
        system("cls");
        viewCourseEnrolled();
        cout << "bam nut bat ky de thoat \n";
        _getch();
        displayCourseForStudent(schoolyear);
        break;
    case '3': // Som
        gotoXY(50, y + 6); cout << ": Enter course ID: ";
        getline(cin, courseID, '\n');
        g_selectCourse = courseID;
        viewScore(schoolyear);
        cout << "press any ket to exit \n";
        _getch();
        system("cls");
        displayCourseWhenDayExceed(schoolyear);
        break;
    case '4': // Khang
        gotoXY(73, y + 4); cout << ": Enter course ID: ";
        getline(cin, courseID);
        g_selectCourse = courseID;
        updateStudentResult(schoolyear);
        cout << "press any ket to exit \n";
        _getch();
        system("cls");
        displayCourseWhenDayExceed(schoolyear);
        break;
    case '5':
        system("cls");
        displaySemester(schoolyear->staff, schoolyear->student, schoolyear);
        break;
    default:
        gotoXY(31, y + 11); cout << "Try again in 2...";
        Sleep(1000);
        gotoXY(31, y + 11); cout << "Try again in 1...";
        Sleep(1000);
        system("cls");
        displaySemester(schoolyear->staff, schoolyear->student, schoolyear);
        break;
    }

}

void displaySemesterForStudent(Staff* staff, Student* student, SchoolYear* schoolyear) {
    getDataSemester(schoolyear);
    Semester* temp = schoolyear->semester;
    bool check1 = false, check2 = false, check3 = false;
    int sem = 1;
    while (temp) {
        if (temp->no == 1) check1 = true;
        else if (temp->no == 2) check2 = true;
        else if (temp->no == 3) check3 = true;
        temp = temp->pNext;
    }
    if (g_Time != "") {
        gotoXY(26, 4); cout << "Date: " << g_Time;
    }
    gotoXY(26, 5); cout << "=======================================================";
    Textcolor(Blue);
    gotoXY(38, 8); cout << "SCHOOL YEAR: " << g_selectyear;
    Textcolor(7);
    cout << "\n\n\t\t\t\tList of semester: Semester 1";
    if (!check1) cout << " (Not created)";
    cout << "\n\t\t\t\t\t\t  Semester 2";
    if (!check2) cout << " (Not created)";
    cout << "\n\t\t\t\t\t\t  Semester 3";
    if (!check3) cout << " (Not created)";

    int no;
    Semester* pCur;
    cout << "\n\n\t\t\t\t1. Get access in semester \n";
    cout << "\n\n\t\t\t\t2. Exit \n";
    cout << "\n\n\t\t\t\tEnter your choice: ";
    char choice = getchar();
    cin.ignore(100, '\n');
    switch (choice) {
    case '1':
        cout << "\n\n\t\t\t\tEnter the semester you want to get access into (number): ";
        cin >> no; cin.ignore();
        getDataSemester(schoolyear);
        pCur = schoolyear->semester;
        while (pCur && pCur->no != no) {
            pCur = pCur->pNext;
        }
        if (pCur) {
            g_selectSemester = no;
            cout << "\n\n\t\t\t\tEntering semester " << no << "...";
            Sleep(2000);
            system("cls");
            if (date_cmp(add0(pCur->register_start_date).c_str(), g_Time.c_str()) < 0
                && date_cmp(add0(pCur->register_end_date).c_str(), g_Time.c_str()) > 0)
                displayCourseForStudent(schoolyear);
            else {
                system("cls");
                
            }
            //displaySelectedYear(staff, student, schoolyear);
        }
        else {
            cout << "\n\n\t\t\tSemester " << no << " doesn't exist.";
            Sleep(2000);
            system("cls");
            displaySemesterForStudent(staff, student, schoolyear);
        }
        break;
    case '2':
        cout << "\n\n\t\t\t\tLoading...";
        Sleep(2000);
        system("cls");
        displaySchoolYearForStudent(staff, student, schoolyear);
        break;
    default:
        cout << "\n\n\t\t\t\tInvalid input. Try again..";
        Sleep(1800);
        system("cls");
        displayMenuClass(staff, student, schoolyear);
        break;
    }
}

