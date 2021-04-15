#include "Header.h"
//extern string z;


int numberOfLine(string filename) {
	ifstream in;
	in.open(filename);
	string s;
	int count = 0;
	while (!in.eof()) {
		getline(in, s, '\n');
		if (s != "") {
			count++;
		}
	}
	in.close();
	return count;
}


void getDataStaff(Staff* &pHead, string filename) {
	z_ = "5";
	ifstream in;
	string t;
	in.open(filename);
	getline(in, t, '\n');
	if (in.is_open()) {
		string nameStaff, staffAccount, staffPassword = "staff";
		Staff* pCur = pHead;
		for (int i = 1; i <= numberOfLine(filename) - 1; i++) {
			if (pHead == nullptr) {
				pHead = new Staff;
				pCur = pHead;
			}
			else {
				pCur->pNext = new Staff;
				pCur = pCur->pNext;
			}
			getline(in, nameStaff, ',');
			getline(in, staffAccount, ',');
			getline(in, staffPassword, '\n');
			pCur->nameStaff = nameStaff;
			pCur->staffAccount = staffAccount;
			pCur->staffPassword = staffPassword;
			pCur->pNext = nullptr;
		}
		in.close();
	}
	else cout << "ERROR \n";
}

void getDataStudent(Student*& pHead, string filename) {
	z_ = "10";
	ifstream in;
	string t;
	in.open(filename);
	getline(in, t, '\n');
	if (in.is_open()) {
		string Firstname, Lastname, Gender, studentPassword = "student", DoB = "N/A";
		int StudentID;
		Student* pCur = pHead;
		for (int i = 1; i <= numberOfLine(filename) - 1; i++) {
			if (pHead == nullptr) {
				pHead = new Student;
				pCur = pHead;
			}
			else {
				pCur->pNext = new Student;
				pCur = pCur->pNext;
			}
			getline(in, Firstname, ',');
			getline(in, Lastname, ',');
			getline(in, Gender, ',');
			in >> StudentID;
			char z;
			in >> z;
			getline(in, studentPassword, ',');
			getline(in, DoB, '\n');
			pCur->Firstname = Firstname;
			pCur->Lastname = Lastname;
			pCur->Gender = Gender;
			pCur->StudentID = StudentID;
			pCur->studentPassword = studentPassword;
			pCur->DoB = DoB;
			pCur->pNext = nullptr;
		}
		in.close();
	}
	else cout << "ERROR \n";
}

void getDataSchoolYear(SchoolYear*& pHead, string path) {
	ifstream in;
	string t;
	in.open(path);
	if (in.is_open()) {
		string year;
		SchoolYear* pCur = pHead;
		while (!in.eof()) {
			if (pHead == nullptr) {
				pHead = new SchoolYear;
				pCur = pHead;
			}
			else {
				pCur->pNext = new SchoolYear;
				pCur = pCur->pNext;
			}
			getline(in, year, '\n');
			pCur->year = year;
			pCur->pNext = nullptr;
		}
		in.close();
	}
	else cout << "\n";
}

void createNewYear(SchoolYear*& year_school) {
	ofstream out;
	out.open("school_year.txt", ios::app);

	cout << "\n\t\t\tPlease input the School year you want to add (2xxx_2xxx): ";
	string y;
	getline(cin, y, '\n');
	out << endl;
	out << y;
	SchoolYear* pCur = year_school;
	while (pCur->pNext != nullptr) {
		pCur = pCur->pNext;
	}
	pCur->pNext = new SchoolYear;
	pCur->pNext->year = y;
	pCur->pNext->pNext = nullptr;
	out.close();
}

void displayYear(SchoolYear* pHead) {
	cout << "\n\t\t\t\tList of school year: ";
	if (pHead) {
		cout << pHead->year;
		pHead = pHead->pNext;
	}
	while (pHead) {
		cout << "\n\t\t\t\t\t\t     " << pHead->year;
		pHead = pHead->pNext;
	}
	cout << endl;
}


void deleteList(Staff*& pHead) {
	Staff *pCur = pHead;
	while (pHead) {
		pHead = pHead->pNext;
		delete pCur;
		pCur = pHead;
	}
}
; bool loginStaff(Staff* staff, string &account) {
	cout << "\n\n\n\n\t\t\t\tAccount: ";
	string acc;
	string password;
	fflush(stdin);
	getline(cin, acc);
	cout << "\n\n\t\t\t\tPassword: ";
	fflush(stdin);
	getline(cin, password);

	while (staff && staff->staffAccount != acc) {
		staff = staff->pNext;
	}
	if (staff) {
		account = acc;
		if (password == staff->staffPassword) return true;
		else return false;
	}
	return false;
}

