#pragma once
#include "Header.h"

class Student {
private:
	std::deque<int> grades;
public:
	double final, capture;
	string surname;
	string name;											
	Student();												
	Student(string, string, std::deque<int>, double);			
	Student(const Student& p1);			
	//Student& operator=(const Student& rhs); breaks sort
	~Student();		
	double GetFinal();
	int Menu();
	void DeleteGrades();
	void PrintData();
	void PrintFile();
	friend std::istream& operator >>(std::istream& input, Student& x);			
	friend std::ostream& operator <<(std::ostream& output, const Student& x);	
};


int wordnum(string); 
