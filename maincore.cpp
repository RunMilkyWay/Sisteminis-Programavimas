#include "Header.h"

int main()
{
	vector<Student> list;
	vector<int> fgrades = { 0 };
	Student scholar;
	int possibility = 0;
	int provisional = 0;
	possibility = scholar.Menu();
	while (possibility != 0) {
		try{
			if (possibility < 0 or possibility >5) {
				throw 404;
			};	
				while (possibility == 1) {
					cin >> scholar;
					list.push_back(scholar);
					scholar.DeleteGrades();
					system("CLS");
					cout << " *** Student has been added ! ***" << endl;
					cout << endl << "1 = Add Another Student : " << endl;
					cout << "2 = Back to Main manu : " << endl;
					cin >> provisional;
					if (provisional == 2) { system("CLS"); possibility = scholar.Menu(); };
					system("CLS");
				};
				while (possibility == 2) {
					cout << "Pavarde" << setw(15) << "Vardas" << setw(20) << "Galutinis(Vid.)" << endl;
					cout << "---------------------------------------------" << endl;
					for (int i = 0; i < list.size(); i++) { cout << list[i]; }
					cout << endl << "1 = Return To Main Menu" << endl;
					cin >> provisional;
					if (provisional == 1) { system("CLS"); possibility = scholar.Menu(); };
				};
				while (possibility == 3) {
					cout << "Pavarde" << setw(15) << "Vardas" << setw(20) << "Galutinis(Med.)" << endl;
					cout << "---------------------------------------------" << endl;
					for (int i = 0; i < list.size(); i++) { list[i].PrintMedian(); }
					cout << endl << "1 = Return To Main Menu" << endl;
					cin >> provisional;
					if (provisional == 1) { system("CLS"); possibility = scholar.Menu(); };
				};
				while (possibility == 4) {
					static int checked = 0;
					if (checked == 0) {
						std::ifstream datafile;
						datafile.open("data.txt");
						string str = "null", fname = "null", fsurname = "null";
						double fscore = 0;
						string arr[50];
						std::getline(datafile, str);
						int counter = wordnum(str);
						while (datafile.peek() != EOF) {
							std::getline(datafile, str);
							std::stringstream ss(str);
							for (int i = 0; i < counter; i++) {
								ss >> arr[i];
								if (i == 0) { fname = arr[i]; }
								else if (i == 1) { fsurname = arr[i]; }
								else if (i > 1 and i + 1 < counter) { fgrades.push_back(stoi(arr[i])); }
								else if (i + 1 == counter) { fscore = stoi(arr[i]); }
							};
							Student fscholar(fname, fsurname, fgrades, fscore);
							list.push_back(fscholar);
							fgrades.clear();
						};
						checked++;
						std::sort(list.begin(), list.end(), [](const Student& lhs, const Student& rhs) {return lhs.name < rhs.name;});
					};
					cout << "Pavarde" << setw(13) << "Vardas" << setw(25) << "FinalScore(avg/med)" << setw(15) << endl;
					cout << "---------------------------------------------" << endl;
					for (int i = 0; i < list.size(); i++) { list[i].PrintFile(); }
					cout << endl << "1 = Return To Main Menu" << endl;
					cin >> provisional;
					if (provisional == 1) { system("CLS"); possibility = scholar.Menu(); };
				}
				while (possibility == 5) { possibility = 0; };
				}
		catch (int ExceptionERR) {
			cout << "ERROR 404: Menu option does not exist" << endl;
			system("pause");
			system("CLS");
			possibility = scholar.Menu();

		};
	};
	return 0;
};
