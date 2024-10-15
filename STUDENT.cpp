#include "Student.h"
#include <iostream>
#include <iomanip>
using namespace std;
Student::Student() : idNumber(0), tests(nullptr), average(0.0), grade('F') {}
Student::~Student()
{
	delete[] tests;
}
Student* Student::allocateArray(int& numStudents, int& numTests)
{
	do {
		cout << "Enter number of students: ";
		cin >> numStudents;
		if (numStudents <= 0) {
			cout << "Invalid input. Must be greater than 0.\n";
		}
	} while (numStudents <= 0);
	do {
		cout << "Enter number of tests per student: ";
		cin >> numTests;
		if (numTests <= 0) {
			cout << "Invalid input. Must be greater than 0.\n";
		}
	} while (numTests <= 0);
	return new Student[numStudents];
}
void Student::getInput(int numStudents, int numTests)
{
	for (int i = 0; i < numStudents; ++i) {
		cout << "Enter details for student " << i + 1 << ":\n";
		cout << "Name: ";
		cin >> name;

		do {
			cout << "ID Number: ";
			cin >> idNumber;
			if (idNumber <= 0) {
				cout << "Invalid ID. Must be positive.\n";
			}
		} while (idNumber <= 0);

		tests = new int[numTests];
		for (int j = 0; j < numTests; ++j) {
			do {
				cout << "Test " << j + 1 << " score: ";
				cin >> tests[j];
				if (tests[j] < 0 || tests[j] > 100) {
					cout << "Invalid score. Enter a number between 0 and 100.\n";
				}
			} while (tests[j] < 0 || tests[j] > 100);
		}
	}
	calcAvgAndGrade(numStudents, numTests);
}
void Student::calcAvgAndGrade(int numStudents, int numTests)
{
	int total = 0;
	for (int j = 0; j < numTests; ++j)
	{
		total += tests[j];
	}
	average = static_cast<double>(total) / numTests;

	if (average >= 90)
		grade = 'A';
	else if (average >= 80)
		grade = 'B';
	else if (average >= 70)
		grade = 'C';
	else if (average >= 60)
		grade = 'D';
	else if (average >= 50)
		grade = 'E';
	else
		grade = 'F';
}
void Student::displayOneStudent(int numTests) const
{
	cout << "\nName: " << name
		<< "\nID Number: " << idNumber
		<< "\nTest Scores: ";
	for (int j = 0; j < numTests; ++j)
	{
		cout << tests[j] << " ";
	}
	cout << "\nAverage Score: " << fixed << setprecision(2) << average
		<< "\nGrade: " << grade << "\n";
}
int Student::getStudentCount(int numStudents, char grade) const
{
	int count = 0;
	for (int i = 0; i < numStudents; ++i) {
		if (this->grade == grade) {
			count++;
		}
	}
	return count;
}
Student* Student::getBestStudent(int numStudents) {
	Student* bestStudent = this;
	for (int i = 1; i < numStudents; ++i) {
		if (this->average > bestStudent->average) {
			bestStudent = this;
		}
	}
	return bestStudent;
}

void Student::displayStudents(int numStudents, int numTests) const
{
	for (int i = 0; i < numStudents; ++i) {
		cout << "\nDetails of student " << i + 1 << ":";
		displayOneStudent(numTests);
	}
}
void Student::displayBestStudent(int numStudents, int numTests)
{
	Student* best = getBestStudent(numStudents);
	cout << "\nBest student details:";
	best->displayOneStudent(numTests);
}
//void Student::deallocateArray(int numStudents,int numTests)
//{
//    delete[] tests;
//}

void Student::deallocateArray(int numStudents, int numTests)
{
	for (int i = 0; i < numStudents; i++)
	{
		delete[] tests;
	}
	delete[] tests;
}

