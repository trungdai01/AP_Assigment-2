#include "university.h"

Student::Student()
{
    name = "";
    score = 0.0;
}
Student::Student(string name, double score) : name(name), score(score) {}
Student::~Student() {}

void Student::setName(string name)
{
    this->name = name;
}

void Student::setScore(double score)
{
    this->score = score;
}

string Student::getName() const
{
    return this->name;
}

double Student::getScore() const
{
    return this->score;
}

University::University()
{
    this->uniName = "";
    this->listOfStudents = NULL;
    this->currentSize = 0;
}
University::University(string uniName, int MAXNUM)
{
    this->uniName = uniName;
    this->listOfStudents = new Student *[MAXNUM];
    this->currentSize = 0;
}
University::~University()
{
    delete[] listOfStudents;
}

void University::addStudent()
{
    string name;
    double score;

    cout << "Enter a student's name: ";
    getline(cin, name);
    cout << "Enter a student's score(0 - 10): ";
    cin >> score;

    Student *Mark = new Student(name, score);
    listOfStudents[currentSize++] = Mark;
    cout << "=======================\n";
}

void University::displayListOfStudents()
{
    if (currentSize == 0)
    {
        cout << " .. The list is empty!!!\n";
        cout << "=======================\n";
        return;
    }
    cout << "Current size: " << currentSize << std::endl;
    cout << "=======================\n";
    cout << "No.\t Name\t Score\n";
    cout << "-----------------------\n";
    for (int i = 0; i < currentSize; i++)
    {
        int it = i;
        printf("%d.\t %s\t %0.2f\n", ++it, listOfStudents[i]->getName().c_str(), listOfStudents[i]->getScore());
    }
    std::cout << "=======================\n";
}

void University::displayBestStudent()
{
    if (currentSize == 0)
    {
        std::cout << "... The list is empty!!!\n";
        return;
    }
    int bestScore = 0;
    bestScore = listOfStudents[0]->getScore();
    for (int i = 0; i < currentSize; i++)
    {
        if (listOfStudents[i]->getScore() > bestScore)
        {
            bestScore = listOfStudents[i]->getScore();
        }
    }
    std::cout << "=======================\n";
    std::cout << "No.\t Name\t Score\n";
    std::cout << "-----------------------\n";
    int it = 0;
    for (int i = 0; i < currentSize; i++)
    {
        if (listOfStudents[i]->getScore() == bestScore)
        {
            printf("%d.\t %s\t %0.2f\n", ++it, listOfStudents[i]->getName().c_str(), listOfStudents[i]->getScore());
        }
    }
    std::cout << "=======================\n";
}

void University::removeStudent()
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
        if (listOfStudents[i]->getName() == name)
        {
            flag = true;
            positionRemove = i;
            cout << "Find at index " << positionRemove << endl;
            break;
        }
    }
    if (flag)
    {
        int newSize = currentSize - 1;
        Student **newList = new Student *[newSize];
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
        cout << "Remove successfully!!\n";
    }
    else
        cout << "Not found in the list\n";
    cout << "=======================\n";
}
