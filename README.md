# Prefix Sum Scan Library
## Overview

This C++ library provides template functions for computing prefix sums (also known as scans) on vectors. It supports both inclusive and exclusive scans, and is implemented using C++ templates to work with various data types.
Features

    Inclusive Scan: Calculates the running total of elements, including the current element.
    Exclusive Scan: Calculates the running total of elements, excluding the current element.
    Two modes of operation: with or without an output vector.
    Templated implementation to support different data types.

## Requirements

    C++ Compiler with C++11 support or higher.
    STL (Standard Template Library).

## Usage
- Including the Library

```cpp
    #include "scan.hpp"
```

## Function Templates

- exclusivePrefixSum
    Computes the exclusive prefix sum of an input vector.
    - Syntax: 
    ```cpp
    void exclusivePrefixSum(std::vector<T> &arr, std::vector<int> &prefixSum)
    ```

- inclusivePrefixSum
    Computes the inclusive prefix sum of an input vector.
    - Syntax: 
    ```cpp
    void inclusivePrefixSum(std::vector<T> &arr, std::vector<int> &prefixSum)
    ```

- scan
    Overloaded function for both inclusive and exclusive scans.
    - Syntax:
    ```cpp
    //With output vector: 
    void scan<ScanType scanType, typename T>(const std::vector<T>& input, std::vector<T>& output)

    //Without output vector: 
    void scan<ScanType scanType, typename T>(std::vector<T>& input)
    ```

## Example Usage

```cpp
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
```
- To compile
```shell
    g++ -std=c++17 -O3 main.cpp -o main
```

## Contributing

Contributions to improve this library are welcome. Please ensure that your code adheres to the existing style and includes tests for new features.

## License

Unlicensed.