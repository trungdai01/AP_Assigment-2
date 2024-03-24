#pragma once

#include <iostream>
#include <string>
#include <array>
#include <limits>

int randomGenerator() {
    time_t now = time(NULL);
    int random = rand();
    return random % 10 + 1;
}

class Student {
    std::string name;
    std::string birthday;
    std::string school_name;
    std::string *course_name;

    int course_number;
    int assignment_number;
    int test_number;
    int exam_number;
    // course_names_t course_name;
public: 
    Student() {
        this->name = "";
        this->birthday = "";
        this->school_name = "";
        for (int i = 0; i < 100; i++) {
            course_name[i] = "";
        }
    };

    Student(std::string name, std::string birthday, std::string school_name) {

        this->name = name;
        this->birthday = birthday;
        this->school_name = school_name;
    };

    std::string getName() {
        return this->name;
    };
    std::string getBirthday() {
        return this->birthday;
    };
    std::string getSchoolname() {
        return this->school_name;
    };
    std::string *getCoursename() {
        return this->course_name;
    };

    void setName(std::string name) {
        this->name = name;
    };
    void setBirthday(std::string birthday) {
        this->birthday = birthday;
    };
    void setSchoolName(std::string school_name) {
        this->school_name = school_name;
    };
    void setCourseName(int length) {
        this->course_name = new std::string[length];
    };

    
    int getCourseNumber() {
        return this->course_number;
    }
    int getAssignmentNumber() {
        return this->assignment_number;
    }
    int getTestNumber() {
        return this->test_number;
    }
    int getExamNumber() {
        return this->exam_number;
    }

    void setCourseNumber(int number) {
        this->course_number = number;
    }
    void setAssignmentNumber(int number) {
        this->assignment_number = number * this->course_number;
    }
    void setTestNumber(int number) {
        this->test_number = number * this->course_number;
    }
    void setExamNumber(int number) {
        this->exam_number = number * this->course_number;
    }

    virtual void DoAssignment() = 0;
    virtual void TakeTest() = 0;
    virtual void TakeExam() = 0;
};

class UniStudent : public Student {
    int semester;
public:
    UniStudent(std::string name, std::string birthday, std::string school_name, int course_number) : Student(name, birthday, school_name) {
        if (course_number > 4) course_number = 4;
        this->setName(name);
        this->setBirthday(birthday);
        this->setSchoolName(school_name);
        this->setCourseName(course_number);

        for (int i = 0; i < course_number; i++) {
            this->getCoursename()[i] = "";
        };

        this->setCourseNumber(course_number);
        this->setAssignmentNumber(3);
        this->setTestNumber(2);
        this->setExamNumber(1);
    };

    UniStudent() : Student() {
        this->setName("");
        this->setBirthday("");
        this->setSchoolName("");
        this->setCourseName(4);

        this->setCourseNumber(4);
        this->setAssignmentNumber(3);
        this->setTestNumber(2);
        this->setExamNumber(1);
    };

    int getSemester() {
        return this->semester;
    };

    void setSemester(int number) {
        if (number > 8) this->semester = 8;
        else this->semester = number;
    }

    void DoAssignment() override {
        std::cout << "Assignment score of " << this->getName() << " is: " << std::endl;
        for (int i = 0; i < this->getAssignmentNumber(); i++) {
            std::cout << "Assignment number " << i + 1 << " : " << randomGenerator() << std::endl;
        }
    }

    void TakeTest() override {
        std::cout << "Test score of " << this->getName() << " is: " << std::endl;
        for (int i = 0; i < this->getTestNumber(); i++) {
            std::cout << "Test number " << i + 1 << " : " << randomGenerator() << std::endl;
        }
    }

    void TakeExam() override {
        std::cout << "Exam score of " << this->getName() << " is: " << std::endl;
        for (int i = 0; i < this->getExamNumber(); i++) {
            std::cout << "Exam number " << i + 1 << " : " << randomGenerator() << std::endl;
        }
    }
};

class CollegeStudent : public Student {
    int semester;
public:
    CollegeStudent(std::string name, std::string birthday, std::string school_name, int course_number) : Student(name, birthday, school_name) {
        if (course_number > 3) course_number = 3; 
        this->setName(name);
        this->setBirthday(birthday);
        this->setSchoolName(school_name);
        this->setCourseName(course_number);

        for (int i = 0; i < course_number; i++) {
            this->getCoursename()[i] = "";
        };

        this->setCourseNumber(course_number);
        this->setAssignmentNumber(1);
        this->setTestNumber(1);
        this->setExamNumber(1);
    };

