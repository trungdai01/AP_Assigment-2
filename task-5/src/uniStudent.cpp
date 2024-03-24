#include "../include/uniStudent.h"

UniStudent::UniStudent() : Student()
{
	this->setName("");
	this->setDayOfBirth("");
	this->setSchoolName("");
	this->setCourseName(4);

	this->setNumOfCourse(4);
	this->setNumOfAssignment(3);
	this->setNumOfTest(2);
	this->setNumOfExam(1);
}
UniStudent::UniStudent(string name, string dayOfBirth, string schoolName, int semester, int numOfCourse) : Student(name, dayOfBirth, schoolName)
{
	this->setName(name);
	this->setDayOfBirth(dayOfBirth);
	this->schoolName = schoolName;
	this->semester = semester;
	numOfCourse = (numOfCourse > 4) ? 4 : numOfCourse;
	this->setCourseName(numOfCourse);

	for (int i = 0; i < numOfCourse; i++)
	{
		this->getCourseName()[i] = "";
	};

	this->setNumOfCourse(numOfCourse);
	this->setNumOfAssignment(3);
	this->setNumOfTest(2);
	this->setNumOfExam(1);
}

int UniStudent::getSemester() const
{
	return this->semester;
}

void UniStudent::setSemester(int semester)
{
	this->semester = (semester > 8) ? 8 : semester;
}

University::University()
{
	listOfUniStudent = NULL;
	currentSize = 0;
}

University::University(string name, int size)
{
	this->name = name;
	listOfUniStudent = new UniStudent *[size];
	currentSize = 0;
}

University::~University()
{
	delete[] listOfUniStudent;
}

string University::getUniName() const
{
	return this->name;
}

void University::makeMenu()
{
	while (1)
	{
		int choice;
		cout << "\t\t\t-----------------------------------------\n";
		cout << "\t\t\t     University Management System\n";
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

void University::addStudent()
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

	string uniName = this->getUniName();

	UniStudent *Mark = new UniStudent(name, dayOfBirth, uniName, semester, numOfCourse);
	listOfUniStudent[currentSize++] = Mark;
	cout << "=======================\n";
}

void University::displayInfo()
{
	if (currentSize == 0)
	{
		cout << " .. The list is empty!!!\n";
		cout << "=======================\n";
		return;
	}
	cout << "Current size: " << currentSize << std::endl;
	cout << "=======================\n";
	// cout << "No.\t Name\t Date Of Birth\t University\t Semester\t Courses\t Assignment\t Test\t Exam\t\n";
	cout << "-----------------------\n";
	for (int i = 0; i < currentSize; i++)
	{
		int it = i;
		cout << ++it << "." << endl;
		cout << "Name: " << listOfUniStudent[i]->getName().c_str() << endl;
		cout << "Day Of Birth: " << listOfUniStudent[i]->getDayOfBirth().c_str() << endl;
		cout << "University: " << this->getUniName().c_str() << endl;
		cout << "Semester: " << listOfUniStudent[i]->getSemester() << endl;
		cout << "No. enrolled courses: " << listOfUniStudent[i]->getNumOfCourse() << endl;
		cout << "No. Assignment: " << listOfUniStudent[i]->getNumOfAssignment();
		cout << "\t"
			 << "No. Test: " << listOfUniStudent[i]->getNumOfTest();
		cout << "\t"
			 << "No. Exam: " << listOfUniStudent[i]->getNumOfExam() << endl;
		cout << endl;
	}
	std::cout << "=======================\n";
}

void University::updateInfo()
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
		if (listOfUniStudent[i]->getName() == name)
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

		listOfUniStudent[positionUpdate]->setName(name);
		listOfUniStudent[positionUpdate]->setDayOfBirth(dayOfBirth);
		listOfUniStudent[positionUpdate]->setSemester(semester);
		listOfUniStudent[positionUpdate]->setNumOfCourse(numOfCourse);
	}
	else
		cout << "Not found in the list\n";
	cout << "=======================\n";
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
		if (listOfUniStudent[i]->getName() == name)
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
		UniStudent **newList = new UniStudent *[newSize];
		for (int i = 0; i < positionRemove; i++)
		{
			newList[i] = listOfUniStudent[i];
		}
		for (int i = positionRemove; i < newSize; i++)
		{
			newList[i] = listOfUniStudent[i + 1];
		}

		currentSize = newSize;
		delete[] listOfUniStudent;
		listOfUniStudent = newList;
		cout << "Remove successfully!!\n";
	}
	else
		cout << "Not found in the list\n";
	cout << "=======================\n";
}
