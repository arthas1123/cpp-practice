#include <iostream>
#include <vector>
#include <numeric> // For std::accumulate
#include <chrono>  // For timing

int addManually(const std::vector<int> &v)
{
    int sum = 0;
    for (int num : v)
    {
        sum += num;
    }
    return sum;
}

int addUsingAccumulate(const std::vector<int> &v)
{
    return std::accumulate(v.begin(), v.end(), 0);
}

template <class T>
auto addUsingAcc(const T &v)
{
    using ValueType = typename T::value_type;
    return std::accumulate(v.begin(), v.end(), ValueType{0});
}
int main()
{
    // Create a large vector for testing
    std::vector<int> v1(1000, 1); // 1 million elements, all initialized to 1
    std::vector<double> v2(1000, 1.5);
    std::cout << "Int Acc: " << addUsingAcc(v1) << " ." << std::endl;
    std::cout << "Double Acc: " << addUsingAcc(v2) << " ." << std::endl;

    return 0;
}