    CollegeStudent() : Student() {
        this->setName("");
        this->setBirthday("");
        this->setSchoolName("");
        this->setCourseName(3);

        this->setCourseNumber(3);
        this->setAssignmentNumber(1);
        this->setTestNumber(1);
        this->setExamNumber(1);
    };

    int getSemester() {
        return this->semester;
    };

    void setSemester(int number) {
        if (number > 4) this->semester = 4;
        else this->semester = number;
    }

    void DoAssignment() override {
        std::cout << "Assignment score of " << this->getName() << " is: " << std::endl;
        for (int i = 0; i < this->getAssignmentNumber(); i++) {
            std::cout << "Assignment number " << i + 1 << " : " << randomGenerator() << std::endl;
        }
    }

    void TakeTest() override {
        std::cout << "Test score of " << this->getName() << " is: " << std::endl;
        for (int i = 0; i < this->getTestNumber(); i++) {
            std::cout << "Test number " << i + 1 << " : " << randomGenerator() << std::endl;
        }
    }

    void TakeExam() override {
        std::cout << "Exam score of " << this->getName() << " is: " << std::endl;
        for (int i = 0; i < this->getExamNumber(); i++) {
            std::cout << "Exam number " << i + 1 << " : " << randomGenerator() << std::endl;
        }
    }
};

class University
{
private:
    std::string uniName;
    UniStudent **listOfStudents;
    int currentSize;

public:
    University() {
        this->uniName = "";
        this->listOfStudents = NULL;
        this->currentSize = 0;
    };

    University(std::string uniName, int MAXNUM) {
        this->uniName = uniName;
        this->listOfStudents = new UniStudent *[MAXNUM];
        this->currentSize = 0;
    };
    ~University() {
        delete[] listOfStudents;
    };

    void addStudent() {
        std::string name;
        std::string birthday;
        std::string school_name;
        int semester;
        int course_number;

        std::cout << "Enter a student's name: ";
        std::getline(std::cin, name);
        std::cout << "Enter a student's birthday: ";
        std::getline(std::cin, birthday);
        std::cout << "Enter a student's school: ";
        std::getline(std::cin, school_name);
        std::cout << "Enter a student's semester: ";
        std::cin >> semester;
        std::cout << "Enter a student's number of course: ";
        std::cin >> course_number;

        UniStudent *newStudent = new UniStudent(name, birthday, school_name, course_number);
        newStudent->setSemester(semester);
        listOfStudents[currentSize++] = newStudent;
        std::cout << "=======================\n";
    };
    void displayListOfStudents() {
        if (currentSize == 0)
        {
            std::cout << " .. The list is empty!!!\n";
            std::cout << "=======================\n";
            return;
        }
            std::cout << "Current size: " << currentSize << std::endl;
            std::cout << "=======================\n";
            std::cout << "No.\t Name\t Birthday School\t Semester\t Courses Assignments\t Tests\t Exams\t\n";
            std::cout << "-----------------------\n";
        for (int i = 0; i < currentSize; i++)
        {
            int it = i;
            printf("%d.\t %s\t %s\t %s\t %d\t %d\t %d\t %d\t %d\t\n", ++it, listOfStudents[i]->getName().c_str(), listOfStudents[i]->getBirthday().c_str(), listOfStudents[i]->getSchoolname().c_str(), listOfStudents[i]->getSemester(), listOfStudents[i]->getCourseNumber(), listOfStudents[i]->getAssignmentNumber(), listOfStudents[i]->getTestNumber(), listOfStudents[i]->getExamNumber());
        }
        std::cout << "=======================\n";
    };
    void removeStudent() {
        bool flag = false;
        if (currentSize == 0)
        {
            std::cout << " .. The list is empty!!!\n";
            return;
        }
        std::string name;
        std::cout << "Enter a name you want to remove from the list: ";
        std::getline(std::cin, name);
        std::cout << "=======================\n";
        int positionRemove = 0;
        for (int i = 0; i < currentSize; i++)
        {
            if (listOfStudents[i]->getName() == name)
            {
                flag = true;
                positionRemove = i;
                std::cout << "Find at index " << positionRemove << std::endl;
                break;
            }
        }
        if (flag)
        {
            int newSize = currentSize - 1;
            UniStudent **newList = new UniStudent *[newSize];
            for (int i = 0; i < positionRemove; i++)
            {
                newList[i] = listOfStudents[i];
            }
            for (int i = positionRemove; i < newSize; i++)
            {
                newList[i] = listOfStudents[i + 1];
            }

            currentSize = newSize;
            delete[] listOfStudents;
            listOfStudents = newList;
            std::cout << "Remove successfully!!\n";
        }
        else
            std::cout << "Not found in the list\n";
        std::cout << "=======================\n";
    };

