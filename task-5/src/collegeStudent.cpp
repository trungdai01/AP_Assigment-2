#include "../include/collegeStudent.h"

CollegeStudent::CollegeStudent() : Student()
{
    this->setName("");
    this->setDayOfBirth("");
    this->setSchoolName("");
    this->setCourseName(3);

    this->setNumOfCourse(3);
    this->setNumOfAssignment(1);
    this->setNumOfTest(1);
    this->setNumOfExam(1);
}

CollegeStudent::CollegeStudent(string name, string dayOfBirth, string schoolName, int semester, int numOfCourse) : Student(name, dayOfBirth, schoolName)
{
    this->setName(name);
    this->setDayOfBirth(dayOfBirth);
    this->schoolName = schoolName;
    this->semester = semester;
    numOfCourse = (numOfCourse > 3) ? 3 : numOfCourse;
    this->setCourseName(numOfCourse);

    for (int i = 0; i < numOfCourse; i++)
    {
        this->getCourseName()[i] = "";
    };

    this->setNumOfCourse(numOfCourse);
    this->setNumOfAssignment(1);
    this->setNumOfTest(1);
    this->setNumOfExam(1);
}

int CollegeStudent::getSemester() const
{
    return this->semester;
}

void CollegeStudent::setSemester(int semester)
{
    this->semester = (semester > 4) ? 4 : semester;
}

College::College()
{
    listOfColStudent = NULL;
    currentSize = 0;
}

College::College(string name, int size)
{
    this->name = name;
    listOfColStudent = new CollegeStudent *[size];
    currentSize = 0;
}

College::~College()
{
    delete[] listOfColStudent;
}

string College::getColName() const
{
    return this->name;
}

void College::makeMenu()
{
    while (1)
    {
        int choice;
        cout << "\t\t\t-----------------------------------------\n";
        cout << "\t\t\t     College Management System\n";
        cout << "\t\t\t-----------------------------------------\n";

        cout << "1. Add a student\n";
        cout << "2. Display student list\n";
        cout << "3. Update a student\n";
        cout << "4. Remove a student from the list\n";
        cout << "-1. Exit the program\n";
        cout << "Enter your choice here: ";
        if (!(cin >> choice))
        {
            cout << "=======================\n";
            cout << "... Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "=======================\n";
            continue;
        }
        cin.ignore();

        cout << "=======================\n";
        switch (choice)
        {
        case ADD:
            addStudent();
            break;
        case DISPLAY:
            displayInfo();
            break;
        case UPDATE:
            updateInfo();
            break;
        case REMOVE:
            removeStudent();
            break;
        case EXIT:
            return;
        default:
            cout << "\n ..... Invalid choice, retry pls!\n\n";
            break;
        }
    }
}

void College::addStudent()
{
    string name;
    string dayOfBirth;
    int semester;
    int numOfCourse;

    cout << "Enter a student's name: ";
    getline(cin, name);
    cout << "Enter a student's dayOfBirth(dd/mm/yy): ";
    getline(cin, dayOfBirth);
    cout << "Enter a semester: ";
    cin >> semester;
    cout << "Enter a number of enrolled courses: ";
    cin >> numOfCourse;

    string uniName = this->getColName();

    CollegeStudent *Ben = new CollegeStudent(name, dayOfBirth, uniName, semester, numOfCourse);
    listOfColStudent[currentSize++] = Ben;
    cout << "=======================\n";
}

void College::displayInfo()
{
    if (currentSize == 0)
    {
        cout << " .. The list is empty!!!\n";
        cout << "=======================\n";
        return;
    }
    cout << "Current size: " << currentSize << std::endl;
    cout << "=======================\n";
    // cout << "No.\t Name\t Date Of Birth\t Uni Name\t Semester\t Courses\t Assignment\t Test\t Exam\t\n";
    cout << "-----------------------\n";
    for (int i = 0; i < currentSize; i++)
    {
        int it = i;
        cout << ++it << "." << endl;
        cout << "Name: " << listOfColStudent[i]->getName().c_str() << endl;
        cout << "Day Of Birth: " << listOfColStudent[i]->getDayOfBirth().c_str() << endl;
        cout << "College: " << this->getColName().c_str() << endl;
        cout << "Semester: " << listOfColStudent[i]->getSemester() << endl;
        cout << "No. enrolled courses: " << listOfColStudent[i]->getNumOfCourse() << endl;
        cout << "No. Assignment: " << listOfColStudent[i]->getNumOfAssignment();
        cout << "\t"
             << "No. Test: " << listOfColStudent[i]->getNumOfTest();
        cout << "\t"
             << "No. Exam: " << listOfColStudent[i]->getNumOfExam() << endl;
        cout << endl;
    }
    cout << "=======================\n";
}

void College::updateInfo()
{
    bool flag = false;
    if (currentSize == 0)
    {
        cout << " .. The list is empty!!!\n";
        return;
    }
    string name;
    cout << "Enter a name you want to update from the list: ";
    getline(cin, name);
    cout << "=======================\n";
    int positionUpdate = 0;
    for (int i = 0; i < currentSize; i++)
    {
        if (listOfColStudent[i]->getName() == name)
        {
            flag = true;
            positionUpdate = i;
            cout << "Found at index " << positionUpdate << endl;
            break;
        }
    }
    if (flag)
    {
        string name;
        string dayOfBirth;
        int semester;
        int numOfCourse;

        cout << "Enter new name: ";
        getline(cin, name);
        cout << "Enter day Of Birth(dd/mm/yy): ";
        getline(cin, dayOfBirth);
        cout << "Enter new semester: ";
        cin >> semester;
        cout << "Enter new number of enrolled courses: ";
        cin >> numOfCourse;

        listOfColStudent[positionUpdate]->setName(name);
        listOfColStudent[positionUpdate]->setDayOfBirth(dayOfBirth);
        listOfColStudent[positionUpdate]->setSemester(semester);
        listOfColStudent[positionUpdate]->setNumOfCourse(numOfCourse);
    }
    else
        cout << "Not found in the list\n";
    cout << "=======================\n";
}

void College::removeStudent()
{
    bool flag = false;
    if (currentSize == 0)
    {
        cout << " .. The list is empty!!!\n";
        return;
    }
    string name;
    cout << "Enter a name you want to remove from the list: ";
    getline(cin, name);
    cout << "=======================\n";
    int positionRemove = 0;
    for (int i = 0; i < currentSize; i++)
    {
        if (listOfColStudent[i]->getName() == name)
        {
            flag = true;
            positionRemove = i;
            cout << "Found at index " << positionRemove << endl;
            break;
        }
    }
    if (flag)
    {
        int newSize = currentSize - 1;
        CollegeStudent **newList = new CollegeStudent *[newSize];
        for (int i = 0; i < positionRemove; i++)
        {
            newList[i] = listOfColStudent[i];
        }
        for (int i = positionRemove; i < newSize; i++)
        {
            newList[i] = listOfColStudent[i + 1];
        }

        currentSize = newSize;
        delete[] listOfColStudent;
        listOfColStudent = newList;
        cout << "Remove successfully!!\n";
    }
    else
        cout << "Not found in the list\n";
    cout << "=======================\n";
}