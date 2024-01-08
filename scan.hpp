#include <vector>
#include <iostream>

// Scan Type Enumeration
enum class ScanType {
    Inclusive,
    Exclusive
};

//exclusive scan
template <typename T>
void exclusivePrefixSum(std::vector<T> &arr, std::vector<int> &prefixSum)
{
    prefixSum[0] = 0;
    for (size_t i = 0; i < arr.size(); i++)
        prefixSum[i+1] = prefixSum[i] + arr[i];
}

//inclusive scan
template <typename T>
void inclusivePrefixSum(std::vector<T> &arr, std::vector<int> &prefixSum)
{
    prefixSum[0] = arr[0];
    for (size_t i = 1; i < arr.size(); i++)
        prefixSum[i] = prefixSum[i - 1] + arr[i];
}

// Overloaded template function for scan with output vector
template <ScanType scanType, typename T>
void scan(const std::vector<T>& input, std::vector<T>& output) {
    if (input.empty()) return;

    T sum = 0;
    for (size_t i = 0; i < input.size(); ++i) {
        if constexpr (scanType == ScanType::Inclusive) {
            sum += input[i];
            output[i] = sum;
        } else { // Exclusive scan
            output[i] = sum;
            sum += input[i];
        }
    }
}

// Overloaded template function for scan without output vector
template <ScanType scanType, typename T>
void scan(std::vector<T>& input) {
    if (input.empty()) return;

    T sum = 0, temp;
    for (size_t i = 0; i < input.size(); ++i) {
        temp = input[i];
        if constexpr (scanType == ScanType::Inclusive) {
            sum += temp;
            input[i] = sum;
        } else { // Exclusive scan
            input[i] = sum;
            sum += temp;
        }
    }
}