    void getAssignmentResultFromStudent() {
        bool flag = false;
        if (currentSize == 0)
        {
            std::cout << " .. The list is empty!!!\n";
            return;
        }
        std::string name;
        std::cout << "Enter a name you want to get assignement results from the list: ";
        std::getline(std::cin, name);
        std::cout << "=======================\n";
        int position = 0;
        for (int i = 0; i < currentSize; i++)
        {
            if (listOfStudents[i]->getName() == name)
            {
                flag = true;
                position = i;
                std::cout << "Find at index " << position << std::endl;
                break;
            }
        }
        if (flag) {
            listOfStudents[position]->DoAssignment();
        }
        else
            std::cout << "Not found in the list\n";
        std::cout << "=======================\n";
    }
    void getTestResultFromStudent() {
        bool flag = false;
        if (currentSize == 0)
        {
            std::cout << " .. The list is empty!!!\n";
            return;
        }
        std::string name;
        std::cout << "Enter a name you want to get test results from the list: ";
        std::getline(std::cin, name);
        std::cout << "=======================\n";
        int position = 0;
        for (int i = 0; i < currentSize; i++)
        {
            if (listOfStudents[i]->getName() == name)
            {
                flag = true;
                position = i;
                std::cout << "Find at index " << position << std::endl;
                break;
            }
        }
        if (flag) {
            listOfStudents[position]->TakeTest();
        }
        else
            std::cout << "Not found in the list\n";
        std::cout << "=======================\n";
    }
    void getExamResultFromStudent() {
        bool flag = false;
        if (currentSize == 0)
        {
            std::cout << " .. The list is empty!!!\n";
            return;
        }
        std::string name;
        std::cout << "Enter a name you want to get exam results from the list: ";
        std::getline(std::cin, name);
        std::cout << "=======================\n";
        int position = 0;
        for (int i = 0; i < currentSize; i++)
        {
            if (listOfStudents[i]->getName() == name)
            {
                flag = true;
                position = i;
                std::cout << "Find at index " << position << std::endl;
                break;
            }
        }
        if (flag) {
            listOfStudents[position]->TakeExam();
        }
        else
            std::cout << "Not found in the list\n";
        std::cout << "=======================\n";
    }
};

class College
{
private:
    std::string uniName;
    CollegeStudent **listOfStudents;
    int currentSize;

public:
    College() {
        this->uniName = "";
        this->listOfStudents = NULL;
        this->currentSize = 0;
    };

    College(std::string uniName, int MAXNUM) {
        this->uniName = uniName;
        this->listOfStudents = new CollegeStudent *[MAXNUM];
        this->currentSize = 0;
    };
    ~College() {
        delete[] listOfStudents;
    };

