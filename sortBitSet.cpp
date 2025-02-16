#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    int countSetBits(int num)
    {
        bitset<32> binary(num);
        return binary.count();
    }
    bool canSortArray(vector<int> &nums)
    {
        int prevMax = INT_MIN;
        int currMin = nums[0];
        int currMax = nums[0];
        int bitCount = countSetBits(nums[0]);

        for (int i = 1; i < nums.size(); i++)
        {
            if (countSetBits(nums[i]) == bitCount)
            {
                currMax = max(nums[i], currMax);
                currMin = min(nums[i], currMin);
            }
            else
            {
                if (prevMax > currMin)
                {
                    return false;
                }
                prevMax = currMax;
                currMin = nums[i];
                currMax = nums[i];
                bitCount = countSetBits(nums[i]);
            }
        }
        return prevMax < currMin;
    }
};

int main()
{
    Solution s;
    // vector<int> nums = {75, 34, 30};
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << s.canSortArray(nums) << endl;
    return 0;
}