bool loginStudent(Student* student, int &ID) {
	cout << "\n\n\n\n\t\t\t\tStudent ID: ";
	string password;
	int StudentID;
	cin >> StudentID;
	cout << "\n\n\t\t\t\tPassword: ";
	cin.ignore();
	getline(cin, password);
	while (student && student->StudentID != StudentID) {
		student = student->pNext;
	}
	if (student && password == student->studentPassword) {
		ID = StudentID;
		return true;
	}
	return false;
}


void changePassStaff(Staff*& staff, Student* student, SchoolYear *schoolyear, string path, string account) {
	cout << "\n\t\t\t\t\tPASSWORD CHANGING\n";
	cout << "\n\t\t\t\tEnter your old password: ";
	string oldPass;
	getline(cin, oldPass, '\n');
	Staff* pCur = staff;
	while (pCur && pCur->staffAccount != account) {
		pCur = pCur->pNext;
	}
	while (oldPass == pCur->staffPassword) {
		cout << "\n\t\t\t\tEnter your new password: ";
		string tempPass, newPass;
		getline(cin, tempPass, '\n');

		cout << "\n\t\t\t\tEnter your new password again: ";
		getline(cin, newPass, '\n'); 

		if (tempPass == newPass) {
			cout << "\n\t\t\t\tLoading...\n";
			Sleep(3000);
			cout << "\n\t\t\t\tYour password has been changed successfully!\n";
			pCur->staffPassword = newPass;
			ifstream in;
			ofstream out;
			string title;
			string nameStaff, staffAccount, staffPassword;
			in.open(path);
			if (in) {
				out.open("temp.csv");
				getline(in, title, '\n');
				out << title << endl;
				for (int i = 1; i <= numberOfLine(path) - 1 ; i++) {
					getline(in, nameStaff, ',');
					out << nameStaff << ",";
					getline(in, staffAccount, ',');
					out << staffAccount << ",";
					getline(in, staffPassword, '\n');
					if (staffAccount == pCur->staffAccount) {
						out << newPass << endl;
					}
					else {
						out << staffPassword << endl;
					}
				}
				out.close();
				in.close();
				remove("Staff.csv");
				rename("temp.csv", "Staff.csv");
			}
			else {
				cout << "ERROR";
			}
			cout << "\n\t\t\t\tPress any key to return back to the previous page...";
			_getch();
			system("cls");
			displayLoginStaff(staff, student, schoolyear, account);
			return;
		}

		cout << "\n\t\t\t\tYour two inputs are not the same. Do you want to insert again?\n\t\t\t\t(y/n): ";
		char choice; cin >> choice; cin.ignore();
		if (choice == 'n' || choice == 'N') {
			cout << "\n\t\t\t\tLoading...\n";
			Sleep(2000);
			system("cls");
			displayLoginStaff(staff,student, schoolyear, account);
			return;
		}
		else continue;
	}
	cout << "\n\t\t\t\tWrong old password! Do you want to insert again?\n\t\t\t\t(y/n): ";
	char choice; cin >> choice; cin.ignore();
	if (choice == 'n' || choice == 'N') {
		cout << "\n\t\t\t\tLoading...\n";
		Sleep(3000);
		system("cls");
		displayLoginStaff(staff, student, schoolyear, account);
		return;
	}
	else {
		system("cls");
		changePassStaff(staff,student, schoolyear, path, account);
	}
}



