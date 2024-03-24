#include <iostream>
#include <string>

#define CAPACITY 100

using namespace std;

enum
{
    EXIT = '0',
    ADD = '1',
    DIS_STUDENT = '2',
    DIS_THEBEST = '3'
};

void addStudents(string *&arrStudent, string name, float *&arrScores, float score, int &curSize)
{
    if (curSize == CAPACITY)
    {
        curSize++;
        string *newarrStudent = new string[curSize];
        float *newarrScores = new float(curSize);
        for (int i = 0; i < curSize - 1; i++)
        {
            newarrStudent[i] = arrStudent[i];
        }
        newarrStudent[curSize - 1] = name;
        newarrScores[curSize - 1] = score;
        arrStudent = newarrStudent;
        cout << "Add student success!!!\n";
    }
    else
    {
        arrStudent[curSize] = name;
        arrScores[curSize] = score;
        curSize++;
        cout << "Add student success!!!\n";
    }
}

void disStudents(string *arrStudent, float *arrScores, int curSize)
{
    cout << "The list of the students and its score:\n";
    for (int i = 0; i < curSize; i++)
    {
        printf("%s\t %.2f\n", arrStudent[i].c_str(), arrScores[i]);
    }
}

void disTheBest(string *arrStudents, float *arrScores, int curSize)
{
    float max = 0;
    for (int i = 0; i < curSize; i++)
    {
        if (max < arrScores[i])
        {
            max = arrScores[i];
        }
    }

    for (int i = 0; i < curSize; i++)
    {
        cout << "The list of best student(s):\n";
        if (max == arrScores[i])
        {
            printf("%s\t %.2f\n", arrStudents[i].c_str(), arrScores[i]);
        }
    }
}

int main()
{
    int curSize = 0;
    string *arrStudents = new string[CAPACITY];
    float *arrScores = new float[CAPACITY];

    while (true)
    {
        char a;
        float score;
        string name;

        cout << "1: add a student.\n";
        cout << "2: display the students list.\n";
        cout << "3: display the best student\n";
        cout << "0: exit the program.\n";
        cout << "Choose the functionalities: \n";

        cin >> a;
        cin.ignore();

        switch (a)
        {
        case EXIT:
            delete[] arrStudents;
            delete[] arrScores;
            return 0;
        case ADD:
            cout << "Type the name of the student and the score:\n";
            getline(cin, name);
            cout << "Type the score of that student:\n";
            cin >> score;

            addStudents(arrStudents, name, arrScores, score, curSize);
            break;
        case DIS_STUDENT:
            disStudents(arrStudents, arrScores, curSize);
            break;
        case DIS_THEBEST:
            disTheBest(arrStudents, arrScores, curSize);
            break;
        default:
            cout << "Invalid input number, please type another!!!\n";
            break;
        }
        cout << "===================\n";
    }
}
