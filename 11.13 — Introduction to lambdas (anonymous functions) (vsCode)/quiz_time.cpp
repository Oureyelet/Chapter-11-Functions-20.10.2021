#include <iostream>
#include <functional>
#include <array>
#include <string>
#include <string_view>

struct student
{
    std::string name{};
    int point{};
};


int main()
{
    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Quiz Time" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Question #1

    Create a struct Student that stores the name and points of a student. Create an array of students and 
    use std::max_element to find the student with the most points, then print that student’s name. std::max_element 
    takes the begin and end of a list, and a function that takes 2 parameters and returns true if the first argument 
    is less than the second.

    Given the following array
    
    std::array<Student, 8> arr{
    { { "Albert", 3 },
        { "Ben", 5 },
        { "Christine", 2 },
        { "Dan", 8 }, // Dan has the most points (8).
        { "Enchilada", 4 },
        { "Francis", 1 },
        { "Greg", 3 },
        { "Hagrid", 5 } }
    };

    your program should print

    Dan is the best student
    */
    std::array students{}



    return 0;
}