void changePassStudent(Staff* staff, Student*& student, SchoolYear* schoolyear, string path, int ID) {
	cout << "\n\t\t\t\t\tPASSWORD CHANGING\n";
	cout << "\n\t\t\t\tEnter your old password: ";
	string oldPass;
	string title;
	string Firstname, Lastname, Gender, studentPassword;
	getline(cin, oldPass, '\n');

	Student* pCur = student;
	while (pCur && pCur->StudentID != ID) {
		pCur = pCur->pNext;
	}

	while (oldPass == pCur->studentPassword) {
		cout << "\n\t\t\t\tEnter your new password: ";
		string tempPass, newPass;
		getline(cin, tempPass, '\n');

		cout << "\n\t\t\t\tEnter your new password again: ";
		getline(cin, newPass, '\n');

		if (tempPass == newPass) {
			cout << "\n\t\t\t\tLoading...\n";
			Sleep(3000);
			cout << "\n\t\t\t\tYour password has been changed successfully!\n";
			pCur->studentPassword = newPass;
			ifstream in;
			ofstream out;
			in.open(path);
			if (in) {
				out.open("tempStudent.csv");
				getline(in, title, '\n');
				out << title << endl;
				for (int i = 1; i <= numberOfLine(path) - 1; i++) {
					getline(in, Firstname, ',');
					out << Firstname << ",";
					getline(in, Lastname, ',');
					out << Lastname << ",";
					getline(in, Gender, ',');
					out << Gender << ",";
					in >> ID;
					out << ID << ",";
					char z;
					in >> z;
					getline(in, studentPassword, '\n');
					if (ID == pCur->StudentID) {
						out << newPass << endl;
					}
					else {
						out << studentPassword << endl;
					}
				}
				out.close();
				in.close();
				remove("Student.csv");
				rename("tempStudent.csv", "Student.csv");
			}
			else {
				cout << "ERROR";
			}
			cout << "\n\t\t\t\tPress any key to return back to the previous page...";
			_getch();
			system("cls");
			displayLoginStudent(staff, student, schoolyear, ID);
			return;
		}

		cout << "\n\t\t\t\tYour two inputs are not the same. Do you want to insert again?\n\t\t\t\t(y/n): ";
		char choice; cin >> choice; cin.ignore();
		if (choice == 'n' || choice == 'N') {
			cout << "\n\t\t\t\tLoading...\n";
			Sleep(3000);
			system("cls");
			displayLoginStudent(staff, student, schoolyear, ID);
			return;
		}
		else continue;
	}
	cout << "\n\t\t\t\tWrong old password! Do you want to insert again?\n\t\t\t\t(y/n): ";
	char choice; cin >> choice; cin.ignore();
	if (choice == 'n' || choice == 'N') {
		cout << "\n\t\t\t\tLoading...\n";
		Sleep(3000);
		system("cls");
		displayLoginStudent(staff, student, schoolyear, ID);
		return;
	}
	else {
		system("cls");
		changePassStudent(staff, student, schoolyear, path, ID);
	}
}
void createClassForYear(SchoolYear*& Schoolyear){
    string class_name;
	cin.ignore();
	getline(cin, class_name);
	Schoolyear->classes = nullptr;
	Class* pcur = Schoolyear->classes;
	while (pcur != nullptr) {
		pcur = pcur->pNext;
	}
	pcur = new Class;
	pcur->className= class_name;
	pcur->pNext = nullptr;
	ofstream out;
	string path = "2021_2022_classes.txt";
	out.open(path, ios::app);
	out << class_name << endl;
	out.close();
}

void createSemester(SchoolYear* &Schoolyear) {
	ofstream out;
	int no;
		string start_date, end_date, register_start_date, register_end_date, teacher_name;
		cout << "\n\t\t\t\tThis is for 1st, 2nd or 3rd semester? ";
		cin >> no;
		string path = Schoolyear->year + "_semester.txt";
		out.open(path, ios::app);
		while (no < 1 && no > 3) {
			out << "\n\t\t\t\tError. Please input again: ";
			cin >> no;
		}
		cin.ignore();
		Semester* pcur = Schoolyear->semester;
		while (pcur != nullptr) {
			pcur = pcur->pNext;
		}
		pcur = new Semester;
		string t = "Semester";
		t.push_back(char(no + 48));
		out << t << ",";
		cout << "\n\t\t\t\tStart date: ";
		getline(cin, start_date);
		out << start_date << ",";
		pcur->start_date = start_date;
		cout << "\n\t\t\t\tEnd date: ";
		getline(cin, end_date);
		out << end_date << ",";
		pcur->end_date = end_date;
		cout << "\n\t\t\t\tRegister start date: ";
		getline(cin, register_start_date);
		out << register_start_date << ",";
		pcur->register_start_date = register_start_date;
		cout << "\n\t\t\t\tRegister end date: ";
		getline(cin, register_end_date);
		out << register_end_date << ",";
		pcur->register_end_date = register_end_date;
		cout << "Teacher in charge: ";
		getline(cin, teacher_name);
		out << teacher_name << endl;
		pcur->teacher_name = teacher_name;
		out.close();
}

void getDataClass(SchoolYear*& Schoolyear) {
	ifstream in;
	ofstream out;
	Class* pCur = Schoolyear->classes;
	string filename = "2022_2023_classes.txt";
	out.open(filename);
	in.open(filename);
	if (in) {
		for (int i = 1; i <= numberOfLine(filename); i++) {
			if (Schoolyear->classes == nullptr) {
				Schoolyear->classes = new Class;
				pCur = Schoolyear->classes;
			}
			else {
				pCur->pNext = new Class;
				pCur = pCur->pNext;
			}
			getline(in, pCur->className);
			pCur->pNext = nullptr;
		}
		in.close();
		out.close();
	}
	else cout << "ERROR\n";
}

void displayClass(SchoolYear* schoolyear) {
	while (schoolyear->classes != nullptr) {
		cout << schoolyear->classes->className << endl;
		schoolyear->classes = schoolyear->classes->pNext;
	}
}

