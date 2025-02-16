// Too difficult to understand, come back later!
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int trapRainWater(vector<vector<int>> &heightMap)
    {
        if (heightMap.empty() || heightMap[0].empty())
            return 0;
        int m = heightMap.size(), n = heightMap[0].size();
        vector<vector<int>> water(m, vector<int>(n, INT_MAX));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = 0; i < m; ++i)
        {
            pq.push({heightMap[i][0], i * n});
            pq.push({heightMap[i][n - 1], i * n + n - 1});
            water[i][0] = heightMap[i][0];
            water[i][n - 1] = heightMap[i][n - 1];
        }
        for (int j = 1; j < n - 1; ++j)
        {
            pq.push({heightMap[0][j], j});
            pq.push({heightMap[m - 1][j], (m - 1) * n + j});
            water[0][j] = heightMap[0][j];
            water[m - 1][j] = heightMap[m - 1][j];
        }

        vector<int> dirs = {-1, 0, 1, 0, -1};
        int res = 0;
        while (!pq.empty())
        {
            auto [h, pos] = pq.top();
            pq.pop();
            int x = pos / n, y = pos % n;
            for (int k = 0; k < 4; ++k)
            {
                int nx = x + dirs[k], ny = y + dirs[k + 1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && water[nx][ny] > max(h, heightMap[nx][ny]))
                {
                    water[nx][ny] = max(h, heightMap[nx][ny]);
                    pq.push({water[nx][ny], nx * n + ny});
                    res += water[nx][ny] - heightMap[nx][ny];
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> heightMap = {{1, 4, 3, 1, 3, 2},
                                     {3, 2, 1, 3, 2, 4},
                                     {2, 3, 3, 2, 3, 1}};

    // [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
    cout << s.trapRainWater(heightMap) << endl;
    return 0;
}
