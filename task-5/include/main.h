#pragma once

#include <iostream>
#include <string>
#include <array>
#include <limits>
#include <iomanip>

using namespace std;

enum
{
    ADD = 1,
    DISPLAY = 2,
    UPDATE = 3,
    REMOVE = 4,
    EXIT = -1,
    UNI = 1,
    COL = 2
};

class Student;
class UniStudent;
class CollegeStudent;
class University;
class College;