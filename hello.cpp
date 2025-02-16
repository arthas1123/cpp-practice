#include <iostream>

using namespace std;

int doubleNum(int num)
{
    return num * 2;
}

int getNum()
{
    int num{};
    cout << "Enter a number: ";
    cin >> num;
    return num;
}

int add(int x, int y);
int main()
{
    // cout << "Hello World" << endl;
    // int x = getNum();
    // cout << doubleNum(x) << endl;
    int x = getNum();
    int y = getNum();
    cout << add(x, y) << endl;
    return 0;
}
