#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
    {
        int maxK = (1 << maximumBit) - 1;
        int s = nums.size();
        int xorr = nums[0];
        for (int i = 1; i < s; i++)
            xorr ^= nums[i];
        vector<int> kVector(s);
        for (int i = 0; i < s; i++)
        {
            kVector[i] = xorr ^ maxK;
            // XOR 後即可得到後面連續ＸＯＲ的結果
            xorr ^= nums[s - 1 - i];
        }
        return kVector;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {0, 1, 1, 3};
    // cout << s.xor_all(nums) << endl;
    vector<int> ans = s.getMaximumXor(nums, 2);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
