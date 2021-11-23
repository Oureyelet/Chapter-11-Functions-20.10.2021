#include <iostream>
#include <algorithm> // for std::swap,

//function prototypes:
double max(double a, double x);
void swap_int(int& a, int& b);
//int& getLargestElement(int* arr, int size);

//

int doSomething()
{
    int array[]{ 1, 2, 3, 4, 5 };
    return array[3];
}

int main()
{
    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Quick Summary" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Another chapter down! The next chapter is the best one, and you’re almost there! There’s just this pesky quiz to get past…

    Function arguments can be passed by value, reference or address. Use pass by value for fundamental data types and enumerators. 
    Use pass by reference for structs, classes, or when you need the function to modify an argument. Use pass by address for 
    passing pointers or built-in arrays. Make your pass by reference and address parameters const whenever possible.

    Values can be returned by value, reference, or address. Most of the time, return by value is fine, however return by 
    reference or address can be useful when working with dynamically allocated data, structs, or classes. If returning by 
    reference or address, remember to make sure you’re not returning something that will go out of scope.

    Inline functions allow you to request that the compiler replace your function call with the function code. You should 
    not need to use the inline keyword because the compiler will generally determine this for you.

    Function pointers allow us to pass a function to another function. This can be useful to allow the caller to customize 
    the behavior of a function, such as the way a list gets sorted.

    Dynamic memory is allocated on the heap.

    The call stack keeps track of all of the active functions (those that have been called but have not yet terminated) 
    from the start of the program to the current point of execution. Local variables are allocated on the stack. The 
    stack has a limited size. std::vector can be used to implement stack-like behavior.

    A recursive function is a function that calls itself. All recursive functions need a termination condition.

    Command line arguments allow users or other programs to pass data into our program at startup. Command line arguments 
    are always C-style strings, and have to be converted to numbers if numeric values are desired.

    Ellipsis allow you to pass a variable number of arguments to a function. However, ellipsis arguments suspend type checking, 
    and do not know how many arguments were passed. It is up to the program to keep track of these details.

    Lambda functions are functions that can be nested inside other functions. They don’t need a name and are very useful in 
    combination with the algorithms library.
    */


    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Quiz time" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Question #1

    Write function prototypes for the following cases. Use const if/when necessary.
    */

    //a) A function named max() that takes two doubles and returns the larger of the two.
    double a{ 55.25 };
    double b{ 7.45 };

    std::cout << max(a, b) << '\n';

    //b) A function named swap() that swaps two integers.
    int a_int{ 3 };
    int b_int{ 77 };

    std::cout << a_int << ' ' << b_int << '\n';

    swap_int(a_int, b_int);

    std::cout << a_int << ' ' << b_int << '\n';

    //c) A function named getLargestElement() that takes a dynamically allocated array of integers 
    //and returns the largest number in such a way that the caller can change the value of the element 
    //returned (don’t forget the length parameter).
    
    /*
    Question #2

    What’s wrong with these programs?
    */




    return 0;
}

double max(double a, double b)
{
    return a>b?a:b;
}

void swap_int(int& a, int& b)
{
    std::swap(a, b);
}

/* im not sure if its right...
int& getLargestElement(int* arr, int size)
{
    arr = new int[size];
}
*/