#pragma once
#include "Header.h"

class Student {
private:
	string surname;
	vector<int> grades;
	double final;
public:
	string name;											
	Student();												
	Student(string, string, vector<int>, double);			
	Student(const Student& p1);			
	//Student& operator=(const Student& rhs); breaks sort
	~Student();												
	int Menu();
	void DeleteGrades();
	void PrintMedian();
	void PrintFile();
	friend std::istream& operator >>(std::istream& input, Student& x);			
	friend std::ostream& operator <<(std::ostream& output, const Student& x);	
};


int wordnum(string); 
