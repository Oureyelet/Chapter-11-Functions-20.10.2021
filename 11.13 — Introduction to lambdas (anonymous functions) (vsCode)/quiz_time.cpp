#include <iostream>
#include <functional> // std::functions
#include <array>
#include <string>
#include <string_view>
#include <algorithm> // for std::max_element, std::sort

struct Student
{
    std::string name{};
    int point{};
};

static bool pkt_compare(int a, int b)
{
    return (a > b);
}

struct Season
{
  std::string_view name{};
  double averageTemperature{};
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
    std::array<Student, 8> arr_Q1{
        {   { "Albert", 3 },
            { "Ben", 5 },
            { "Christine", 2 },
            { "Dan", 8 },
            { "Enchilada", 4 },
            { "Francis", 1 },
            { "Greg", 3 },
            { "Hagrid", 5 }  }
    };

    const auto max {std::max_element(arr_Q1.begin(),
                                arr_Q1.end(),
                                [](const Student& a, const Student& b) { return (a.point <   b.point); })};

    std::cout << max->name << " is the best student\n";


    /*
    Question #2

    Use std::sort and a lambda in the following code to sort the seasons by ascending average temperature.
    */

     std::array<Season, 4> seasons{
        { { "Spring", 285.0 },
        { "Summer", 296.0 },
        { "Fall", 288.0 },
        { "Winter", 263.0 } }
    };
    
    std::sort(seasons.begin(), 
              seasons.end(), 
              [](const Season& a, const Season& b) { return (a.averageTemperature < b.averageTemperature); });

    for (const auto& season : seasons)
    {
        std::cout << season.name << '\n';
    }


    return 0;
}