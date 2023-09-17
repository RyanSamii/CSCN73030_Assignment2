// CSCN73030_Assignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Author: Ryan S
// Date: 09/17/2023
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

//#define PRE_RELEASE

using namespace std;

// student data object
struct STUDENT_DATA {
    string firstName;
    string lastName;
#ifdef PRE_RELEASE
    string email;
#endif // PRE_RELEASE


};

int main()
{
#ifdef PRE_RELEASE
    cout << "Currently running pre-release version." << endl;
#else
    cout << "Currently running standard version." << endl;
#endif // PRE_RELEASE


    // Vector holding student data
    vector<STUDENT_DATA> studentData;

    // opening file 
    // NOTE I ADDED THESE FILES TO GITIGNORE I DON'T WANT THEM ON MY REPO
#ifdef PRE_RELEASE
    string fileName = "StudentData_Emails.txt";
#else
    string fileName = "StudentData.txt";
#endif
    ifstream fileIn;
    fileIn.open(fileName);
    if (fileIn.is_open()) {
        // file reading loop
        while (!fileIn.eof()) {
            // setting up variables for data parsing
            STUDENT_DATA tempData;
            string line;
            getline(fileIn, line);
            istringstream inutStringStreamLine(line);
            string input;
            // parsing and collecting data
            getline(inutStringStreamLine, input, ',');
            tempData.firstName = input;
            getline(inutStringStreamLine, input, ',');
            tempData.lastName = input;
#ifdef PRE_RELEASE
            getline(inutStringStreamLine, input, ',');
            tempData.email = input;
#endif // PRE_RELEASE

            // adding data to vector
            studentData.push_back(tempData);
            // to fix end of file doing an extra loop
            fileIn.peek();

        }
    }
    else {
        cout << "Could not open file: " << fileName << endl;
    }
    fileIn.close();
    // debug functionality to print out file data to console
#ifdef _DEBUG
    for (int i = 0; i < studentData.size(); i++) {
        cout << "Student first name: " << studentData.at(i).firstName << endl;
        cout << "Student last name: " << studentData.at(i).lastName << endl;
#ifdef PRE_RELEASE
        cout << "Student email: " << studentData.at(i).email << endl;
#endif // PRE_RELEASE

    }
#endif
    return 1;
}