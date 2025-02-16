#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maximumCount(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        int posCount = 0, negCount = 0;

        // Find the first positive number
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= 1)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        posCount = nums.size() - left;

        left = 0;
        right = nums.size() - 1;

        // Find the last negative number
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < 0)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        negCount = right + 1;

        return max(negCount, posCount);
    }
};

int main()
{
    Solution s;
    vector<int> nums = {-2, -1, -1, 1, 2, 3};
    cout << s.maximumCount(nums) << endl;
    return 0;
}
