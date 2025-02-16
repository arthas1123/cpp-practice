#include <vector>
#include <queue>
#include <tuple>
#include <iostream>

using namespace std;

class Solution
{
public:
    int minCost(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> cost(rows, vector<int>(cols, INT_MAX));
        deque<pair<int, int>> dq;
        dq.push_front({0, 0});
        cost[0][0] = 0;

        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!dq.empty())
        {
            auto [i, j] = dq.front();
            dq.pop_front();

            for (int d = 0; d < 4; ++d)
            {
                int ni = i + directions[d][0];
                int nj = j + directions[d][1];
                int newCost = cost[i][j] + (grid[i][j] != d + 1);

                if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && newCost < cost[ni][nj])
                {
                    cost[ni][nj] = newCost;
                    if (grid[i][j] == d + 1)
                    {
                        dq.push_front({ni, nj});
                    }
                    else
                    {
                        dq.push_back({ni, nj});
                    }
                }
            }
        }

        return cost[rows - 1][cols - 1];
    }
};

int main()
{
    Solution s;
    // vector<vector<int>> grid = {{1, 1, 1, 1}, {2, 2, 2, 2}, {1, 1, 1, 1}, {2, 2, 2, 2}};
    vector<vector<int>> grid2 = {{1, 1, 3}, {3, 2, 2}, {1, 1, 4}};
    int res = s.minCost(grid2);
    cout << res << endl;
    return 0;
}
