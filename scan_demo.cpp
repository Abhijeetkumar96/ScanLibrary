#include <iostream>
#include <vector>

#include "scan.hpp"

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5};
    std::vector<int> result(data.size());

    // Test inclusive scan
    scan<ScanType::Inclusive>(data, result);
    std::cout << "Inclusive Scan: ";
    for (const auto& num : result) 
        std::cout << num << " ";
    std::cout << std::endl;

    // Test exclusive scan
    scan<ScanType::Exclusive>(data, result);
    std::cout << "Exclusive Scan: ";
    for (const auto& num : result) 
        std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}
