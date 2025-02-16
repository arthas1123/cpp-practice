#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX_N = 1000;
vector<int> dp(MAX_N + 1, false);
vector<int> valid_numbers;

class Solution
{
public:
    bool isValid(int num, int origin)
    {
        string str_num = to_string(num);
        int l = str_num.size();
        int tot_part = 1 << (l - 1);
        for (int mask = 0; mask < tot_part; mask++)
        {
            int sum = 0;
            int part = 0;
            for (int i = 0; i < l; i++)
            {
                part = part * 10 + (str_num[i] - '0');

                if ((mask & (1 << i)) || i == l - 1)
                {
                    sum += part;
                    part = 0;
                }
            }
            if (sum == origin)
                return true;
        }
        return false;
    }
    int punishmentNumber(int n)
    {
        for (int i = 1; i <= MAX_N; i++)
        {
            if (isValid(i * i, i))
            {
                dp[i] = true;
                valid_numbers.push_back(i);
            }
        }
        int res = 0;
        for (int i : valid_numbers)
        {
            if (i <= n)
            {
                res += i * i;
            }
            else
                break;
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.punishmentNumber(1000) << endl;
    return 0;
}
