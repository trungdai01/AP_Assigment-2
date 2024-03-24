#pragma once

#include <iostream>
#include <string>
#include <limits>

using namespace std;

enum
{
    EXIT = -1,
    ADD = 1,
    DISPLAY = 2,
    BEST = 3,
    REMOVE = 4
};

class Student
{
private:
    string name;
    double score;

public:
    Student();
    Student(string, double);
    ~Student();

    void setName(string);
    void setScore(double);
    string getName() const;
    double getScore() const;
};

class University
{
private:
    string uniName;
    Student **listOfStudents;
    int currentSize;

public:
    University();
    University(string, int);
    ~University();

    void addStudent();
    void displayListOfStudents();
    void displayBestStudent();
    void removeStudent();
};
