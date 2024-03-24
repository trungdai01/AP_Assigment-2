#pragma once
#include "student.h"

class UniStudent : public Student
{
private:
    int semester;

public:
    UniStudent();
    UniStudent(string, string, string, int, int);

    int getSemester() const;

    void setSemester(int number);
};

class University
{
private:
    string name;
    UniStudent **listOfUniStudent;
    int currentSize;

public:
    University();
    University(string, int);
    ~University();

    string getUniName() const;

    void makeMenu();
    void addStudent();
    void displayInfo();
    void updateInfo();
    void removeStudent();
};