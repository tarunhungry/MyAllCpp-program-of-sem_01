// C++ program to concatenate two strings
#include<iostream>
#include<string>
using namespace std;

int main() {
    string name, greet = "Hello, ";
    cout << "Enter your name:\t";
    getline( cin, name);

    string concated = greet + name;
    cout << concated;

    

  
    

    return 0;
}