#include <iostream>
#include <string>
#include <limits>

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
    std::string name;
    double score;

public:
    Student()
    {
        name = "";
        score = 0.0;
    }
    Student(std::string name, double score)
    {
        this->name = name;
        this->score = score;
    }
    ~Student() {}

    void setScore(double score)
    {
        this->score = score;
    }
    void setName(std::string name)
    {
        this->name = name;
    }
    std::string getName() const
    {
        return this->name;
    }
    double getScore() const
    {
        return this->score;
    }
};

void addStudent(Student **&list, int &size)
{
    std::string name;
    double score;

    std::cout << "Enter a student's name: ";
    getline(std::cin, name);
    std::cout << "Enter a student's score(0 - 10): ";
    std::cin >> score;

    Student *Mark = new Student(name, score);
    list[size++] = Mark;
}

void displayStudent(Student **&list, int &size)
{
    if (size == 0)
    {
        std::cout << " .. The list is empty!!!\n";
        return;
    }
    std::cout << "Current size: " << size << std::endl;
    std::cout << "=======================\n";
    std::cout << "No.\t Name\t Score\n";
    std::cout << "-----------------------\n";
    for (int i = 0; i < size; i++)
    {
        int it = i;
        printf("%d.\t %s\t %0.2f\n", ++it, list[i]->getName().c_str(), list[i]->getScore());
    }
    std::cout << "=======================\n";
}

void displayBestStudent(Student **&list, int &size)
{
    if (size == 0)
    {
        std::cout << "... The list is empty!!!\n";
        return;
    }
    int bestScore = 0;
    bestScore = list[0]->getScore();
    for (int i = 0; i < size; i++)
    {
        if (list[i]->getScore() > bestScore)
        {
            bestScore = list[i]->getScore();
        }
    }
    std::cout << "=======================\n";
    std::cout << "No.\t Name\t Score\n";
    std::cout << "-----------------------\n";
    int it = 0;
    for (int i = 0; i < size; i++)
    {
        if (list[i]->getScore() == bestScore)
        {
            printf("%d.\t %s\t %0.2f\n", ++it, list[i]->getName().c_str(), list[i]->getScore());
        }
    }
    std::cout << "=======================\n";
}

void removeStudent(Student **&list, int &size)
{
    bool flag = false;
    if (size == 0)
    {
        std::cout << " .. The list is empty!!!\n";
        return;
    }
    std::string name;
    std::cout << "Enter a name you want to remove from the list: ";
    getline(std::cin, name);
    int positionRemove = 0;
    for (int i = 0; i < size; i++)
    {
        if (list[i]->getName() == name)
        {
            flag = true;
            positionRemove = i;
            std::cout << "Find index at " << positionRemove << std::endl;
            break;
        }
    }
    if (flag)
    {
        int newSize = size - 1;
        Student **newList = new Student *[newSize];
        for (int i = 0; i < positionRemove; i++)
        {
            newList[i] = list[i];
        }
        for (int i = positionRemove; i < newSize; i++)
        {
            newList[i] = list[i + 1];
        }

        size = newSize;
        delete[] list;
        list = newList;
        std::cout << "Remove successfully!!\n";
    }
    else
        std::cout << "Not found in the list\n";
}

int main()
{
    int numOfStudents = 0;
    Student **listOfStudents = new Student *[100];

    std::cout << "+++++++++++++++++" << std::endl;
    std::cout << "+   Education   +\n";
    std::cout << "+++++++++++++++++" << std::endl;
    for (;;)
    {
        int choice;

        std::cout << "1. Add a student" << std::endl;
        std::cout << "2. Display student list" << std::endl;
        std::cout << "3. Display best student" << std::endl;
        std::cout << "4. Remove a student from the list" << std::endl;
        std::cout << "-1. Exit the program" << std::endl;
        std::cout << "Enter your choice here: ";
        if (!(std::cin >> choice))
        {
            std::cout << "... Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore();

        switch (choice)
        {
        case ADD:
            addStudent(listOfStudents, numOfStudents);
            break;
        case DISPLAY:
            displayStudent(listOfStudents, numOfStudents);
            break;
        case BEST:
            displayBestStudent(listOfStudents, numOfStudents);
            break;
        case REMOVE:
            removeStudent(listOfStudents, numOfStudents);
            break;
        case EXIT:
            for (int i = 0; i < numOfStudents; i++)
            {
                delete listOfStudents[i];
            }
            delete[] listOfStudents;
            return 0;
        default:
            std::cout << "\n ..... Invalid choice, retry pls!\n\n";
            break;
        }
    }
}