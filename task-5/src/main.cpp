#include "../include/student.h"
#include "../include/uniStudent.h"
#include "../include/collegeStudent.h"

int main()
{
    University *uni = new University("HCMUT", 12);
    College *col = new College("Cao Thang", 12);
    while (1)
    {
        int choice;
        cout << "1. University management system\n";
        cout << "2. College management system\n";
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
        switch (choice)
        {
        case UNI:
            uni->makeMenu();
            break;
        case COL:
            col->makeMenu();
            break;
        case EXIT:
            return 0;
        default:
            break;
        }
    }
}