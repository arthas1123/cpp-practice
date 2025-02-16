#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

struct student
{
    string name;
    int age;
    // Sub: langugaes, math, science
    map<string, int> grades;
};

class FileIO
{
public:
    void readFromFile(string filename)
    {
        ifstream fin(filename);
        if (!fin)
        {
            cout << "File not found" << endl;
            return;
        }
        string line;
        while (getline(fin, line))
        {
            cout << line << endl;
        }
        fin.close();
    }
};
int main()
{
    // ifstream fin("day12_input_file");
    FileIO f;
    // f.readFromFile("day12_input_file");
    student s1;
    cout << "Enter name: ";
    cin >> s1.name;
    cout << "Enter age: ";
    cin >> s1.age;
    cout << "Enter grades: (langugaes, math, science)" << endl;
    cin >> s1.grades["langugaes"] >> s1.grades["math"] >> s1.grades["science"];
    string fileName = s1.name + "_record";
    ofstream outFile(fileName);
    outFile << "Name: " << s1.name << endl;
    outFile << "Age: " << s1.age << endl;
    outFile << "Grades: " << endl;
    for (auto it = s1.grades.begin(); it != s1.grades.end(); it++)
    {
        outFile << it->first << ": " << it->second << endl;
    }
    int avg = (s1.grades["langugaes"] + s1.grades["math"] + s1.grades["science"]) / 3;
    outFile << "Average: " << avg << endl;
    outFile << "End of record" << endl;
    outFile.close();
    f.readFromFile(fileName);
    return 0;
}
