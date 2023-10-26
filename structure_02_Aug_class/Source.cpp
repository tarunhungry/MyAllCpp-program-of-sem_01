

// C++ program to learn structure in class of students

#include<iostream>
#include<string>
using namespace std;
    const int NUMSTD = 3;

    const int SECTION = 2;
struct student {
    string name;
    long id;
    float gpa;
};

// fcuntion to recieve information of student which return student datatype
student getStudentInfo();
// function to print the student information
void printStudentInfo(student std);

// funciton to get class from user
void getClass(student classList[][NUMSTD]);
// fucntion to print the whole class data
void printClass(student classList[][NUMSTD]);
// function to validate the id if it is present or not
int validateId(student classList[], const int NUMSTD, long id);
// fucntion to change gpa
void changeGpa(student& std1, float newgpa);
// fucntion to validate gpa
bool validateGpa(float newgpa);
int main() {
    student classList[SECTION][NUMSTD];
    // this include name, id and gpa
    //classList[0] = getStudentInfo();
    //// let's print what we have entered
    //printStudentInfo(std_01);

    /*for (int i = 0; i < NUMSTD; i++) {
        classList[i] = getStudentInfo();
    }*/
    /*for (int i = 0; i < NUMSTD; i++) {
        printStudentInfo(classList[i]);
    }*/
    getClass(classList);
    printClass(classList);

    // we can change the gpa with asking id number
    //long id; // we can declare it because usmein .id ayegi yeh id hai
    //cout << "Enter student ID to change the gpa : ";
    //cin >> id;

    // variable to store returned index
    int indexId;
    //indexId = validateId(classList, NUMSTD, id); // if id not matched it will throw -1
    /*if (indexId == -1) {
        cout << "\nThere is no Student with ID " << id << " in this class\n";
    }
    else {
        float gpa;
        cout << "\nEnter new gpa : \n";
        cin >> gpa;

    }*/

    return 0;
}

student getStudentInfo() {
    student std;
    //cin.ignore(); // here it will ignore the first letter of the string so don't use it here
    cout << "\nPlease Enter Student Name : ";
    getline(cin, std.name);
    cout << "\nPlease Enter Student ID : ";
    cin >> std.id;
    cout << "\nPlease Enter Student GPA : ";
    cin >> std.gpa;
    
    cin.ignore();
    return std;
}

void printStudentInfo(student std) {
    cout << "\nStudent Name : " << std.name;
    cout << "\nStudent ID : " << std.id;
    cout << "\nStudent GPA : " << std.gpa;

}

void getClass(student classList[][NUMSTD]) {
    for (int j = 0; j < SECTION; j++) {
        for (int i = 0; i < NUMSTD; i++) {
            classList[j][i] = getStudentInfo();
        }
    }
}

void printClass(student classList[][NUMSTD]) {
    for (int j = 0; j < SECTION; j++) {
        for (int i = 0; i < NUMSTD; i++) {
            printStudentInfo(classList[j][i]);
        }
    }
}

//int validateId(student classList[], const int NUMSTD, long id) {
//    for (int i = 0; i < NUMSTD; i++)
//    {   
//        if (classList[i].id == id) {
//            return i; // return the index
//        }
//
//    }
//    return -1;
//}

//void changeGpa(student& std1, float newgpa) {
//    // before changing it we need to validate
//    bool flag = validateGpa(newgpa);
//    std1.gpa = newgpa;
//}

//bool validateGpa(float newgpa) {
//    return (newgpa > 0 && newgpa <= 4.333 ? true : false);
//}



