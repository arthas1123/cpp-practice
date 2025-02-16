
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    vector<int> constructDistancedSequence(int n)
    {
        int size = 2 * n - 1;
        vector<int> res(size, 0);
        set<int> used;

        if (!backtrack(0, size, res, used))
        {
            return {};
        }
        else
        {
            return res;
        }
    }

private:
    bool backtrack(int index, int size, vector<int> &res, set<int> &used)
    {
        if (index == size)
        {
            return true;
        }

        if (res[index] != 0)
        {
            return backtrack(index + 1, size, res, used);
        }

        for (int num = size / 2 + 1; num > 0; num--)
        {
            if (used.find(num) != used.end())
            {
                continue;
            }

            if (num == 1)
            {
                res[index] = 1;
                used.insert(1);
                if (backtrack(index + 1, size, res, used))
                {
                    return true;
                }
                res[index] = 0;
                used.erase(1);
            }
            else
            {
                int next_index = index + num;
                if (next_index < size && res[next_index] == 0)
                {
                    res[index] = res[next_index] = num;
                    used.insert(num);
                    if (backtrack(index + 1, size, res, used))
                    {
                        return true;
                    }
                    res[index] = res[next_index] = 0;
                    used.erase(num);
                }
            }
        }

        return false;
    }
};

int main()
{
    Solution s;
    vector<int> res = s.constructDistancedSequence(3);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
