#include "header.h"

int main()
{
    int choice;
    University *bk = new University("Bach Khoa", 12);
    College *ok = new College("Bach Khoa 2", 12);
    while (1) {
        std::cout << "1. Add new university students" << std::endl;
        std::cout << "2. Add new college students" << std::endl;
        std::cout << "3. Display university students" << std::endl;
        std::cout << "4. Display college students" << std::endl;
        std::cout << "5. Remove university students" << std::endl;
        std::cout << "6. Remove college students" << std::endl;
        std::cout << "7. Display a university student's assignment result" << std::endl;
        std::cout << "8. Display a university student's test result" << std::endl;
        std::cout << "9. Display a university student's exam result" << std::endl;
        std::cout << "10. Display a college student's assignment result" << std::endl;
        std::cout << "11. Display a college student's test result" << std::endl;
        std::cout << "12. Display a college student's exam result" << std::endl;
        std::cin >> choice;
        std::cin.ignore();
        switch (choice) {
        case 1:
            bk->addStudent();
            break;
        case 2: 
            ok->addStudent();
            break;
        case 3: 
            bk->displayListOfStudents();
            break;
        case 4: 
            ok->displayListOfStudents();
            break;
        case 5: 
            bk->removeStudent();
            break;
        case 6: 
            ok->removeStudent();
            break;
        case 7:
            bk->getAssignmentResultFromStudent();
            break;
        case 8:
            bk->getTestResultFromStudent();
            break;
        case 9:
            bk->getExamResultFromStudent();
            break;
        case 10:
            ok->getAssignmentResultFromStudent();
            break;
        case 11:
            ok->getTestResultFromStudent();
            break;
        case 12:
            ok->getExamResultFromStudent();
            break;
        default:
            bk->~University();
            ok->~College();
            return 0;
            break;
        }
    }

    return 0;
}