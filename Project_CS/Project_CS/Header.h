#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <direct.h>
#include "Console.h"


using namespace std;

struct Student {
    int No, StudentID, SocialID;
    float totalMark, finalMark, midtermMark, otherMark;
    string studentPassword = "12345678";
    string Firstname, Lastname;
    string Gender;
    string DoB;
    string studentClass;
    Student* pNext;
};


struct Course {
    string courseID, courseName;
    string teacherName;
    int creditNum;
    int maxNum_ofStudents = 50;
    int numOfStudents;
    string courseDate;
    string courseSession;
    Student* studentInCourse;
    Course* pNext;
};


struct Staff {
    string nameStaff;
    string staffAccount, staffPassword = "staff";
    /*Class* staffClass;*/
    Course* staffCourse;
    /*string teacherCourse = "N/A";
    string teacherClass = "N/A";*/
    Staff* pNext;
};

struct Class {
    string className;
    Student* student;
    Staff* staff;
    Class* pNext;
};

struct Semester {
    int no;
    string start_date, end_date, register_start_date, register_end_date, teacher_name;
    int max_NoS[50];
    Course* course;
    Semester* pNext;
};

struct SchoolYear {
    string year;
    Class* classes;
    SchoolYear* pNext;
    Student* student;
    Semester* semester = nullptr;
    Staff* staff;
};



// Get Input
void getDataStaff(Staff* &pHead, string filename);
void getDataSchoolYear(SchoolYear*& school_year, string path);
void getDataStudent(Student*& pHead, string filename);
void getDataClass(SchoolYear*& Schoolyear);
void getDataSemester(SchoolYear*& schoolyear);
void getDataStudentinClass(SchoolYear*& schoolyear);
void getDataCourseInSemester(SchoolYear*& schoolyear);
void getDataStudentInCourse(SchoolYear*& schoolyear);
void createClassForYear(SchoolYear*& Schoolyear);
void createSemester(SchoolYear*& Schoolyear);
void deleteList(Staff*& pHead);
void createNewYear(SchoolYear*& school_year);
void inputStudent();
void AddStudentIntoClass(SchoolYear*& schoolyear, Student*& student, string path);
void updateCourse(SchoolYear); // Phat
void deleteACourse(SchoolYear); // Phat
void exportListStudentInCourse(SchoolYear* schoolyear, string name_course);
void enroll(SchoolYear* &schoolyear);


// Login Functions
void changePassStaff(Staff*& staff, Student* student,SchoolYear *schoolyear, string path);
void changePassStudent(Staff* staff, Student*& student, SchoolYear* schoolyear, string path);
bool loginStaff(Staff* staff);
bool loginStudent(Student* student);

// khi khoi tao student ko co hoc sinh nho xuong dong
// Display menus function
void displayLogin(Staff *staff, Student *student, SchoolYear *schoolyear);
void displayLoginStaff(Staff* staff, Student* student, SchoolYear* schoolyear);
void displaySchoolYearForStaff(Staff* staff, Student* student, SchoolYear* &schoolyear);
void displaySchoolYearForStudent(Staff* staff, Student* student, SchoolYear*& schoolyear);
void displayStaffProfile(Staff* staff);
void displayLoginStudent(Staff* staff, Student* student, SchoolYear* schoolyear);
void displayStudentProfile(Student*& student, string path);
void displayClass(SchoolYear* schoolyear);
void displayMenuClass(Staff* staff, Student* student, SchoolYear* &schoolyear);
void displayYear(SchoolYear* pHead);
string displaySelectedYearForStaff(Staff* staff, Student* student, SchoolYear* schoolyear);
string displaySelectedYearForStudent(Staff* staff, Student* student, SchoolYear* schoolyear);
void displayStudentInClass(SchoolYear*& schoolyear, Student* student);
void displaySemester(Staff* staff, Student* student, SchoolYear* schoolyear);// Phat
void displayCourseInSemester(SchoolYear*& schoolyear); // Phat
void displayCourseWhenDayExceed(SchoolYear*& schoolyear);
void viewScore(SchoolYear* schoolyear);


// Others
int numberOfLine(string filename);
void loadingSuccess();
string add0(string date);
int date_cmp(const char* d1, const char* d2);
void sortedList(struct Semester** head_ref, struct Semester* new_node);

