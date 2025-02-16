#include <iostream>
using namespace std;
class PointerArithmetic
{
public:
    void pointerArithmetic()
    {
        int arr[] = {10, 20, 30, 40, 50};
        int *ptr = arr;
        for (int i = 0; i < 5; i++)
        {
            cout << "Address: " << (ptr + i) << ", Value: " << *(ptr + i) << endl;
        }
    }
    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    void reverseArray(int *start, int size)
    {
        int *end = start + size - 1;
        while (start < end)
        {
            swap(start, end);
            start++;
            end--;
        }
    }
    void dynamicArr(int size)
    {
        int *arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            cout << "Enter the element: " << endl;
            cin >> arr[i];
        }
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        delete[] arr;
    }
};
int main()
{
    int a = 10;
    int b = 5;
    int *ptr = &a;
    int arr[] = {10, 20, 30, 40, 50};
    cout << ptr << endl;
    cout << *ptr << endl;
    PointerArithmetic pa;
    pa.pointerArithmetic();
    cout << "Before swap: " << "a = " << a << ", b = " << b << endl;
    pa.swap(&a, &b);
    cout << "After swap: " << "a = " << a << ", b =  " << b << endl;
    pa.reverseArray(arr, 5);
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    pa.dynamicArr(size);

    return 0;
}
