// CSCN73030_Assignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Author: Ryan S
// Date: 09/17/2023
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

// student data object
struct STUDENT_DATA {
    string firstName;
    string lastName;

};

int main()
{
    // Vector holding student data
    vector<STUDENT_DATA> studentData;

    // opening file 
    // NOTE I ADDED THESE FILES TO GITIGNORE I DON'T WANT THEM ON MY REPO
    string fileName = "StudentData.txt";
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
            // adding data to vector
            studentData.push_back(tempData);
        }
    }
    else {
        cout << "Could not open file: " << fileName << endl;
    }
    fileIn.close();
    return 1;
}