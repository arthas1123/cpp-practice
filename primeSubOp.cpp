#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> precomputePrimes(int limit)
    {
        vector<bool> is_prime(limit + 1, true);
        is_prime[0] = is_prime[1] = false;

        for (int i = 2; i * i <= limit; ++i)
        {
            if (is_prime[i])
            {
                for (int j = i * i; j <= limit; j += i)
                {
                    is_prime[j] = false;
                }
            }
        }

        vector<int> primes;
        for (int i = 2; i <= limit; ++i)
        {
            if (is_prime[i])
                primes.push_back(i);
        }
        return primes;
    }

    int findLargestPrimeLessThan(const vector<int> &primes, int target)
    {
        int low = 0, high = primes.size() - 1, result = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (primes[mid] < target)
            {
                result = primes[mid]; // Update result and move right
                low = mid + 1;
            }
            else
            {
                high = mid - 1; // Move left
            }
        }

        return result;
    }

    bool primeSubOperation(vector<int> &nums)
    {
        int max_limit = *max_element(nums.begin(), nums.end());
        vector<int> primes = precomputePrimes(max_limit);

        for (int i = nums.size() - 1; i > 0; --i)
        {
            if (nums[i - 1] >= nums[i])
            {
                int largest_prime = findLargestPrimeLessThan(primes, nums[i]);
                if (largest_prime == -1 || nums[i - 1] - largest_prime <= nums[i])
                    return false;
                nums[i - 1] -= largest_prime;
            }
        }

        return true;
    }
};

int main()
{
    Solution s;
    vector<int> temp = {15, 20, 17, 7, 16};
    cout << s.primeSubOperation(temp) << endl;
    return 0;
}
