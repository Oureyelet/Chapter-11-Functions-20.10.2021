#include <iostream>
#include <algorithm> // for std::swap,
#include <iterator> 
#include <cmath> // for std::floor

int binarySearch(const int* array, int target, int min, int max)
{  
    int center_element{static_cast<int>(std::floor( max / 2 )) }; // = index of array.
 
    for(int i{ min }; i < max; ++i)
    {
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        if(array[center_element] > target)
        {
            int center_element_NEST_1{static_cast<int>(std::floor( center_element / 2 )) };

            if(array[center_element_NEST_1] > target)
            {
                int center_element_NEST_2{static_cast<int>(std::floor( center_element_NEST_1 / 2 )) };
            }
            else if(array[center_element] < target)
            {
                
            }
            else if(array[center_element_NEST_1] == target)
            {
                return array[center_element_NEST_1];
            }
        }
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        else if(array[center_element] < target)
        {
            int new_x{ static_cast<int>(std::floor( ((max) - center_element) / 2 ))};
            int new_y{ center_element + new_x };
            int center_element_NEST_1A{ array[new_y] };

            if(center_element_NEST_1A > target)
            {
                //int center_element_NEST_2A{static_cast<double>(std::floor( new_y / 2 )) };
            }
            else if(center_element_NEST_1A < target)
            {
                //int new_x{ static_cast<int>(std::floor( ((std::size(array) - 1) - center_element) / 2 ))};
                //int new_y{ center_element + new_x };
                //int center_element_NEST_1A{ array[new_y] };

                if(center_element_NEST_1A > target)
                {
                    //int center_element_NEST_1{static_cast<double>(std::floor( center_element / 2 )) };
                }
                else if(array[center_element] < target)
                {
                    
                }
                else if(array[center_element_NEST_1A] == target)
                {
                    return array[center_element_NEST_1A];
                }
            }
            else if(array[center_element_NEST_1A] == target)
            {
                return array[center_element_NEST_1A];
            }
        }
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        else if(array[center_element] == target)
        {
            return array[center_element];
        }
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        else
        {
           std::cout << "Not founded" << '\n';

           return 0;
        }
    }

}




int main()
{
    constexpr int array[]{ 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };
                        //[0][1][2][ 3][ 4][ 5][ 6][ 7][ 8][ 9][10][11][12][13][14]
                                                    //
    int center_element{static_cast<int>( std::floor( (std::size(array) - 1) / 2) )};

    //std::cout << center_element << '\n';

    int new_x{ static_cast<int>(std::floor( ((std::size(array) - 1) - center_element) / 2 ))};
    int new_y{ center_element + new_x };



    //std::cout << array[new_y] << '\n';

    std::cout << binarySearch(array, 44, 0, static_cast<int>(std::size(array)) - 1) << '\n';


    return 0;
}