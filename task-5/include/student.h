#pragma once
#include "main.h"

class Student
{
protected:
    string name;
    string dayOfBirth;
    string schoolName;
    string *courseName;

    int numOfCourse;
    int numOfAssignment;
    int numOfTest;
    int numOfExam;

public:
    Student();

    Student(string, string, string);
    ~Student();
    void setName(string);
    void setDayOfBirth(string);
    void setSchoolName(string);
    void setCourseName(int);

    void setNumOfCourse(int);
    void setNumOfAssignment(int);
    void setNumOfTest(int);
    void setNumOfExam(int);

    string getName() const;
    string getDayOfBirth() const;
    string getSchoolName() const;
    string *getCourseName() const;

    int getNumOfCourse() const;
    int getNumOfAssignment() const;
    int getNumOfTest() const;
    int getNumOfExam() const;
};