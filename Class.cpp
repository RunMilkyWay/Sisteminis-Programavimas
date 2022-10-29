#include "Class.h"

Student::Student() {
	name = "Null";
	surname = "Null";
	final = 1;
};
Student::Student(string xname, string xsurname, vector<int>xgrades, double xfinal) {
	name = xname;
	surname = xsurname;
	grades = xgrades;
	final = xfinal;
};

Student::~Student() {
	grades.clear();
}

Student::Student(const Student& p1) {
	name = p1.name;
	surname = p1.surname;
	grades = p1.grades;
	final = p1.final;
}

//Student& Student::operator=(const Student& off) {
//	
//}

void Student::DeleteGrades() {
	grades.clear();
}

int Student::Menu() {
	int temp;
	cout << "--------------------MENU--------------------" << endl;
	cout << "********************************************" << endl;
	cout << "1 = Enter Students data" << endl;
	cout << "2 = Read Students data /w Avarage " << endl;
	cout << "3 = Read Students data /w Median" << endl;
	cout << "4 = Read FILE + Sort by name (avg/med) " << endl;
	cout << "--------------------------------------------" << endl;
	cout << "5 = Exit " << endl;
	cout << "********************************************" << endl;
	cin >> temp;
	system("CLS");
	return temp;

};

void Student::PrintMedian() {
	double math = std::accumulate(grades.begin(), grades.end(), 0.0) / grades.size();
	double fscore = (0.4 * math) + (0.6 * final);
	std::nth_element(grades.begin(), grades.begin() + grades.size() / 2, grades.end());
	cout << left << setw(15) << surname << left << setw(15) << name << std::setprecision(2) << fscore << "/" << "(" << grades[grades.size() / 2] << ")" << endl;
}

void Student::PrintFile() {
	double math = std::accumulate(grades.begin(), grades.end(), 0.0) / grades.size();
	double fscore = (0.4 * math) + (0.6 * final);
	std::nth_element(grades.begin(), grades.begin() + grades.size() / 2, grades.end());
	cout << left << setw(15) << surname << left << setw(15) << name << std::setprecision(2) << fscore << "/" << std::setprecision(2) << "(" << math << ")" << "(" << grades[grades.size() / 2]<<")" << endl;

};

std::istream& operator >>(std::istream& input, Student& x) {
	int temp;
	cout << "------------------------------------ADD-NEW----------------------------" << endl;
	cout << "***********************************************************************" << endl;
	cout << " Student name : ";
	cin >> x.name;
	cout << " Student surname : ";
	cin >> x.surname;
	cout << "**********************************************************************" << endl;
	cout << "Enter student grades, after each press ENTER otherwise type 000 to end" << endl;
	cout << "********************************************************** 111 for RNG" << endl;
	cin >> temp;
	while (temp != 000) {
		if (temp == 111) {
			for (int i = 0; i < 10; i++) {
				int random = rand() % 10 + 1;
				x.grades.push_back(random);
			}
			int random = rand() % 10 + 1;
			x.final = random;
			return	input;
		}
		else if (temp > 10 or temp < 0) {
			cout << "ERROR! , PLEASE ENTER NUMBER BETWEEN 0 and 10! " << endl;
			cin >> temp;
		}
		else
		{
			x.grades.push_back(temp);
			cout << "~~~" << endl;
			cin >> temp;

		}
	};
	cout << "**********************************************************************" << endl;
	cout << endl << "Iveskite Egzamino pazymi :";
	cin >> x.final;
	system("CLS");
	cout << "Student data saved" << endl;
	return input;
};

std::ostream& operator <<(std::ostream& output, const Student& x) {
	double math = std::accumulate(x.grades.begin(), x.grades.end(), 0.0) / x.grades.size();
	double fscore = (0.4 * math) + (0.6 * x.final);
	cout << left << setw(15) << x.surname << left << setw(15) << x.name << std::setprecision(2) << fscore << "/" << std::setprecision(2) << "(" << math << ")" << endl;
	return output;
};


int wordnum(string wordnume) {
	int countinger = 0;
	std::string word;
	std::stringstream strm(wordnume);

	while (strm >> word) {
		++countinger;
	};
	return countinger;
};