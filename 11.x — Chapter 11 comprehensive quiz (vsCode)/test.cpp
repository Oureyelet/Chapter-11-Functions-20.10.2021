#include <iostream>
#include <algorithm> // for std::swap,
#include <iterator> 
#include <cmath> // for std::floor
#include <numeric> // for std::midpoint(a, b)


int main()
{
    constexpr int array[]{ 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };

    constexpr int testValues[9]{ 0, 3, 12, 13, 22, 26, 43, 44, 49 };

    if(std::binary_search(std::begin(array), std::end(array), testValues))
    {
        std::cout << "founded !" << '\n';
    }
    else
    {
        std::cout << "not founded ;/" << '\n';
    }

    return 0;
}