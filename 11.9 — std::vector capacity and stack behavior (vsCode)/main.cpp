#include <iostream>
#include <vector>


int main()
{
    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "std::vector capacity and stack behavior" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    In lesson 10.23 -- An introduction to std::vector, we introduced std::vector and talked about how std::vector can be 
    used as a dynamic array that both remembers its length and can be dynamically resized as required.

    Although this is the most useful and commonly used part of std::vector, std::vector has some additional attributes 
    and capabilities that make it useful in some other capacities as well.
    */


    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Length vs capacity" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Consider the following example:
    */
    int *array{ new int[10] {1, 2, 3, 4, 5} };

    /*
    We would say that this array has a length of 10, even though we’re only using 5 of the elements that we allocated.

    However, what if we only wanted to iterate over the elements we’ve initialized, reserving the unused 
    ones for future expansion? In that case, we’d need to separately track how many elements were “used” 
    from how many elements were allocated. Unlike a built-in array or a std::array, which only remembers its length, 
    std::vector contains two separate attributes: length and capacity. In the context of a std::vector, length is how 
    many elements are being used in the array, whereas capacity is how many elements were allocated in memory.

    Taking a look at an example from the previous lesson on std::vector:
    */
    std::vector<int> vector_array {0, 1, 2};
    vector_array.resize(5); //set lenght to 5

    std::cout << "The length is: " << vector_array.size() << '\n';

    for(auto& element : vector_array)
    {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    /*
    In the above example, we’ve used the resize() function to set the vector’s length to 5. This tells variable array 
    that we’re intending to use the first 5 elements of the array, so it should consider those in active use. However, 
    that leaves an interesting question: what is the capacity of this array?

    We can ask the std::vector what its capacity is via the capacity() function:
    */
    std::cout << "The capacity is: " << vector_array.capacity() << '\n';

    /*
    In this case, the resize() function caused the std::vector to change both its length and capacity. 
    Note that the capacity is guaranteed to be at least as large as the array length (but could be larger), 
    otherwise accessing the elements at the end of the array would be outside of the allocated memory!
    */


    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "More length vs. capacity" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    
    */


    return 0;
}