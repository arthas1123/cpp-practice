#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();
    unordered_map<int, pair<int, int>> pos;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            pos[mat[i][j]] = {i, j};
        }
    }
    vector<int> rowCount(m, 0);
    vector<int> colCount(n, 0);

    for (int i = 0; i < arr.size(); ++i)
    {
        int num = arr[i];
        auto [r, c] = pos[num];
        if (++rowCount[r] == n || ++colCount[c] == m)
        {
            return i;
        }
    }

    return -1; // This should never be reached if input is valid
}

int main()
{
    vector<int> arr = {1, 3, 4, 2};
    vector<vector<int>> mat = {{1, 4}, {2, 3}};
    int result = firstCompleteIndex(arr, mat);
    // Output: 2
    return 0;
}
