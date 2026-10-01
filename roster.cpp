// Vector and List algorithms
// Alex Donahue
// 9/29/2026

#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

bool readRoster(map<string, set<string>>& students, const string& fileName, const string& className)
{
    ifstream course(fileName);
    if (!course)
	{
		return false;
	}
        
    string firstName;
    string lastName;
	//Append each classname to each student
    while (course >> firstName >> lastName)
	{
		students[firstName + ' ' + lastName].insert(className);
	}
        

    return true;
}

int main(int argc, char* argv[])
{
    if (argc != 5)
    {
        cerr << "Usage: " << argv[0]
             << " cs1.txt cs2.txt cs3.txt cs4.txt\n";
        return 1;
    }
	// Map of students with sets of classes
    map<string, set<string>> students;

    for (int i = 1; i <= 4; ++i)
    {
        string className = "CS" + to_string(i);

        if (!readRoster(students, argv[i], className))
        {
            cerr << "Could not open " << argv[i] << '\n';
            return 1;
        }
    }
	
    for (const auto& student : students)
    {
        cout << student.first << ": ";

        bool firstClass = true;
		// Loop through each classname in the value portion of the map.
        for (const auto& className : student.second)
        {
            if (!firstClass)
			{
				cout << ", ";
			}
            cout << className;
            firstClass = false;
        }

        cout << '\n';
    }

    return 0;
}
