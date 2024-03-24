#include "university.h"

int main()
{
    University *uni = new University("HCMUT", 100);
    cout << "+++++++++++++++++\n";
    cout << "+      MENU     +\n";
    cout << "+++++++++++++++++\n";
    for (;;)
    {
        int choice;

        cout << "1. Add a student\n";
        cout << "2. Display student list\n";
        cout << "3. Display best student\n";
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
            uni->addStudent();
            break;
        case DISPLAY:
            uni->displayListOfStudents();
            break;
        case BEST:
            uni->displayBestStudent();
            break;
        case REMOVE:
            uni->removeStudent();
            break;
        case EXIT:
            delete uni;
            return 0;
        default:
            cout << "\n ..... Invalid choice, retry pls!\n\n";
            break;
        }
    }
}