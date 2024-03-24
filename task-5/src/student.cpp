#include "../include/student.h"

Student::Student()
{
    this->name = "";
    this->dayOfBirth = "";
    this->schoolName = "";
    for (int i = 0; i < 100; i++)
    {
        courseName[i] = "";
    }
}
Student::Student(string name, string dayOfBirth, string schoolName) : name(name), dayOfBirth(dayOfBirth), schoolName(schoolName) {}
Student::~Student()
{
    delete[] courseName;
}

void Student::setName(string name)
{
    this->name = name;
}
void Student::setDayOfBirth(string dayOfBirth)
{
    this->dayOfBirth = dayOfBirth;
}
void Student::setSchoolName(string schoolName)
{
    this->schoolName = schoolName;
}
void Student::setCourseName(int length)
{
    this->courseName = new string[length];
}

void Student::setNumOfAssignment(int numOfAssignment)
{
    this->numOfAssignment = numOfAssignment;
}
void Student::setNumOfTest(int numOfTest)
{
    this->numOfTest = numOfTest;
}
void Student::setNumOfExam(int numOfExam)
{
    this->numOfExam = numOfExam;
}
void Student::setNumOfCourse(int numOfCourse)
{
    this->numOfCourse = numOfCourse;
}

string Student::getName() const
{
    return this->name;
}
string Student::getDayOfBirth() const
{
    return this->dayOfBirth;
}
string Student::getSchoolName() const
{
    return this->schoolName;
}
string *Student::getCourseName() const
{
    return this->courseName;
}

int Student::getNumOfCourse() const
{
    return this->numOfCourse;
}
int Student::getNumOfAssignment() const
{
    return this->numOfAssignment * this->numOfCourse;
}
int Student::getNumOfTest() const
{
    return this->numOfTest * this->numOfCourse;
}
int Student::getNumOfExam() const
{
    return this->numOfExam * this->numOfCourse;
}
