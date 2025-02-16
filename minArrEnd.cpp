#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    int countZeros(int n)
    {
        int count = 0;
        while ((n & 1) == 0 && n != 0)
        {
            n = n >> 1;
            count++;
        }
        return count;
    }
    int merge(int x, int y)
    {
        // remove zeros
        int shift = countZeros(x);
        x = x >> shift;
        while ((x & y) != 0)
        {
            y = y << 1;
        }
        return x | y;
    }
    long long minEnd(int n, int x)
    {
        long result = x;
        long remaining = n - 1;
        long position = 1;

        while (remaining)
        {
            if (!(x & position))
            {
                result |= (remaining & 1) * position;
                remaining >>= 1;
            }
            position <<= 1;
        }

        return result;
    }
};

int main()
{
    Solution s;
    cout << s.minEnd(3, 4) << endl;
    return 0;
}
