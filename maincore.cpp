#include "Header.h"

int main()
{
	std::deque<Student> list;
	std::deque<int> fgrades = { 0 };
	Student scholar;
	int possibility = 0;
	int provisional = 0;
	double timer10k, timer100k, timer1000k, timeadd10k, timeadd100k, timeadd1000k, offload = 0;
	string tempname, tempsurname;
	int generated = 0;
	possibility = scholar.Menu();
	while (possibility != 0) {
		try{
			if (possibility < 0 or possibility >10) {
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
					cout << "Pavarde" << setw(15) << "Vardas" << setw(20) << "Galutinis(Med.)" << endl;
					cout << "---------------------------------------------" << endl;
					for (int i = 0; i < list.size(); i++) { list[i].PrintData(); }
					cout << "---------------------------------------------" << endl;
					cout << endl << "1 = Return To Main Menu" << endl;
					cin >> provisional;
					if (provisional == 1) { system("CLS"); possibility = scholar.Menu(); };
				};
				while (possibility == 3) {
					std::sort(list.begin(), list.end(), [](Student& lhs, Student& rhs) {return lhs.GetName() < rhs.GetName();});
					cout << "Pavarde" << setw(13) << "Vardas" << setw(25) << "FinalScore(avg/med)" << setw(15) << endl;
					cout << "---------------------------------------------" << endl;
					for (int i = 0; i < list.size(); i++) { list[i].PrintFile(); }
					cout << "---------------------------------------------" << endl;
					cout << endl << "1 = Return To Main Menu" << endl;
					cin >> provisional;
					if (provisional == 1) { system("CLS"); possibility = scholar.Menu(); };
				}
				while (possibility == 4) {	
					if (generated == 0) {
						cout << "Generating students";
						std::ofstream out10k("10kk.txt");
						auto start = std::chrono::high_resolution_clock::now();
						out10k << "Name" << "\t" << "Surname" << "\t" << "ND1" << "\t" << "ND2" << "\t" << "ND3" << "\t" << "ND4" << "\t" << "ND5" << "\t" << "EGZ";
						for (int i = 0; i < 10000; i++) {
							out10k << "\n" << "Name" << i << "\t";
							out10k << "Surname" << i << "\t";
							int random = rand() % 10 + 1;
							out10k << random << "\t";
							random = rand() % 10 + 1;
							out10k << random << "\t";
							random = rand() % 10 + 1;
							out10k << random << "\t";
							random = rand() % 10 + 1;
							out10k << random << "\t";
							random = rand() % 10 + 1;
							out10k << random << "\t";
							random = rand() % 10 + 1;
							out10k << random;
						};
						auto end = std::chrono::high_resolution_clock::now();
						std::chrono::duration<double>elapsed_seconds = end - start;
						timeadd10k = elapsed_seconds.count();
						out10k.close();
						cout << endl << "10,000 Students list have been generated in :" << timeadd10k << " seconds" << endl;

						std::ofstream out100k("100kk.txt");
						auto start2 = std::chrono::high_resolution_clock::now();
						out100k << "Name" << "\t" << "Surname" << "\t" << "ND1" << "\t" << "ND2" << "\t" << "ND3" << "\t" << "ND4" << "\t" << "ND5" << "\t" << "EGZ";
						for (int i = 10000; i < 110000; i++) {
							out100k << "\n" << "Name" << i << "\t";
							out100k << "Surname" << i << "\t";
							int random = rand() % 10 + 1;
							out100k << random << "\t";
							random = rand() % 10 + 1;
							out100k << random << "\t";
							random = rand() % 10 + 1;
							out100k << random << "\t";
							random = rand() % 10 + 1;
							out100k << random << "\t";
							random = rand() % 10 + 1;
							out100k << random << "\t";
							random = rand() % 10 + 1;
							out100k << random;
						};
						auto end2 = std::chrono::high_resolution_clock::now();
						std::chrono::duration<double>elapsed_seconds2 = end2 - start2;
						timeadd100k = elapsed_seconds2.count();
						out100k.close();
						cout << "100,000 Students list have been generated in :" << timeadd100k << " seconds" << endl;

						std::ofstream out1000k("1000kk.txt");
						auto start3 = std::chrono::high_resolution_clock::now();
						out1000k << "Name" << "\t" << "Surname" << "\t" << "ND1" << "\t" << "ND2" << "\t" << "ND3" << "\t" << "ND4" << "\t" << "ND5" << "\t" << "EGZ";
						for (int i = 110000; i < 1110000; i++) {
							out1000k << "\n" << "Name" << i << "\t";
							out1000k << "Surname" << i << "\t";
							int random = rand() % 10 + 1;
							out1000k << random << "\t";
							random = rand() % 10 + 1;
							out1000k << random << "\t";
							random = rand() % 10 + 1;
							out1000k << random << "\t";
							random = rand() % 10 + 1;
							out1000k << random << "\t";
							random = rand() % 10 + 1;
							out1000k << random << "\t";
							random = rand() % 10 + 1;
							out1000k << random;
						};
						auto end3 = std::chrono::high_resolution_clock::now();
						std::chrono::duration<double>elapsed_seconds3 = end3 - start3;
						timeadd1000k = elapsed_seconds3.count();
						out1000k.close();
						generated++;
						cout << "1,000,000 Students list have been generated in :" << timeadd1000k << " seconds" << endl;

						cout << endl << "1 = Return To Main Menu" << endl;
						cin >> provisional;
						if (provisional == 1) { system("CLS"); possibility = scholar.Menu(); };
					}
					else if (generated == 1) {
						cout << "Lists have already been generated" << endl;
						cout << endl << "10,000 Students list have been generated in :" << timeadd10k << " seconds" << endl;
						cout << "100,000 Students list have been generated in :" << timeadd100k << " seconds" << endl;
						cout << "1,000,000 Students list have been generated in :" << timeadd1000k << " seconds" << endl;
						cout << endl << "1 = Return To Main Menu" << endl;
						cin >> provisional;
						if (provisional == 1) { system("CLS"); possibility = scholar.Menu(); };
					};
				};
				while (possibility == 5) {
					if (generated > 0) {
						cout << "Loading 10,000 Students ....";
						static int checked = 0;
						if (checked == 0) {
							std::ifstream datafile;
							datafile.open("10kk.txt");
							string str = "null", fname = "null", fsurname = "null";
							double fscore = 0;
							string arr[50];
							std::getline(datafile, str);
							int counter = wordnum(str);
							auto start = std::chrono::high_resolution_clock::now();
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
								Student scholar(fname, fsurname, fgrades, fscore);
								list.push_back(scholar);
								fgrades.clear();
							};
							auto end = std::chrono::high_resolution_clock::now();
							std::chrono::duration<double>elapsed_seconds = end - start;
							timer10k = elapsed_seconds.count();
							checked++;
							datafile.close();
							std::sort(list.begin(), list.end(), [](Student& lhs, Student& rhs) {return lhs.GetFinal() < rhs.GetFinal();});
						};



						cout << endl << endl << "10,000 Students has been added in :" << timer10k << " seconds" << endl;

						cout << "---------------------------------------------" << endl;
						cout << endl << "1 = Print on screen";
						cout << endl << "2 = Return To Main Menu" << endl;
						cin >> provisional;
						if (provisional == 1) { system("CLS"); possibility = 2; };
						if (provisional == 2) { system("CLS"); possibility = scholar.Menu(); };
					}
					else if (generated == 0) {
						cout << "Please First Generate the Student Lists" << endl;
						cout << endl << "1 = Back to Main menu" << endl;
						cin >> provisional;
						if (provisional == 1) { system("CLS"); possibility = scholar.Menu(); };
					};
				}
				while (possibility == 6) {
					if (generated > 0) {
						cout << "Loading 100,000 Students ....";
						static int checked = 0;
						if (checked == 0) {
							std::ifstream datafile;
							datafile.open("100kk.txt");
							string str = "null", fname = "null", fsurname = "null";
							double fscore = 0;
							string arr[50];
							std::getline(datafile, str);
							int counter = wordnum(str);
							auto start5 = std::chrono::high_resolution_clock::now();
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
								Student scholar(fname, fsurname, fgrades, fscore);
								list.push_back(scholar);
								fgrades.clear();
								auto end5 = std::chrono::high_resolution_clock::now();
								std::chrono::duration<double>elapsed_seconds5 = end5 - start5;
								timer100k = elapsed_seconds5.count();
							};
							checked++;
							datafile.close();
							std::sort(list.begin(), list.end(), [](Student& lhs, Student& rhs) {return lhs.GetFinal() < rhs.GetFinal();});
						};
						cout << endl << endl << "100,000 Students has been added in :" << timer100k << " seconds!" << endl;
						cout << "---------------------------------------------" << endl;
						cout << endl << "1 = Print on screen";
						cout << endl << "2 = Return To Main Menu" << endl;
						cin >> provisional;
						if (provisional == 1) { system("CLS"); possibility = 2; };
						if (provisional == 2) { system("CLS"); possibility = scholar.Menu(); };
					}
					else if (generated == 0) {
						cout << "Please First Generate the Student Lists" << endl;
						cout << endl << "1 = Back to Main menu" << endl;
						cin >> provisional;
						if (provisional == 1) { system("CLS"); possibility = scholar.Menu(); };
					};
				};
				while (possibility == 7) {
					if (generated > 0) {
						cout << "Loading 1,000,000 Students ....";
						static int checked = 0;
						if (checked == 0) {
							std::ifstream datafile;
							datafile.open("1000kk.txt");
							string str = "null", fname = "null", fsurname = "null";
							double fscore = 0;
							string arr[50];
							std::getline(datafile, str);
							int counter = wordnum(str);
							auto start6 = std::chrono::high_resolution_clock::now();
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
								Student scholar(fname, fsurname, fgrades, fscore);
								list.push_back(scholar);
								fgrades.clear();
								auto end6 = std::chrono::high_resolution_clock::now();
								std::chrono::duration<double>elapsed_seconds6 = end6 - start6;
								timer1000k = elapsed_seconds6.count();
							};
							datafile.close();
							checked++;
							std::sort(list.begin(), list.end(), [](Student& lhs, Student& rhs) {return lhs.GetFinal() < rhs.GetFinal();});
						};
						cout << endl << endl << "1,000,000 Students has been added in :" << timer1000k << " seconds!" << endl;
						cout << "---------------------------------------------" << endl;
						cout << endl << "1 = Print on screen";
						cout << endl << "2 = Return To Main Menu" << endl;
						cin >> provisional;
						if (provisional == 1) { system("CLS"); possibility = 2; };
						if (provisional == 2) { system("CLS"); possibility = scholar.Menu(); };
					}
					else if (generated == 0) {
						cout << "Please First Generate the Student Lists" << endl;
						cout << endl << "1 = Back to Main menu" << endl;
						cin >> provisional;
						if (provisional == 1) { system("CLS"); possibility = scholar.Menu(); };
					};
				};
				while (possibility == 9 ) {			
					auto start555 = std::chrono::high_resolution_clock::now();
					cout << "Sorting students..." << endl;
					std::deque<Student>Good;
					std::deque<Student>Bad;
					std::partition_copy(list.begin(), list.end(), std::back_inserter(Good), std::back_inserter(Bad), [](Student& temper) {return temper.GetFinal() >= 5;});
					auto end555 = std::chrono::high_resolution_clock::now();
					std::chrono::duration<double>elapsed_seconds555 = end555 - start555;
					offload = elapsed_seconds555.count();
					cout << "Sorting took :" << offload << " seconds" << endl;
					cout <<endl<< "Offloading... ";
					auto start111 = std::chrono::high_resolution_clock::now();
					std::ofstream PoorGrade("PoorGradeStudentlist.txt");
					PoorGrade << "Name" << "\t" << "Surname" << "\t" << "FinalGrade" << "\n";
					for (int i = 0; i < Bad.size(); i++) {
						PoorGrade << Bad[i].GetName() << "\t" << Bad[i].GetSurname() << "\t" << Bad[i].GetFinal() << "\n"; }
					PoorGrade.close();
					auto end111 = std::chrono::high_resolution_clock::now();
					std::chrono::duration<double>elapsed_seconds111 = end111 - start111;
					offload = elapsed_seconds111.count();
					cout << endl << "Poor Students List of:"<< Bad.size() <<" students has been ganerated and offloaded in :" << offload << " seconds" << " "<<"(Poorlist.txt)"<< endl;

					auto start222 = std::chrono::high_resolution_clock::now();
					std::ofstream GoodGrade("GoodGradeStudentlist.txt");
					GoodGrade << "Name" << "\t" << "Surname" << "\t" << "FinalGrade" << "\n";
					for (int i = 0; i < Good.size(); i++) {
						GoodGrade << Good[i].GetName() << "\t" << Good[i].GetSurname() << "\t" << Good[i].GetFinal() << "\n";
					}
					GoodGrade.close();
					auto end222 = std::chrono::high_resolution_clock::now();
					std::chrono::duration<double>elapsed_seconds222 = end222 - start222;
					offload = elapsed_seconds222.count();
					cout << "Good Students List of:"<< Good.size()<<" students has been ganerated and offloaded in :" << offload << " seconds"<<" "<< "(Goodlist.txt)" << endl;


					cout << endl << "1 = Return To Main Menu" << endl;
					cin >> provisional;
					if (provisional == 1) { system("CLS"); possibility = scholar.Menu(); };
				
				};
				while (possibility == 8) {
					cout << "Enter student information" << endl;
					cout << "Student name :";
					cin >> tempname;
					cout << "Student Surname :";
					cin >> tempsurname;
					for (int i = 0; i < list.size(); i++) {
						if (list[i].GetName() == tempname && list[i].GetSurname() == tempsurname) {
							list.erase(list.begin() + i);
							system("CLS");
							cout << "The Student has been found and deleted off the list" << endl;
							break;

						}
						else if (list.size() -1 == i) {
							system("CLS");
							cout << "Student with provided name/surname has not been found!" << endl;
							break;
						}
					};

					cout << endl << "1 = Return To Main Menu" << endl;
					cin >> provisional;
					if (provisional == 1) { system("CLS"); possibility = scholar.Menu(); };

				};
				while (possibility == 10) { possibility = 0; };
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
