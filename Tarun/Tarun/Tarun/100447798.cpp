/*
Tarun Chauhan
100447798
*/
// we can use structurer of arrays

#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;
const int STD = 15, LABS = 8; // named constants


void readData(long int studentId[], long int studentMarks[STD][LABS], ifstream& infile, int size_id);
void printData(long int studentId[], long int studentMarks[STD][LABS], int size_id);
void findAverage(long int studentId[], long int studentMarks[STD][LABS], int size_id);
void displayAverage(long stdId, double average);
void getLowestLab(long int studentId[], long int studentMarks[STD][LABS], int size_id);
void validateLab(long int studentId[], long int studentMarks[STD][LABS]);


int main() {
	long int studentId[STD]; // to store student id
	int size_id = 15;
	// rows are student id and col are labs marks
	//15 x 7
	long int studentMarks[STD][LABS];
	int choice; bool stay =  true;
	while (stay) {
		ifstream infile("Labs.txt");
		if (!infile) {
			cout << "Error in opening a file";
			return -1;
		}

		//readData(studentId, studentMarks, infile, size_id);
		/*cout << studentId[2] << endl;
		cout << studentMarks[3][0];*/

		//cout << "data readed";

		cout << "\n1- Print all students with their marks\n";
		cout << "2- Get a student's average lab by providing their student ID\n";
		cout << "3- Get a student's lowest lab by providing their student ID\n";
		cout << "4- end program\n";
		cin >> choice;
		switch (choice) {
		case 1:
			printData(studentId, studentMarks, size_id);
			break;
		case 2:
			findAverage(studentId, studentMarks, size_id);
			break;
			//	findAverage();
		case 3:
			getLowestLab(studentId, studentMarks, size_id);
			break;
		case 4:
			exit(0);
			break;
		default:
			cout << "Invalid input \n";

		}
		system("pause");
		system("cls");
	}

	return 0;
}/*
void readData(long int studentId[], long int studentMarks[STD][LABS], ifstream& infile, int size_id) {
	//bool stay = true;
	//for ( int i = 0; i < STD; i++) {
	//		infile >> studentId[i];
	//	for (int j = 0; j < LABS; j++) {
	//		//infile >> studentMarks[i][j];
	//	}
	//}
	while (infile && !infile.eof()) {
		for (int i = 0; i < STD; i++) {
					infile >> studentId[i];
					for (int j = 0; j < LABS; j++) {
						infile >> studentMarks[i][j];

				}
			}
			validateLab(studentId, studentmarks);
	}
	
}
*/
void printData(long int studentId[], long int studentMarks[STD][LABS], int size_id) {
	cout << "actually i got an error in reciving a data\n";
	int gap = 20;
	cout << fixed << left << setw(gap) << "Student ID" << setw(gap) << "lab 1" << setw(gap) << "lab 2" << setw(gap) << "lab 3" << setw(gap) << "lab 4" << setw(gap) << "lab 5" << setw(gap) << "lab 6" << setw(gap) << "lab 7" << endl;
	for (int i = 0; i < STD + 1; i++) {
			cout << left << setw(gap) << studentId[i];
		for (int j = 0; j < LABS-1; j++) {
			cout << left << setw(gap) << studentMarks[i][j];
		}
		cout << endl;
	}
}


void findAverage(long int studentId[], long int studentMarks[STD][LABS], int size_id) {
	long tempId;
	cout << "\nPlease enter student ID to get their average lab\n";
	cin >> tempId;
	double sum = 0;
	bool id_valid = false;
	for (int i = 0; i < size_id; i++) {
		if (tempId == studentId[i]) {
			for (int j = 0; j < LABS; j++) {
				sum += studentMarks[i][j];
			}
			id_valid = true;
		}
		
	}
	if (id_valid) { // it will be false if you didn't get id same
		cout << "Your entered id is wrong pls try again:( \n";
		system("pause");
	}
	else
	displayAverage(tempId, sum / 7);
	/*cout << "\nStudent with ID number " << tempId << " average is " << sum / 7;*/
}
void displayAverage(long stdId, double average) {
	cout << "\nStudent with ID number " << stdId << " average is " << average << endl;
}

void getLowestLab(long int studentId[], long int studentMarks[STD][LABS], int size_id) {
	long tempId;
	cout << "\nPlease enter student Id to get their lowest lab : \n";
	cin >> tempId;
	bool id_valid = false;
	int lowest_index=0;
	int lowest = 0;
	for (int i = 0; i < size_id; i++) {
		if (tempId == studentId[i]) {
			id_valid = true;
			lowest = studentMarks[i][0];
			for (int j = 0; j < LABS; j++) {
				if (studentMarks[i][j]<= lowest) {
					lowest = studentMarks[i][j];
					lowest_index = j;
					//lowest++;
					id_valid = true;
				}
			}
		}

	}
	if (!id_valid) {
		cout << "\nInvalid Input \n";
	}
	else {
		cout << "\n Lab " << lowest_index << " is the Lowest lab mark. It is " << lowest_index << "\n";
	}

	
}

void validateLab(long int studentId[],long int studentMarks[STD][LABS]) {
	for (int i = 0; i < STD; i++) {
		for (int j = 1; j < LABS; j++) {
			if (studentMarks[i][j] < 0) {
				cout << "\nPlease enter lab " << j << " mark of student with ID number " << studentId[i] << endl;
				cin >> studentMarks[i][j];
			}
		}
	}
}