#pragma once
#include "student.h"

class CollegeStudent : public Student
{
private:
    int semester;

public:
    CollegeStudent();
    CollegeStudent(string, string, string, int, int);

    int getSemester() const;

    void setSemester(int);
};

class College
{
private:
    string name;
    CollegeStudent **listOfColStudent;
    int currentSize;

public:
    College();
    College(string, int);
    ~College();

    string getColName() const;

    void makeMenu();
    void addStudent();
    void displayInfo();
    void updateInfo();
    void removeStudent();
};