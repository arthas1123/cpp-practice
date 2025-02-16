#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX = 6;
inline int roll() { return (rand() % MAX) + 1; };

int main()
{
    int loops = 10; // default number of rolls
    cout << "Enter the number of times to roll the dice: ";
    cin >> loops;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        loops = 10;
        cout << "Invalid input. Please enter a number.\n";
        return 1;
    }
    /*************  ✨ Codeium Command 🌟  *************/
    for (int i = 0; i < loops; ++i)
    {
        int a = roll();
        int b = roll();
        cout << a << " " << b << endl;
    }
    /******  06b2d840-4b0b-4db0-a0d3-740cebb5ee24  *******/
    return 0;
}
