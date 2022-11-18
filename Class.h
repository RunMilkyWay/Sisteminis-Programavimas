#pragma once
#include "Header.h"

class Student {
private:
	std::deque<int> grades;
	string name, surname;
	double final;
public:
	double capture;										
	Student();												
	Student(string, string, std::deque<int>, double);			
	Student(const Student& p1);			
	Student& operator=(const Student& og);
	~Student();		
	string GetName();
	string GetSurname();
	double GetFinal();
	int Menu();
	void DeleteGrades();
	void PrintData();
	void PrintFile();
	friend std::istream& operator >>(std::istream& input, Student& x);			
	friend std::ostream& operator <<(std::ostream& output, const Student& x);	
};


int wordnum(string); 
