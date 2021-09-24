//Luke Trombatore
//GAME-2303

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
using namespace std;


class Student
{
public:
    string firstName;
    string lastName;
    int grade;

    string StudentInfo(string f, string l, int g)
    {
        firstName = f;
        lastName = l;
        grade = g;
        
        return firstName;
        return lastName;


    }
    int getG()
    {
        return grade;
    }
};


int main()
{
    vector<string> Students;
    Student obj;
    obj.StudentInfo(obj.firstName, obj.lastName, obj.grade);
    //Input file name
    ifstream studentInfo("Students.txt");
    //string to readd the file
    string currentLine;
    //Spaces to split information
    int firstSpace;
    int secondSpace;
    //string to convert grade to int
    string tempGrade;
    int total = 0;
    int average;


    if (studentInfo.is_open())
    {
        while (getline(studentInfo, currentLine))
        {
            int i = 0;
            //Save the information from doc to list.
            Students.push_back(currentLine);

            //Find the end of first name
            firstSpace = currentLine.find(' ');
            //Save the first name
            obj.firstName = currentLine.substr(0, firstSpace);
            //reacquire the last name and grade
            obj.lastName = currentLine.substr(firstSpace + 1);
            //find the second space location between last name and grade
            secondSpace = obj.lastName.find(' ');
            //save the last name
            obj.lastName = currentLine.substr(firstSpace + 1, secondSpace);
            //find the grade and store it as string
            tempGrade = currentLine.substr(secondSpace + firstSpace + 1);
            //convert the grade to an int
            obj.grade = stoi(tempGrade);
            //Add all the grades together
            total += obj.grade;

            Students[i].push_back(i);

            i++;

        }
        // calc average
        average = total / Students.size();

        //Display

        for (int i = 0; i < Students.size(); i++)
        {
            cout << Students[i] << endl;
        }
        cout << "Average: " << average;
    
    }
}


