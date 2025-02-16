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

int main()
{
    // Create a large vector for testing
    std::vector<int> v(1'000'000, 1); // 1 million elements, all initialized to 1

    // Measure time for manual addition
    auto startManual = std::chrono::high_resolution_clock::now();
    int sumManual = addManually(v);
    auto endManual = std::chrono::high_resolution_clock::now();
    auto durationManual = std::chrono::duration_cast<std::chrono::microseconds>(endManual - startManual);

    // Measure time for std::accumulate
    auto startAccumulate = std::chrono::high_resolution_clock::now();
    int sumAccumulate = addUsingAccumulate(v);
    auto endAccumulate = std::chrono::high_resolution_clock::now();
    auto durationAccumulate = std::chrono::duration_cast<std::chrono::microseconds>(endAccumulate - startAccumulate);

    // Output results
    std::cout << "Manual addition result: " << sumManual << ", Time: " << durationManual.count() << " microseconds\n";
    std::cout << "Accumulate result: " << sumAccumulate << ", Time: " << durationAccumulate.count() << " microseconds\n";

    return 0;
}
