#include <iostream>
#include <string>

#define CAPACITY 100

using namespace std;
enum
{
    EXIT = -1,
    ADD = 1,
    DISPLAY = 2,
    REMOVE = 3
};

void addStudents(string arrStudents[], string name, int &size)
{
    cout << "Please type a name of a student: ";
    getline(cin, name);
    arrStudents[size++] = name;
}

void displayStudents(string arrStudents[], int size)
{
    cout << "========================" << endl;
    cout << "The list of students are: \n";
    if (size == 0)
        return;
    for (int i = 0; i < size; i++)
    {
        cout << arrStudents[i] << endl;
    }
    cout << "========================" << endl;
}

void rmStudents(string arrStudents[], string name, int &size)
{
    for (int i = 0; i < CAPACITY; i++)
    {
        if (arrStudents[i] == name)
        {
            arrStudents[i] = "";
            for (int j = i + 1; j < size; j++, i++)
            {
                arrStudents[i] = arrStudents[j];
            }
            size--;
            cout << "Succesfully remove" << endl;
            return;
        }
    }
}

int main()
{
    string arrStudents[CAPACITY];
    int curSize = 0;
    while (true)
    {
        cout << "1: add a student.\n";
        cout << "2: display the students list.\n";
        cout << "3: remove a student.\n";
        cout << "-1: exit the program.\n";
        cout << "Choose the functionalities: ";

        int a;
        cin >> a;
        cin.ignore();
        string name;
        switch (a)
        {
        case ADD:
            addStudents(arrStudents, name, curSize);
            break;
        case DISPLAY:
            displayStudents(arrStudents, curSize);
            break;
        case REMOVE:
            cout << "Please  type a name of a student:\n";
            getline(cin, name);
            rmStudents(arrStudents, name, curSize);
            break;
        case EXIT:
            return 0;
            break;
        default:
            cout << "Nummber functionalities is invalid!\n";
            break;
        }
    }
    return 0;
}