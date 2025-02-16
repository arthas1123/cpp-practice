#include <iostream>
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

int main()
{
    student s1;
    s1.name = "Emilia";
    s1.age = 8;
    s1.grades["langugaes"] = 90;
    s1.grades["math"] = 100;
    s1.grades["science"] = 95;

    cout << "Name: " << s1.name << endl;
    cout << "Age: " << s1.age << endl;
    cout << "Grades: " << endl;
    for (auto it = s1.grades.begin(); it != s1.grades.end(); it++)
    {
        cout << it->first << ": " << it->second << endl;
    }
    return 0;
}
