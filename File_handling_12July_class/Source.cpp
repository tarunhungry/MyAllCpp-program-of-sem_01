// C++ program to know about files and one dimensional array

#include<iostream>
#include<ctime>
#include<fstream>
#include<iomanip>

using namespace std;

int generateRND(const int max, const int min);
void fillfile(const int NUMBSTD, const int MAX, const int MIN, ofstream& ofile);
//void //countRating(const int NUMBSTD, ifstream &infile, int & count1, int & count2, int& count3, int& count4, int& count5, int& count6, int& count7, int& count8, int& count9, int& count10);
int countRating(const int NUMBSTD, ifstream &infile, int count[]);
int writeChart(ofstream & chartFile, int count1, int count2, int count3, int count4, int count5, int count6, int count7, int count8, int count9, int count10);

int main() {
    const int MAX = 10, MIN = 1, NUMBSTD = 30;
    /*
    * we replaced them by a array
    int counter1 = 0,
        counter2 = 0,
        counter3 = 0,
        counter4 = 0,
        counter5 = 0,
        counter6 = 0,
        counter7 = 0,
        counter8 = 0,
        counter9 = 0,
        counter10 = 0;
        */
    int counter[10];

    srand(time(0));
    
    ofstream ofile("feedback.txt"); // to open a file
    if (!ofile) { // check the file
        cout << "No enough storage\n";
        return -1;
    }
    /*
    int randnumber;
    for (auto i = 0; i < NUMBSTD; i++) {
        randnumber = generateRND(MAX, MIN);
        
        ofile <<"\ncount "<<i+1<<" = " << randnumber << endl; // write in file
    }
    ofile.close(); // close the file
    system("pause");
    */
    fillfile(NUMBSTD, MAX, MIN, ofile); 
    ofile.close();

    ifstream infile("feedback.txt");
    if (!infile) {
        cout << "\nFile not found\n";
        return -1;
    }
    //countRating(NUMBSTD, infile, counter1, counter2, counter3, counter4, counter5, counter6, counter7, counter8, counter9, counter10);
    countRating(NUMBSTD, infile, counter[]);
    /*
    cout << counter1 << endl << counter2 << endl << counter3 << endl;
    cout << counter4 << endl << counter5 << endl << counter6 << endl;
    cout << counter7 << endl << counter8 << endl << counter9 << endl<<counter10;
    */
    // write  the results in a file as a bar chart
    ofstream charFile("barchart.txt");
    if (!charFile) {
        cout << "could not open the file\n";
    }
    writeChart(charFile, counter[]);
    charFile.close();
    // find the highest rating
    // find the lowest rating
    return 0;
}

int generateRND(const int max, const int min) {
    return rand() % (max - min + 1) + min;
}

void fillfile(const int NUMBSTD, const int MAX, const int MIN, ofstream& ofile) {
    int randnumber;
    for (auto i = 0; i < NUMBSTD; i++) {
        randnumber = generateRND(MAX, MIN);

        ofile << randnumber << endl; // write in file
    }

}

// rating wala without array
int countRating(const int NUMBSTD, ifstream& infile, int count[]) {
    int number = 0, rating;

    // we can also use for loop if we know how many numbers in file
    
    while (number < NUMBSTD && !infile.eof()) {
        infile >> rating;
        count[rating - 1]++;
        number++;
        /*
        infile >> rating;
        switch (rating) {
        case 1:
            count1++;
            break;
        case 2:
            count2++;
            break;
        case 3:
            count3++;
            break;
        case 4:
            count4++;
            break;
        case 5:
            count5++;
            break;
        case 6:
            count6++;
            break;
        case 7:
            count7++;
            break;
        case 8:
            count8++;
            break;
        case 9:
            count9++;
            break;
        case 10:
            count10++;
            break;
        }
        number++;
        */
    }
    
}

int writeChart(ofstream& chartFile, int count[]) {
    chartFile << setfill('*');
    /*
    chartFile << "1s " << setw(count1) << "*" << endl;
    chartFile << "2s " << setw(count2) << "*" << endl;
    chartFile << "3s " << setw(count3) << "*" << endl;
    chartFile << "4s " << setw(count4) << "*" << endl;
    chartFile << "5s " << setw(count5) << "*" << endl;
    chartFile << "6s " << setw(count6) << "*" << endl;
    chartFile << "7s " << setw(count7) << "*" << endl;
    chartFile << "8s " << setw(count8) << "*" << endl;
    chartFile << "9s " << setw(count9) << "*" << endl;
    chartFile << "10s " << setw(count10) << "*" << endl;

    */
    for (size_t i = 0; i < 10; i++) {
        chartFile << i + 1 << "s " << setw(count[i]) << "*" << endl;
    }
}

