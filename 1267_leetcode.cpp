// https://leetcode.com/problems/count-servers-that-communicate/
// Optimized solution
#include <vector>
using namespace std;

class Solution
{
public:
    int countServers(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> row_count(m, 0);
        vector<int> col_count(n, 0);
        int tot = 0;

        // Count the number of servers in each row and column
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    tot++;
                    row_count[i]++;
                    col_count[j]++;
                }
            }
        }

        int connected = 0;
        // Count connected servers
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && (row_count[i] > 1 || col_count[j] > 1))
                {
                    connected++;
                }
            }
        }

        return connected;
    }
};
