#include <iostream>
using namespace std;

int main()
{
    int smallRooms = 0;
    int bigRooms = 0;
    int priceSmall = 25;
    int priceBig = 35;
    int taxRate = 6;
    int cost = 0;
    float tax = 0.0;
    cout << "Frank's Carpet Cleaning Service" << endl;
    cout << "--------------------------------" << endl;
    cout << "Charges:" << endl;
    cout << "    $" << priceSmall << " per small room" << endl;
    cout << "    $" << priceBig << " per big room" << endl;
    cout << endl;
    cout << "Sales tax rate is " << taxRate << "%" << endl;
    cout << "Estimates are valid for 30 days" << endl;
    cout << "--------------------------------" << endl;
    cout << endl
         << endl;
    cout << "Estimate for carpet cleaning service" << endl;
    cout << "Enter the number of small rooms: ";
    cin >> smallRooms;
    cout << "Enter the number of big rooms: ";
    cin >> bigRooms;
    cout << "Price per small room: $" << priceSmall << endl;
    cout << "Price per big room: $" << priceBig << endl;
    cost = smallRooms * priceSmall + bigRooms * priceBig;
    cout
        << "Cost: $" << cost << endl;
    tax = cost * taxRate / 100;
    cout << "Tax: $" << tax << endl;
    cout << "Total estimate: $" << cost + tax << endl;
    cout << "This estimate is valid for 30 days" << endl;
    return 0;
}
