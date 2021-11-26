#include <iostream>
#include <algorithm> // for std::swap,
#include <iterator> 
#include <cmath> // for std::floor
#include <numeric> // for std::midpoint(a, b)

int midPoint(int x, int y)
{
    int center_element{static_cast<int>(std::floor( (x+y) / 2 )) };

    return center_element;
}


int binarySearch(const int* array, int target, int min, int max)// if max 8
{  
    int center_element{ midPoint(min, max) }; // 4

    if(array[center_element] == target)
        return center_element;
    else if(array[center_element] > target)
    {
        mix = center_element;
        int center_element_1{ midPoint(min, max) };

        if(array[center_element] == target)
        return center_element;
    }
    else if(array[center_element] < target)
    {
        min = center_element + 1 ; // 5(index)     max = 8
        int center_element_2{ midPoint(min, max) };

        if(array[center_element] == target)
        return center_element;
    }

    for(int i{ 20 }; i != 0; --i)
    {
        
    }
}




int main()
{
    //constexpr int array[]{ 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };
                        //[0][1][2][ 3][ 4][ 5][ 6][ 7][ 8][ 9][10][11][12][13][14]
                                                    
    //int center_element{static_cast<int>(std::floor( 14 / 2 )) };

    std::cout << midPoint(0, 10) << '\n';//5
    std::cout << midPoint(3, 8) << '\n';//5
    std::cout << midPoint(5, 9) << '\n';//7
    std::cout << midPoint(2, 10) << '\n';//6

    std::cout << "Hello" << '\n';

    return 0;
}