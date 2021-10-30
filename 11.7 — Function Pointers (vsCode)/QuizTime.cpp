#include <iostream>
#include <limits> // for std::numeric_limits

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

typedef int (*fcn_ptr)(int,int); 

int ask_user(std::size_t x, std::size_t y, char c)
{
    /*
    std::size_t x{};
    std::size_t y{}; 
    char c{};
    */

    std::cout << "Enter forst integer: ";

    while (true) // Loop until user enters a valid input
    {
        std::cin >> x;

        if (std::cin.fail()) 
        {
            std::cin.clear();
            ignoreLine();
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            ignoreLine();
            break;
        }
    }
    std::cout << '\n';

    std::cout << "Enter second mathematical operation (‘+’, ‘-‘, ‘*’, ‘/’): ";
    while (true)
    {
        std::cin >> c;
        ignoreLine();

        switch (c)
        {
        case '+':
        case '-':
        case '*':
        case '/':
            std::cout << '\n';
            std::cout << "Your input is: " << x << ' ' << y << ' ' << c << '\n';
            break;

        default: // otherwise tell the user what went wrong
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
        break;
    }
    std::cout << '\n';


    std::cout << "Enter second integer: ";

    while (true) // Loop until user enters a valid input
    {
        std::cin >> y;

        if (std::cin.fail()) 
        {
            std::cin.clear();
            ignoreLine();
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            ignoreLine();
            break;
        }
    }
}

int add(int x, int y)
{
    return x + y;
}

int subtract(int x, int y)
{
    return x - y;
}

int multiply(int x, int y)
{
    return x * y;
}

int division(int x, int y)
{
    return x / y;
}


fcn_ptr getArithmeticFunction(char c)
{
    switch (c)
    {
    case '+':
        return add;
    case '-':
        return subtract;
    case '*':
        return multiply;
    case '/':
        return division;
    }
    return nullptr;
}

int main()
{
    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Quiz time!" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    In this quiz, we’re going to write a version of our basic calculator using function pointers.
    */


    /*
    1a) Create a short program asking the user for two integer inputs and a mathematical operation 
    (‘+’, ‘-‘, ‘*’, ‘/’). Ensure the user enters a valid operation.
    */
    //ask_user();


    /*
    1b) Write functions named add(), subtract(), multiply(), and division(). These should take two integer parameters 
    and return an integer.
    */
    //std::cout << add(3, 3) << '\n';

    //std::cout << subtract(3, 3) << '\n';

    //std::cout << multiply(3, 3) << '\n';

    //std::cout << division(3, 3) << '\n';


    /*
    1d) Write a function named getArithmeticFunction() that takes an operator character and returns the appropriate 
    function as a function pointer.
    */
    //getArithmeticFunction('*');


    /*
    1e) Modify your main() function to call getArithmeticFunction(). Call the return value from that function 
    with your inputs and print the result.
    */



    return 0;
}