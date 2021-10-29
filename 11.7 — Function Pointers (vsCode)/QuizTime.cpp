#include <iostream>
#include <limits> // for std::numeric_limits

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void ask_user()
{
    int x{};
    int y{}; 
    char c{};

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
            break;
        default: // otherwise tell the user what went wrong
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
    }

    std::cout << '\n';

    std::cout << "Your input is: " << x << y << c << '\n';
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
    ask_user();
    


    return 0;
}