    void addStudent() {
        std::string name;
        std::string birthday;
        std::string school_name;
        int semester;
        int course_number;

        std::cout << "Enter a student's name: ";
        std::getline(std::cin, name);
        std::cout << "Enter a student's birthday: ";
        std::getline(std::cin, birthday);
        std::cout << "Enter a student's school: ";
        std::getline(std::cin, school_name);
        std::cout << "Enter a student's semester: ";
        std::cin >> semester;
        std::cout << "Enter a student's number of course: ";
        std::cin >> course_number;

        CollegeStudent *newStudent = new CollegeStudent(name, birthday, school_name, course_number);
        newStudent->setSemester(semester);
        listOfStudents[currentSize++] = newStudent;
        std::cout << "=======================\n";
    };
    void displayListOfStudents() {
        if (currentSize == 0)
        {
            std::cout << " .. The list is empty!!!\n";
            std::cout << "=======================\n";
            return;
        }
            std::cout << "Current size: " << currentSize << std::endl;
            std::cout << "=======================\n";
            std::cout << "No.\t Name\t Birthday School\t Semester\t Courses Assignments\t Tests\t Exams\t\n";
            std::cout << "-----------------------\n";
        for (int i = 0; i < currentSize; i++)
        {
            int it = i;
            printf("%d.\t %s\t %s\t %s\t %d\t %d\t %d\t %d\t %d\t\n", ++it, listOfStudents[i]->getName().c_str(), listOfStudents[i]->getBirthday().c_str(), listOfStudents[i]->getSchoolname().c_str(), listOfStudents[i]->getSemester(), listOfStudents[i]->getCourseNumber(), listOfStudents[i]->getAssignmentNumber(), listOfStudents[i]->getTestNumber(), listOfStudents[i]->getExamNumber());
        }
        std::cout << "=======================\n";
    };
    void removeStudent() {
        bool flag = false;
        if (currentSize == 0)
        {
            std::cout << " .. The list is empty!!!\n";
            return;
        }
        std::string name;
        std::cout << "Enter a name you want to remove from the list: ";
        std::getline(std::cin, name);
        std::cout << "=======================\n";
        int positionRemove = 0;
        for (int i = 0; i < currentSize; i++)
        {
            if (listOfStudents[i]->getName() == name)
            {
                flag = true;
                positionRemove = i;
                std::cout << "Find at index " << positionRemove << std::endl;
                break;
            }
        }
        if (flag)
        {
            int newSize = currentSize - 1;
            CollegeStudent **newList = new CollegeStudent *[newSize];
            for (int i = 0; i < positionRemove; i++)
            {
                newList[i] = listOfStudents[i];
            }
            for (int i = positionRemove; i < newSize; i++)
            {
                newList[i] = listOfStudents[i + 1];
            }

            currentSize = newSize;
            delete[] listOfStudents;
            listOfStudents = newList;
            std::cout << "Remove successfully!!\n";
        }
        else
            std::cout << "Not found in the list\n";
        std::cout << "=======================\n";
    };

    void getAssignmentResultFromStudent() {
        bool flag = false;
        if (currentSize == 0)
        {
            std::cout << " .. The list is empty!!!\n";
            return;
        }
        std::string name;
        std::cout << "Enter a name you want to get assignement results from the list: ";
        std::getline(std::cin, name);
        std::cout << "=======================\n";
        int position = 0;
        for (int i = 0; i < currentSize; i++)
        {
            if (listOfStudents[i]->getName() == name)
            {
                flag = true;
                position = i;
                std::cout << "Find at index " << position << std::endl;
                break;
            }
        }
        if (flag) {
            listOfStudents[position]->DoAssignment();
        }
        else
            std::cout << "Not found in the list\n";
        std::cout << "=======================\n";
    }
    void getTestResultFromStudent() {
        bool flag = false;
        if (currentSize == 0)
        {
            std::cout << " .. The list is empty!!!\n";
            return;
        }
        std::string name;
        std::cout << "Enter a name you want to get test results from the list: ";
        std::getline(std::cin, name);
        std::cout << "=======================\n";
        int position = 0;
        for (int i = 0; i < currentSize; i++)
        {
            if (listOfStudents[i]->getName() == name)
            {
                flag = true;
                position = i;
                std::cout << "Find at index " << position << std::endl;
                break;
            }
        }
        if (flag) {
            listOfStudents[position]->TakeTest();
        }
        else
            std::cout << "Not found in the list\n";
        std::cout << "=======================\n";
    }
    void getExamResultFromStudent() {
        bool flag = false;
        if (currentSize == 0)
        {
            std::cout << " .. The list is empty!!!\n";
            return;
        }
        std::string name;
        std::cout << "Enter a name you want to get exam results from the list: ";
        std::getline(std::cin, name);
        std::cout << "=======================\n";
        int position = 0;
        for (int i = 0; i < currentSize; i++)
        {
            if (listOfStudents[i]->getName() == name)
            {
                flag = true;
                position = i;
                std::cout << "Find at index " << position << std::endl;
                break;
            }
        }
        if (flag) {
            listOfStudents[position]->TakeExam();
        }
        else
            std::cout << "Not found in the list\n";
        std::cout << "=======================\n";
    }
};