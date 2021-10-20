#include <iostream>

int main()
{
    std::cout << "Hello World\n";

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Function parameters and arguments" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    In Chapter 2, we covered function basics in the following sections:

    2.1 -- Introduction to functions
    2.3 -- Introduction to function parameters and arguments
    2.6 -- Forward declarations and definitions
    2.7 -- Programs with multiple code files
    2.10 -- Header files

    You should be familiar with the concepts discussed in those lessons before proceeding.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Parameters vs Arguments" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////
    /*
    In the next three lessons, we’ll talk quite a bit about parameters and arguments, so let’s revisit those definitions 
    before proceeding.

    In common usage, the terms parameter and argument are often interchanged. However, for the purposes of further discussion, 
    we will make a distinction between the two:

    A function parameter (sometimes called a formal parameter) is a variable declared in the function declaration:
    */

    /*
    void foo(int x);// declaration (function prototype) -- x is a parameter

    void foo(int x)// definition (also a declaration) -- x is a parameter
    {

    }
    */

    /*
    An argument (sometimes called an actual parameter) is the value that is passed to the function by the caller:

    foo(6); // 6 is the argument passed to parameter x
    foo(y+1);// the value of y+1 is the argument passed to parameter x
    */

    /*
    When a function is called, all of the parameters of the function are created as variables, and the value of the 
    arguments are copied into the parameters. For example:
    
    void foo(int x, int y)
    {

    }
    foo(6, 7);

    */




   return 0;
}