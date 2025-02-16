#include <vector>
#include <algorithm> // sort
#include <iostream>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), [](int a, int b)
             { return a > b; });
        int ans = nums[0];
        int count = 1;
        int n = nums.size();
        if (ans >= target)
            return count;
        // 83 + 26 + 28 + 25 * 3
        for (int i = 1; i < n; ++i)
        {
            ans += nums[i];
            count += 1;
            if (ans >= target)
                return count;
        }
        if (count == n && ans < target)
            count = 0;
        return count;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {12, 28, 83, 4, 25, 26, 25, 2, 25, 25, 25, 12};
    int target = 213;
    cout << s.minSubArrayLen(target, nums) << endl;
    return 0;
}
