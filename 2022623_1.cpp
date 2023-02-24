#include <iostream>
#include <cstring>

using namespace std;

const int MAX_STUDENTS = 100;
const int MAX_TEACHERS = 20;
const int MAX_COURSES = 50;

enum EducationLevel {FSC, BSC, MSC, PHD};
enum Department {CS, EE, ME, CE};
enum Grade {A, B, C, D, F};

struct Address {
    char street[100];
    char city[50];
    char country[50];
};

struct Person {
    char name[100];
    int age;
    Address address;
    EducationLevel educationLevel;
};

struct Student {
    int rollNo;
    Person person;
    Department department;
};

struct Teacher {
    Person person;
    int salary;
    Department department;
};

struct Admin {
    Person person;
    int salary;
};

struct Course {
    char name[100];
    char code[10];
    char teacherName[100];
    int enrolledStudents[MAX_STUDENTS];
    int numEnrolledStudents;
    int droppedStudents[MAX_STUDENTS];
    int numDroppedStudents;
    struct Grade gradedStudents[MAX_STUDENTS];
    int numGradedStudents;
};

int numStudents = 0;
Student students[MAX_STUDENTS];

int numTeachers = 0;
Teacher teachers[MAX_TEACHERS];

int numCourses = 0;
Course courses[MAX_COURSES];

// Admin user functions
void addStudent() {
    cout << "Enter student name: ";
    cin >> students[numStudents].person.name;
    cout << "Enter student age: ";
    cin >> students[numStudents].person.age;
    cout << "Enter student address: " << endl;
    cout << "Street: ";
    cin >> students[numStudents].person.address.street;
    cout << "City: ";
    cin >> students[numStudents].person.address.city;
    cout << "Country: ";
    cin >> students[numStudents].person.address.country;
    cout << "Enter student education level (0=FSC, 1=BSC, 2=MSC, 3=PHD): ";
    int eduLevel;
    cin >> eduLevel;
    students[numStudents].person.educationLevel = static_cast<EducationLevel>(eduLevel);
    cout << "Enter student department (0=CS, 1=EE, 2=ME, 3=CE): ";
    int dept;
    cin >> dept;
    students[numStudents].department = static_cast<Department>(dept);
    numStudents++;
}

void removeStudent() {
    int rollNo;
    cout << "Enter student roll number to remove: ";
    cin >> rollNo;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].rollNo == rollNo) {
            for (int j = i; j < numStudents - 1; j++) {
                students[j] = students[j + 1];
            }
            numStudents--;
            cout << "Student with roll number " << rollNo << " removed." << endl;
            return;
        }
    }
    cout << "Student with roll number " << rollNo << " not found." << endl;
}

void updateStudent() {
    int rollNo;
    cout << "Enter student roll number to update: ";
    cin >> rollNo;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].rollNo == rollNo) {
            cout << "Enter updated student name: ";
            cin >> students[i].person.name;
