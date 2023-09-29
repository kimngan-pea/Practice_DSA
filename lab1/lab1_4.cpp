// Define a Student structured datatype which contains: Student ID (string), Student Name (string),  BirthYear (string), Gender (Char), and student marks including Math (float), Physics (float), Chemistry (float), Average (float).
// Write a program to manage student information (store and display).
// Note: Average = (Math + Physics + Chemistry) / 3

// INPUT FORMAT
// Input Format: (suppose that all input requirements are satisfied)
// 07 lines contain information about a student: 
// Student ID
// Student Name
// Date of Birth in the format "dd/mm/yyyy" (example: "01/01/2008")
// Gender character: M for Male. F for Female
// Math Score  
// Physics score
// Chemistry score

// OUTPUT FORMAT
// Display student information:
// Student ID, Student Name, Date of Birth, Gender, Math Score, Physics Score, Chemistry Score, and Average Score, separated by a tab.
// Average Scores are rounded to two decimal places (using precision).

// EXAMPLES
// Input	
// 07520504
// Luong Thanh
// 31/07/1989
// M
// 10
// 9.5
// 10
// Output
// 07520504	Luong Thanh	31/07/1989	M	10	9.5	10	9.83

// Input
// 07520111
// Nguyen Anh Hong
// 07/12/1991
// F
// 8
// 9
// 7
// Output
// 07520111	Nguyen Anh Hong	07/12/1991	F	8	9	7	8

// Input
// 08520045
// Ho Quang Hieu
// 01/01/1990
// M
// 6
// 6.5
// 7
// Output
// 08520045	Ho Quang Hieu	01/01/1990	M	6	6.5	7	6.5

#include<iostream>
#include<string>
using namespace std;

struct Student {
	char ID[50];
	char Name[100];
	char DOB[50];
	char gender;
	float math;
	float physic;
	float chemistry;
	float average;

	void Input() {
		cout << "Enter the student information: \n"
			<< "ID: ";
		cin.getline(ID, 50);
		cout << "Name: ";
		cin.getline(Name, 100);
		cout << "Date of birth (dd/mm/yyyy):  ";
		cin.getline(DOB, 50);
		cout << "Gender (M/F): ";
		cin >> gender;
		cout << "Math score: ";
		cin >> math;
		cout << "Physic score: ";
		cin >> physic;
		cout << "Chemistry score: ";
		cin >> chemistry;
	}

	void Output() {
		average = (float)(math + physic + chemistry) / 3.0;
		cout << ID << "\t" 
			<< Name << "\t" 
			<< DOB << "\t" 
			<< gender << "\t"
			<< math << "\t" 
			<< physic << "\t" 
			<< chemistry << "\t"
			<< average << "\n";
	}
};


int main() {
	Student std;
	std.Input();
	std.Output();
	return 0;
}