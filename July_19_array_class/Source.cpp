#include<iostream>
#include<fstream>
// this file is continuation of last class
using namespace std;

// we want to use function to replace the above files which we did earlier
void readFile(ifstream& infile,string name[], double quiz1[], int noMarks);
void highest(string name[],double quiz1[], int noMarks);
void lowest(string name[], double quiz1[], int noMarks);
void Sum(double quiz1[], int noMarks, double &sum);
void Average(double quiz1[], int noMarks, double &sum, double &average);
int countMarks(double quiz1[],string names[], int noMarks, double specificMarks);
int counter = 0;
double specificMarks = 0;

int main() {
    const int NUMSTD = 35;
    double quiz1[NUMSTD] = {};
    string name[NUMSTD];
    double sum = 0, average = 0;

    int noMarks; // number of marks from file it will take first input

    ifstream infile("marks.txt");
    if (!infile) { // checking file exist or not
        cout << "\nFile not found\n";
        return -1;
        // exit(0);
    }

    infile >> noMarks;

    // check noMarks should not be bigger than the array size
    if (noMarks > NUMSTD) {
        cout << "number of marks is bgger than maximum number of student\n";
        exit(0);
    }
    readFile(infile, name, quiz1, noMarks);
    // we can use while loop to ask user what he want
    bool stay = true; int choice;
    while (stay) {
        cout << "\n\nWhat you want to know ?\n";
        cout << "1. Highest\n2. Lowest\n3. Sum\n4. Average\n5. Count Specific Marks occurence\n6. Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            // function to find highest
            highest(name, quiz1, noMarks);
            break;
        case 2:
            // function to find lowest
            lowest(name, quiz1, noMarks);
            break;
        case 3:
            // funciton to find sum of all inputs
            Sum(quiz1, noMarks, sum);
            cout << "\nSum : " << sum;
            sum = 0;
            break;
        case 4:
            // function to find average of all inputs
            Average(quiz1, noMarks, sum, average);
            cout << "\nAverage : " << average;
            sum = 0;
            break;
        case 5:
            cout << "\nEnter marks to count : ";
            cin >> specificMarks;
            counter = countMarks(quiz1, name,noMarks, specificMarks);
            cout << endl << specificMarks << " occurs " << counter << " times in a file\n";
            break;

        default:
            // funciton to exit
            cout << "Thank you :)\n";
            stay = false;
        }
        
    }
   
   
    
    // fuction to find the lowest
    // function to find the sum
    // function to find the average

    infile.close();
    return 0;
}

void readFile(ifstream& infile,string names[], double quiz1[], int noMarks) {
    for (int i = 0; i <= noMarks; i++) {
        infile >> names[i];
        infile >> quiz1[i];
        //cout << quiz1[i] << " ";
    }
}

void highest(string name[],double quiz1[], int noMarks) {
    int indexMax = 0;
    for (int i = 0; i < noMarks; i++)
    {
        if (quiz1[indexMax] < quiz1[i]) {
            indexMax = i;
        }
    }
    cout << "\nThe highest quiz mark is : " << name[indexMax] << " got " << quiz1[indexMax] << endl;
}

void lowest(string name[], double quiz1[], int noMarks) {
    int indexMax = 0;
    for (int i = 0; i < noMarks; i++)
    {
        if (quiz1[indexMax] > quiz1[i]) {
            indexMax = i;
        }
    }
    cout << "\nThe lowest quiz mark is : " <<name[indexMax]<<" got " << quiz1[indexMax] << endl;
}

void Sum(double quiz1[], int noMarks, double &sum) {
    for (int i = 0; i < noMarks; i++) {
        sum += quiz1[i];
    }
    
}

void Average(double quiz1[], int noMarks, double& sum, double& average) {
    Sum(quiz1, noMarks, sum);
    average = sum / noMarks;
   
}

int countMarks(double quiz1[], string names[], int noMarks, double specificMarks){
    int counter = 0;
    for (int i = 0; i < noMarks; i++) {
        if (quiz1[i] == specificMarks) {
            counter++;
            cout<<"\n\t"<<names[i] << endl;
        }
    }
    return counter;
}

// need to count how many student got the specific marks occur in this array

// need to focus on two dimensional array which comes in next assignment and final exam
