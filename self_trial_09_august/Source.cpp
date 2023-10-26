#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
using namespace std;
void getDatas(int id[], string name[], double gp[]);
void printIntoFile(ifstream & infile, int id[], string name[], double gp);



int main() {
    int id[2];
    double gp[2];
    string name[2];
    
    getDatas(id, name, gp);
    ofstream ofile("tarun.txt");
    if (!ofile) {
        cout << "no";
        return -1;
    }
     {
        for (int i = 0; i < 2; i++) {
            //ofile << id[i] << "\t" << name[i] << "\t" << gp[i] << "\n";
            ofile << id[i] <<"\t" << gp[i] << "\n";
        }
    }
    ofile.close();
    int trial[2];
    double trial_02[2];
    ifstream infile("tarun.txt");
    while (infile && !infile.eof()) {
        int count = 0;
        for (int i = 0; i < 2; i++)
        {
            infile >> trial[i] >> trial_02[i];
            cout << "\nWhat we got : " << trial[i] << "\t" << trial_02[i] << endl;
        }
        count++;
        if (count > 0) {
            break;
        }
    }
    

    return 0;
}
void getDatas(int id[], string name[], double gp[] ) {
    for (int i = 0; i < 2; i++) {
        cin >> id[i]>>gp[i];
        
    }
}

void printIntoFile(ifstream& infile, int id[], string name[], double gp) {

}